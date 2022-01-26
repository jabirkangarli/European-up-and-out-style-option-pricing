#include<vector>

class EuropeanUpAndOutCall{
public:

	//constructor
	EuropeanUpAndOutCall(
		int nInt_,
		double strike_,
		double spot_,
		double vol_,
		double r_,
		double expiry_,
		double barrier_
		);

	//destructor
	~EuropeanUpAndOutCall(){};

	//methods
	void generatePath();
	void printPath();
	double getEuropeanCallPrice(int nReps);

	//members
	std::vector<double> thisPath;
	int nInt;
	double strike;
	double spot;
	double vol;
	double r;
	double expiry;
	double barrier;
};
