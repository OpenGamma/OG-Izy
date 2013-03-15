function retstr = gendata(fnname, uname, lang, arg0, arg1)
  complexD=false;
  if(any(~isreal(arg0)))
    complexD=true;
    filetag='vz_';
  else
    filetag='vd_';
  end

  if(~complexD)
  disp(['REAL: Calling function: ',fnname,' for IZY ',uname]);
  else
  disp(['CMPLX: Calling function: ',fnname,' for IZY ',uname]);
  end

  

  if(strcmp(lower(lang),'c'))
    fname=[filetag,uname,'_c.inc'];
  elseif(strcmp(lower(lang),'java'))
    fname=[filetag,uname,'_java.inc'];
  else
    error('unknown language',lang);
  end

  retstr = ['@Test\n public void ',filetag,uname,'Test() {\n #include "',fname,'"\n'];

  fp=fopen(fname,'w+');
  if(fp<0)
    error('file open failed')
  end

  % functions starting x are of form const(OP)array so n_in depends on arg1
  if(strcmp(upper(uname(1)),'X'))
    fprintf(fp,'int n_in = %d;\n',numel(arg1));
  else
    fprintf(fp,'int n_in = %d;\n',numel(arg0));
  end

  eval(['fnname_handle=@',fnname,';']);
  
  if(nargin==4)
    writeData(fp,arg0,'in_data','',lang);
    out1=[];
    try
            [out0,out1]=arrayfun(fnname_handle,arg0);
    catch 
            [out0]=arrayfun(fnname_handle,arg0);
    end

    if(any(~isreal(out0))||any(~isreal(out1)))
      scale=2;
    else
      scale=1;
    end

    fprintf(fp,'// for debug:\n int n_expected = %d;\n',numel(out0));
    if(~isempty(out1))
      writeData(fp,out0,'expected_data','0',lang);
      writeData(fp,out1,'expected_data','1',lang);
      retstr = [retstr,'double[] y0 = new double[',num2str(scale),'*expected_data0.length];\n'];
      retstr = [retstr,'double[] y1 = new double[',num2str(scale),'*expected_data1.length];\n'];
      retstr = [retstr,'_izy.',filetag,uname,'(new int[] {n_in}, in_data, zero, y0, zero, y1, zero);\n'];
      retstr = [retstr, 'assertTrue(FPEquals.fuzzyEqualsDynamicTol(y0, expected_data0));\n'];
      retstr = [retstr, 'assertTrue(FPEquals.fuzzyEqualsDynamicTol(y1, expected_data1));\n'];
    else
      writeData(fp,out0,'expected_data','',lang);
      retstr = [retstr,'double[] y0 = new double[expected_data.length];\n'];
      retstr = [retstr,'_izy.',filetag,uname,'(new int[] {n_in}, in_data, zero, y0, zero);\n'];
      retstr = [retstr, 'assertTrue(FPEquals.fuzzyEqualsDynamicTol(y0, expected_data));\n'];
    end
  elseif(nargin==5)  
    
      if(strcmp(upper(uname(end)),'X'))% functions ending in "x" need 1 const value 
        writeData(fp,arg0,'in_data','0',lang);          
        writeData(fp,arg1(1),'in_data','1',lang);   
      elseif(strcmp(upper(uname(1)),'X'))% functions starting in "x" need 1 const value 
        writeData(fp,arg0(1),'in_data','0',lang);   
        writeData(fp,arg1,'in_data','1',lang);
      elseif (strcmp(upper(uname),'power'))
        writeData(fp,arg0,'in_data','0',lang);   
        writeData(fp,arg1(1),'in_data','1',lang);   
      else
        writeData(fp,arg0,'in_data','0',lang);   
        writeData(fp,arg1,'in_data','1',lang);   
      end
        
    out1=[];
    out0=[];
    try
            [out0,out1]=arrayfun(fnname_handle,arg0,arg1);
    catch
            [out0]=arrayfun(fnname_handle,arg0,arg1);
    end

    fprintf(fp,'int n_expected = %d;\n',numel(out0));
    if(~isempty(out1))
      writeData(fp,out0,'expected_data','0',lang);
      writeData(fp,out1,'expected_data','1',lang);
      retstr = [retstr,'double[] y0 = new double[',num2str(scale),'*expected_data0.length];\n'];
      retstr = [retstr,'double[] y1 = new double[',num2str(scale),'*expected_data1.length];\n'];
      retstr = [retstr,'_izy.',filetag,uname,'(new int[] {n_in}, in_data0, zero, in_data1, zero, y0, zero, y1, zero);\n'];
      retstr = [retstr, 'assertTrue(FPEquals.fuzzyEqualsDynamicTol(y0, expected_data0));\n'];
      retstr = [retstr, 'assertTrue(FPEquals.fuzzyEqualsDynamicTol(y1, expected_data1));\n'];
    else
      writeData(fp,out0,'expected_data','',lang);
      retstr = [retstr,'double[] y0 = new double[expected_data.length];\n'];
      retstr = [retstr,'_izy.',filetag,uname,'(new int[] {n_in}, in_data0, zero, in_data1, zero, y0, zero);\n'];
      retstr = [retstr, 'assertTrue(FPEquals.fuzzyEqualsDynamicTol(y0, expected_data));\n'];
    end
  else
          error('Too many args')
  end
  retstr = [retstr,'\n};\n\n'];
  fclose(fp);
