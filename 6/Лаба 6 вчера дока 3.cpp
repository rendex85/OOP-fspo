#include <iostream> // подключение основной библиотеки для работы основных функций
#include <string>
using namespace std; // использование постоянного пространства имен для удобного пользования

struct Single_List {//структура данных
	string name;
	int pos;
	Single_List *Next; //адресное поле
};
Single_List *Head;
void Make_Single_List(int n, Single_List** Head, int iter);
void Print_Single_List(Single_List* Head);
Single_List* Insert_Item_Single_List(Single_List* Head, int Number,  int DataItem);
void Delete_Single_List(Single_List* Head);
void changeFluz(Single_List* Head, int iter);
Single_List* Delete_Item_Single_List(Single_List* Head, int Number);
void changeMinas(Single_List* Head, int iter);


int main()
{
	int n, num, iter=1;


	
	cout << "vvedite kol-vo mashin an avtosotyanke";
	cin >> n;
	cin >> num;
	Make_Single_List(n, &Head, iter);
	Print_Single_List(Head);
	*Head = *Insert_Item_Single_List(Head, num, num);
	changeFluz(Head, iter);
	/*cout << "\n";
	cin >> num;
	*Head = *Delete_Item_Single_List(Head,num);
	changeMinas(Head,iter);
	cout << "\n";
	Delete_Single_List(Head);*/



}


void Make_Single_List(int n, Single_List** Head,int iter) {
	if (n > 0) {
		(*Head) = new Single_List();
		//выделяем память под новый элемент
		cout << "Vedite imya machini ";
		cin >> (*Head)-> name;
		(*Head)->pos = iter;
		//вводим значение информационного поля
		(*Head)->Next = NULL;//обнуление адресного поля
		Make_Single_List(n - 1, &((*Head)->Next), iter+1);
	}
}
void Print_Single_List(Single_List* Head) {
	if (Head != NULL) {
		cout<<"|Name: " << Head->name <<", Position: " << Head->pos << "|\t";
		Print_Single_List(Head->Next);
		//переход к следующему элементу
	}
	else cout << "\n";
}
void changeFluz (Single_List* Head, int iter) {
	
	if (Head != NULL) {
		Head->pos = iter;
		cout << "|Name: " << Head->name << ", Position: " << Head->pos << "|\t";
		changeFluz(Head->Next, iter + 1);
		//переход к следующему элементу
	}
}
void changeMinas(Single_List* Head, int iter)
{
	if (Head != NULL) {
		Head->pos = iter;
		cout << "|Name: " << Head->name << ", Position: " << Head->pos << "|\t";
		changeMinas(Head->Next, iter + 1 );
		//переход к следующему элементу
	}
}

void Delete_Single_List(Single_List* Head) {
	if (Head != NULL) {
		Delete_Single_List(Head->Next);
		delete Head;
	}
}

Single_List* Insert_Item_Single_List(Single_List* Head,int Number, int DataItem) 
{
	Number--;
	string name_;
	Single_List *NewItem = new(Single_List);
	cout << "mat";
	cin >> name_;
	NewItem->name = name_;
	NewItem->pos = DataItem;
	NewItem->Next = NULL;
		Single_List *Current = Head;
		for (int i = 1; i < Number && Current->Next != NULL; i++)
		{
			Current = Current->Next;
		}
		if (Number == 0) {
			//вставляем новый элемент на первое место
			NewItem->Next = Current;
			Head = NewItem;
			;
		}
		else {//вставляем новый элемент на непервое место
			if (Current->Next != NULL)
			{
				NewItem->Next = Current->Next;
			}
			Current->Next = NewItem;
		}
	
		
	
	
	return Head;
}

Single_List* Delete_Item_Single_List(Single_List* Head, int Number) {
	Single_List *ptr;//вспомогательный указатель
	Single_List *Current = Head;
	for (int i = 1; i < Number && Current != NULL; i++)
	{
		Current = Current->Next;
	}
	if (Current != NULL) {//проверка на корректность
		if (Current == Head) {//удаляем первый элемент
			Head = Head->Next;
			delete(Current);
			Current = Head;
		}
		else {//удаляем непервый элемент
			ptr = Head;
			while (ptr->Next != Current)
			{
				ptr = ptr->Next;
			}
			ptr->Next = Current->Next;
			delete(Current);
			Current = ptr;
		}
	}
	return Head;
}


