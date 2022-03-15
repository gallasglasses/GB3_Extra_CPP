#include "Matrix.h"

Matrix::Matrix(size_t size)
	: size_m(size)
{
	det.ptrM = new double* [size_m];
	for (size_t i = 0; i < size_m; i++)
	{
		det.ptrM[i] = new double[size_m];
	}

	//setMatrix(det.ptrM);
	det.d = 0;
}

void Matrix::printMatrix(double** ptrM, size_t size_m)
{
	for (size_t i = 0; i < size_m; i++)
	{
		for (size_t j = 0; j < size_m; j++)
		{
			std::cout << ptrM[i][j] << " ";
		}
		std::cout << "\n";
	}
}
void Matrix::setSize(size_t s)
{
	size_m = s;
}

void Matrix::setMatrix(double **ptrM, std::vector<double>& v)
{
	double x = 1;
	std::vector<double>::iterator it = v.begin();
	for (size_t i = 0; i < size_m; i++)
	{
		for (size_t j = 0; j < size_m; j++)
		{
			if (it != v.end())
			{
				ptrM[i][j] = *it;
				++it;
			}
		}
	}

	printMatrix(det.ptrM, size_m);
}

void Matrix::getMatrix(double** ptrM, double** newM, size_t i, size_t size_m)
{
	size_t iPos = 0,
		   jPos = 0;
	for (size_t iNew = 0; iNew < size_m; iNew++)
	{
		if (iNew == i)
		{
			iPos = 1;
		}
		for (size_t jNew = 0; jNew < size_m; jNew++)
		{
			if (jNew == 0)
			{
				jPos = 1;
			}
			newM[iNew][jNew] = ptrM[iNew + iPos][jNew + jPos];
		}
	}
	//printMatrix(newM, size_m);
}

double Matrix::getDeterminant(double** ptrM, size_t size_m)
{
	size_t j = 0,
		size_newM = size_m - 1;
	int sign = 1;
	double dValue = 0;
	double **newM;

	newM = new double* [size_newM];
	for (size_t i = 0; i < size_newM; i++)
	{
		newM[i] = new double[size_newM];
	}

	if (size_m == 1)
	{
		return ptrM[0][0];
	}
	if (size_m == 2)
	{
		return ptrM[0][0] * ptrM[1][1] - ptrM[1][0] * ptrM[0][1];
	}
	if (size_m > 2)
	{
		for (size_t i = 0; i < size_m; i++)
		{
			getMatrix(ptrM, newM, i, size_newM);
			dValue += sign * (ptrM[i][j]) * getDeterminant(newM, size_newM);
			
			sign = -sign;
		}
		clearMatrix(newM, size_newM);
	}
	det.d = dValue;
	return det.d;
}

void Matrix::clearMatrix(double** ptrM, size_t size_m)
{
	for (size_t i = 0; i < size_m; i++)
	{
		delete[] ptrM[i];
	}
	delete[] ptrM;
	ptrM = nullptr;
}

Matrix::~Matrix()
{
	clearMatrix(det.ptrM, size_m);
}