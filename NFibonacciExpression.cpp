#include <iostream>
using namespace std;

void fibonacci(int A[], int B[], int C[], int word, int n)
{
	A[0] = 1;
	B[0] = 1;
	
	int cache = 0;
	int rest = 0;
	bool flag;
	
	for(int i = 3; i <= word; i++)
	{
		for(int j = n-1; j >= 0; j--)
		{
			cache = A[j] + B[j];;
			C[j] = cache % 10;
			C[j+1] += cache / 10;
		}
		
		do
		{
			flag = false;
				for(int j = n-1; j >= 0; j--)
				{
					if(C[j] > 9)
					{
						flag = true;
						cache = C[j];
						C[j] = cache % 10;
						C[j+1] = C[j+1] + (cache / 10);
					}
				}
		}while(flag);
		
			for(int j = n-1; j >= 0; j--)
		{
			A[j] = B[j];
			B[j] = C[j];
			C[j] = 0;
		}
		
	}
}

void print(int B[], int n)
{
	int flag2 = false;
		for(int j = n-1; j >= 0; j--)
		{
			if(B[j] != 0) flag2 = true;
			if(flag2) cout << B[j];
		}
		
}

int main()
{
	setlocale(LC_ALL,"");
	int word = 100;
	int n = 200;
	int A[n] = {0};
	int B[n] = {0};
	int C[n] = {0};
	fibonacci(A, B, C, word, n);
	print(B, n);
	
	
	return 0;
}
