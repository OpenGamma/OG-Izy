%
% Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies
%
% Please see distribution for license.
%

function retstr = gendata(fnname, uname, lang, arg0, arg1)
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

  

  if(strcmp(lower(lang),'c'))
    fname=[filetag,uname,"_c.inc"];
  elseif(strcmp(lower(lang),'java'))
    fname=[filetag,uname,"_java.inc"];
  else
    error("unknown language",lang);
  end

  retstr = ["@Test\n public void ",filetag,uname,"Test() {\n #include \"",fname,"\"\n"];

  fp=fopen(fname,'w+');
  if(fp<0)
    error("file open failed")
  end

  if(nargin==4)
    fprintf(fp,'int n_in = %d;\n',numel(arg0));
    writeData(fp,arg0,'in_data','',lang);
    out1=[];
    try
            [out0,out1]=arrayfun(fnname,arg0);
    catch 
            [out0]=arrayfun(fnname,arg0);
    end
  
    retstr = [retstr,"double[] y0 = new double[expected0.length];\n"]
    fprintf(fp,'int n_expected = %d;\n',numel(out0));
    if(~isempty(out1))
      writeData(fp,out0,'expected_data','0',lang);
      writeData(fp,out1,'expected_data','1',lang);
      retstr = [retstr,"double[] y1 = new double[expected1.length];\n"]
      retstr = [retstr,"_izy.",filetag,uname,"(new int[] {n_in}, arg0, zero, y0, zero, y1, zero);"];
    else
      writeData(fp,out0,'expected_data','',lang);
      retstr = [retstr,"_izy.",filetag,uname,"(new int[] {n_in}, arg0, zero, y0, zero);"];
    end
  elseif(nargin==5)  
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

    retstr = [retstr,"double[] y0 = new double[expected0.length];\n"]
    fprintf(fp,'int n_expected = %d;\n',numel(out0));
    if(~isempty(out1))
      writeData(fp,out0,'expected_data','0',lang);
      writeData(fp,out1,'expected_data','1',lang);
      retstr = [retstr,"double[] y1 = new double[expected1.length];\n"]
      retstr = [retstr,"_izy.",filetag,uname,"(new int[] {n_in}, arg0, zero, arg1, zero, y0, zero, y1, zero);"];
    else
      writeData(fp,out0,'expected_data','',lang);
      retstr = [retstr,"_izy.",filetag,uname,"(new int[] {n_in}, arg0, zero, arg1, zero, y0, zero);"];
    end
  else
          error("Too many args")
  end
  retstr = [retstr,"\n};"]
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

function [] = writeData(fp,out,name,val,lang);
    if(~any(iscomplex(out)))
      fmt = '%24.15e';
      if(strcmp(lower(lang),'c'))
        declstr=['static double ',name,val,'[] = {'];
      elseif(strcmp(lower(lang),'java'))
        declstr=['double ',name,val,'[] = {'];
      else
        error("unknown language",lang);
      end
    else      % complex numbers
      if(strcmp(lower(lang),'c'))
        declstr=['static complex double ',name,val,'[] = {'];
        fmt = '%24.15e+I*%24.15e';
      elseif(strcmp(lower(lang),'java'))
        declstr=['double ',name,val,'[] = {'];
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

