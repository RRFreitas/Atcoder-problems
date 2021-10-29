#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int const N = 200020, inf = (int) 2e9;
int n, a[N], lis[N], ans[N];
vector<int> adj[N];

void dfs(int v = 0, int p = -1){
    int pos = (int) (lower_bound(lis, lis + N, a[v]) - lis);
    int ant = lis[pos];
    lis[pos] = a[v];
    ans[v] = (int) (lower_bound(lis, lis+N, inf) - lis) - 1;
    for (int f : adj[v]){
        if (f == p) continue;
        dfs(f, v);
    }
    lis[pos] = ant;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    lis[0] = -inf;
    for (int i=1; i<N; i++) lis[i] = inf;

    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n-1; i++){
        int u,v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs();
    for (int i=0; i<n; i++) cout << ans[i] << endl;
}
