#ifndef LU_MODIFICADO_H
#define LU_MODIFICADO_H

#include <iostream>
#include <cmath>

#include "Mat.h"
#include "Vec.h"

using namespace std;

class LuModificado {
	
public:
	Mat B;
	Vec f;
	int n;

	LuModificado(const Mat& M, const Vec& b, int size) {
		
		B = M;
		f.vec = b.vec;
		f.length = b.length;
		n = size;
	}

	const Vec LuModificadoCalculate() {
		
		Mat L(this->defineL(), n);
		Mat U(this->defineU(), n);
		Mat D(this->defineD(U), n);
		Mat P(this->defineP(U), n);

		Vec y(this->SubstituicaoSucessiva(L, f), n);
		Vec s(this->SubstituicaoSucessiva(D, y), n);
		Vec d(this->SubstituicaoRetroativa(P, s), n);
    

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
/*	
    	*/
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
				m = (-1) * B(i,k)/B(k,k);
				mult[step] = B(i,k)/B(k,k);
				B(i,k) = 0;
				step += 1;

				for (int j = k + 1; j < n; j++) {
					B(i,j) = B(i,j) + m*B(k,j);
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
	        	if (i>j) {matrixAux[i][j] = mult[k]; k+=1;}
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
				m = (-1) * B(i,k)/B(k,k);
				B(i,k) = 0;

				for (int j = k + 1; j < n; j++) {
					B(i,j) = B(i,j) + m*B(k,j);
				}
				b[i] = b[i] + m*b[k];
			}
		}

		return B;
	}


	const Mat defineD(const Mat& matrixU){

		double** matrixAux = (double**) malloc(n * sizeof(double*));

	    for (int i = 0; i < n; i++){
	        matrixAux[i] = (double*) malloc(n * sizeof(double));
	    }

	    for (int i = 0; i < n; i++){
	        for (int j = 0; j < n; j++){
	        	if (i !=j) matrixAux[i][j] = 0;
	        	if (i==j) matrixAux[i][j] = matrixU(i,i);
	        }
	    }

	 	Mat D(matrixAux, n);	

		return D;
	}
	
	const Mat defineP(const Mat& matrixU){

		double** matrixAux = (double**) malloc(n * sizeof(double*));

	    for (int i = 0; i < n; i++){
	        matrixAux[i] = (double*) malloc(n * sizeof(double));
	    }

	    for (int i = 0; i < n; i++){
	        for (int j = 0; j < n; j++){
	        	if (i < j) matrixAux[i][j] = matrixU(i,j)/matrixU(i,i);
	        	if (i == j) matrixAux[i][j] = 1;
	        	if (i > j) matrixAux[i][j] = 0;
	        }
	    }

	 	Mat P(matrixAux, n);		
		
		return P;
	}
 
};

#endif