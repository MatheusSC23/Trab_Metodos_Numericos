#ifndef MAT3_H
#define MAT3_H

#include <iostream>
#include <cmath>

#include "Vec3.h"

using namespace std;

class Mat3 {
	
private:
	Vec3 c1, c2, c3;

public:

	// Problemas com este construtor (A soma não pode ser efetuada)
	Mat3() {

		c1 = Vec3(1, 0, 0);
		c2 = Vec3(0, 1, 0);
		c3 = Vec3(0, 0, 1);
	}

	Mat3(float x1, float x2, float x3,
			float y1, float y2, float y3,
			float z1, float z2, float z3) {

		c1 = Vec3(x1, y1, z1);
		c2 = Vec3(x2, y2, z2);
		c3 = Vec3(x3, y3, z3);

	}

	Mat3 (const Vec3& v1, const Vec3& v2, const Vec3& v3) {
		
		c1 = v1;
		c2 = v2;
		c3 = v3;
	}

	Mat3(const Mat3& mat) {

		c1 = mat.c1;
		c2 = mat.c2;
		c3 = mat.c3;
	}
	

	// Método de impressão na tela
	friend ostream& operator << (ostream& out, const Mat3& mat) {
		return out << endl << "[" << mat.c1[0] << ", " << mat.c2[0] << ", " << mat.c3[0] << endl
							<< mat.c1[1] << ", " << mat.c2[1] << ", " << mat.c3[1] << endl
							<< mat.c1[2] << ", " << mat.c2[2] << ", " << mat.c3[2] << "]" << endl;
	}

	float operator () (int row, int col) const {
		switch (col % 3) {
			case 0:
				return c1[row];
				break;
			case 1:
				return c2[row];
				break;
			case 2:
				return c3[row];
				break;
			default:
				break;
		}
	}

	float& operator () (int row, int col) {
		switch (col % 3) {
			case 0:
				return c1[row];
				break;
			case 1:
				return c2[row];
				break;
			case 2:
				return c3[row];
				break;
			default:
				break;
		}
	}
	

	// Método de soma de matrizes
	const Mat3 operator +(const Mat3& mat) const {
		Mat3 newMatrix(this->c1 + mat.c1, this->c2 + mat.c2, this->c3 + mat.c3);
		return newMatrix;
	}

	
	// Método de subtração de matrizes
	const Mat3 operator -(const Mat3& mat) const {
		Mat3 newMatrix(this->c1 - mat.c1, this->c2 - mat.c2, this->c3 - mat.c3);
		return newMatrix;
	}

	// Multiplicação da matriz por um escalar
	const Mat3 operator * (float k) const {
		Mat3 newMatrix(this->c1 * k, this->c2 * k, this->c3 * k);
		return newMatrix;
	}

	// Multiplicação da matriz por um vetor
	const Vec3 operator * (const Vec3& vec) const {
		float j = 0;
		float k = 0;
		float l = 0;

		for (int i = 0; i < 3; i++){
			j = j + (this->c1[i] * vec[i]);
		}
		
		for (int i = 0; i < 3; i++){
			k = k + (this->c2[i] * vec[i]);
		}

		for (int i = 0; i < 3; i++){
			l = l + (this->c3[i] * vec[i]);
		}

		Vec3 newVector(j, k, l);
		return newVector;
	}

