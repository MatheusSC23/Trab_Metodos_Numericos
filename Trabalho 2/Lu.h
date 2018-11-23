#ifndef LU_H
#define LU_H

#include <iostream>
#include <cmath>

#include "Mat3.h"

using namespace std;

class Lu
{
	
private:
	Mat3 A;
	Vec3 d;
	Vec3 f;
	int n;

public:
	Lu(const Mat3& M, const Vec3& b, int m) {
		A = M;
		f = b;
		n = m;
	}

	// Ly = b; Ux = y
	const Vec3 LuCalculator() {
		
		Mat3 L(this->defineL());
		Mat3 U(this->defineU());

		Vec3 y(this->SubstituicaoSucessiva(L, f));
		cout << y << endl;

		Vec3 d(this->SubstituicaoRetroativa(U, y));
		cout << d << endl;



		// cout << L << endl;
		// cout << U << endl;
		Vec3 test(1,2,3);
		return test;


	}
	const Vec3 SubstituicaoSucessiva(const Mat3& Mat, const Vec3& bVector) {
		float m;
		float x[n];
		float soma;
		Mat3 M(Mat);
		Vec3 b(bVector);

		x[0] = b[0]/A(0,0);
		for (int i = 1; i < n; i++) {
			soma = 0;

			for (int j = 0; j < i; j++) {
				soma += (A(i,j) * x[j]);
			}
			x[i] = (b[i] - soma)/A(i,i);
		}

	}

	const Vec3 SubstituicaoRetroativa(const Mat3& Mat, const Vec3& bVector) {
		
		float m;
		float x[n];
		float soma;
		Mat3 M(Mat);
		Vec3 b(bVector);

		x[n-1] = b[n-1]/A(n-1,n-1);

		for (int i = n-2; i > 0; i--) {
			soma = 0;

			for (int j = i+1; j < n; j++) {
				soma += (A(i,j) * x[j]);
			}
			x[i] = (b[i] - soma)/A(i,i);
		}



		Vec3 y(x[0], x[1], x[2]);
		return y;
	}
	
	const Mat3 defineL(){
		float m;
		float mult[n];
		float b[n];
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
 		Mat3 L(1,0,0,
 			  mult[0],1,0,
 			  mult[1],mult[2],1);
		
		return L;
	}

	const Mat3 defineU(){
		float m;
		float b[n];

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