#include <iostream> // ����������� �������� ���������� ��� ������ �������� �������
#include <math.h> // ����������� ���������� ��� �������������� ����������
#include <limits> // ����������� ���������� ��� ������� ����������� ��������
using namespace std; // ������������� ����������� ������������ ���� ��� �������� �����������
void mas(float *& A, float *& W, int *n);//�������� ������� ������������� �������
void func(float *maxa, float *maxw, float *geoma, float *geomw, int *n, float *& A, float *& W, int *numba, int *numbw);//�������� ������� ���������� ������� �� ��������
void vivod(float *maxa, float *maxw, float *geoma, float *geomw, int *numba, int *numbw);//�������� ������� ������
void main()
{
	float *A, *W, maxa = numeric_limits<float>::min(), maxw = numeric_limits<float>::min(), geoma = 1, geomw = 1; //�������� ���� ���������� ��� ��������, ���������� ��� ���������� ������������� �������� � ���� ���������� ��� �������� ��������������� 
	int n = 0, numba, numbw; // ��������  ����������, �������� ����� ��������, � ���������� �������� ������� ������������� �������� ��������
	
	mas(A, W, &n); // ����� ������� ������������� �������
	func(&maxa, &maxw, &geoma, &geomw, &n, *&A, *&W, &numba, &numbw); //����� ������� ���������� ������� �� ��������
	vivod(&maxa, &maxw, &geoma, &geomw, &numba, &numbw); //����� ������� ������ ������

	delete[] A; //�������� ������ �� ������� �
	delete[] W; //�������� ������ �� ������� W
	

}
void mas(float *&A, float *&W, int *n)
{
	int i = 0;
	cout << "vvedite dlinu oboih massivov:";
	cin >> *n;
	A = new float[*n]; // �������� ������� �
	W = new float[*n]; // �������� ������� W
	for (int i = 0; i < *n; i++) // ���� ����� ������ �
	{
		cout << "Please enter A[" << i << "] number "; // ��������� � ����� i-���� ��������
		cin >> A[i]; // ������� i-���� ��������
	}
	for (int i = 0; i < *n; i++) // ���� ����� ������ W
	{
		cout << "Please enter W[" << i << "] number "; // ��������� � ����� i-���� ��������
		cin >> W[i]; // ������� i-���� ��������
	}
}
void func(float *maxa, float *maxw, float *geoma, float *geomw, int *n, float *& A, float *& W, int *numba, int *numbw)
{
	for (int i = 0; i < *n; i++) // ���� �� ������ ������������ ��������� � �� ��������
	{
		if (A[i] > *maxa) //������ ����������, �� ��������� � ���������� �� �� �������� �� ��� ��� ������
		{
			*maxa = A[i]; //������ ���������� �������� ������� � �� ������ ������ �������� 
			*numba = i;  // ������ ������ ����������� �������� ������� � �� ������ ������ �������� 

		}
		if (W[i] > *maxw) //������ ����������, �� ��������� � ���������� �� �� �������� �� ��� ��� ������
		{
			*maxw = W[i]; //������ ���������� �������� ������� W �� ������ ������ �������� 
			*numbw = i; // ������ ������ ����������� �������� ������� W �� ������ ������ �������� 

		}
	}


	for (int i = 0; i < *numba; i++) // ���� ��� ������������ ��������� �� ������������� � ������� �
	{
		*geoma = A[i] * *geoma; //��������� �������� ��� ������� i � ����� ������������� ���������
	}
	

	for (int i = 0; i < *numbw; i++) // ���� ��� ������������ ��������� �� ������������� � ������� W
	{
		*geomw = W[i] * *geomw; //��������� �������� ��� ������� i � ����� ������������� ���������
	}
}
void vivod(float *maxa, float *maxw, float *geoma, float *geomw, int *numba, int *numbw)
{
	cout << "Kol-vo el. v massive A do max. elementa :" << *numba << endl; // ����� ���������� ��������� �� ������������� � ������� �
	cout << "Kol-vo el. v massive W do max. elementa :" << *numbw << endl; // ����� ���������� ��������� �� ������������� � ������� W
	cout << "srednee geometricheskoe pervih " << *numba << "elementov v Massive A = " << pow(*geoma, float(1) / *numba) << endl; //��������� ���������� � ����� �������� ��������������� � ������� �
	cout << "srednee geometricheskoe pervih " << *numbw << "elementov v Massive W = " << pow(*geomw, float(1) / *numbw) << endl; //��������� ���������� � ����� �������� ��������������� � ������� W
}
