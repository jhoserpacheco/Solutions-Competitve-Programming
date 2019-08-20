/********************************************************************
 * Ejercicio:  El sueño del emperador                               *
 * Url: http://trainingcenter.ufps.edu.co/problemas/71/detalle/es   *
 * Lenguaje: C++                                                    *
 * Autor: Jhoser Pacheco                                            *
 * Comentarios: Plataforma del semillero - TrainingCenter           *
 *******************************************************************/

#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
 
const int MAX = 200; //Cantidad maxima de nodos
vector<int> g[MAX]; //Lista de adyacencia
bitset<MAX> vis; //Marca los nodos ya visitados
int n, m, numCC; //Cantidad de nodos y aristas
 
void dfs(int u) {
    vis[u] = true;
    for (auto v : g[u]) {
        if (!vis[v]) {
        	dfs(v);
        }
    }
}
 
void init() {
    for(int i = 0; i <= n; i++) {
        g[i].clear();
        vis[i] = false;
    }
}
 
int main() {
	int casos; cin>>casos;
	while(casos--){
		numCC=0;
		init();
		cin>>n>>m;
 
		for(int i =0;i<m;i++){
			int v,e;
			cin>>v>>e;
			g[v].pb(e);
			g[e].pb(v);
		}
		dfs(0);
		for(int i=1; i <=n; i++){
            if(!vis[i]){
                numCC++;
                dfs(i);
            }
        }
        if(numCC==1)  cout<<"El sueno del emperador se ha cumplido\n";
        else
        cout<<"El sueno del emperador se ha roto en "<<numCC<<" partes\n";
	}
	return 0;
}