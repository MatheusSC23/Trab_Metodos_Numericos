#include "../NumericalMethods/FalsePosition.h"
#include "../NumericalMethods/Bissection.h"
#include "../NumericalMethods/NewtonRapson.h"

int main(int argc, char const *argv[]) {

	FalsePosition fs(1, pow(10, -5), 30);
	Bissection b(1, pow(10, -5), 30);
	NewtonRapson nr(1, pow(10,-5), 30);

	fs.falsePosition();
	b.bissection();
	nr.newtonRapson();

	return 0;
}