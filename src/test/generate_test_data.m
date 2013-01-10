clear all; close all; clc;


function ret = gendata(fnname, arg0, arg1)
disp(["Calling function: ",fnname]);
if(nargin==2)
        out1=[];
        try
        [out0,out1]=feval(fnname,arg0);
        end
        if(~isempty(out1))
                tmp=zeros(1,2*length(out0));
                tmp(1:2:end)=out0;
                tmp(2:2:end)=out1;
                dlmwrite(["expected_",fnname,".txt"], tmp, "delimiter", "\\n", "newline", "\\n","precision","%24.15f")
                outvals=2;
        else
                dlmwrite(["expected_",fnname,".txt"], out0, "delimiter", "\\n", "newline", "\\n","precision","%24.15f")
                outvals=1;
        end
        dlmwrite(["count_",fnname,".txt"], [1;outvals]*length(arg0), "delimiter", "\\n", "newline", "\\n")
        dlmwrite(["input_",fnname,".txt"], arg0, "delimiter", "\\n", "newline", "\\n","precision","%24.15f")
elseif(nargin==3)        
        out1=[];
        try
        [out0,out1]=feval(fnname,arg0,arg1);
        end
        if(~isempty(out1))
                tmp=zeros(1,2*length(out0));
                tmp(1:2:end)=out0;
                tmp(2:2:end)=out1;
                dlmwrite(["expected_",fnname,".txt"], tmp, "delimiter", "\\n", "newline", "\\n","precision","%24.15f")
                outvals=2;
        else
                dlmwrite(["expected_",fnname,".txt"], out0, "delimiter", "\\n", "newline", "\\n","precision","%24.15f")
                outvals=1;
        end
        dlmwrite(["count_",fnname,".txt"], [2;outvals]*length(arg0), "delimiter", "\\n", "newline", "\\n")
        tmp=zeros(1,2*length(arg0));
        tmp(1:2:end)=arg0;
        tmp(2:2:end)=arg1;
        dlmwrite(["input_",fnname,".txt"], tmp, "delimiter", "\\n", "newline", "\\n","precision","%24.15f")
        
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
'div',
'linearfrac',
'mul',
'sqr',
'sub'
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

% trig
gendata('acos',invtrig_range);
gendata('asin',invtrig_range);
gendata('atan',invtrig_range);
gendata('atan2',invtrig_range, perm_invtrig_range);
gendata('cos',trig_range);
gendata('sin',trig_range);
gendata('sincos',trig_range);
gendata('tan',trig_range);