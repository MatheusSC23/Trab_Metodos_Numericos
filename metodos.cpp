//#include "falsa_posicao.h"
#include "bissecao.h"
//#include "newton_rapson.h"

int main(int argc, char const *argv[]) {
	
	double raiz = bissecao(1, pow(10,-5));
	cout << "Raiz: " << raiz << endl;

	return 0;
}