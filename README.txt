The aim of this course was to provide techniques of incorporating `c++` code into `R` environment. Three techniques discussed and used in my project:

* `cppFunction()` function - for short inline `c++` code chunks
* `sourceCpp()` function - for longer `c++` code chunks located in separate `*.cpp` files
* `Rcpp` package - for a project that consist of 2 or more files 

The `Rcpp` package used to provide function defined in `c++` which will be responsible for providing valuations of path-dependent option of European style using the Monte Carlo simulation technique.



We are considering an `European style up-and-out call` option with a `barrier` active between the moment of pricing and the option expiry.

Specifically, we are interested in:

1. the theoretical price of this option

2. relation between the theoretical price of the option and two factors (simultaneously):
a) volatility of the underlying instrument returns, and
b) time to maturity of the option.


We will create an `Rcpp` package which provides a function returning the `Monte Carlo` approximation of the option theoretical price.

Our code is ready to price the option for any values of its characteristics, nevertheless we will use the theoretical price for the following values:

• price of the underyling at the moment of option pricing: S0 = 105,
• strike price K = 100,
• annualized volatility rate σ = 0.22
• annualized risk-free rate r = 0.05
• time to maturity t = 0.5

As far as the barrier level is concerned, since the bareer options are used for hedging in short term, I marked bareer level as 120. If the bareer level would be approximation of 110, most likely the option would be knocked out.



Please find the following instructions to have proper environment to be able to work on the project, please refer to the Mr. Paweł Sakowski's reporsitory :
https://github.com/pawelsakowski/AF-RCPP-2021-2022/


