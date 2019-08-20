/***********************************************************************************************
 * Ejercicio: Place the Guards                                                                 *
 * Url: https://uva.onlinejudge.org/external/110/11080.pdf                                     *
 * Lenguaje: C++                                                                               *
 * Autor: Jhoser Pacheco                                                                       *
 **********************************************************************************************/

#include <bits/stdc++.h>
 
#define endl '\n'
#define pb push_back
 
using namespace std;
 
int v, e; //vertices, arcos
const int MAX=500; //Cantidad maxima de nodos del grafo
vector<int> ady[MAX]; //lista de Adyacencia del grafo
int color[MAX]; //Estructura auxiliar para almacenar la distancia a cada nodo.
bool bipartite;
 
/*Este metodo se llama con el indice del nodo desde el que se desea comenzar
el recorrido.*/
 
int bfs(int s){
  queue<int> q;
  q.push(s);
  color[s] = 1;
  int guardias[2]{0,1};
  int actual, i, next;
  while(q.size()){
    actual = q.front();
    q.pop();
    for( i = 0; i < ady[actual].size(); i++){
      next = ady[actual][i];
      if(color[next] == -1){
        color[next] = 1 - color[actual];
        if(color[next]==1) guardias[1]++;
        else if(color[next]== 0) guardias[0]++;
        q.push(next);	
      }else if(color[next] == color[actual]){
        bipartite = false;
    	return -1;	
      }
    }
  }
  bipartite=true;
  if(guardias[0] == 0) return  guardias[1];
    else return  min(guardias[1],guardias[0]);
 
}
 
int main() {
	int casos,aux;
	cin>>casos;
	while(casos--){
		cin>>v>>e;
		for(int i =0;i<v;i++) ady[i].clear();
		memset(color,-1,sizeof(color));
		for(int i =0;i<e;i++){
			int una,calle; cin>>una>>calle;
			ady[una].pb(calle);
			ady[calle].pb(una);
		}
		int despuesDeDosHoras=0;
		bool salir = false;
		for(int i =0;i<v and !salir;i++) { 
			if(color[i]==-1){ 
			int	estaDificil = bfs(i);
				if(estaDificil==-1){
					despuesDeDosHoras = -1;
					salir=true;
				}else	despuesDeDosHoras+=estaDificil;
 
			}
		}
		cout<<despuesDeDosHoras<<endl;
		//Me voy a dormir, adios :D
	}
	return 0;
}