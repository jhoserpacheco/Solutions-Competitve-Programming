/***********************************************************************************************
 * Ejercicio: Seasonal Wars                                                                    *
 * Url: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=288 *
 * Lenguaje: C++                                                                               *
 * Autor: Jhoser Pacheco                                                                       *
 **********************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int tam = 1000; //Tamanio maximo de la matriz
int dy[] = {1,1,0,-1,-1,-1, 0, 1}; //Posibles movimientos:
int dx[] = {0,1,1, 1, 0,-1,-1,-1}; //  (8 direcciones)
char grid[tam][tam]; //Matriz de caracteres
int Y, X; //Tamanio de la matriz
int cont=0;


int floodfill(int y, int x, char c1, char c2) {
    if (y < 0 || y >= Y || x < 0 || x >= X) return 0;
    if (grid[y][x] != c1) return 0;
    grid[y][x] = c2;
	int ans = 1;
    for (int i = 0; i < 8; i++) {
        ans += floodfill(y + dy[i], x + dx[i], c1, c2);
    }
    return ans;
}

int main() {
	int casos=1;
	while(cin>>Y){
		cont=0;
		X=Y;
		for(int i =0;i<Y;i++){
			for(int j =0;j<Y;j++){
				cin>>grid[i][j];
			}	
		}
		for(int i =0;i<Y;i++){
			for(int j =0;j<Y;j++){
				if(grid[i][j]=='1'){
					cont++;
					floodfill(i,j,'1','0');
					
				}
			}	
		}
		cout<<"Image number "<< casos++ <<" contains "<<cont<<" war eagles."<<endl;
		
	}
	return 0;
}