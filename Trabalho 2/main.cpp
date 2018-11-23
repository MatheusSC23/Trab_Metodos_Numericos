#include <iostream>

#include "Lu.h"
//#include "Mat3.h"

using namespace std;

int main() {
    Mat3 matrixTest(20,7,9,
	              7,30,8,
	              9,8,30);

    Vec3 vecTest(16,38,38);

    Lu test(matrixTest, vecTest, 3);

    cout << test.LuCalculator() << endl;

    return 0;
}


