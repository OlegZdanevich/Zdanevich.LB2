#include <iostream>

using namespace std;


double** Difference(double**, double**, int);
double CosMy(double, double);
double MaxElement(double**, int);
inline double** AllocMatrix(int);
inline double MaxElement(double*, int);
inline double PeriodDown(double);
void FillMatrixMyFunction(double**, int, double);
void FillMatrixNotMyFunction(double**, int);
void DisplayMatrix(double**, int);
inline void ClearMemory(double**, int);


double pi = 3.14159265359;



int main()
{

	while (true)
	{
		cout.width(50);
		cout << endl << "Welcome to the programm!";
		cout << endl << endl << "*******************************************************************************" << endl << endl;
		cout << "Enter the n: ";
		int n;
		cin >> n;
		double **a = AllocMatrix(n);
		cout << "Enter the epsilon: ";
		double eps;
		cin >> eps;
		system("cls");
		FillMatrixMyFunction(a, n, eps);
		cout << endl << "With my function" << endl << endl;
		DisplayMatrix(a, n);
		cout << endl << endl << "*******************************************************************************" << endl << endl;
		cout << endl << "Without my function" << endl << endl;
		double **b = AllocMatrix(n);
		FillMatrixNotMyFunction(b, n);
		DisplayMatrix(b, n);
		cout << endl << endl << "*******************************************************************************" << endl << endl;
		cout << endl << "difference" << endl << endl;
		double **c = Difference(a, b, n);
		DisplayMatrix(c, n);
		cout << endl << endl << "*******************************************************************************" << endl << endl;
		double max = MaxElement(c, n);
		cout << "Maximum element in matrix= " << max << endl;
		cout << "Ebsilon= " << eps << endl;
		cout << endl;
		system("pause");
		system("cls");
		ClearMemory(a, n);
		ClearMemory(b, n);
		ClearMemory(c, n);
		char s;
		cout << "Would you like to countinie? " << endl;
		cout << "Yes- y or Y " << endl;
		cout << "No- other symbols" << endl;
		cout << "Waiting for Enter: " << endl;
		cin >> s;
		system("cls");
		if (s == 'y' || s == 'Y') continue;
		break;

	}

	return 0;
}



double** Difference(double**a, double**b, int n)
{
	double **c = AllocMatrix(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c[i][j] = fabs(a[i][j] - b[i][j]);
		}
	}
	return c;
}

double CosMy(double x, double eps)
{
	double sum = 0;
	double an = 1;
	int n = 0;
	while (fabs(an)>eps)
	{
		sum += an;
		n++;
		an *= -x*x / (2 * n - 1) / (2 * n);
	}
	return sum;
}

double MaxElement(double**matr, int n)
{
	double max = MaxElement(matr[0], n);
	for (int i = 1; i < n; i++)
	{
		double strmax = MaxElement(matr[i], n);
		if (strmax>max) max = strmax;
	}
	return max;
}

inline double** AllocMatrix(int n)
{
	double**a = new double*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}
	return a;
}


inline double MaxElement(double*arr, int n)
{
	double max = arr[0];
	for (int j = 1; j < n; j++)
	{
		if (arr[j]>max) max = arr[j];
	}
	return max;
}

inline double PeriodDown(double rad)
{
	while (rad > pi) rad -= 2* pi;
	return rad;
}

void FillMatrixMyFunction(double **a, int n, double eps)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j != i)
			{
				a[i][j] = (pow(i + j+2, 2) - CosMy(PeriodDown(2*i+2), eps) + CosMy(PeriodDown(2 * j+2), eps)) / (CosMy(PeriodDown(i+j+2), eps) + pow(i + 2, 2));
			}
			else a[i][j] = 2 * i;
		}
	}
}

void FillMatrixNotMyFunction(double**b, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j != i)
			{
				b[i][j] = (pow(i + j+2, 2) - cos(2 * i+2) + cos(2 * j+2)) / (cos(i + j+2) + pow(i + 2, 2));
			}
			else b[i][j] = 2 * i;
		}
	}
}




void DisplayMatrix(double** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(20);
			cout << a[i][j];
		}
		cout << endl;
	}
}

inline void ClearMemory(double**a, int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] a[i];
	}
	delete[] a;
}
