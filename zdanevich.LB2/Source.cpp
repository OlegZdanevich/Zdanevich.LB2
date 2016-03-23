#include <iostream>

using namespace std;

double** AllocMatrix(int);
double** Difference(double**, double**, int);
double CosMy(double, double);
void FillMatrixMyFunction(double**, int, double);
void FillMatrixNotMyFunction(double**, int);
void DisplayMatrix(double**, int);
void ClearMemory(double**, int);






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

double** AllocMatrix(int n)
{
	double**a = new double*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}
	return a;
}

double** Difference(double**a, double**b, int n)
{
	double **c = AllocMatrix(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c[i][j] = a[i][j] - b[i][j];
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


void FillMatrixMyFunction(double **a, int n, double eps)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j != i)
			{
				a[i][j] = (pow(i + j, 2) - CosMy(2 * i, eps) + CosMy(2 * j, eps)) / (CosMy(i + j, eps) + pow(i + 1, 2));
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
				b[i][j] = (pow(i + j, 2) - cos(2 * i) + cos(2 * j)) / (cos(i + j) + pow(i + 1, 2));
			}
			else b[i][j] = 2 * i;
		}
	}
}



void DisplayMatrix(double**a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
			if (j < n - 1) cout.width(20);
			if(i==j&& i==0)cout.width(32);
		}
		cout << endl;

	}
}

void ClearMemory(double**a, int m)
{
	for (int i = 0; i < m; i++)
	{

		delete[] a[i];
	}
	delete[] a;
}
