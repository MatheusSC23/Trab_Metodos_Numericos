#ifndef BISSECTION_H
#define BISSECTION_H

#include <iostream>
#include <cmath>

using namespace std;

class Bissection {
private:
	double fitParam;
	double a;
	double b;
	double e;
	int maxIter;

public:
	Bissection (double fit, double error, double iters) {
		fitParam = fit;
		e = error;
		maxIter = iters;
	}
 
	/* 'd' - is the offset measured in centimeter
	 * 'a' - is a paramter of fit for keep safe a rocket
	 * 		 with the max safety and possible efficiency
	 */
	double f (double d, double a) {
		return a * d - d * log(d);
	}

	void isolation (double a) {
		double d = exp(a);
		this->a = floor(d);
		this->b = floor(d) + 1;
	}

	double bissection () {
		isolation(this->fitParam);

		double a = this->a;
		double b = this->b;
		double fitParam = this->fitParam;
		double e = this->e;
		int maxIter = this->maxIter;

		if (b - a < e) return a;

		int k = 0;
		double x;
		double fx;

		// Header
		cout.precision(6);
		cout << fixed;
		cout << "k" << " | ";
		cout << "   x  " << " | ";
		cout << "  f(x) " << " | ";
		cout << "b - a" << endl;

		while ((b - a) >= e && k < maxIter) {			
			k += 1;
			
			x = (a + b) / 2;	
			fx = f(x, fitParam);
		
			if(fx > 0) {
				a = x;
			} else {
				b = x;
			}

			// Prints
			cout << k << " | ";
			cout << x << " | ";

			if(fx >= 0) {
				cout << "+";
			}

			cout << fx << " | ";
			cout << b - a << endl;

			if(abs(fx) < e){
				return x;
			}
		}

		return x;
	}
};

#endif