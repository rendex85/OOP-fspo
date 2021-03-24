#include <iostream> // ����������� �������� ���������� ��� ������ �������� �������
#include <string>
using namespace std; // ������������� ����������� ������������ ���� ��� �������� �����������

struct Single_List {//��������� ������
	string name;
	int pos;
	Single_List *Next; //�������� ����
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
		//�������� ������ ��� ����� �������
		cout << "Vedite imya machini ";
		cin >> (*Head)-> name;
		(*Head)->pos = iter;
		//������ �������� ��������������� ����
		(*Head)->Next = NULL;//��������� ��������� ����
		Make_Single_List(n - 1, &((*Head)->Next), iter+1);
	}
}
void Print_Single_List(Single_List* Head) {
	if (Head != NULL) {
		cout<<"|Name: " << Head->name <<", Position: " << Head->pos << "|\t";
		Print_Single_List(Head->Next);
		//������� � ���������� ��������
	}
	else cout << "\n";
}
void changeFluz (Single_List* Head, int iter) {
	
	if (Head != NULL) {
		Head->pos = iter;
		cout << "|Name: " << Head->name << ", Position: " << Head->pos << "|\t";
		changeFluz(Head->Next, iter + 1);
		//������� � ���������� ��������
	}
}
void changeMinas(Single_List* Head, int iter)
{
	if (Head != NULL) {
		Head->pos = iter;
		cout << "|Name: " << Head->name << ", Position: " << Head->pos << "|\t";
		changeMinas(Head->Next, iter + 1 );
		//������� � ���������� ��������
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
			//��������� ����� ������� �� ������ �����
			NewItem->Next = Current;
			Head = NewItem;
			;
		}
		else {//��������� ����� ������� �� �������� �����
			if (Current->Next != NULL)
			{
				NewItem->Next = Current->Next;
			}
			Current->Next = NewItem;
		}
	
		
	
	
	return Head;
}

Single_List* Delete_Item_Single_List(Single_List* Head, int Number) {
	Single_List *ptr;//��������������� ���������
	Single_List *Current = Head;
	for (int i = 1; i < Number && Current != NULL; i++)
	{
		Current = Current->Next;
	}
	if (Current != NULL) {//�������� �� ������������
		if (Current == Head) {//������� ������ �������
			Head = Head->Next;
			delete(Current);
			Current = Head;
		}
		else {//������� �������� �������
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


