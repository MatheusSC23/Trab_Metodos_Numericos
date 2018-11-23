#include <iostream>

//#include "Lu.h"
//#include "Mat3.h"
#include "Vec.h"

using namespace std;

int main() {
    /*Mat3 matrixTest(20,7,9,
	              7,30,8,
	              9,8,30);

    Vec3 vecTest(16,38,38);

    Lu test(matrixTest, vecTest, 3);

    cout << test.LuCalculator() << endl; */
	int n = 3;
	double vec1[n] = {7,2,5};
	double vec2[n] = {1,4,5};

    Vec vector1(vec1, n);
    Vec vector2(vec2, n);
   	Vec vector3(vector1, n);


	// ================= PRINT VEC 1 =================
	cout << "[ ";
    for (int i = 0; i < n; i++) {
    	//cout << vector1.vec[i] << " ";
    }
	cout << "]" << endl;

	// ================= PRINT VEC 2 =================
	cout << "[ ";
    for (int i = 0; i < n; i++) {
    	//cout << vector2.vec[i] << " ";
    }
	cout << "]" << endl;

	// ================= PRINT VEC 3 =================
	cout << "[ ";
    for (int i = 0; i < n; i++) {
    	cout << vector3.vec[i] << " ";
    }
	cout << "]" << endl;

	// ================= PRINT VEC 2.2 =================
		//cout << vector2.vec[2] << " ";


    return 0;
}


