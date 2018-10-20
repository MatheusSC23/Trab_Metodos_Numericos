#include <iostream>
#include <cmath>
using namespace std;



double f (double d) {
	/*d é o deslocamento medido em cm e 
	a é um parâmetro de ajuste para que se projete um foguete com a máxima segurança e eficiência possível
	*/
	double a = 1.0; //Usuario passa o a tbm?
	return a*d-d*log(d); //Logaritmo 
}


double falsePosition(double (*f)(double), double a, double b, double e1, double e2, int maxInter) {

	if (b-a < e1) {
		return a;
	}

	int k = 0;
	double x;
	double fx; // função f aplicada a x
	double fa; // função f aplicada a a
	double fb; // função f aplicada a b

	//cabeçalho
	cout.precision(4);
	cout << fixed;
	cout << "k" << " | ";
	cout << "   x  " << " | ";
	cout << "  f(x) " << " | ";
	cout << "b-a" << endl;
	fa = (*f)(a);
	fb = (*f)(b);
	while ((b-a) >= e1 && k < maxInter) {

		
		if (fa*fb > 0){
			throw "Erro: função não muda de sinal entre a e b";
			cout << "Erro: função não muda de sinal entre a e b" << endl;
		}

		if (abs(fa) < e2) {
			return a;
		}

		if (abs(fb) < e2) {
			return b;
		}


		x = ((a*fb) - (b*fa))/(fb - fa);

		fx = (*f)(x);

		k++;
		//prints
		cout << k << " | ";
		cout << x << " | ";
		cout << fx << " | ";
		cout << b-a << endl;
		
		if (fx > 0) {
			a = x;
			fa = (*f)(a);
		} else {
			b = x;
			fb = (*f)(b);
		}

	}
 
	return x;
}

/*
int main() {
	double erro = pow(10,-4);
	double raiz = falsePosition(f, 2, 3, erro, erro, 20);
	cout << "Raiz: " << raiz << endl;
	return 0;
}*/