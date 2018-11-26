#include <iostream>
#include <cmath>

using namespace std;

class PivotingLU {
  public:
    PivotingLU(float **M, int _p[], float _b[], int d) {
        A = M;
        dim = d;
        p = _p;
        b = _b;
    };
    void calculate(float[]); 
    int dim;

    float **A;
    float *b;
    void LU();
    int *p;

    void swapRows(int, int);
    // void swapRows(int, int);
    int getPivot(int);
    void retroactiveSubst(float[], float[]);
    void successivesSubst(float[]);
};

void PivotingLU::swapRows(int k, int r) {
    if (k <= dim && r <= dim && r != k) {
        float aux = p[k];
        p[k] = p[r];
        p[r] = aux;
        for (int j = 0; j < dim; j++) {
            float aux = A[k][j];
            A[k][j] = A[r][j];
            A[r][j] = aux;
        }
    }
};

int PivotingLU::getPivot(int k) {
    float pv = abs(A[k][k]);
    int r = k;
    for (int i = k + 1; i < dim; i++) {
        if (abs(A[i][k]) > pv) {
            pv = abs(A[i][k]);
            r = i;
        }
    }
    return r;
};

void PivotingLU::retroactiveSubst(float y[], float x[]) {
    for (int i = dim - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = dim - 1; j > i; j--) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
};



void PivotingLU::successivesSubst(float y[]) {
    for (int i = 0; i < dim; i++) {
        float sum = 0;
        for (int j = 0; j < i; j++) {
            sum += A[i][j] * y[j];
        }
        y[i] = b[i] - sum;
    }
};





void PivotingLU::LU() {
    for (int i = 0; i < dim; i++) {
        p[i] = i;
    }

    for (int k = 0; k < dim - 1; k++) {
        int r = getPivot(k);
        if (A[r][k] == 0) {
            cout << "Matriz singular!";
            return;
        }
        swapRows(k, r);

        float m;
        for (int i = k+1; i < dim; i++) {
            m = A[i][k] / A[k][k];
            A[i][k] = m;

            for (int j = k + 1; j < dim; j++) {
                A[i][j] = A[i][j] - m * A[k][j];
            }
        }
    }

    float blin[dim];
    for (int i = 0; i < dim; i++) {
        int r = p[i];
        blin[i] = b[r];
    }
    for (int i = 0; i < dim; i++) {
        b[i] = blin[i];
    }
};

void PivotingLU::calculate(float x[]) {
    LU();

    float y[dim];
    successivesSubst(y);
    retroactiveSubst(y, x);
};

