#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include"EuropeanUpAndOutCall.h"
#include"getVecMean.h"
#include"getVecStdDev.h"
#include <Rcpp.h>


using std::vector;
using std::cout;
using std::cin;
using namespace Rcpp;

// [[Rcpp::export]]
double getEuropeanCallPrice(
	  int nInt,
    double strike,
    double spot,
    double vol,
    double r,
    double expiry,
    double barrier,
    int nReps = 10000
){

	// set the seed
	
	srand( time(NULL) );
  //create a new instance of class
  
  EuropeanUpAndOutCall EuropeanCall(nInt, strike, spot, vol, r, expiry, barrier);
  
  
  //run Monte Carlo to obtain theoretical price of European options
  
  return EuropeanCall.getEuropeanCallPrice(nReps);
  

}
