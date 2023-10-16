#include <iostream>
#include <cstdlib>
using namespace std;

void stot(int tab[], string s, int n);
void multiplyByTwo(int tab[], int index, int n);
void print(int tab[], int n);

int main()
{
    const int n = 100;
    int tab[n] = {0};
    string s = "2";

    stot(tab, s, n);
    multiplyByTwo(tab, 100, n);
    print(tab, n);

    return 0;
}

void stot(int tab[], string s, int n){
    int l = s.length();
    string l1;
    for (int i = 0; i < l; i++){
        l1 = s[l - 1 - i];
        tab[i] = atoi(l1.c_str());
    }
}

void multiplyByTwo(int tab[], int index, int n){
    int nextNumber = 0;
    int carry = 0;

    for (int p = 0; p < index - 1; p++)
        for (int i = n - 1; i >= 0; i--){
            carry = (tab[i] * 2);
            nextNumber = carry / 10;
            tab[i] = carry % 10;
            tab[i + 1] += nextNumber;
        }
}

void print(int tab[], int n){
    int firstNumberOn = 0;
    for (int i = n - 1; i >= 0; i--){
        if (tab[i] != 0) firstNumberOn = true;
        if (firstNumberOn) cout << tab[i];
    }
}
