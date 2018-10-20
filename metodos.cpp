#include "FalsaPosicao.h"
#include "Bissecao.h"
//#include "newton_rapson.h"

int main(int argc, char const *argv[]) {
	
	FalsaPosicao fs(1, pow(10,-5), 30);
	Bissecao b(1, pow(10,-5), 30);

	fs.falsa_posicao();
	b.bissecao();
	
	return 0;
}