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

  private:
    float **A;
    int dim;
    int *p;
    float *b;

    void swapRows(int, int);
    // void swapRows(int, int);
    int getPivot(int);
    void retroactiveSubst(float[], float[]);
    void successivesSubst(float[]);
    void LU();
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

// void PivotingLU::swapRows(int i, int j) {
//     if (i <= dim && j <= dim && j != i) {
//         float aux = b[i];
//         b[i] = b[j];
//         b[j] = aux;
//     } 
// };

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

int main(void) {
    const int n = 3;
    float m[n][n] = {
        20, 7, 9,
        7, 30, 8,
        9, 8, 30
    };

    float **A;
    A = new float *[n];
    for (int i = 0; i < n; i++) {
        A[i] = new float[n];
    }

    for (int k = 0; k < n; k++) {
        for (int q = 0; q < n; q++) {
            A[k][q] = m[k][q];
        }
    }
    
    int p[n];
    float x[n];
    
    float b[n] = {
        16,
        38,
        38
    };

    PivotingLU calc(A, p, b, n);
    calc.calculate(x);

    cout << "M = " << endl;
    cout << A[0][0] << ", " << A[0][1] << ", " << A[0][2] << endl;
    cout << A[1][0] << ", " << A[1][1] << ", " << A[1][2] << endl;
    cout << A[2][0] << ", " << A[2][1] << ", " << A[2][2] << endl;

    cout << endl;

    cout << "X = " << endl;
    cout << x[0] << ", " << x[1] << ", " << x[2] << endl;

    cout << endl;

    cout << "P = " << endl;
    cout << p[0] << ", " << p[1] << ", " << p[2] << endl;
    return 0;
}