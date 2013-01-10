clear all; close all; clc;


function ret = gendata(fnname, uname, arg0, arg1)
disp(["Calling function: ",fnname," for IZY ",uname]);
if(nargin==3)
        out1=[];
        try
        [out0,out1]=feval(fnname,arg0);
        end
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
        try
        [out0,out1]=feval(fnname,arg0,arg1);
        end
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

function [a,b]=sincos(data)
        a=sin(data);
        b=cos(data);
end

function write_ascii(var)

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


%% main code

rand('state',0);

trig_range=linspace(-1.99*pi,1.99*pi,10);
invtrig_range=linspace(-0.99,0.99,10);
perm_invtrig_range=invtrig_range(randperm(length(invtrig_range)));

hyp_range=linspace(-10,10,10);
invhyp_range=linspace(-0.99,0.99,10);

std_range_small = 0.01+(-10:0.5:10); %% shift for things like div so theres no 0/0
std_range_large = 7*std_range_small;
std_const = 10;

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