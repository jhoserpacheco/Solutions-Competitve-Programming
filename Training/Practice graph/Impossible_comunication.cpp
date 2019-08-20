/********************************************************************
 * Ejercicio: Impossible Communication - I                          *
 * Url: https://uva.onlinejudge.org/contests/384-1338eeb6/13301.pdf *
 * Lenguaje: C++                                                    *
 * Autor: Jhoser Pacheco                                            *
 * Comentarios: Maraton nacional de Colombia 2018                   *
 *******************************************************************/

#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back 
#define popb pop_back 
#define endl '\n'
 
int v, e; 
const int MAX = 1000; // Maxima cantidad de nodos
int dfs_low[MAX];
int dfs_num[MAX];
bool marked[MAX];
vector<int> s;
int dfsCont, cantSCC;
vector<int> ady[MAX];
 
void tarjanSCC(int u){
	dfs_low[u] = dfs_num[u] = dfsCont;
	dfsCont++;
	s.pb(u);
	marked[u] = true;
 
	int j, v;
 
	for(j = 0; j < ady[u].size(); j++){
		v = ady[u][j];
 
		if(dfs_num[v] == -1){
			tarjanSCC(v);
		}
 
		if(marked[v]){
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
	}
 
	if( dfs_low[u] == dfs_num[u] ){
		cantSCC++;
        /* ********************************************************* */
        /* Esta seccion se usa para imprimir las componentes conexas */
		//cout << "COMPONENTE CONEXA #" << cantSCC << "\n";
		while(true){
			v = s.back();
			s.pop_back();
			marked[v] = false;
			//cout << v << ",";
			if(u == v) {
				//cout << "\n";
				break;
 
			}
		}/*
        /* ********************************************************** */
	}	
}
void init() {
 
	for(int i = 0; i <= v; i++) {
        ady[i].clear();
        dfs_low[i]=0;
        dfs_num[i]=-1;
        marked[i]=false;
	}
}
 
int main (){
    while(cin>>v>>e){
    	if (v+e==0) break;
    	init();
	    long str2,str3,str4;
	    for(int i = 0;i<e;i++){
	    	cin>>str2;
	    	if(str2==1){
	    	cin>>str3>>str4;
	    	ady[str3-1].pb(str4-1);
			}else{
				long vec[str2];
				for(int i =0;i<str2;i++)
					cin>>vec[i];
				for(int i =0;i<str2-1;i++){	
					//cout<<str3<<" "<<str4<<endl;
					ady[vec[i]-1].pb(vec[i+1]-1);
					ady[vec[i+1]-1].pb(vec[i]-1);
				}
 
			}
 
	    }
	    int aux = dfsCont =cantSCC = 0;
        s.clear();
 	    for(int i = 0; i < v; i++){ //Por si el grafo no es conexo
	         if(dfs_num[i] == -1){
	         //	cout<<"entre1\n";
            	tarjanSCC(i); 
        	}
	    }  
 
	    if(cantSCC==1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
    }
}