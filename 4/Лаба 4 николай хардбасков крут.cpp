#include <iostream> // ����������� �������� ���������� ��� ������ �������� �������
#include <string.h> // ����������� ���������� ��� ��������� ���� �����
using namespace std; // ������������� ����������� ������������ ���� ��� �������� �����������
void main() // ������� ������� �������� ���������
{
	struct price//  �������� ���������, ������ �� ������
	{
		char tovar[50]; //  �������� ������� ���� char
		char mag[50];//  �������� ������� ���� char
		double stoim;//  �������� ������� ���� double
	} *prises; //  �������� ��������� ��� ���������
	int i, n, count = 0; //���������� ���������� ��������, ������� ������� �������� � �����
	char magaz[50];//���������� �������������� ���������� ��� ������ ��������
	cout << "vvedite dlinu massiva structur:";
	cin >> n;//���� ������ ������� ���������
	prises = new struct price[n];//�������� ������� ��������

	for (i = 0; i < n; i++)//���� ����� ������� ���������
	{
		cout << "vvedite imya tovara v price " << i << ": ";
		cin >> prises[i].tovar;
		cout << "vvedite imya magazina v price " << i << ": ";
		cin >> prises[i].mag;
		cout << "vvedite stoimost tovara v price " << i << ": ";
		cin >> prises[i].stoim;
	}
	cout << "vvedite imya magazina, v kotorom vi hotite uznat inf. o tovarah: ";
	cin >> magaz;//���� �������������� ��� ������ ��������
	cout << "magazine " << magaz << ":" << endl;
	for (i = 0; i < n; i++) //���� � ������� ������� � ��������
	{
		if (!strcmp(magaz, prises[i].mag))
		{
			count = count + 1;
			cout << prises[i].tovar << " stoit " << prises[i].stoim << endl;
		}
	}
	if (count == 0)//������ ��������� ��� ��������� ������� ��������
	{
		cout << "Dannogo magazina ne sushestvuet v baze dannyh";
	}




	delete[] prises;//�������� ������ �� ������� ��������
}
