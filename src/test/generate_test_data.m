clear all; close all; clc;


function [] = writeData(fp,out,name,val,lang);
    if(~any(iscomplex(out)))
      fmt = '%24.15e';
      if(strcmp(lower(lang),'c'))
        declstr=['static double ',name,val,'[] = {'];
      elseif(strcmp(lower(lang),'java'))
        declstr=['private static double ',name,val,'[] = {'];
      else
        error("unknown language",lang);
      end
    else      % complex numbers
      if(strcmp(lower(lang),'c'))
        declstr=['static complex double ',name,val,'[] = {'];
        fmt = '%24.15e+I*%24.15e';
      elseif(strcmp(lower(lang),'java'))
        declstr=['private static double ',name,val,'[] = {'];
        fmt = '%24.15e, %24.15e';
      else
        error("unknown language",lang)
      end
    end

    fprintf(fp,'%s\n',declstr);
    if(~any(iscomplex(out)))
      for k=1:numel(out)-1
        fprintf(fp,fmt,out(k))
        fprintf(fp,',\n');
      end
      fprintf(fp,fmt,out(end))
    else
      for k=1:numel(out)-1
        fprintf(fp,fmt,[real(out(k)),imag(out(k))])
        fprintf(fp,',\n');
      end
        fprintf(fp,fmt,[real(out(end)),imag(out(end))])
    end

    fprintf(fp,'\n};\n');
end


function ret = gendata(fnname, uname, lang, arg0, arg1)
  complexD=false;
  if(any(iscomplex(arg0)))
    complexD=true;
    filetag="vz_";
  else
    filetag="vd_";
  end

  if(~complexD)
  disp(["REAL: Calling function: ",fnname," for IZY ",uname]);
  else
  disp(["CMPLX: Calling function: ",fnname," for IZY ",uname]);
  end

  if(nargin==4)
    if(strcmp(lower(lang),'c'))
      fname=[filetag,uname,"_c.inc"];
    elseif(strcmp(lower(lang),'java'))
      fname=[filetag,uname,"_java.inc"];
    else
      error("unknown language",lang);
    end
    fp=fopen(fname,'w+');
    if(fp<0)
      error("file open failed")
    end
    
    fprintf(fp,'int n_in = %d;\n',numel(arg0));
    writeData(fp,arg0,'in_data','',lang);
    out1=[];
    try
            [out0,out1]=arrayfun(fnname,arg0);
    catch 
            [out0]=arrayfun(fnname,arg0);
    end
    fprintf(fp,'int n_expected = %d;\n',numel(out0));
    if(~isempty(out1))
      writeData(fp,out0,'expected_data','0',lang);
      writeData(fp,out1,'expected_data','1',lang);
    else
      writeData(fp,out0,'expected_data','',lang);
    end
  elseif(nargin==5)  
    if(strcmp(lower(lang),'c'))
      fname=[filetag,uname,"_c.inc"];
    elseif(strcmp(lower(lang),'java'))
      fname=[filetag,uname,"_java.inc"];
    else
      error("unknown language",lang);
    end
    fp=fopen(fname,'w+');
    if(fp<0)
      error("file open failed")
    end
    fprintf(fp,'int n_in = %d;\n',numel(arg0));
    writeData(fp,arg0,'in_data','0',lang);
    writeData(fp,arg1,'in_data','1',lang);   

    out1=[];
    out0=[];
    try
            [out0,out1]=arrayfun(fnname,arg0,arg1);
    catch
            [out0]=arrayfun(fnname,arg0,arg1);
    end

    fprintf(fp,'int n_expected = %d;\n',numel(out0));
    if(~isempty(out1))
      writeData(fp,out0,'expected_data','0',lang);
      writeData(fp,out1,'expected_data','1',lang);
    else
      writeData(fp,out0,'expected_data','',lang);
    end
  else
          error("Too many args")
  end
  fclose(fp);
