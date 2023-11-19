#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m; cin >> n >> m;
	cout << 1 << "\n";
	for(int j=0; j<m; j++) cout << "(" << 0 << ", " << j << ")\n";

	for(int i=1; i<n; i++){
		if(i&1){
			for(int j=m-1; j>=1; j--) cout << "(" << i << ", " << j << ")\n";
		}else{
			for(int j=1; j<m; j++) cout << "(" << i << ", " << j << ")\n";
		}
	}
	for(int i=n-1; i>=1; i--) cout << "(" << i << ", " << 0 << ")\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
}
