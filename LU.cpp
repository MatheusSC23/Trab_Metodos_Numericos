#include <iostream>
#include <cmath>
#include <limits>
using namespace std;


int main(int argc, char const *argv[]){
	// Ax = b
	double m, s, maior, aux; //auxiliares
	int row, col, n, linha, l;
	row = 3;
	col = 3;
	n = 3;
	double L[row][col] = {
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}
	};
	double U[row][col] = {
		{20, 7, 9},
		{7, 30, 8},
		{9, 8, 30}
	};
	double y[row][1]; //vetor auxiliar y
	double x[row][1]; //vetor resposta x
	double b[row][1] = {
		{16}, 
		{38}, 
		{38}
	};
	
	//Eliminação
	for (int k = 0; k < n-1; k++){//percorre as colunas
		maior = -numeric_limits<double>::max();//-infinito
		for (int i = k+1; i < n; i++){ //percorre as linhas
			//pivotamento
			l = i-1;
			if(abs(U[l][k]) > maior){
				maior = abs(U[l][k]);//pega o maior pivo
				linha = l; //acha a linha do maior pivô
			}
			if(linha!=k){
				for (int t = k; t < n; t++){//percorre as colunas
					//troca as linhas  
					aux = U[linha][t];
					U[linha][t] = U[k][t];
					U[k][t] = aux;
				}
				aux = b[linha][0];
				b[linha][0] = b[k][0];
				b[k][0] = aux;
			}
			//end_pivoteamento
			m = U[i][k]/U[k][k];
			U[i][k] = 0;
			L[i][k] = m;
			for (int j = k+1; j < n; j++){//percorre as linhas calculando seus novos valores
				U[i][j] = U[i][j] - m*U[k][j];
			}
			b[i][0] = b[i][0] - m*b[k][0];
		}
	}

	//resolução do sistema Ly = b
	
	y[0][0] = b[0][0]/L[0][0];
	for (int k = 1; k < n; k++){//substituição
		s = 0;
		for (int j = k+1; j < n; j++){
			s = s + L[k][j]*y[j][0];
		}
		y[k][0] = (b[k][0]-s)/L[k][k];
	}

	//resolução do sistema Ux = y
	x[n][0] = y[n][0]/U[n][n];
	for (int k = n-1; k >= 0; k--){//substituição retroativa
		s = 0;
		for (int j = k+1; j < n; j++){
			s = s + U[k][j]*x[j][0];
		}
		x[k][0] = (y[k][0]-s)/U[k][k];
	}

	//imprimir x
	cout << "Vetor resposta:" << endl;
	for (int i = 0; i < n; i++){
		cout << x[i][0] << endl;
	}
	return 0;
}