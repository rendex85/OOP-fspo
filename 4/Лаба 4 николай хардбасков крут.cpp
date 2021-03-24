#include <iostream> // подключение основной библиотеки дл€ работы основных функций
#include <string.h> // подключение библиотеки дл€ сравнени€ двух строк
using namespace std; // использование посто€нного пространства имен дл€ удобного пользовани€
void main() // главна€ область действи€ программы
{
	struct price//  создание структуры, данной по зданию
	{
		char tovar[50]; //  создание объекта типа char
		char mag[50];//  создание объекта типа char
		double stoim;//  создание объекта типа double
	} *prises; //  создание указател€ дл€ структуры
	int i, n, count = 0; //объ€вление переменных итерации, размера массива стукртур и счета
	char magaz[50];//объ€вление дополнительной переменной дл€ поиска магазина
	cout << "vvedite dlinu massiva structur:";
	cin >> n;//ввод длинны массива структуры
	prises = new struct price[n];//создание массива стуктуры

	for (i = 0; i < n; i++)//цикл ввода массива структуры
	{
		cout << "vvedite imya tovara v price " << i << ": ";
		cin >> prises[i].tovar;
		cout << "vvedite imya magazina v price " << i << ": ";
		cin >> prises[i].mag;
		cout << "vvedite stoimost tovara v price " << i << ": ";
		cin >> prises[i].stoim;
	}
	cout << "vvedite imya magazina, v kotorom vi hotite uznat inf. o tovarah: ";
	cin >> magaz;//ввод индетификатора дл€ поиска магазина
	cout << "magazine " << magaz << ":" << endl;
	for (i = 0; i < n; i++) //цикл с поиском товаров в магазине
	{
		if (!strcmp(magaz, prises[i].mag))
		{
			count = count + 1;
			cout << prises[i].tovar << " stoit " << prises[i].stoim << endl;
		}
	}
	if (count == 0)//выдача сообщени€ при отсутсвии нужного магазина
	{
		cout << "Dannogo magazina ne sushestvuet v baze dannyh";
	}




	delete[] prises;//очищение пам€ти от массива структур
}
