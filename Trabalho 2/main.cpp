#include <iostream>

#include "Lu.h"
//#include "Mat3.h"

using namespace std;

int main() {
    Mat3 matrixTest(20,7,9,
              7,30,8,
              9,8,30);

    Vec3 vecTest(1,2,3);

    Lu test(matrixTest, vecTest, 3);

    test.LuCalculator();

    return 0;
}


