/*************************************************************************************************************
 * Ejercicio: Trust Groups                                                                                   *
 * Url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2756 *
 * Lenguaje: C++                                                                                             *
 * Autor: Jhoser Pacheco                                                                                     *
 ************************************************************************************************************/

#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back 
#define popb pop_back 
#define endl '\n'
 
int v, e; 
const int MAX = 1000; // Máxima cantidad de nodos
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
		//	cout << v << "\n";
			if(u == v) break;
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
	map<string,int> mapa;
    while(cin>>v>>e){
 
    	if (v==0) break;
    	init();
	    for(int i =0;i<v;i++){
	    	string str,str2;
	    	cin>>str>>str2;
	    	mapa[str+str2]=i;
	    	//cout<<mapa[str]<<" ";
	    }
	    //cout<<"\n";	
	    string str2,str3;
	    for(int i = 0;i<e;i++){
	    	cin>>str2>>str3;
	    	string aux = str2+str3;
	    	cin>>str2>>str3;
	    	//cout<<str2<< " " <<str3<<endl;
	    	//cout<<mapa[str2]<<" "<<mapa[str3];
	    	ady[mapa[aux]].pb(mapa[str2+str3]);
	    }
	    int aux =0;
	    dfsCont = 0;
        s.clear();
        cantSCC=0;
	    for(int i = 0; i < v; i++){ //Por si el grafo no es conexo
	    	//cout<<"entre\n";
	         if(dfs_num[i] == -1){
	         //	cout<<"entre1\n";
            	tarjanSCC(i); 
        	}
	    }  
	    cout<<cantSCC<<endl;
 
    }
}