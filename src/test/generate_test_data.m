clear all; close all; clc;


function ret = gendata(fnname, uname, arg0, arg1)
disp(["Calling function: ",fnname," for IZY ",uname]);
if(nargin==3)
        out1=[];
        try
                [out0,out1]=arrayfun(fnname,arg0);
        catch 
                [out0]=arrayfun(fnname,arg0);
        end
        out0=real(out0);
        out1=real(out1);
        if(~isempty(out1))
                tmp=zeros(1,2*length(out0));
                tmp(1:2:end)=out0;
                tmp(2:2:end)=out1;
                dlmwrite(["expected_",uname,".txt"], tmp, "delimiter", "\\n", "newline", "\\n","precision","%24.15f")
                outvals=2;
        else
                dlmwrite(["expected_",uname,".txt"], out0, "delimiter", "\\n", "newline", "\\n","precision","%24.15f")
                outvals=1;
        end
        dlmwrite(["count_",uname,".txt"], [1;outvals]*length(arg0), "delimiter", "\\n", "newline", "\\n")
        dlmwrite(["input_",uname,".txt"], arg0, "delimiter", "\\n", "newline", "\\n","precision","%24.15f")
elseif(nargin==4)        
        out1=[];
        out0=[];
        try
                [out0,out1]=arrayfun(fnname,arg0,arg1);
        catch
                [out0]=arrayfun(fnname,arg0,arg1);
        end
        out0=real(out0);
        out1=real(out1);
        if(~isempty(out1))
                tmp=zeros(1,2*length(out0));
                tmp(1:2:end)=out0;
                tmp(2:2:end)=out1;
                dlmwrite(["expected_",uname,".txt"], tmp, "delimiter", "\\n", "newline", "\\n","precision","%24.15f")
                outvals=2;
        else
                dlmwrite(["expected_",uname,".txt"], out0, "delimiter", "\\n", "newline", "\\n","precision","%24.15f")
                outvals=1;
        end
        dlmwrite(["count_",uname,".txt"], [2;outvals]*length(arg0), "delimiter", "\\n", "newline", "\\n")
        tmp=zeros(1,2*length(arg0));
        tmp(1:2:end)=arg0;
        tmp(2:2:end)=arg1;
        dlmwrite(["input_",uname,".txt"], tmp, "delimiter", "\\n", "newline", "\\n","precision","%24.15f")
        
else
        error("Too many args")
end

end

fnlist_trig={
'acos',
'asin',
'atan',
'atan2',
'cos',
'sin',
'sincos',
'tan'
};

fnlist_hyp={
'acosh',
'asinh',
'atanh',
'cosh',
'sinh',
'tanh'
};

fnlist_pwr={
'cbrt',
'hypot',
'inv',
'invcbrt',
'invsqrt',
'pow',
'powx',
'pow2o3',
'pow3o2',
'sqrt'
};

fnlist_el={
'exp',
'expm1',
'ln',
'log10',
'log1p'
};


fnlist_arith={
'abs',
'add',
'addx',
'div',
'divx',
'linearfrac',
'mul',
'mulx',
'sqr',
'sub',
'subx'
};

fnlist_round={
'ceil',
'floor',
'modf',
'nearbyint',
'rint',
'round',
'trunc'
};

fnlist_specfun={
'cdfnorm',
'cdfnorminv',
'erf',
'erfc',
'erfinv',
'erfcinv',
'lgamma',
'tgamma'
};

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

%% main code

rand('state',0);

trig_range=linspace(-1.99*pi,1.99*pi,10);
invtrig_range=linspace(-0.99,0.99,10);
perm_invtrig_range=invtrig_range(randperm(length(invtrig_range)));

hyp_range=linspace(-10,10,10);
acosh_range=linspace(1.01,10,10);
asinh_range=linspace(-10,10,10);
atanh_range=linspace(-0.99,0.99,10);

std_range_small = 0.01+(-10:0.5:10); %% shift for things like div so theres no 0/0
std_range_large = 7*std_range_small;
std_const = 10;

log_range_small = 0.01+(0:0.5:10); %% shift to avoid 0

bounded_one_one = linspace(-1,1,20);

% trig
gendata('acos','acos',invtrig_range);
gendata('asin','asin',invtrig_range);
gendata('atan','atan',invtrig_range);
gendata('atan2','atan2',invtrig_range, perm_invtrig_range);
gendata('cos','cos',trig_range);
gendata('sin','sin',trig_range);
gendata('sincos','sincos',trig_range);
gendata('tan','tan',trig_range);

%  arith
gendata('abs','abs',std_range_small);
gendata('plus','add',std_range_small,std_range_large);
gendata('plus','addx',std_range_small,std_const);
gendata('rdivide','div',std_range_small,std_range_large);
gendata('rdivide','divx',std_range_small,std_const);
%  gendata(''); % RESERVED for linearfrac, not sure whether it's worth impl
gendata('times','mul',std_range_small,std_range_large);
gendata('times','mulx',std_range_small,std_const);
gendata('power','sqr',std_range_small,2);
gendata('minus','sub',std_range_small,std_range_large);
gendata('minus','subx',std_range_small,std_const);

%exp+log
gendata('exp','exp',log_range_small);
gendata('expm1','expm1',log_range_small);
gendata('log','ln',log_range_small);
gendata('log10','log10',log_range_small);
gendata('log1p','log1p',log_range_small);

%hyp
gendata('acosh','acosh',acosh_range);
gendata('asinh','asinh',asinh_range);
gendata('atanh','atanh',atanh_range);
gendata('cosh','cosh',hyp_range);
gendata('sinh','sinh',hyp_range);
gendata('tanh','tanh',hyp_range);

%specfun
gendata('normcdf','cdfnorm',bounded_one_one);
%  gendata(''); % RESERVED for cdfnorminv, not sure whether it's worth impl ATM
gendata('erf','erf',bounded_one_one);
gendata('erfc','erfc',bounded_one_one);
%  gendata(''); % RESERVED for erfinv, not sure whether it's worth impl ATM
%  gendata(''); % RESERVED for erfcinv, not sure whether it's worth impl ATM
gendata('lgamma','lgamma',std_range_small);
gendata('gamma','tgamma',std_range_small);


%  %PWR
gendata('cbrt','cbrt',std_range_small);
gendata('hypot','hypot',std_range_small, std_range_large);
gendata('invsingle','inv',std_range_small); % we use our own fn as inv returns 2 args, one is the rcond no
gendata('invcbrt','invcbrt',std_range_small);
gendata('invsqrt','invsqrt',std_range_small);
gendata('power','pow', std_range_small, std_range_small);
gendata('power','powx', std_range_small, std_const);
gendata('pow2o3','pow2o3', log_range_small);
gendata('pow3o2','pow3o2', log_range_small);
gendata('sqrt','sqrt',log_range_small);

