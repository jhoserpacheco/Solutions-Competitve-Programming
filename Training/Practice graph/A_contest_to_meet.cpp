/********************************************************************
 * Ejercicio: A Contest To Meet - A                                 *
 * Url: https://uva.onlinejudge.org/external/132/13249.pdf          *
 * Lenguaje: C++                                                    *
 * Autor: Jhoser Pacheco                                            *
 * Comentarios: Maraton nacional de Colombia 2017                   *
 *******************************************************************/

#include <bits/stdc++.h>
 
using namespace std;
 
#define INF (1<<2)
 
const int MAX = 105; //Cantidad maxima de nodos
int g[MAX][MAX]; //Matriz de adyacencia
int N, M; //Cantidad de nodos y aristas
 
void floydWarshall() {
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}
 
void init() {
    memset(g,INF,sizeof(g));
}
 
int main() {
	while(cin>>N>>M){
		init();
		 for (int i = 0; i < N; i++)
            g[i][i] = 0;
 
 
		for(int i =0;i<M;i++){
			int x,y,d;
			cin>>x>>y>>d;
			g[x][y] = g[y][x] = d;
		}
		floydWarshall();
		int rta=0;
		for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                rta = max(rta, g[i][j]);
 
        int va,vb,vc,s;       
        cin>>va>>vb>>vc;
        va = min(va,min(vb,vc));
        cout<<ceil((rta-1)/(va+1))+1<<endl;
	}
	return 0;
}