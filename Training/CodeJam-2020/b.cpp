#include <bits/stdc++.h>

using namespace std;

/** @autor Jhoser Pacheco */

#define endl "\n"
#define pb push_back

int main(){

  ios::sync_with_stdio(0), cin.tie(0);
	int t, cases = 1, a, aux;
  string str, rta = "" ;
	cin >> t;
	while(t--){
    cin >> str;
    rta = ""; a = 0;
    for(int i = 0; i < str.length(); i++){
        aux = str[i] - 48;
        if(aux < a)
        	for(int i = a - aux - 1; i >= 0; i--) rta += ')';
        else
        	for(int i = aux - a - 1; i >= 0; i--) rta += '(';
        rta += str[i];
        a = aux;
    }

		for(int i = a - 1; i >= 0; i--) rta += ')';

		cout << "Case #" << cases++ << ": " << rta << endl;
    }

	return 0;
}
