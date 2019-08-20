/********************************************************************
 * Ejercicio: Bicoloring                                            *
 * Url: https://uva.onlinejudge.org/external/100/10004.pdf          *
 * Lenguaje: C++                                                    *
 * Autor: Jhoser Pacheco                                            *
 *******************************************************************/

#include <bits/stdc++.h>
 
#define ll long long 
#define endl '\n'
#define pb push_back
 
using namespace std;
 
int v, e; //vertices, arcos
const int MAX=100005; //Cantidad maxima de nodos del grafo
vector<int> ady[MAX]; //lista de Adyacencia del grafo
int color[MAX]; //Estructura auxiliar para almacenar la distancia a cada nodo.
bool bipartite;
 
/*Este metodo se llama con el indice del nodo desde el que se desea comenzar
el recorrido.*/
 
void bfs(int s){
  queue<int> q;
  q.push(s);
  color[s] = 0;
  int actual, i, next;
 
  while(q.size() > 0){
    actual = q.front();
    q.pop();
 
    for( i = 0; i < ady[actual].size(); i++){
      next = ady[actual][i];
      if(color[next] == -1 ){
        color[next] = 1 - color[actual];
        q.push(next);
      }else if(color[next] == color[actual] ){
        bipartite = false;
        return;
      }
    }
  }
  bipartite = true;
 
}
 
int main() {
	int nodes,aux; 
	while(cin>>nodes,nodes!=0){
		int ar; cin>>ar;
		memset(color,-1,sizeof(color));
		for(int i =0;i<nodes;i++) ady[i].clear();
		for(int i =0;i<ar;i++){
			cin>>v;cin>>e;	
			ady[v].pb(e);
			ady[e].pb(v);
		}
		bfs(0);
		if(bipartite) cout<<"BICOLORABLE.\n";
			else cout<<"NOT BICOLORABLE.\n";
 
 
	}
 
	return 0;
}