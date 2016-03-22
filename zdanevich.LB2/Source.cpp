#include <iostream>

using namespace std;

double** AllocMatrix(int );
double CosMy(double ,double);
double Sum(double**, int);
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
		DisplayMatrix(a, n);
		cout << endl << "With my function" << endl << endl;
		double **b = AllocMatrix(n);
		FillMatrixNotMyFunction(b,n);
		DisplayMatrix(b, n);
		cout << endl << "Without my function" << endl << endl;
		double sum1 = Sum(a, n);
		double sum2 = Sum(b, n);
		cout << "Sum of fist one " << sum1 << endl;
		cout << "Sum of second one " << sum2 << endl;
		system("pause");
		system("cls");
		ClearMemory(a, n);
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


double CosMy(double x, double eps)
{
	double sum = 0;
	double an = 1;
	int n=0;
	while (fabs(an)>eps)
	{
		sum += an;
		n++;
		an *= -x*x / (2*n - 1) / (2*n);
	}
	return sum;
}

double Sum(double**a, int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum += a[i][j];
		}
	}
	return sum;
}
void FillMatrixMyFunction(double **a, int n,double eps)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j != i)
			{
				a[i][j]=(pow(i + j, 2) - CosMy(2 * i, eps) + CosMy(2 * j, eps)) / (CosMy(i + j, eps) + pow(i + 1, 2));
			}
			else a[i][j] = 2*i;
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