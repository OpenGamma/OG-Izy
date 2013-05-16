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

  lgamma_range = [0.5:0.5:10];
  tgamma_range = [-9.5:2:-0.5,0.5:0.5:4];

  log_range_small = 0.5+(0:0.5:10); %% shift to avoid 0
  exp_range_small = -5:5;

  pow_range_small = [-8:1:-1,0.5:0.5:4]; 
  std_pow_const = 3;

  bounded_one_one = linspace(-1,1,20);

  [x,y]=meshgrid([-10:10],[-10:10]);
  complex_data=x+i*y;
  complex_std_const = 10+5i;
  complex_std_const_small = 1+2i;

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
  gendata('plus','addx',lang,std_range_small,std_const*ones(size(std_range_small)));
  gendata('rdivide','div',lang,std_range_small,std_range_large);
  gendata('rdivide','divx',lang,std_range_small,std_const*ones(size(std_range_small)));
  gendata('rdivide','xdiv',lang,std_const*ones(size(std_range_small)),std_range_small);
  %  gendata(''); % RESERVED for linearfrac, not sure whether it's worth impl
  gendata('times','mul',lang,std_range_small,std_range_large);
  gendata('times','mulx',lang,std_range_small,std_const*ones(size(std_range_small)));
  gendata('sqr','sqr',lang,std_range_small);
  gendata('minus','sub',lang,std_range_small,std_range_large);
  gendata('minus','subx',lang,std_range_small,std_const*ones(size(std_range_small)));
  gendata('minus','xsub',lang,std_const*ones(size(std_range_small)),std_range_small);
  gendata('uminus','negate',lang,std_range_small);

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
  gendata('gammaln','lgamma',lang,lgamma_range);
  gendata('gamma','tgamma',lang,tgamma_range);


  %  %PWR
  gendata('cbrt','cbrt',lang,std_range_small);
  gendata('hypot','hypot',lang,std_range_small, std_range_large);
  gendata('invsingle','inv',lang,std_range_small); % we use our own fn as inv returns 2 args, one is the rcond no
  gendata('invcbrt','invcbrt',lang,std_range_small);
  gendata('invsqrt','invsqrt',lang,log_range_small);
  gendata('power','pow',lang, pow_range_small, pow_range_small);
  gendata('power','powx',lang, pow_range_small, std_pow_const*ones(size(pow_range_small)));
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
  gendata('atan','atan',lang,complex_data+sqrt(2));
  gendata('cos','cos',lang,complex_data);
  gendata('sin','sin',lang,complex_data);
  gendata('tan','tan',lang,complex_data);

  %hype
  gendata('acosh','acosh',lang,complex_data);
  gendata('asinh','asinh',lang,complex_data);
  gendata('atanh','atanh',lang,complex_data+sqrt(2));
  gendata('cosh','cosh',lang,complex_data);
  gendata('sinh','sinh',lang,complex_data);
  gendata('tanh','tanh',lang,complex_data);

  % pwr
  gendata('power','pow',lang,complex_data,complex_data);
  gendata('power','powx',lang,complex_data, complex_std_const_small*ones(size(complex_data)));
  gendata('sqrt','sqrt',lang,complex_data);
  gendata('exp','exp',lang,complex_data);
  gendata('log','ln',lang,complex_data+sqrt(2));
  gendata('log10','log10',lang,complex_data+sqrt(2));

  gendata('abs','abs',lang,complex_data);
  gendata('plus','add',lang,complex_data,complex_data);
  gendata('plus','addx',lang,complex_data,complex_std_const*ones(size(complex_data)));
  gendata('rdivide','div',lang,complex_data,complex_data+sqrt(2));
  gendata('rdivide','divx',lang,complex_data,complex_std_const*ones(size(complex_data)));
  gendata('rdivide','xdiv',lang,complex_std_const*ones(size(complex_data(complex_data~=0))),complex_data(complex_data~=0));

  gendata('arg','arg',lang,complex_data);
  gendata('conj','conj',lang,complex_data);
    
  gendata('times','mul',lang,complex_data,complex_data);
  gendata('times','mulx',lang,complex_data,complex_std_const*ones(size(complex_data)));
  gendata('mulbyconj','mulbyconj',lang,complex_data,conj(complex_data)); %conj the second data so that we do a.*conj(conj(b)) = a.*b;
  gendata('minus','sub',lang,complex_data,5*complex_data);
  gendata('minus','subx',lang,complex_data,complex_std_const*ones(size(complex_data)));
  gendata('minus','xsub',lang,complex_std_const*ones(size(complex_data)),complex_data);

  gendata('uminus','negate',lang,complex_data);

  gendata('negatereal','negatereal',lang,complex_data);
end