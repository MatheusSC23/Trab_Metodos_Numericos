#ifndef LU_H
#define LU_H

#include <iostream>
#include <cmath>

#include "Mat.h"
#include "Vec.h"

using namespace std;

class Lu {
	
public:
	Mat A;
	Vec f;
	int n;

	Lu(const Mat& M, const Vec& b, int size) {
		
		A = M;
		f.vec = b.vec;
		f.length = b.length;
		n = size;
	}

	const Vec LuCalculate() {

		Mat L(this->defineL(), n);
		Mat U(this->defineU(), n);
		
		Vec y(this->SubstituicaoSucessiva(L, f), n);
		Vec d(this->SubstituicaoRetroativa(U, y), n);

		return d;
	}

	const Vec SubstituicaoSucessiva(const Mat& matrix, const Vec& bVector) {
		double m;
		double soma;
		double yAux[n];
		double newVector[this->n];

		Mat M(matrix, this->n);
		Vec b(bVector, this->n);

		yAux[0] = b[0]/M(0,0);

		for (int i = 1; i < n; i++) {
			soma = 0;

			for (int j = 0; j < i; j++) {
				soma += (M(i,j) * yAux[j]);
			}

			yAux[i] = (b[i] - soma)/M(i,i);			
		}

		for (int i = 0; i<this->n; i++) {
			newVector[i] = yAux[i];
		}

		Vec y(newVector, this->n);

		return y;
	}

	const Vec SubstituicaoRetroativa(const Mat& matrix, const Vec& bVector) {
		
		double m;
		double x[n];
		double newVector[this->n];
		double soma;
		double p = 0;

		Mat M(matrix, this->n);
		Vec b(bVector, this->n);

		x[n-1] = b[n-1]/M(n-1,n-1);

		for (int i = n-2; i >= 0; i--) {
			soma = 0;

			for (int j = i+1; j < n; j++) {
				soma += (M(i,j) * x[j]);
			}
			x[i] = (b[i] - soma)/ (double)M(i,i);
		}

		for (int i = 0; i<this->n; i++) {
			newVector[i] = x[i];
		}

		Vec y(newVector, this->n);

		return y;
	}
	
	const Mat defineL(){

		double m;
		double mult[n];
		double b[n];
		int step = 0;
		for (int k = 0; k < n - 1; k++) {
			for (int i = k + 1; i < n; i++) {
				m = (-1) * A(i,k)/A(k,k);
				mult[step] = A(i,k)/A(k,k);
				A(i,k) = 0;
				step++;

				for (int j = k + 1; j < n; j++) {
					A(i,j) = A(i,j) + m*A(k,j);
				}
				b[i] = b[i] + m*b[k];
			}
		}


		double** matrixAux = (double**) malloc(n * sizeof(double*));

	    for (int i = 0; i < n; i++){
	        matrixAux[i] = (double*) malloc(n * sizeof(double));
	    }
	    int k = 0;
	    for (int i = 0; i < n; i++){
	        for (int j = 0; j < n; j++){
	        	if (i<j) matrixAux[i][j] = 0;
	        	if (i==j) matrixAux[i][j] = 1;
	        	if (i>j) {matrixAux[i][j] = mult[k]; k++;}
	        }
	    }

 		Mat L(matrixAux, n);
		
		return L;
	}

	const Mat defineU(){
		double m;
		double b[n];

		for (int k = 0; k < n - 1; k++) {
			for (int i = k + 1; i < n; i++) {
				m = (-1) * A(i,k)/A(k,k);
				A(i,k) = 0;

				for (int j = k + 1; j < n; j++) {
					A(i,j) = A(i,j) + m*A(k,j);
				}
				b[i] = b[i] + m*b[k];
			}
		}
		
		return A;
	}
   
};

#endif