#!/bin/bash
#
# Copyright (C) 2014 - present by OpenGamma Inc. and the OpenGamma group of companies.
#
# Please see distribution for license.
#
#not pretty, generates man pages

## Generate the easy binary function man pages
double_bs_fn=(abs acos acosh asin asinh atan atanh cbrt ceil cos cosh erf erfc exp expm1 floor inv invcbrt invsqrt lgamma ln log10 log1p nearbyint negate pow2o3 pow3o2 rint round sin sinh sqr sqrt tan tanh tgamma trunc);
double_bs_fn_operations=("abs(arg0)" "acos(arg0)" "acosh(arg0)" "asin(arg0)" "asinh(arg0)" "atan(arg0)" "atanh(arg0)" "cbrt(arg0)" "ceil(arg0)" "cos(arg0)" "cosh(arg0)" "erf(arg0)" "erfc(arg0)" "exp(arg0)" "expm1(arg0)" "floor(arg0)" "1\/arg0" "1\/cbrt(arg0)" "1\/sqrt(arg0)" "lgamma(arg0)" "log(arg0)" "log10(arg0)" "log1p(arg0)" "nearbyint(arg0)" "\-(arg0)" "power(arg0,2\/3)" "power(arg0,3\/2)" "rint(arg0)" "round(arg0)" "sin(arg0)" "sinh(arg0)" "power(arg0,2)" "sqrt(arg0)" "tan(arg0)" "tanh(arg0)" "tgamma(arg0)" "trunc(arg0)")
double_bs_fn_link=(
"abs(3), vd_ceil(3), vd_floor(3)"
"acos(3), vd_asin(3), vd_atan(3), vz_acos(3)"
"acosh(3), vd_sinh(3), vd_tanh(3), vz_acosh(3)"
"asin(3), vd_cos(3), vd_tan(3), vz_asin(3)"
"asinh(3), vd_acosh(3), vd_atanh(3), vz_asinh(3)"
"atan(3), vd_acos(3), vd_asin(3), vz_atan(3)"
"atanh(3), vd_acosh(3), vd_asinh(3), vzatanh(3)"
"cbrt(3), vd_sqrt(3), vd_pow(3)"
"ceil(3), vd_floor(3), vd_trunc(3)"
"cos(3), vd_sin(3), vd_tan(3), vz_cos(3)"
"cosh(3), vd_sinh(3), vd_tanh(3), vz_cosh(3)"
"erf(3), vd_erfc(3)"
"erfc(3), vd_erf(3)"
"exp(3), vd_expm1(3), vz_exp(3)"
"expm1(3), vd_exp(3), vz_exp(3) "
"floor(3), vd_ceil(3), vd_abs(3)"
"vd_div(3), vd_xdiv(3), vd_divx(3)"
"cbrt(3), vd_invsqrt(3), vd_inv(3)"
"sqrt(3), vd_invcbrt(3), vd_inv(3)"
"lgamma(3), vd_tgamma(3)"
"log(3), vd_log10(3), vd_log1p(3), vz_ln(3)"
"log10(3), vd_log(3), vd_log1p(3), vz_log10(3)"
"log1p(3), vd_log(3), vd_log10(3)"
"nearbyint(3), vd_floor(3), vd_round(3)"
"vz_negate(3), vz_negatereal(3)"
"power(3), vd_pow(3), vd_powx(3), vz_pow(3)"
"power(3), vd_pow(3), vd_powx(3), vz_pow(3)"
"rint(3), vd_nearbyint(3), vd_floor(3), vd_round(3)"
"round(3), vd_nearbyint(3), vd_floor(3), vd_rint(3)"
"sin(3), vd_cos(3), vd_tan(3), vz_sin(3)"
"sinh(3), vd_cosh(3), vd_tanh(3), vz_sinh(3)"
"power(3), vd_pow(3), vd_powx(3), vz_pow(3)"
"sqrt(3), vd_cbrt(3), vd_hypot(3), vz_sqrt(3)"
"tan(3), vd_cos(3), vd_sin(3), vz_tan(3)"
"tanh(3), vd_cosh(3), vd_sinh(3), vz_tanh(3)"
"tgamma(3), vd_lgamma(3)"
"trunc(3), vd_rint(3), vd_nearbyint(3), vd_floor(3), vd_ceil(3), vd_round(3)"
)

