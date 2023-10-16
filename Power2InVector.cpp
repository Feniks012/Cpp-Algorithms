#include <iostream>
#include <vector>    
using namespace std;

void times2(vector <int> &power, int number, int ToWhich)
{
	int rest = 0;
	int cache = 0;
		int length = 0;
		int insert = 0;
	power.push_back(number);

	for(int i = 1; i < ToWhich; i++)
	{
		length = power.size();
		
		for(int j = length-1; j >= 0; j--)
		{
			
			cache = (power[j] * 2);
			rest = cache % 10;
			insert = cache / 10;
			if(j == length-1 && cache > 9){
			 power.push_back(insert);}
				if(j != length-1 && cache > 9){
				 power[j + 1] = power[j + 1] + (cache / 10);}
			power[j] = rest;
		
		};
		
	};
	 
}

void print(vector <int> &power)
{
	
	for(int i = power.size() - 1; i >= 0; i--) cout << power[i];
}

int main() 
{
setlocale(LC_ALL,"");
int number = 2;
int ToWhich = 100;
vector <int> power;
times2(power, number, ToWhich);
print(power);

return 0;
}
