clear all; close all; clc;
  trig_range=linspace(-6.25,6.25,11);
  invtrig_range=-0.9:0.1:0.9;
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

  lang="java";

  %% REAL Functions
  % trig 
  str="";
  str=[str,gendata('acos','acos',lang,invtrig_range)];
  str=[str,gendata('asin','asin',lang,invtrig_range)];
  str=[str,gendata('atan','atan',lang,invtrig_range)];
  str=[str,gendata('atan2','atan2',lang,invtrig_range, perm_invtrig_range)];
  str=[str,gendata('cos','cos',lang,trig_range)];
  str=[str,gendata('sin','sin',lang,trig_range)];
  str=[str,gendata('sincos','sincos',lang,trig_range)];
  str=[str,gendata('tan','tan',lang,trig_range)];

  %  arith
  str=[str,gendata('abs','abs',lang,std_range_small)];
  str=[str,gendata('plus','add',lang,std_range_small,std_range_large)];
  str=[str,gendata('plus','addx',lang,std_range_small,std_const)];
  str=[str,gendata('rdivide','div',lang,std_range_small,std_range_large)];
  str=[str,gendata('rdivide','divx',lang,std_range_small,std_const)];
  %  str=[str,gendata('')]; % RESERVED for linearfrac, not sure whether it's worth impl
  str=[str,gendata('times','mul',lang,std_range_small,std_range_large)];
  str=[str,gendata('times','mulx',lang,std_range_small,std_const)];
  str=[str,gendata('sqr','sqr',lang,std_range_small)];
  str=[str,gendata('minus','sub',lang,std_range_small,std_range_large)];
  str=[str,gendata('minus','subx',lang,std_range_small,std_const)];

  %exp+log
  str=[str,gendata('exp','exp',lang,exp_range_small)];

  str=[str,gendata('expm1','expm1',lang,exp_range_small)];
  str=[str,gendata('log','ln',lang,log_range_small)];
  str=[str,gendata('log10','log10',lang,log_range_small)];
  str=[str,gendata('log1p','log1p',lang,log_range_small)];

  %hyp
  str=[str,gendata('acosh','acosh',lang,acosh_range)];
  str=[str,gendata('asinh','asinh',lang,asinh_range)];
  str=[str,gendata('atanh','atanh',lang,atanh_range)];
  str=[str,gendata('cosh','cosh',lang,hyp_range)];
  str=[str,gendata('sinh','sinh',lang,hyp_range)];
  str=[str,gendata('tanh','tanh',lang,hyp_range)];

  %specfun
  str=[str,gendata('normcdf','cdfnorm',lang,bounded_one_one)];
  %  str=[str,gendata('')]; % RESERVED for cdfnorminv, not sure whether it's worth impl ATM
  str=[str,gendata('erf','erf',lang,bounded_one_one)];
  str=[str,gendata('erfc','erfc',lang,bounded_one_one)];
  %  str=[str,gendata('')]; % RESERVED for erfinv, not sure whether it's worth impl ATM
  %  str=[str,gendata('')]; % RESERVED for erfcinv, not sure whether it's worth impl ATM
  str=[str,gendata('lgamma','lgamma',lang,lgamma_range)];
  str=[str,gendata('gamma','tgamma',lang,tgamma_range)];


  %  %PWR
  str=[str,gendata('cbrt','cbrt',lang,std_range_small)];
  str=[str,gendata('hypot','hypot',lang,std_range_small, std_range_large)];
  str=[str,gendata('invsingle','inv',lang,std_range_small)]; % we use our own fn as inv returns 2 args, one is the rcond no
  str=[str,gendata('invcbrt','invcbrt',lang,std_range_small)];
  str=[str,gendata('invsqrt','invsqrt',lang,log_range_small)];
  str=[str,gendata('power','pow',lang, pow_range_small, pow_range_small)];
  str=[str,gendata('power','powx',lang, pow_range_small, std_pow_const)];
  str=[str,gendata('pow2o3','pow2o3',lang, log_range_small)];
  str=[str,gendata('pow3o2','pow3o2',lang, log_range_small)];
  str=[str,gendata('sqrt','sqrt',lang,log_range_small)];

  % ROUNDING
  str=[str,gendata('ceil','ceil',lang,trig_range)];
  str=[str,gendata('floor','floor',lang,trig_range)];
  str=[str,gendata('modf','modf',lang,trig_range)];
  str=[str,gendata('nearbyint','nearbyint',lang,trig_range)];
  str=[str,gendata('nearbyint','rint',lang,trig_range)];
  str=[str,gendata('round','round',lang,trig_range)];
  str=[str,gendata('fix','trunc',lang,trig_range)];


  %% COMPLEX Functions
  % trig
  str=[str,gendata('acos','acos',lang,complex_data)];
  str=[str,gendata('asin','asin',lang,complex_data)];
  str=[str,gendata('atan','atan',lang,complex_data)+sqrt(2)];
  str=[str,gendata('cos','cos',lang,complex_data)];
  str=[str,gendata('sin','sin',lang,complex_data)];
  str=[str,gendata('tan','tan',lang,complex_data)];

  %hype
  str=[str,gendata('acosh','acosh',lang,complex_data)];
  str=[str,gendata('asinh','asinh',lang,complex_data)];
  str=[str,gendata('atanh','atanh',lang,complex_data+sqrt(2))];
  str=[str,gendata('cosh','cosh',lang,complex_data)];
  str=[str,gendata('sinh','sinh',lang,complex_data)];
  str=[str,gendata('tanh','tanh',lang,complex_data)];

  % pwr
  str=[str,gendata('power','pow',lang,complex_data,complex_data)];
  str=[str,gendata('power','powx',lang,complex_data, complex_std_const)];
  str=[str,gendata('sqrt','sqrt',lang,complex_data)];
  str=[str,gendata('exp','exp',lang,complex_data)];
  str=[str,gendata('log','ln',lang,complex_data+sqrt(2))];
  str=[str,gendata('log10','log10',lang,complex_data+sqrt(2))];

  str=[str,gendata('abs','abs',lang,complex_data)];
  str=[str,gendata('plus','add',lang,complex_data,complex_data)];
  str=[str,gendata('plus','addx',lang,complex_data,complex_std_const)];
  str=[str,gendata('rdivide','div',lang,complex_data,complex_data+sqrt(2))];
  str=[str,gendata('rdivide','divx',lang,complex_data,complex_std_const)];

  str=[str,gendata('arg','arg',lang,complex_data)];
  str=[str,gendata('conj','conj',lang,complex_data)];
    
  str=[str,gendata('times','mul',lang,complex_data,complex_data)];
  str=[str,gendata('times','mulx',lang,complex_data,complex_std_const)];
  str=[str,gendata('mulbyconj','mulbyconj',lang,complex_data,conj(complex_data))]; %conj the second data so that we do a.*conj(conj(b)) = a.*b;
  str=[str,gendata('minus','sub',lang,complex_data,5*complex_data)];
  str=[str,gendata('minus','subx',lang,complex_data,complex_std_const)];

