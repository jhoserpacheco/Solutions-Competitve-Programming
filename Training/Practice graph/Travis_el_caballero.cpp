/********************************************************************
 * Ejercicio: Travis el Caballero                                   *
 * Url: http://trainingcenter.ufps.edu.co/problemas/394/detalle/es  *
 * Lenguaje: C++                                                    *
 * Autor: Jhoser Pacheco                                            *
 * Comentarios: Plataforma del semilliero - Training Center         *
 *******************************************************************/

#include <bits/stdc++.h>
 
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define endl '\n';
 
using namespace std;
 
const int MAX = 505; //Cantidad maxima de nodos
vector<int> g[MAX]; //Lista de adyacencia
bitset<MAX> vis; //Marca los nodos ya visitados
int n, m; //Cantidad de nodos y aristas
int dist[MAX][MAX];
int N;
int dy[8]={2,1,-1,-2,-2,-1,1,2};
int dx[8]={1,2,2,1,-1,-2,-2,-1};
//int dx[8]= {2, 1, -1, -2, -2, -1,  1,  2 }; 
//int dy[8] = {1, 2,  2,  1, -1, -2, -2, -1}; 
 
void bfs(pii u) {
    queue<pii> q;
    q.push(u);
    dist[u.F][u.S] = 0;
    while (q.size()) {
        pii u = q.front();
        q.pop();
        for(int i =0;i<8;i++){
        	pii sig = {u.F+dx[i],u.S+dy[i]};
        	if(sig.S <0 ||sig.S>N || sig.F<0 ||sig.F>N) continue;
        	if(dist[sig.F][sig.S]!=-1) continue;
        	dist[sig.F][sig.S] = dist[u.F][u.S]+1;
        	q.push(sig);
        }
    }
}
 
void init() {
	memset(dist,-1,sizeof(dist));
}
 
int main() {
	while(cin>>N){
		init();
		int xT,yT,xJ,yJ;
		cin>>xT>>yT>>xJ>>yJ;
		bfs({xT,yT});
		cout<<dist[xJ][yJ]<<endl;
	}
	return 0;
}