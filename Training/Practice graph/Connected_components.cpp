/**********************************************************************
 * Ejercicio: Connected Components                                    *
 * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1082 *
 * Lenguaje: C++                                                      *
 * Autor: Jhoser Pacheco                                              *
 *********************************************************************/

#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back 
#define popb pop_back 
#define endl '\n'
 
int v, e; 
const int MAX = 1000; // Mxima cantidad de nodos
int dfs_low[MAX];
int dfs_num[MAX];
bool marked[MAX];
vector<int> s;
int dfsCont, cantSCC;
vector<char> ady[MAX];
 
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
	//cout <<"\n";
	if( dfs_low[u] == dfs_num[u] ){
		cantSCC++;
        /* ********************************************************* */
        /* Esta seccion se usa para imprimir las componentes conexas */
		string str="";
		while(true){
			v = s.back();
			s.pop_back();
			marked[v] = false;
			//cout << char(v+'a') << ", ";
			str+=(char(v+'a'));
			sort(str.begin(),str.end());
			if(u == v) {
				for(int i =0;i<str.length();i++)
				cout<<str[i]<<',';
				cout<<endl;
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
	int casos; cin>>casos;
	int aux=1;
    while(casos--){
    	cin>>v>>e;
    	init();
	    //cout<<"\n";	
	    char str2,str3;
	    for(int i = 0;i<e;i++){
	    	cin>>str2>>str3;
	    	//cout<<str2<< " " <<str3<<endl;
	    	//cout<<mapa[str2]<<" "<<mapa[str3];
	    	ady[str2-'a'].pb(str3-'a');
	    	ady[str3-'a'].pb(str2-'a');
	    }
	    dfsCont = 0;
        s.clear();
        cantSCC=0;
        cout<<"Case #"<<aux++<<":\n";
	    for(int i = 0; i < v; i++){ //Por si el grafo no es conexo
	         if(dfs_num[i] == -1){
	         //	cout<<"entre1\n";
            	tarjanSCC(i); 
        	}
	    }  
	    cout<<cantSCC<<" connected components\n\n";
 
    }
}