#ifndef VEC_H
#define VEC_H

#include <iostream>
#include <cmath>

using namespace std;

class Vec
{
	
private:
	double* vec;
	int size;

public:

	Vec(double* vector, int sizeVector) {
		vec = vector;
		size = sizeVector;
	}

	Vec(const Vec& vector, int sizeVector) {
		size = sizeVector;
		for (int i = 0; i < size; i++) {
			vec[i] = vector.vec[i];
		}
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
		double vector[this->size];
		for (int i=0; i < this->size; i++){
			vector[i] = this->vec[i] + a.vec[i];
		}

		Vec newVector(vector, this->size);
		return newVector;
	}

	
	const Vec operator -(const Vec& a) const 
	{
		double vector[this->size];
		for (int i=0; i < this->size; i++){
			vector[i] = this->vec[i] - a.vec[i];
		}

		Vec newVector(vector, this->size);
		return newVector;
	}

	const Vec operator *(const Vec& a) const 
	{
		double vector[this->size];
		for (int i=0; i < this->size; i++){
			vector[i] = this->vec[i] * a.vec[i];
		}

		Vec newVector(vector, this->size);
		return newVector;
	}

	const Vec operator /(const Vec& a) const 
	{
		double vector[this->size];
		for (int i=0; i < this->size; i++){
			vector[i] = this->vec[i] / a.vec[i];
		}

		Vec newVector(vector, this->size);
		return newVector;
	}

	const Vec& operator=(const Vec& a) 
	{
		for (int i=0; i < this->size; i++){
			this->vec[i] = a.vec[i];
		}

		return *this;
	}
};



#endif