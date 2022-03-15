#pragma once

#include <iostream>
#include <vector>
#include <cmath>

class Matrix
{
private:

	size_t size_m;
	double** ptrM;
	struct Determinant
	{
		double d = 0;
		double** ptrM;
	};

public:

	Matrix(size_t size);
	
	Determinant det;

	void setSize(size_t s);
	void setMatrix(double** ptrM, std::vector<double>& v);
	void getMatrix(double** ptrM, double** newM, size_t i, size_t size_m);
	void printMatrix(double** ptrM, size_t size_m);
	void clearMatrix(double** ptrM, size_t size_m);

	double getDeterminant(double** ptrM, size_t size_m);

	~Matrix();
};

