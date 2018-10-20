#ifndef FALSAPOSICAO_H
#define FALSAPOSICAO_H

#include <iostream>
#include <cmath>

using namespace std;

class FalsaPosicao {

private:
	double parametroAjuste;
	double a;
	double b;
	double e;
	int maxIter;

public:

	FalsaPosicao (double ajuste, double erro, double iteracoes) {
		parametroAjuste = ajuste;
		e = erro;
		maxIter = iteracoes;
	}

	/* d é o deslocamento medido em cm
	 * a é um parâmetro de ajuste para que se projete um foguete com a máxima segurança e eficiência possível
	 */
	double f (double d, double a) {
		return a * d - d * log(d);
	}

	void isolamento (double a) {
		double d = exp(a);
		int* intervalo = (int*) malloc(sizeof(int) * 2);
		this->a =  floor(d);
		this->b = floor(d) + 1;
	}

	double falsa_posicao() {
		double a = this->a;
		double b = this->b;
		double parametroAjuste = this->parametroAjuste;
		double e = this->e;
		int maxIter = this->maxIter;

		if (b - a < e) {
			return a;
		}

		int k = 0;
		double x;
		double fx; // função f aplicada a x
		double fa; // função f aplicada a a
		double fb; // função f aplicada a b

		//cabeçalho
		cout.precision(6);
		cout << fixed;
		cout << "k" << " | ";
		cout << "   x  " << " | ";
		cout << "  f(x) " << " | ";
		cout << "b-a" << endl;
		fa = f(a, parametroAjuste);
		fb = f(b, parametroAjuste);
		while ((b - a) >= e && k < maxIter) {

			
			if (fa * fb > 0){
				throw "Erro: função não muda de sinal entre a e b";
				cout << "Erro: função não muda de sinal entre a e b" << endl;
			}

			if (abs(fa) < e) {
				return a;
			}

			if (abs(fb) < e) {
				return b;
			}


			x = ((a * fb) - (b * fa)) / (fb - fa);

			fx = f(x, parametroAjuste);

			k++;
			//prints
			cout << k << " | ";
			cout << x << " | ";
			cout << fx << " | ";
			cout << b - a << endl;
			
			if (fx > 0) {
				a = x;
				fa = f(a, parametroAjuste);
			} else {
				b = x;
				fb = f(b, parametroAjuste);
			}
		}
	 
		return x;
	}
}
#endif