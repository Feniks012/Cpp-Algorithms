#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

struct Human
{
	string name;
	string surname;
	short age;
	string phone;
};
short HowManyPeople;
Human people[20];

void RequireEnter()
{
	cout << "Require enter for continue" << endl;
	while(getch() != 13);
};

void AddUser()
{
	cout << "Give name: ";
	cin >> people[HowManyPeople].name;
	
	cout << "Give surname: ";
	cin >> people[HowManyPeople].surname;
	
	cout << "Give age: ";
	cin >> people[HowManyPeople].age;
	
	cout << "Give phone number: ";
	cin >> people[HowManyPeople].phone;
	
	
	HowManyPeople++;
};

void ShowPeople()
{
	if(HowManyPeople > 0)
	{
		for(int i = 0; i < HowManyPeople; i++)
		{
			cout << "Person nr: " << (i+1) << endl;
			cout << "Name: " << people[i].name << endl;
			cout << "Surname: " << people[i].surname << endl;
			cout << "Age: " << people[i].age << endl;
			cout << "Phone: " << people[i].phone << endl << endl;
		}
	}else cout << "Database is empty" << endl;
};

void SaveUser()
{
	ofstream file("base.txt");
	if(file.is_open())
	{
		file << HowManyPeople << endl;
		for(int i = 0; i < HowManyPeople; i++)
		{
			
			file << people[i].name << endl;
			file << people[i].surname << endl;
			file << people[i].age << endl;
			file << people[i].phone << endl;
		}
		file.close();
		cout << "Users save" << endl;
	}else cout << "Save ERROR" << endl;
};

void ReadUser()
{
	ifstream file("base.txt");
	if(file.is_open())
	{
		file >> HowManyPeople;
		for(int i = 0; i < HowManyPeople; i++)
		{
			
			file >> people[i].name; 
			file >> people[i].surname; 
			file >> people[i].age;
			file >> people[i].phone;
		}
		file.close();
		cout << "Users upload" << endl;
	}else cout << "Failed to open file" << endl;
}


void SearchUser()
{
	if(HowManyPeople != 0)
	{
		string name;
		cout << "Give name: ";
		cin >> name;
		
		for(int j = 0; j < HowManyPeople; j++)
		{
			if(name == people[j].name)
			{
				cout << "Person nr: " << (j+1) << endl;
				cout << "Name: " << people[j].name << endl;
				cout << "Surname: " << people[j].surname << endl;
				cout << "Age: " << people[j].age << endl;
				cout << "Phone: " << people[j].phone << endl << endl;
			}
		}
	}else cout << "Database is empty" <<endl;
}

void DeleteUser()
{
	if(HowManyPeople != 0)
	{
		short index;
		cout << "Give index person to delete" ;
		cin >> index;
		for(short k = index; k < HowManyPeople; k++)
		{
		
			people[k-1].name == people[k].name;
			people[k-1].surname == people[k].surname;
			people[k-1].age  == people[k].age;
			people[k-1].phone == people[k].phone;
		}
		HowManyPeople--;
		
		cout << "User with index:" << index << "has been removed";
	}else cout << "Database is empty" <<endl;
}

int main()
{
	
	char test;
	
	do{
		cout << "People in base: " << HowManyPeople << endl;
		cout << "Menu" << endl;
		cout << "1. Add user" << endl;
		cout << "2. Show users" << endl;
		cout << "3. Save users to file" << endl;
		cout << "4. Read users from a file" << endl;
		cout << "5. Search database" << endl;
		cout << "6. Delete user" << endl;
		
		test = getch();
		
		switch(test)
		{
			case '1':
				AddUser();
			break;
			
			case '2':
				ShowPeople();
			break;
			
			case '3':
				SaveUser();
			break;
			
			case '4':
				ReadUser();
			break;
			
			case '5':
				SearchUser();
			break;
			
			case '6':
				DeleteUser();
			break;
		
		}
		RequireEnter();
		system("cls");
	}while(test != 27);
	
	
	return 0;
}