header="\n...
/**\n...
 * Copyright (C) 2013 - present by OpenGamma Inc. and the OpenGamma group of companies\n...
 * \n...
 * Please see distribution for license.\n...
 */\n...
/* AUTOGENERATED: DO NOT EDIT */\n...
package com.opengamma.maths.lowlevelapi.exposedapi.IZYTests;\n...
\n...
import static org.testng.Assert.assertTrue;\n...
\n...
import org.testng.annotations.Test;\n...
\n...
import com.opengamma.maths.lowlevelapi.exposedapi.IZY;\n...
import com.opengamma.maths.lowlevelapi.functions.FPEquals;\n...
\n...
/**\n...
 * Test harness for izy implementations\n...
 */\n...
@Test\n...
public class IzyBasicTest {\n...
  IzyBasicTest() {\n...
  };\n...
\n...
  private IZY _izy = new IZY(IZY.backing.OGnative);\n...
\n...
  /**\n...
   * Say which izy is going to be tested\n...
   */\n...
  public IzyBasicTest(IZY.backing back) {\n...
    _izy = new IZY(back);\n...
  }\n...
\n...
  int[] zero = new int[] {0 };\n...
 ";


  total=[header,str,"}"];
  fp=fopen("java_unit_test.javap","w+");
  fprintf(fp,'%s',total);
  fclose(fp);
