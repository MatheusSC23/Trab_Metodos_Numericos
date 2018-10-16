#include <iostream>
#include <cmath>
using namespace std;



double f (double d){
	/*d é o deslocamento medido em cm e 
	a é um parâmetro de ajuste para que se projete um foguete com a máxima segurança e eficiência possível
	*/
	double a = 1.0; //Usuario passa o a tbm?
	return a*d-d*log(d);
}


double bissecao(double (*f)(double), double a, double b, double e, int maxInter){
	if (b-a < e){
		return a;
	}
	int k = 0;
	double M;
	double x;
	double fx;

	//cabeçalho
	cout.precision(4);
	cout << fixed;
	cout << "k" << " | ";
	cout << "   x  " << " | ";
	cout << "  f(x) " << " | ";
	cout << "b-a" << endl;

	while((b-a) >= e && k < maxInter){
		k++;
		
		
		x = (a+b)/2;	
		fx = (*f)(x);
	
		if(fx > 0){
			a = x;
		}else{
			b = x;
		}

		//prints
		cout << k << " | ";
		cout << x << " | ";
		if(fx>=0){
			cout << "+";
		}
		cout << fx << " | ";
		cout << b-a << endl;
		if(abs(fx) < e){
			return x;
		}
	}

	return x;
}


int main()
{
	double raiz = bissecao(f, 2, 3 , pow(10,-4), 20);
	cout << raiz << endl;
	return 0;
}