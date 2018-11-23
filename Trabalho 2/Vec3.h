#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>

using namespace std;

class Vec3
{
	
private:
	float x,
		  y,
		  z;

public:

	Vec3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	Vec3(int a)
	{
		x = a;
		y = a;
		z = a;
	}


	Vec3(float a, float b, float c)
	{
		x = a;
		y = b;
		z = c;
	}

	Vec3(const Vec3& vec)
	{
		x = vec.x;
		y = vec.y;
		z = vec.z;
	}

	


	/* -----------------------------------------------------------------------------------------------------
                                                     Operadores
         	                  
	--------------------------------------------------------------------------------------------------------*/


	friend ostream& operator << (ostream& out, const Vec3& vetor)
	{
		return out << "[" << vetor.x << ", " << vetor.y << ", " << vetor.z << "]" << endl;
	}


	float operator [] (int index) const
	{
		switch(index % 3) 
		{
			case 0:
				return x;
				break;
			case 1:
				return y;
				break;
			case 2:
				return z;
				break;
			default:
				break;

		}
	}

	float& operator [] (int index)
	{
		switch(index % 3)
		{
			case 0:
				return x;
				break;
			case 1:
				return y;
				break;
			case 2:
				return z;
				break;
			default:
				break;

		}
	}


	const Vec3 operator +(const Vec3& a) const 
	{
		Vec3 novoVetor(this->x + a.x, this->y + a.y, this->z + a.z);
		return novoVetor;
	}

	
	const Vec3 operator - (const Vec3& a) const 
	{
		Vec3 novoVetor(this->x - a.x, this->y - a.y, this->z - a.z);
		return novoVetor;
	}

	const Vec3 operator * (float a) const 
	{
		Vec3 novoVetor(this->x * a, this->y * a, this->z * a);
		return novoVetor;
	}

	const Vec3 operator / (float a) const 
	{
		Vec3 novoVetor(this->x / a, this->y / a, this->z / a);
		return novoVetor;
	}

	const Vec3& operator=(const Vec3& a) 
	{
		
		this->x = a[0];
		this->y = a[1];
		this->z = a[2];
		
		return *this;
	}

	const Vec3& operator+=(const Vec3& a)
	{
		*this = *this + a;

		return *this;
	}

	const Vec3& operator-=(const Vec3& a)
	{
		*this = *this - a;

		return *this;
	}

	const Vec3& operator*=(float a) 
	{
		*this = *this * a;

		return *this;
	}

	const Vec3& operator/=(float a)
	{
		*this = *this / a;

		return *this;
	}
};



#endif