#include <iostream> 
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std ;

const int N = 10;
void input(int T[N][N]){
srand(time(NULL));
for (int i = 0; i < N; i++)
for (int j = 0; j < N; j++)
T[i][j] = rand() % 10;
}
void calculate (int T[N][N], int G[N][N], int r){
    double add; 	
for (int rows = 0; rows < N; rows++){ 	
for (int cols = 0; cols < N; cols++){	
    add = 0;	
    for(int i = rows - r; i <= rows + r; i++){	
        for(int j = cols - r; j <= cols + r; j++) 
        {
            if(i >= 0 && j >= 0 && i < N && j < N){	
            add += T[i][j]; 
            }
        }
    }
    add = add / 9;
    add = round(add);
    
G[rows][cols] = add; 
}
}
}
void print(int G[N][N]){
    for (int i = 0; i < N; i++){
for (int j = 0; j < N; j++){
cout << setw(5) << G[i][j];
}
cout << endl;
}
cout << endl;
}
int main(){
int r = 1;
int T[N][N] = {0};
int G[N][N] = {0};
input(T);
print(T);
calculate(T, G, r);
print(G);
return 0;
}






 

