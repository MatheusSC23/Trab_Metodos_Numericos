#ifndef BISSECAO_H
#define BISSECAO_H

#include <iostream>
#include <cmath>

using namespace std;

class Bissecao {

private:
	double parametroAjuste;
	double a;
	double b;
	double e;
	int maxIter;


public:

	Bissecao (double ajuste, double erro, double iteracoes) {
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
		this->a =  floor(d);
		this->b = floor(d) + 1;
	}

	double bissecao () {
		
		isolamento(this->parametroAjuste);

		double a = this->a;
		double b = this->b;
		double parametroAjuste = this->parametroAjuste;
		double e = this->e;
		int maxIter = this->maxIter;

		if (b - a < e) return a;

		int k = 0;
		double x;
		double fx;

		//cabeçalho
		cout.precision(6);
		cout << fixed;
		cout << "k" << " | ";
		cout << "   x  " << " | ";
		cout << "  f(x) " << " | ";
		cout << "b - a" << endl;

		while((b - a) >= e && k < maxIter) {
			
			k += 1;
			
			x = (a + b) / 2;	
			fx = f(x, parametroAjuste);
		
			if(fx > 0) {
				a = x;
			} else {
				b = x;
			}

			//prints
			cout << k << " | ";
			cout << x << " | ";
			if(fx >= 0) {
				cout << "+";
			}
			cout << fx << " | ";
			cout << b - a << endl;
			if(abs(fx) < e){
				return x;
			}
		}

		return x;
	}
};
#endif