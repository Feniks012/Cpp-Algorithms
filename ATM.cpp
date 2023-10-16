#include <iostream>
#include <string>
using namespace std;
void change(int number)
{
	string s[]={"piêæset", "dwieœcie", "sto", "piêædziesi¹t", "dwadzieœcia", "dziesiêæ" ,"piêæ" ,"dwa", "jeden"};
	int C[]={500, 200, 100, 50, 20, 10, 5, 2, 1};
	for(int i = 0; i < 9; i++)
	{
		while(number >= C[i])
		{
			cout << s[i] << " ";
			number = number - C[i];
		}
	}
}	
	

int main()
{
	setlocale(LC_ALL,"");

int number = 847;
change(number);
}
