#include <iostream>
#include <cmath>

using namespace std;

/* d é o deslocamento medido em cm
 * a é um parâmetro de ajuste para que se projete um foguete com a máxima segurança e eficiência possível
 */
double f (double d, double a){
	return a * d - d * log(d);
}

int* isolamento (double a) {
	double d = exp(a);
	int* intervalo = (int*) malloc(sizeof(int) * 2);
	intervalo[0] = floor(d);
	intervalo[1] = floor(d) + 1;
	
	return intervalo;
}

double bissecao (double parametroAjuste, double e) {
	int* intervalo = isolamento(parametroAjuste);

	float a = intervalo[0];
	float b = intervalo[1];

	cout << a << " | " << b << endl;

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

	while((b - a) >= e && k < maxInter) {
		
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