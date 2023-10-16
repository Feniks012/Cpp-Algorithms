#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int jump = 5;

string encription(string text)
{
	int temp;
	for(int i = 0; i < text.length(); i++)
	{
		temp = text[i] + jump;
		
		if((text[i] > 64) && (text[i] < 91))
		{
			if(temp < 65) 
				text[i] += (26 + jump);
			else if(temp > 90) 
				text[i] -= (26 - jump);
			else 
				text[i] += jump;
		}
		else if((text[i] > 96) && (text[i] < 123))
		{
			if(temp < 97) 
				text[i] += (26 + jump);
			else if(temp > 122) 
				text[i] -= (26 - jump);
			else 
				text[i] += jump;
		}
	}
	
	return text;
};

string description(string text)
{
	int temp;
	for(int i = 0; i < text.length(); i++)
	{
		temp = text[i] - jump;
		
		if((text[i] > 64) && (text[i] < 91))
		{
			if(temp < 65) 
				text[i] += (26 - jump);
			else if(temp > 90) 
				text[i] -= (26 + jump);
			else 
				text[i] -= jump;
		}
		else if((text[i] > 96) && (text[i] < 123))
		{
			if(temp < 97) 
				text[i] += (26 - jump);
			else if(temp > 122) 
				text[i] -= (26 + jump);
			else 
				text[i] -= jump;
		}
	}
	
	return text;
};



int main()
{
	string text ="";
	cout << "Give a message " << endl;
	getline(cin, text);
	
	cout << "Encription message: " << encription(text) << endl;
	cout << "Decription message: " << description(encription(text)) << endl;

	
	
	return 0;
}
