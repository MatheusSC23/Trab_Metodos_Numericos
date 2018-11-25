#include <iostream>

#include "Lu.h"
#include "Lu_Modificado.h"


using namespace std;

int main() {
    int n = 3;

    //double vec[n] = {8,6,11};
    double vec[n] = {16,38,38};
    double** mat = (double**) malloc(n * sizeof(double*));
    for(int i = 0; i < n; i++){
        mat[i] = (double*) malloc(n * sizeof(double));
    }

    /*mat[0][0] = 3; mat[0][1] = -2; mat[0][2] = 1;
    mat[1][0] = 1; mat[1][1] = -3; mat[1][2] = 4;
    mat[2][0] = 9; mat[2][1] = 4; mat[2][2] = -5;*/

    mat[0][0] = 20; mat[0][1] = 7; mat[0][2] = 9;
    mat[1][0] = 7; mat[1][1] = 30; mat[1][2] = 8;
    mat[2][0] = 9; mat[2][1] = 8; mat[2][2] = 30;

    Mat matrix(mat, n);
    Vec vector(vec, n);
    
    Lu test(matrix, vector, n);
    LuModificado test2(matrix, vector, n);
    
    Vec a(test.LuCalculate(), n);
    Vec b(test2.LuModificadoCalculate(), n);

    for (int i = 0; i < n; ++i)
    {
        cout << b[i] << endl;
    }
    return 0;
}


