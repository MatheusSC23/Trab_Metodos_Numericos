#include <iostream>

#include "Lu.h"


using namespace std;

int main() {
    int n = 3;

    double vec[n] = {16,38,38};
    double** mat = (double**) malloc(n * sizeof(double*));
    for(int i = 0; i < n; i++){
        mat[i] = (double*) malloc(n * sizeof(double));
    }
    mat[0][0] = 20; mat[0][1] = 7; mat[0][2] = 9;
    mat[1][0] = 7; mat[1][1] = 30; mat[1][2] = 8;
    mat[2][0] = 9; mat[2][1] = 8; mat[2][2] = 30;

    Mat matrix(mat, n);
    Vec vector(vec, n);
    
    Lu test(matrix, vector, n);
    Vec a(test.LuCalculator(), n);
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << endl;
    }
    return 0;
}