for (( i=0; i<${#double_bs_fn[@]}; i++));
do
echo $i ${double_bs_fn[${i}]}
tmp=`echo ${double_bs_fn_operations[${i}]}|sed -e 's/arg0/in_data[i]/g'`
today=`date +"%d %b %Y"`
cat 1in1outTemplate|sed -e "s/FNAME/${double_bs_fn[${i}]}/g" -e "s/OPERATION/${double_bs_fn_operations[${i}]}/" -e "s/SEE_ALSO/${double_bs_fn_link[${i}]}/g" -e "s/CEVAL/${tmp}/g" -e "s/DATE/${today}/g"> "vd_${double_bs_fn[${i}]}.3";
done

## generate the A _OP_ B man pages
double_op_fn=(add div mul sub)
double_op_fn_operations=("arg0 + arg1" "arg0 \/ arg1" "arg0 \* arg1" "arg0 - arg1")
double_op_fn_link=(
"vd_div(3), vd_mul(3), vd_sub(3), vz_add(3)"
"vd_add(3), vd_mul(3), vd_sub(3), vz_div(3)"
"vd_mul(3), vd_add(3), vd_div(3), vz_mul(3)"
"vd_add(3), vd_div(3), vd_mul(3), vz_sub(3)"
)

for (( i=0; i<${#double_op_fn[@]}; i++));
do
echo $i ${double_op_fn[${i}]}
tmp=`echo ${double_op_fn_operations[${i}]}|sed -e 's/arg0/in_data0[i]/g' -e 's/arg1/in_data1[i]/g' `
cat AopBinCoutTemplate|sed -e "s/FNAME/${double_op_fn[${i}]}/g" -e "s/OPERATION/${double_op_fn_operations[${i}]}/" -e "s/SEE_ALSO/${double_op_fn_link[${i}]}/g" -e "s/CEVAL/${tmp}/g" -e "s/DATE/${today}/g"> "vd_${double_op_fn[${i}]}.3";
done


## generate the A _OP_ const B man pages
double_op_const_fn=(addx divx mulx subx)
double_op_const_fn_operations=("arg0 + arg1" "arg0 \/ arg1" "arg0 \* arg1" "arg0 - arg1")
double_op_const_fn_operations_literal=("arg0 + (constant) arg1" "arg0 \/ (constant) arg1" "arg0 \* (constant) arg1" "arg0 - (constant) arg1")
double_op_const_fn_link=(
"vd_divx(3), vd_mulx(3), vd_subx(3), vz_addx(3)"
"vd_addx(3), vd_mulx(3), vd_subx(3), vz_divx(3)"
"vd_mulx(3), vd_addx(3), vd_divx(3), vz_mulx(3)"
"vd_addx(3), vd_divx(3), vd_mulx(3), vz_subx(3)"
)

for (( i=0; i<${#double_op_const_fn[@]}; i++));
do
echo $i ${double_op_const_fn[${i}]}
tmp=`echo ${double_op_const_fn_operations[${i}]}|sed -e 's/arg0/in_data0[i]/g' -e 's/arg1/in_data1[0]/g' `
cat AopConstBinCoutTemplate|sed -e "s/FNAME/${double_op_const_fn[${i}]}/g" -e "s/OPERATION/${double_op_const_fn_operations_literal[${i}]}/" -e "s/SEE_ALSO/${double_op_const_fn_link[${i}]}/g" -e "s/CEVAL/${tmp}/g" -e "s/DATE/${today}/g"> "vd_${double_op_const_fn[${i}]}.3";
done


## generate the const A _OP_ B man pages
double_const_op_fn=(xsub xdiv)

double_const_op_fn_operations=("arg0 - arg1" "arg0 \/ arg1")
double_const_op_fn_operations_literal=("(constant) arg0 - arg1" "(constant) arg0 \/  arg1")
double_const_op_fn_link=(
"vd_subx(3), vd_sub(3), vd_xdiv(3), vz_xsub(3)"
"vd_divx(3), vd_div(3), vd_xsub(3), vz_xdiv(3)"
)

for (( i=0; i<${#double_const_op_fn[@]}; i++));
do
echo $i ${double_const_op_fn[${i}]}
tmp=`echo ${double_op_const_fn_operations[${i}]}|sed -e 's/arg0/in_data0[0]/g' -e 's/arg1/in_data1[i]/g' `
cat ConstAopBinCoutTemplate|sed -e "s/FNAME/${double_const_op_fn[${i}]}/g" -e "s/OPERATION/${double_const_op_fn_operations_literal[${i}]}/" -e "s/SEE_ALSO/${double_const_op_fn_link[${i}]}/g" -e "s/CEVAL/${tmp}/g" -e "s/DATE/${today}/g"> "vd_${double_const_op_fn[${i}]}.3";
done

## generate the 2 arg function man pages
double_2_op_fn=(atan2 hypot pow)
double_2_op_fn_operations=("atan2(arg0, arg1)" "hypot(arg0, arg1)" "pow(arg0, arg1)")
double_2_op_fn_link=(
"atan2(3), vd_hypot(3), vz_atan2(3)"
"hypot(3), vd_atan2(3)"
"pow(3), vd_powx(3), vz_pow(3)"
)
for (( i=0; i<${#double_2_op_fn[@]}; i++));
do
echo $i ${double_2_op_fn[${i}]}
tmp=`echo ${double_2_op_fn_operations[${i}]}|sed -e 's/arg0/in_data0[i]/g' -e 's/arg1/in_data1[i]/g' `
today=`date +"%d %b %Y"`
cat twoArgTemplate|sed -e "s/FNAME/${double_2_op_fn[${i}]}/g" -e "s/OPERATION/${double_2_op_fn_operations[${i}]}/" -e "s/SEE_ALSO/${double_2_op_fn_link[${i}]}/g" -e "s/CEVAL/${tmp}/g" -e "s/DATE/${today}/g"> "vd_${double_2_op_fn[${i}]}.3";
done

## generate the 2 arg function, 1 is const man pages
double_2_op_const_fn=(powx)
double_2_op_const_fn_operations=("pow(arg0, arg1)")
double_2_op_const_fn_operations_literal=("pow(arg0, (constant) arg1)")
double_2_op_const_fn_link=(
"pow(3), vd_pow(3), vd_pow3o2(3), vd_pow2o3(3), vz_pow(3)"
)

for (( i=0; i<${#double_2_op_const_fn[@]}; i++));
do
echo $i ${double_2_op_const_fn[${i}]}
tmp=`echo ${double_2_op_const_fn_operations[${i}]}|sed -e 's/arg0/in_data0[i]/g' -e 's/arg1/in_data1[0]/g' `
cat twoArgOneIsConstTemplate|sed -e "s/FNAME/${double_2_op_const_fn[${i}]}/g" -e "s/OPERATION/${double_2_op_const_fn_operations_literal[${i}]}/" -e "s/SEE_ALSO/${double_2_op_const_fn_link[${i}]}/g" -e "s/CEVAL/${tmp}/g" -e "s/DATE/${today}/g"> "vd_${double_2_op_const_fn[${i}]}.3";
done

## generate the 1 arg 2 outputs man pages
# annoyingly sincos() is void, modf() returns double
double_1_arg_2_out_fn=(modf)
double_1_arg_2_out_fn_link=(
"modf(3), vd_trunc(3)"
)

for (( i=0; i<${#double_1_arg_2_out_fn[@]}; i++));
do
echo $i ${double_1_arg_2_out_fn[${i}]}
cat oneArgTwoOutDoubleFunctionTemplate|sed -e "s/FNAME/${double_1_arg_2_out_fn[${i}]}/g" -e  "s/SEE_ALSO/${double_1_arg_2_out_fn_link[${i}]}/g" -e "s/DATE/${today}/g"> "vd_${double_1_arg_2_out_fn[${i}]}.3";
done

double_1_arg_2_out_fn=(sincos)
double_1_arg_2_out_fn_link=(
"sincos(3), vd_sin(3), vd_cos(3), vz_sin(3), vz_cos(3)"
)

#sincos is a mess because it's and #define _GNU_SOURCE but not C99, so we use a rather customised sincos template
for (( i=0; i<${#double_1_arg_2_out_fn[@]}; i++));
do
echo $i ${double_1_arg_2_out_fn[${i}]}
cat vd_sincosFunctionTemplate|sed -e "s/SEE_ALSO/${double_1_arg_2_out_fn_link[${i}]}/g" -e "s/DATE/${today}/g"> "vd_${double_1_arg_2_out_fn[${i}]}.3";
done

## generate the special function man pages
double_bs_fn=(cdfnorm cdfnorminv  erfcinv erfinv)
double_bs_fn_operations=("cdfnorm(arg0)" "cdfnorminv(arg0)" "erfcinv(arg0)" "erfinv(arg0)")
double_bs_fn_descr=(
"the value of the cumulative distribution function of the normal function at arg0, computed with a mean of 0 and a standard deviation of 1."
"the value of the inverse cumulative distribution function of the normal function at arg0, computed with a mean of 0 and a standard deviation of 1."
"the value of the inverse complimentary error function at position arg0."
"the value of the inverse error function at position arg0."
)
double_bs_fn_link=(
"erf(3), erfc(3), vd_erf(3), vd_cdfnorminv(3)"
"erf(3), erfc(3), vd_erf(3), vd_cdfnorm(3)"
"erfc(3), erf(3), vd_erf(3), vd_erfinv(3)"
"erf(3), erfc(3), vd_erfc(3), vd_erfcinv(3)"
)

for (( i=0; i<${#double_bs_fn[@]}; i++));
do
echo $i ${double_bs_fn[${i}]}
tmp=`echo ${double_bs_fn_operations[${i}]}|sed -e 's/arg0/in_data[i]/g'`
today=`date +"%d %b %Y"`
cat specialFunctionsTemplate|sed -e "s/FNAME/${double_bs_fn[${i}]}/g" -e "s/OPERATION/${double_bs_fn_operations[${i}]}/" -e "s/SEE_ALSO/${double_bs_fn_link[${i}]}/g" -e "s/CEVAL/${tmp}/g" -e "s/DATE/${today}/g" -e "s/WHATITCOMPUTES/${double_bs_fn_descr[${i}]}/"> "vd_${double_bs_fn[${i}]}.3";
done



## complex functions
cmplx_bs_fn=(acos acosh asin asinh atan atanh conj cos cosh exp ln log10 sin sinh sqrt tan tanh negate negatereal)
cmplx_bs_fn_operations=("acos(arg0)" "acosh(arg0)" "asin(arg0)" "asinh(arg0)" "atan(arg0)" "atanh(arg0)" "conj(arg0)" "cos(arg0)" "cosh(arg0)" "exp(arg0)" "log(arg0)" "log10(arg0)" "sin(arg0)" "sinh(arg0)" "sqrt(arg0)" "tan(arg0)" "tanh(arg0)" "-arg0" "-real(arg0)+I*imag(arg0)")
cmplx_bs_fn_as_code_operations=("cacos(arg0)" "cacosh(arg0)" "casin(arg0)" "casinh(arg0)" "catan(arg0)" "catanh(arg0)" "conj(arg0)" "ccos(arg0)" "ccosh(arg0)" "cexp(arg0)" "clog(arg0)" "clog(arg0)\/log(10)" "csin(arg0)" "csinh(arg0)" "csqrt(arg0)" "ctan(arg0)" "ctanh(arg0)" "-arg0" "-creal(arg0)+I*cimag(arg0)")
cmplx_bs_fn_link=(
"acos(3), vd_acos(3)"
"acosh(3), vd_acosh(3)"
"asin(3), vd_asin(3)"
"asinh(3), vd_asinh(3)"
"atan(3), vd_atan(3)"
"atanh(3), vd_atanh(3)"
"conj(3), vz_negate(3), vz_negatereal(3)"
"cos(3), vd_cos(3)"
"cosh(3), vd_cosh(3)"
"exp(3), vd_exp(3)"
"log(3), vd_log(3)"
"log10(3), vd_log10(3)"
"sin(3), vd_sin(3)"
"sinh(3), vd_sinh(3)"
"sqrt(3), vd_sqrt(3)"
"tan(3), vd_tan(3)"
"tanh(3), vd_tanh(3)"
"conj(3), vz_conj(3), vz_negatereal(3)"
"conj(3), vz_conj(3), vz_negate(3)"
)

for (( i=0; i<${#cmplx_bs_fn[@]}; i++));
do
echo "$i c${cmplx_bs_fn[${i}]}"
tmp=`echo ${cmplx_bs_fn_as_code_operations[${i}]}|sed -e 's/arg0/in_data[i]/g'`
today=`date +"%d %b %Y"`
cat complex_1in1outTemplate|sed -e "s/FNAME/${cmplx_bs_fn[${i}]}/g" -e "s/OPERATION/${cmplx_bs_fn_operations[${i}]}/" -e "s/SEE_ALSO/${cmplx_bs_fn_link[${i}]}/g" -e "s/CEVAL/${tmp}/g" -e "s/DATE/${today}/g"> "vz_${cmplx_bs_fn[${i}]}.3";
done


cmplx_A_OP_B_fn=(add div mul mulbyconj sub)
cmplx_A_OP_B_fn_operations=("arg0 + arg1" "arg0 \/ arg1" "arg0 \* arg1" "arg0 \* conj(arg1)" "arg0 - arg1")
cmplx_A_OP_B_fn_link=(
"vz_div(3), vz_mul(3), vz_sub(3), vd_add(3)"
"vz_add(3), vz_mul(3), vz_sub(3), vd_div(3)"
"vz_mul(3), vz_mulbyconj(3), vz_add(3), vz_div(3), vd_mul(3)"
"vz_mul(3), vz_add(3), vz_div(3), vd_mul(3)"
"vz_add(3), vz_div(3), vz_mul(3), vd_sub(3)"
)
for (( i=0; i<${#cmplx_A_OP_B_fn[@]}; i++));
do
echo "$i c${cmplx_A_OP_B_fn[${i}]}"
tmp=`echo ${cmplx_A_OP_B_fn_operations[${i}]}|sed -e 's/arg0/in_data0[i]/g' -e 's/arg1/in_data1[i]/g' `
cat complex_AopBinCoutTemplate|sed -e "s/FNAME/${cmplx_A_OP_B_fn[${i}]}/g" -e "s/OPERATION/${cmplx_A_OP_B_fn_operations[${i}]}/" -e "s/SEE_ALSO/${cmplx_A_OP_B_fn_link[${i}]}/g" -e "s/CEVAL/${tmp}/g" -e "s/DATE/${today}/g"> "vz_${cmplx_A_OP_B_fn[${i}]}.3";
done


cmplx_A_OP_const_B_fn=(addx divx mulx subx)
cmplx_A_OP_const_B_fn_operations=("arg0 + arg1" "arg0 \/ arg1" "arg0 \* arg1" "arg0 - arg1")
cmplx_A_OP_const_B_fn_operations_literal=("arg0 + (constant) arg1" "arg0 \/ (constant) arg1" "arg0 \* (constant) arg1" "arg0 - (constant) arg1")
cmplx_A_OP_const_B_fn_link=(
"vz_divx(3), vz_mulx(3), vz_subx(3), vd_addx(3)"
"vz_addx(3), vz_mulx(3), vz_subx(3), vd_divx(3)"
"vz_mulx(3), vz_addx(3), vz_divx(3), vd_mulx(3)"
"vz_addx(3), vz_divx(3), vz_mulx(3), vd_subx(3)"
)

for (( i=0; i<${#cmplx_A_OP_const_B_fn[@]}; i++));
do
echo $i ${cmplx_A_OP_const_B_fn[${i}]}
tmp=`echo ${cmplx_A_OP_const_B_fn_operations[${i}]}|sed -e 's/arg0/in_data0[i]/g' -e 's/arg1/in_data1[0]/g' `
cat complex_AopConstBinCoutTemplate|sed -e "s/FNAME/${cmplx_A_OP_const_B_fn[${i}]}/g" -e "s/OPERATION/${cmplx_A_OP_const_B_fn_operations_literal[${i}]}/" -e "s/SEE_ALSO/${cmplx_A_OP_const_B_fn_link[${i}]}/g" -e "s/CEVAL/${tmp}/g" -e "s/DATE/${today}/g"> "vz_${cmplx_A_OP_const_B_fn[${i}]}.3";
done

cmplx_const_A_OP_B_fn=(xsub xdiv)
cmplx_const_A_OP_B_fn_operations=("arg0 - arg1" "arg0 \/ arg1")
cmplx_const_A_OP_B_fn_operations_literal=("(constant) arg0 - arg1" "(constant) arg0 \/  arg1")
cmplx_const_A_OP_B_fn_link=(
"vz_subx(3), vz_sub(3), vz_xdiv(3), vd_xsub(3)"
"vz_divx(3), vz_div(3), vz_xsub(3), vd_xdiv(3)"
)

for (( i=0; i<${#cmplx_const_A_OP_B_fn[@]}; i++));
do
echo $i ${cmplx_const_A_OP_B_fn[${i}]}
tmp=`echo ${cmplx_const_A_OP_B_fn_operations[${i}]}|sed -e 's/arg0/in_data0[0]/g' -e 's/arg1/in_data1[i]/g' `
cat complex_ConstAopBinCoutTemplate|sed -e "s/FNAME/${cmplx_const_A_OP_B_fn[${i}]}/g" -e "s/OPERATION/${cmplx_const_A_OP_B_fn_operations_literal[${i}]}/" -e "s/SEE_ALSO/${cmplx_const_A_OP_B_fn_link[${i}]}/g" -e "s/CEVAL/${tmp}/g" -e "s/DATE/${today}/g"> "vz_${cmplx_const_A_OP_B_fn[${i}]}.3";
done

cmplx_returns_double_fn=(abs arg)
cmplx_returns_double_fn_operations=("fabs(arg0)" "arg(arg0)")
cmplx_returns_double_fn_as_code_operations=("cabs(arg0)" "carg(arg0)")
cmplx_returns_double_fn_link=(
"cabs(3), vz_arg(3), vd_hypot(3)"
"carg(3), vz_abs(3), vd_hypot(3)"
)
for (( i=0; i<${#cmplx_returns_double_fn[@]}; i++));
do
echo "$i c${cmplx_returns_double_fn[${i}]}"
tmp=`echo ${cmplx_returns_double_fn_as_code_operations[${i}]}|sed -e 's/arg0/in_data[i]/g'`
today=`date +"%d %b %Y"`
cat complex_1in1out_returns_double_Template|sed -e "s/FNAME/${cmplx_returns_double_fn[${i}]}/g" -e "s/OPERATION/${cmplx_returns_double_fn_operations[${i}]}/" -e "s/SEE_ALSO/${cmplx_returns_double_fn_link[${i}]}/g" -e "s/CEVAL/${tmp}/g" -e "s/DATE/${today}/g"> "vz_${cmplx_returns_double_fn[${i}]}.3";
done


## generate the 2 arg function man pages
cmplx_2_op_fn=(pow)
cmplx_2_op_fn_operations=("pow(arg0, arg1)")
cmplx_2_op_fn_as_code_operations=("cpow(arg0, arg1)")
cmplx_2_op_fn_link=(
"pow(3), vz_powx(3), vd_pow(3)"
)
for (( i=0; i<${#cmplx_2_op_fn[@]}; i++));
do
echo $i ${cmplx_2_op_fn[${i}]}
tmp=`echo ${cmplx_2_op_fn_as_code_operations[${i}]}|sed -e 's/arg0/in_data0[i]/g' -e 's/arg1/in_data1[i]/g' `
today=`date +"%d %b %Y"`
cat complex_twoArgTemplate|sed -e "s/FNAME/${cmplx_2_op_fn[${i}]}/g" -e "s/OPERATION/${cmplx_2_op_fn_operations[${i}]}/" -e "s/SEE_ALSO/${cmplx_2_op_fn_link[${i}]}/g" -e "s/CEVAL/${tmp}/g" -e "s/DATE/${today}/g"> "vz_${cmplx_2_op_fn[${i}]}.3";
done

## generate the 2 arg function, 1 is const man pages
cmplx_2_op_const_fn=(powx)
cmplx_2_op_const_fn_operations=("pow(arg0, arg1)")
cmplx_2_op_const_fn_operations_literal=("pow(arg0, (constant) arg1)")
cmplx_2_op_const_fn_as_code_operations=("cpow(arg0, arg1)")
cmplx_2_op_const_fn_link=(
"pow(3), vz_pow(3), vd_pow3o2(3), vd_pow2o3(3), vd_pow(3)"
)

for (( i=0; i<${#cmplx_2_op_const_fn[@]}; i++));
do
echo $i ${cmplx_2_op_const_fn[${i}]}
tmp=`echo ${cmplx_2_op_const_fn_as_code_operations[${i}]}|sed -e 's/arg0/in_data0[i]/g' -e 's/arg1/in_data1[0]/g' `
cat complex_twoArgOneIsConstTemplate|sed -e "s/FNAME/${cmplx_2_op_const_fn[${i}]}/g" -e "s/OPERATION/${cmplx_2_op_const_fn_operations_literal[${i}]}/" -e "s/SEE_ALSO/${cmplx_2_op_const_fn_link[${i}]}/g" -e "s/CEVAL/${tmp}/g" -e "s/DATE/${today}/g"> "vz_${cmplx_2_op_const_fn[${i}]}.3";
done
