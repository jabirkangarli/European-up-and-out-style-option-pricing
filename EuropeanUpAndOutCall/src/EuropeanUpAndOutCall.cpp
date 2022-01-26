#include<iostream>
#include<cmath>
#include"getOneGaussianByBoxMueller.h"
#include"EuropeanUpAndOutCall.h"
#include<algorithm>

//definition of constructor
EuropeanUpAndOutCall::EuropeanUpAndOutCall(
	int nInt_,
	double strike_,
	double spot_,
	double vol_,
	double r_,
	double expiry_,
	double barrier_){
		nInt = nInt_;
		strike = strike_;
		spot = spot_;
		vol = vol_;
		r = r_;
		expiry = expiry_;
		barrier = barrier_;
		generatePath();
}

//method definition
void EuropeanUpAndOutCall::generatePath(){
	double thisDrift = (r * expiry - 0.5 * vol * vol * expiry) / double(nInt);
	double cumShocks = 0;
	thisPath.clear();

	for(int i = 0; i < nInt; i++){
		cumShocks += (thisDrift + vol * sqrt(expiry / double(nInt)) * getOneGaussianByBoxMueller());
		thisPath.push_back(spot * exp(cumShocks));
	}
}

//method definition
void EuropeanUpAndOutCall::printPath(){

	for(int i = 0;  i < nInt; i++){

		std::cout << thisPath[i] << "\n";

	}

}


//method definition
double EuropeanUpAndOutCall :: getEuropeanCallPrice(int nReps){

	double rollingSum = 0.0;

	
	for(int i = 0; i < nReps; i++){
		generatePath();
		double thisMax = *max_element(thisPath.begin(), thisPath.end());
		double lastPrice =thisPath.back();
		rollingSum += ((lastPrice > strike) && (lastPrice < barrier)) ? (lastPrice-strike) : 0;

	}

	return exp(-r*expiry)*rollingSum/double(nReps);

}


