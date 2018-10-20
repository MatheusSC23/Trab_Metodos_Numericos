#ifndef NEWTONRAPSON_H
#define NEWTONRAPSON_H

#include <iostream>
#include <cmath>

using namespace std;

class NewtonRapson {

private:
	double fitParam;
	double x0;
	double e;
	int maxIter;

public:
	NewtonRapson (double fit, double error, double iters) {
		fitParam = fit;
		e = erro;
		maxIter = iters;
	}

	/* 'd' - is the offset measured in centimeter
	 * 'a' - is a paramter of fit for keep safe a rocket
	 * 		 with the max safety and possible efficiency
	 */
	double f (double d, double a) {
		return a * d - d * log(d);
	}


	double fLine(double d, double a){
		return a - log(d) - 1;
	}

	double phi(double d, double a){
		return d - (f(d, a) / fLine(d, a));
	}


	void initPoint (double a) {
		this->x0 = exp(a) + 0.5;
	}


	double newtonRapson () {
		initPoint(this->fitParam);

		double x0 = this->x0;
		double fitParam = this->fitParam;
		double e = this->e;
		int maxIter = this->maxIter;

		double fx0 = f(x0, fitParam);

		if(abs(fx0) < e) return x0;

		int k = 1;
		double x1;
		double fx1;

		// Header
		cout.precision(6);
		cout << fixed;
		cout << "k" << " | ";
		cout << "   x  " << " | ";
		cout << "f(x)  " << "  | ";
		cout << "f'(x)" << endl;

		cout << 0 << " | ";
		cout << x0 << " | ";
		cout << fx0 << "  | ";
		cout << fLine(x0, fitParam) <<endl;

		while (k < maxIter){
			x1 = phi(x0, fitParam);
			fx1 = f(x1, fitParam);

			// Prints
			cout << k << " | ";
			cout << x1 << " | ";
			cout << fx1 << " | ";
			cout << fLine(x1, fitParam) <<endl;

			if (abs(x1 - x0) < e or abs(fx1) < e ){
				return x1;
			}

			x0 = x1;
			k += 1;
		}

		return x1;
	}
};

#endif