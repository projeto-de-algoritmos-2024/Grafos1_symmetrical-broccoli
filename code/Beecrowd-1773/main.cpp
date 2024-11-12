#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef tuple<int,int> tp;
typedef vector<tp> vtp;
 
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const int MAX = 1e4 + 5;
const int NONE = 0;

void solve(int n){
	int m;
	cin >> m;
	vi adj[n+1];
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}	

	vi keys[n+1];
	memset(keys,0,sizeof(keys));
	for(int i=2;i<=n;i++){
	       	int sala;
       		cin >>sala;
 		keys[sala].push_back(i);
	}		

	queue<int> fila;
	fila.push(1);
	int tenho[n+1];
	memset(tenho,0,sizeof(tenho));
	tenho[1] = 1;
	vi visited(n+1,0);
	vi aguard(n+1,0);
	while(!fila.empty()){
		auto u = fila.front();
		fila.pop();
		visited[u]=1;
		for(auto chave_atual : keys[u]){
			tenho[chave_atual]=1;
			if(aguard[chave_atual]){
				fila.push(chave_atual);
				aguard[chave_atual]=0;
			}
		}
		for(auto k : adj[u]) {
			if(!visited[k]){
				if(tenho[k]) {
					fila.push(k); 
					aguard[k]=0;
				}else aguard[k]=1;
			}	
		}
	}	
	visited[0]=1;
	if(*min_element(visited.begin(),visited.end())==0) cout << "nao\n";
	else cout << "sim\n";		
}
 
int main(){
	fastInp;     
	        
	ll t;
	
	//cin >> t;		 
		   
    while(cin >> t) solve(t);
	return 0;
}
