#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'

long long const N = 5e5 + 1, M = 1e9 + 7;
long long fn[N], fd[N], iv[N];

void initnck(){
    iv[1] = fn[1] = fd[1] = fn[0] = fd[0] = 1;
    for (long long i=2; i<N; i++){
        iv[i] = (M - (M/i) * iv[M%i] % M) % M;
        fn[i] = fn[i-1]*i%M;
        fd[i] = fd[i-1]*iv[i]%M;
    }
}

long long nck(long long n, long long k){
    return fn[n] * fd[n-k] % M * fd[k] % M;
}

void solvetask(){
    initnck();
    long long n,m; cin >> n >> m;
    long long ans = fn[m] * fd[m - n] % M;
    for (int i=1; i<=n; i++){
        if (i & 1) ans = (ans - nck(n, i) * fn[m - i] % M * fd[m - n] % M + M)%M;
        else ans = (ans + nck(n, i) * fn[m - i] % M * fd[m - n] % M)%M;
    }
    cout << ans * fn[m] % M * fd[m - n] % M << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1; //cin >> t;
    while(t--) solvetask();
}