	// Multiplicação da matriz por uma matriz
	const Mat3 operator * (const Mat3& mat) const {

		int col = 3;
		int row = 3;
		float matrix[row][col];
		
		matrix[0][0] = (this->c1[0] * mat(0, 0)) + (this->c2[0] * mat(1, 0)) + (this->c3[0] * mat(2, 0));
		matrix[0][1] = (this->c1[0] * mat(0, 1)) + (this->c2[0] * mat(1, 1)) + (this->c3[0] * mat(2, 1));
		matrix[0][2] = (this->c1[0] * mat(0, 2)) + (this->c2[0] * mat(1, 2)) + (this->c3[0] * mat(2, 2));

		matrix[1][0] = (this->c1[1] * mat(0, 0)) + (this->c2[1] * mat(1, 0)) + (this->c3[1] * mat(2, 0));
		matrix[1][1] = (this->c1[1] * mat(0, 1)) + (this->c2[1] * mat(1, 1)) + (this->c3[1] * mat(2, 1));
		matrix[1][2] = (this->c1[1] * mat(0, 2)) + (this->c2[1] * mat(1, 2)) + (this->c3[1] * mat(2, 2));
		
		matrix[2][0] = (this->c1[2] * mat(0, 0)) + (this->c2[2] * mat(1, 0)) + (this->c3[2] * mat(2, 0));
		matrix[2][1] = (this->c1[2] * mat(0, 1)) + (this->c2[2] * mat(1, 1)) + (this->c3[2] * mat(2, 1));
		matrix[2][2] = (this->c1[2] * mat(0, 2)) + (this->c2[2] * mat(1, 2)) + (this->c3[2] * mat(2, 2)); 

		Mat3 newMatrix(matrix[0][0], matrix[0][1], matrix[0][2],
						matrix[1][0], matrix[1][1], matrix[1][2],
						matrix[2][0], matrix[2][1], matrix[2][2]);
		
		return newMatrix;
	}


	// Multiplicação da matriz por um escalar
	const Mat3 operator / (float k) const {
		Mat3 newMatrix(this->c1 / k, this->c2 / k, this->c3 / k);
		return newMatrix;
	}

	// Atribuição de matriz
	const Mat3& operator=(const Mat3& mat) {
		
		this->c1 = mat.c1;
		this->c2 = mat.c2;
		this->c3 = mat.c3;
		
		return *this;
	}

	// Soma de matriz com atribuição
	const Mat3& operator+=(const Mat3& mat) {
		
		*this = *this + mat;
		
		return *this;
	}

	// Subtração de matriz com atribuição
	const Mat3& operator-=(const Mat3& mat) {
		
		*this = *this - mat;
		
		return *this;
	}

	// Multiplicação de matriz por escalar com atribuição
	const Mat3& operator*=(float k) {
		
		*this = *this * k;
		
		return *this;
	}

	// Multiplicação de matriz com atribuição
	const Mat3& operator*=(const Mat3& mat) {
		
		*this = *this * mat;
		
		return *this;
	}

	// Divisão de matriz por escalar com atribuição
	const Mat3& operator/=(float k) {
		
		*this = *this / k;
		
		return *this;
	}

	
	// Retorna o determinante da matriz
	static const Mat3 det(const Mat3& mat){
		int determinant[3][3];
		float det;
		int row, col;
		 
		for(row = 0; row < 3; row++) {
			for(col = 0; col < 3; col++) {
				determinant[row][col] = mat(row, col);
			}
		}
		 
		det = ((determinant[0][0] * determinant[1][1] * determinant[2][2])
			+ (determinant[0][1] * determinant[1][2] * determinant[2][0])
			+ (determinant[0][2] * determinant[1][0] * determinant[2][1]))

			- ((determinant[2][0] * determinant[1][1] * determinant[0][2])
			+ (determinant[2][1] * determinant[1][2] * determinant[0][0])
			+ (determinant[2][2] * determinant[1][0] * determinant[0][1]));

		cout << "Determinante: " << det << endl;
		 		  
	}

	// Retorna a matriz transposta
	static const Mat3 transpose(const Mat3& mat) {
		float transp[3][3];

		for (int row = 0; row < 3; row++){
			for (int col = 0; col < 3; col++){
				transp[col][row] = 0;
			}
		}

		for (int row = 0; row < 3; row++){
			for (int col = 0; col < 3; col++){
				transp[col][row] = mat(row, col);
			}
		}

		return Mat3 (transp[0][0], transp[0][1], transp[0][2], 
					transp[1][0], transp[1][1], transp[1][2], 
					transp[2][0], transp[2][1], transp[2][2]);
	}
};

#endif