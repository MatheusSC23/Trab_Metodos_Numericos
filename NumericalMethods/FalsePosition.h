#ifndef FALSEPOSITION_H
#define FALSEPOSITION_H

#include <iostream>
#include <cmath>

using namespace std;

class FalsePosition {

private:
	double fitParam;
	double e;
	double a;
	double b;
	int maxIter;

public:

	FalsePosition (double fit, double error, double iters) {
		fitParam = fit;
		e = error;
		maxIter = iters;
		isolation(this->fitParam);
	}

	FalsePosition (double fit, double error, double iters, double a, double b) {
		fitParam = fit;
		e = error;
		maxIter = iters;
		this->a = a;
		this->b = b;
	}

	/* 'd' - is the offset measured in centimeter
	 * 'a' - is a paramter of fit for keep safe a rocket
	 * 		 with the max safety and possible efficiency
	 */
	double f (double d, double a) {
		return a * d - d * log(d);
	}

	string getIsolation () {
		return "[" + to_string(a) + ", " + to_string(b) + "]"; 
	}

	void isolation (double fit) {
		double d = exp(fit);
		this->a = floor(d);
		this->b = floor(d) + 1;
	}

	double falsePosition () {
		double a = this->a;
		double b = this->b;
		double fitParam = this->fitParam;
		double e = this->e;
		int maxIter = this->maxIter;

		if (b - a < e) {
			return a;
		}

		int k = 0;
		double x;
		double fx; // function f applied to 'x'
		double fa; // function f applied to 'a'
		double fb; // function f applied to 'b'

		fa = f(a, fitParam);
		fb = f(b, fitParam);

		while ((b - a) >= e && k < maxIter) {
			if (fa * fb > 0){
				throw "Error: function not changes of signal between 'a' and 'b'";
				cout << "Error: function not changes of signal between 'a' and 'b'" << endl;
			}

			if (abs(fa) < e) {
				return a;
			}

			if (abs(fb) < e) {
				return b;
			}


			x = ((a * fb) - (b * fa)) / (fb - fa);

			fx = f(x, fitParam);

			k++;
			
			if (fx > 0) {
				a = x;
				fa = f(a, fitParam);
			} else {
				b = x;
				fb = f(b, fitParam);
			}
		}
	 
		return x;
	}
};

#endif