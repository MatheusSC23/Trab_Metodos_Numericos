#ifndef VEC_H
#define VEC_H

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Vec {
	
public:
	int length;
	double *vec;

	Vec() {

		double newVector[3] = {0,0,0};
		vec = (double*) malloc(3 * sizeof(double));
		vec = newVector;
		length = 3;

	}

	Vec(double* vector, int sizeVector) {
		vec = vector;
		length = sizeVector;
	}

	Vec(const Vec& vector, int sizeVector) {
		vec = (double*) malloc(sizeVector * sizeof(double));
		for (int i=0; i<sizeVector; i++){
			vec[i] = vector[i];
		}
		length = sizeVector;
	}

	/* -----------------------------------------------------------------------------------------------------
                                                     Operadores
         	                  
	--------------------------------------------------------------------------------------------------------*/

	double operator [] (int index) const
	{
		return vec[index];
	}

	double& operator [] (int index)
	{
		return vec[index];
	}


	const Vec operator +(const Vec& a) const 
	{
		double vector[this->length];
		for (int i=0; i < this->length; i++){
			vector[i] = this->vec[i] + a.vec[i];
		}

		Vec newVector(vector, this->length);
		return newVector;
	}

	
	const Vec operator -(const Vec& a) const 
	{
		double vector[this->length];
		for (int i=0; i < this->length; i++){
			vector[i] = this->vec[i] - a.vec[i];
		}

		Vec newVector(vector, this->length);
		return newVector;
	}

	const Vec operator *(const Vec& a) const 
	{
		double vector[this->length];
		for (int i=0; i < this->length; i++){
			vector[i] = this->vec[i] * a.vec[i];
		}

		Vec newVector(vector, this->length);
		return newVector;
	}

	const Vec operator /(const Vec& a) const 
	{
		double vector[this->length];
		for (int i=0; i < this->length; i++){
			vector[i] = this->vec[i] / a.vec[i];
		}

		Vec newVector(vector, this->length);
		return newVector;
	}

	const Vec& operator=(const Vec& a) 
	{
		for (int i=0; i < this->length; i++){
			this->vec[i] = a.vec[i];
		}

		return *this;
	}
};



#endif