end % function

% functions for which there is no impl
function ret = invcbrt(arg0)
        ret = 1./cbrt(arg0);
end

function ret = invsqrt(arg0)
        ret = 1./sqrt(arg0);
end

function ret = invsingle(arg0)
        ret = 1./arg0;
end

function [a,b]=sincos(data)
        a=sin(data);
        b=cos(data);
end

function ret = pow2o3(arg0)
        ret = power(arg0,2/3);
end

function ret = pow3o2(arg0)
        ret = power(arg0,1.5);
end

function [integral,fraction]=modf(arg0)
        integral = fix(arg0);
        fraction = arg0 - integral;
end

% botch
function ret = nearbyint(arg0)
        ret = zeros(size(arg0));
        for(i=1:length(arg0))
                v = abs(arg0(i));
                if(v-fix(v)>0.50)
                        rv = fix(v) + 1;
                else
                        rv = fix(v);
                end
                ret(i)=sign(arg0(i))*rv;
        end
end


function[] = gen_per_lang(lang)

  trig_range=linspace(-6.25,6.25,11);
  invtrig_range=linspace(-0.99,0.99,10);
  perm_invtrig_range=invtrig_range(randperm(length(invtrig_range)));

  hyp_range=linspace(-5,5,21);
  acosh_range=linspace(1.01,10,10);
  asinh_range=linspace(-10,10,10);
  atanh_range=linspace(-0.99,0.99,10);

  std_range_small = [-10:0.5:-0.5,0.5:0.5:10]; %% shift for things like div so theres no 0/0
  std_range_large = 10*std_range_small;
  std_const = 10;

  lgamma_range = [-9.5:2:-0.5,0.5:0.5:10];
  tgamma_range = [-9.5:2:-0.5,0.5:0.5:4];

  log_range_small = 0.5+(0:0.5:10); %% shift to avoid 0
  exp_range_small = -5:5;

  pow_range_small = [-8:1:-1,0.5:0.5:4]; 
  std_pow_const = 3;

  bounded_one_one = linspace(-1,1,20);

  [x,y]=meshgrid([-10:10],[-10:10]);
  complex_data=x+i*y;
  complex_std_const = 10+5i;

  %% REAL Functions
  % trig
  gendata('acos','acos',lang,invtrig_range);
  gendata('asin','asin',lang,invtrig_range);
  gendata('atan','atan',lang,invtrig_range);
  gendata('atan2','atan2',lang,invtrig_range, perm_invtrig_range);
  gendata('cos','cos',lang,trig_range);
  gendata('sin','sin',lang,trig_range);
  gendata('sincos','sincos',lang,trig_range);
  gendata('tan','tan',lang,trig_range);

  %  arith
  gendata('abs','abs',lang,std_range_small);
  gendata('plus','add',lang,std_range_small,std_range_large);
  gendata('plus','addx',lang,std_range_small,std_const);
  gendata('rdivide','div',lang,std_range_small,std_range_large);
  gendata('rdivide','divx',lang,std_range_small,std_const);
  %  gendata(''); % RESERVED for linearfrac, not sure whether it's worth impl
  gendata('times','mul',lang,std_range_small,std_range_large);
  gendata('times','mulx',lang,std_range_small,std_const);
  gendata('power','sqr',lang,std_range_small,2);
  gendata('minus','sub',lang,std_range_small,std_range_large);
  gendata('minus','subx',lang,std_range_small,std_const);

  %exp+log
  gendata('exp','exp',lang,exp_range_small);

  gendata('expm1','expm1',lang,exp_range_small);
  gendata('log','ln',lang,log_range_small);
  gendata('log10','log10',lang,log_range_small);
  gendata('log1p','log1p',lang,log_range_small);

  %hyp
  gendata('acosh','acosh',lang,acosh_range);
  gendata('asinh','asinh',lang,asinh_range);
  gendata('atanh','atanh',lang,atanh_range);
  gendata('cosh','cosh',lang,hyp_range);
  gendata('sinh','sinh',lang,hyp_range);
  gendata('tanh','tanh',lang,hyp_range);

  %specfun
  gendata('normcdf','cdfnorm',lang,bounded_one_one);
  %  gendata(''); % RESERVED for cdfnorminv, not sure whether it's worth impl ATM
  gendata('erf','erf',lang,bounded_one_one);
  gendata('erfc','erfc',lang,bounded_one_one);
  %  gendata(''); % RESERVED for erfinv, not sure whether it's worth impl ATM
  %  gendata(''); % RESERVED for erfcinv, not sure whether it's worth impl ATM
  gendata('lgamma','lgamma',lang,lgamma_range);
  gendata('gamma','tgamma',lang,tgamma_range);


  %  %PWR
  gendata('cbrt','cbrt',lang,std_range_small);
  gendata('hypot','hypot',lang,std_range_small, std_range_large);
  gendata('invsingle','inv',lang,std_range_small); % we use our own fn as inv returns 2 args, one is the rcond no
  gendata('invcbrt','invcbrt',lang,std_range_small);
  gendata('invsqrt','invsqrt',lang,std_range_small);
  gendata('power','pow',lang, pow_range_small, pow_range_small);
  gendata('power','powx',lang, pow_range_small, std_pow_const);
  gendata('pow2o3','pow2o3',lang, log_range_small);
  gendata('pow3o2','pow3o2',lang, log_range_small);
  gendata('sqrt','sqrt',lang,log_range_small);

  % ROUNDING
  gendata('ceil','ceil',lang,trig_range);
  gendata('floor','floor',lang,trig_range);
  gendata('modf','modf',lang,trig_range);
  gendata('nearbyint','nearbyint',lang,trig_range);
  gendata('nearbyint','rint',lang,trig_range);
  gendata('round','round',lang,trig_range);
  gendata('fix','trunc',lang,trig_range);


  %% COMPLEX Functions
  % trig
  gendata('acos','acos',lang,complex_data);
  gendata('asin','asin',lang,complex_data);
  gendata('atan','atan',lang,complex_data);
  gendata('cos','cos',lang,complex_data);
  gendata('sin','sin',lang,complex_data);
  gendata('tan','tan',lang,complex_data);

  %hype
  gendata('acosh','acosh',lang,complex_data);
  gendata('asinh','asinh',lang,complex_data);
  gendata('atanh','atanh',lang,complex_data);
  gendata('cosh','cosh',lang,complex_data);
  gendata('sinh','sinh',lang,complex_data);
  gendata('tanh','tanh',lang,complex_data);

  % pwr
  gendata('power','pow',lang,complex_data,complex_data);
  gendata('power','powx',lang,complex_data, complex_std_const);
  gendata('sqrt','sqrt',lang,complex_data);
  gendata('exp','exp',lang,complex_data);
  gendata('log','ln',lang,complex_data);
  gendata('log10','log10',lang,complex_data);

  gendata('abs','abs',lang,complex_data);
  gendata('plus','add',lang,complex_data,complex_data);
  gendata('plus','addx',lang,complex_data,complex_std_const);
  gendata('rdivide','div',lang,complex_data,complex_data);
  gendata('rdivide','divx',lang,complex_data,complex_std_const);

  gendata('arg','arg',lang,complex_data);
  gendata('conj','conj',lang,complex_data);
    
  gendata('times','mul',lang,complex_data,complex_data);
  gendata('times','mulx',lang,complex_data,complex_std_const);
  gendata('times','mulbyconj',lang,complex_data,conj(complex_data));
  gendata('minus','sub',lang,complex_data,complex_data);
  gendata('minus','subx',lang,complex_data,complex_std_const);
end



%% main code

rand('state',0);
gen_per_lang("c");
gen_per_lang("java");