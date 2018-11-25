#ifndef MAT_H
#define MAT_H

#include <iostream>
#include <cmath>

using namespace std;

class Mat {
	
public:
	double** M;
	int length;

	Mat() {
		length = 3;
		double** matrixAux = (double**) malloc(length * sizeof(double*));

	    for (int i = 0; i < length; i++){
	        matrixAux[i] = (double*) malloc(length * sizeof(double));
	        for (int j = 0; j < length; j++) {
	        	matrixAux[i][j] = 0;
	        }
	    }
	    M = matrixAux;
	}

	Mat(double** mat, int sizeMatrix) {
		M = mat;
		length = sizeMatrix;
	}

	Mat(const Mat& mat, int sizeMatrix) {
		length = sizeMatrix;
		M = mat.M;
	}

	double operator () (int row, int col) const {
		return M[row][col];
	}

	double& operator () (int row, int col) {
		return M[row][col];
	}

	const Mat& operator=(const Mat& mat) {
		this->M = mat.M;
		return *this;
	}
};

#endif