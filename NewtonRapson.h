#ifndef NEWTONRAPSON_H
#define NEWTONRAPSON_H

#include <iostream>
#include <cmath>

using namespace std;

class NewtonRapson {

private:
	double parametroAjuste;
	double x0;
	double e;
	int maxIter;

public:
	NewtonRapson (double ajuste, double erro, double iteracoes) {
		parametroAjuste = ajuste;
		e = erro;
		maxIter = iteracoes;
	}

	/* d é o deslocamento medido em cm e 
	 * a é um parâmetro de ajuste para que se projete um foguete com a máxima segurança e eficiência possível
	 */
	double f (double d, double a) {
		return a * d - d * log(d);
	}


	double fLine(double d, double a){
		return a - log(d) - 1;
	}

	double phi(double d, double a){
		return d - (f(d, a) / fLine(d, a));
	}


	void pontoInicial (double a) {
		this->x0 = exp(a) + 0.5;
	}


	double newton_rapson () {
		pontoInicial(this->parametroAjuste);

		double x0 = this->x0;
		double parametroAjuste = this->parametroAjuste;
		double e = this->e;
		int maxIter = this->maxIter;

		double fx0 = f(x0, parametroAjuste);

		if(abs(fx0) < e) return x0;

		int k = 1;
		double x1;
		double fx1;

		//cabeçalho
		cout.precision(6);
		cout << fixed;
		cout << "k" << " | ";
		cout << "   x  " << " | ";
		cout << "f(x)  " << "  | ";
		cout << "f'(x)" << endl;

		cout << 0 << " | ";
		cout << x0 << " | ";
		cout << fx0 << "  | ";
		cout << fLine(x0, parametroAjuste) <<endl;

		while(k < maxIter){
			x1 = phi(x0, parametroAjuste);
			fx1 = f(x1, parametroAjuste);

			//prints
			cout << k << " | ";
			cout << x1 << " | ";
			cout << fx1 << " | ";
			cout << fLine(x1, parametroAjuste) <<endl;

			if (abs(x1 - x0) < e or abs(fx1) < e ){
				return x1;
			}

			x0 = x1;
			k += 1;
		}

		return x1;
	}
};
#endif