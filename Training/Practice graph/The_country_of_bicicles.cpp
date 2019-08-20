/**********************************************************************
 * Ejercicio: The Country of Bicycles                                 *
 * Url: https://www.urionlinejudge.com.br/judge/en/problems/view/1454 *
 * Lenguaje: C++                                                      *
 * Autor: Jhoser Pacheco                                              *
 *********************************************************************/

#include <bits/stdc++.h>
 
using namespace std;
 
#define INF (1<<30)
 
const int MAX = 103; //Cantidad maxima de nodos
int g[MAX][MAX]; //Matriz de adyacencia
int N, M; //Cantidad de nodos y aristas
 
void floydWarshall() {
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                //g[i][j] = max(g[i][j], g[i][k] + g[k][j]);
                if(g[i][j] > max(g[i][k], g[k][j]))
                   g[i][j] = max(g[i][k], g[k][j]);
 
 
}
 
void init() {
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            g[i][j] = INF;
        }
    }
}
 
int main() {
	int casos=1;
	while(cin>>N>>M){
		if(N+M==0) break;
		init();
		for(int i=0;i<M;i++){
			int v,e,w;
			cin>>v>>e>>w;
			g[v][e]=w;
			g[e][v]=w;
		}
		floydWarshall();
		int q;cin>>q;
		cout<<"Instancia "<<casos++<<endl;
		for(int i =0;i<q;i++){
			int x,y;
			cin>>x>>y;
			if(x==y) cout<<"0\n";
			else
			cout<<g[x][y]<<endl;
		}
		cout<<endl;
 
	}
	return 0;
}