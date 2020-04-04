#include <bits/stdc++.h>

using namespace std;

/** @autor Jhoser Pacheco */

#define endl "\n"
#define pb push_back

int main() {
	ios::sync_with_stdio(0),cin.tie(0);
	int t, cases = 1;
	cin >> t;
	while(t--){
		int n, d = 0, cf = 0, cc = 0;
		cin >> n;
		int m[n][n];
		set <int> v1, v2;
   		memset(m, 0, sizeof(m));

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> m[i][j];
				if(i == j) 	d += m[i][j];
			}
		}

		for(int i = 0; i < n; i++){
			v1.clear(); v2.clear();
			for(int j = 0; j < n; j++){
				v1.insert(m[i][j]);
				v2.insert(m[j][i]);
			}
			(v1.size() != n) ? cf++ : cf += 0;
			(v2.size() != n) ? cc++ : cc += 0;
		}

		cout << "Case #" << cases++ << ": " << d << " " << cf << " " << cc << endl;
	}
	return 0;
}
