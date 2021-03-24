#include <iostream> // подключение основной библиотеки дл¤ работы основных функций
#include <string> //
using namespace std; // 
void main() // 
{
	int len,cheku,count=0,iter;
	string mat;
	getline(cin, mat);
	len = mat.length();
	cheku = len % 2;
	if (cheku == 0)
	{
		cout << "please enter correct string";
	}
	else
	{
		cheku = len / 2;
		cout << "mat rebenka utopila"<<endl;
		for (int i = 0; i < cheku;i++)
		{
			if (mat[i] == mat[len - i - 1])
			{
				count += 1;

			}
			else
			{
				if (count >= 3)
				{
					mat[i] = ' ';
					mat[len - i - 1] = ' ';
					count = 0;
				}
				else
				{
					mat[i] = ' ';
					mat[len - i - 1] = ' ';
					for (int j = 0; j < count;j++)
					{
						iter = i - count;
						mat[iter] = ' ';
						mat[len-iter-1] = ' ';
						iter++;
					}
					count = 0;
				}
				
			}
		}
		cout << mat;
	}
	
}
