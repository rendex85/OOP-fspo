#include <iostream> // подключение основной библиотеки для работы основных функций
#include <string>
using namespace std; // использование постоянного пространства имен для удобного пользования

struct Single_List{//структура данных
					int Data; //информационное поле
					Single_List *Next; //адресное поле
};

Single_List *Head;

void Make_Single_List(int n, Single_List** Head) {
	
	if (n > 0) {
		(*Head) = new Single_List();
		//выделяем память под новый элемент
		cout << "Enter prikop";
		cin >> (*Head)->Data;
		//вводим значение информационного поля
		(*Head)->Next = NULL;//обнуление адресного поля
		Make_Single_List(n - 1, &((*Head)->Next));
	}
}

void Print_Single_List(Single_List* Head) {
	
	if (Head != NULL) {
		cout << Head->Data << "\t";
		Print_Single_List(Head->Next);
		//переход к следующему элементу
	}
	else cout << "\n";
}

Single_List* Insert_Item_Single_List(Single_List* Head,
	int Number, int DataItem) {
	Number--;
	Single_List *NewItem = new(Single_List);
	NewItem->Data = DataItem;
	NewItem->Next = NULL;
	if (Head == NULL) {//список пуст
		Head = NewItem;//создаем первый элемент списка
	}
	else {//список не пуст
		Single_List *Current = Head;
		for (int i = 1; i < Number && Current->Next != NULL; i++)
			Current = Current->Next;
		if (Number == 0) {
			//вставляем новый элемент на первое место
			NewItem->Next = Head;
			Head = NewItem;
		}
		else {//вставляем новый элемент на непервое место
			if (Current->Next != NULL)
				NewItem->Next = Current->Next;
			Current->Next = NewItem;
		}
	}
	return Head;
}

Single_List* Delete_Item_Single_List(Single_List* Head,
	int Number) {
	Single_List *ptr;//вспомогательный указатель
	Single_List *Current = Head;
	for (int i = 1; i < Number && Current != NULL; i++)
		Current = Current->Next;
	if (Current != NULL) {//проверка на корректность
		if (Current == Head) {//удаляем первый элемент
			Head = Head->Next;
			delete(Current);
			Current = Head;
		}
		else {//удаляем непервый элемент
			ptr = Head;
			while (ptr->Next != Current)
				ptr = ptr->Next;
			ptr->Next = Current->Next;
			delete(Current);
			Current = ptr;
		}
	}
	return Head;
}

void Delete_Single_List(Single_List* Head) {
	if (Head != NULL) {
		Delete_Single_List(Head->Next);
		delete Head;
	}
}


int main()
{
	int n, num, iter=1;


	
	cout << "vvedite kol-vo mashin an avtosotyanke";
	cin >> n;
	cout << "Ins";
	cin >> num;
	Make_Single_List(n, &Head);
	Print_Single_List(Head);
	Head = Insert_Item_Single_List(Head, num, 1488);
	Print_Single_List(Head);


}