end % function

% functions for which there is no impl
function ret = invcbrt(arg0)
        ret = 1./cbrt(arg0);
end

function ret = invsqrt(arg0)
        ret = 1./sqrt(arg0);
end

function ret = sqr(arg0)
        ret = arg0.^2;
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

function ret = mulbyconj(arg0,arg1)
  ret = arg0.*conj(arg1);
end

function ret = negatereal(arg0)
  ret = uminus(real(arg0))+i.*(imag(arg0));
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

% bad, compensates for no stats package
function ret = normcdf(arg0)
    ret = erfc(arg0/(-sqrt(2)))/2;
end

function ret = cbrt(arg0)
    if(arg0>0)   
        ret = power(arg0,1/3);
    else
        ret = -power(-arg0,1/3);
    end
end

function ret = arg(arg0)
    ret = atan2 (imag(arg0), real(arg0));
end

function [] = writeData(fp,out,name,val,lang);
    if(~any(~isreal(out)))
      fmt = '%24.15e';
      if(strcmp(lower(lang),'c'))
        declstr=['static double ',name,val,'[] = {'];
      elseif(strcmp(lower(lang),'java'))
        declstr=['double ',name,val,'[] = {'];
      else
        error('unknown language',lang);
      end
    else      % complex numbers
      if(strcmp(lower(lang),'c'))
        declstr=['static complex double ',name,val,'[] = {'];
        fmt = '%24.15e+I*%24.15e';
      elseif(strcmp(lower(lang),'java'))
        declstr=['double ',name,val,'[] = {'];
        fmt = '%24.15e, %24.15e';
      else
        error('unknown language',lang)
      end
    end

    fprintf(fp,'%s\n',declstr);
    if(~any(~isreal(out)))
      for k=1:numel(out)-1
        fprintf(fp,fmt,out(k));
        fprintf(fp,',');
        if(~mod(k,10))
          fprintf(fp,'\n');
        end
      end
      fprintf(fp,fmt,out(end));
    else
      for k=1:numel(out)-1
        fprintf(fp,fmt,[real(out(k)),imag(out(k))]);
        fprintf(fp,',');
        if(~mod(k,10))
          fprintf(fp,'\n');
        end
      end
        fprintf(fp,fmt,[real(out(end)),imag(out(end))]);
    end

    fprintf(fp,'\n};\n');
end

