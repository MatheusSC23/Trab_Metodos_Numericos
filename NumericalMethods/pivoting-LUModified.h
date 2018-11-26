#include <iostream>
#include <cmath>
#include "pivoting-LU.h"

class PivotingLUModified : public PivotingLU {
public:
	PivotingLUModified(float **_M, int _p[], float _b[], int _d) : PivotingLU(_M,_p,_b,_d) {};
	void calculate(float[]);
private:
	void successivesSubst(float y[],float v[], float** M);
    void retroactiveSubst(float y[], float x[],float** M);
    void successivesSubstDiagonal(float y[],float v[], float** M);
};

void PivotingLUModified::retroactiveSubst(float y[], float x[],float** M) {
    for (int i = dim - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = dim - 1; j > i; j--) {
            x[i] -= M[i][j] * x[j];
        }
        x[i] /= M[i][i];
    }
};

void PivotingLUModified::successivesSubst(float y[],float v[], float** M) {
    for (int i = 0; i < dim; i++) {
        float sum = 0;
        for (int j = 0; j < i; j++) {
            sum += M[i][j] * y[j];
        }
        y[i] = v[i] - sum;
    }
};

void PivotingLUModified::successivesSubstDiagonal(float y[],float v[], float** M) {
    for (int i = 0; i < dim; i++) {
        y[i] = v[i] / M[i][i];
    }
};

void PivotingLUModified::calculate(float x[]) {
    LU();

    float** L;
    float** D;
    float** P;

    L = new float *[dim];
    D  = new float *[dim];
    P = new float *[dim];
    
    for (int i = 0; i < dim; i++) {
        L[i] = new float[dim];
        D[i] = new float[dim];
        P[i] = new float[dim];
    }

    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(i>j){
                L[i][j] = A[i][j];
                D[i][j] = 0;
                P[i][j] = 0;
            }
            else if(i==j){
                L[i][j] = 1;
                D[i][j] = A[i][j];
                P[i][j] = 1;
            }
            else if(i<j){
                L[i][j] = 0;
                P[i][j] = A[i][j]/A[i][i];
                D[i][j] = 0;
            }
        }
    }

    float y[dim];
    float s[dim];
    successivesSubst(y,b,L);
    successivesSubstDiagonal(s,y,D);
    retroactiveSubst(s, x,P);
};