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
		isolation(this->fitParam);
	}

	Bissection (double fit, double error, double iters, double a, double b) {
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

	void isolation (double fit) {
		this->a = 0.000001;
		this->b = 1;

		double fa = f(this->a, fit);
		double fb = f(this->b, fit);

		while (fa * fb > 0) {
			this->a = this->b;
			this->b += 1;

			fa = f(this->a, fit);
			fb = f(this->b, fit);
		}
	}

	double bissection () {
		double a = this->a;
		double b = this->b;
		double fitParam = this->fitParam;
		double e = this->e;
		int maxIter = this->maxIter;

		if (abs(b - a) < e) return a;

		int k = 0;
		double x;
		double fx;

		while (abs(b - a) >= e && k < maxIter) {			
			k += 1;

			x = (a + b) / 2;	
			fx = f(x, fitParam);

			if(fx > 0) {
				a = x;
			} else {
				b = x;
			}

			if(abs(fx) < e){
				return x;
			}
		}

		return x;
	}
};

#endif