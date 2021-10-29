#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, s; cin >> n >> s;
    int a[n+1], dp[n+1][3001], ac[n+1][3001];
    for (int i=1; i<=n; i++) cin >> a[i];

    memset(dp, 0, sizeof dp);
    long long ans = 0;
    for (int i=1; i<=n; i++){
        dp[i][a[i]] = i;
        for (int j = a[i]+1; j<=s; j++){
            dp[i][j] = (dp[i][j] + ac[i-1][j - a[i]])%MOD;
            ac[i][j] = (dp[i][j] + ac[i-1][j])%MOD;
        }
        for (int j = a[i]; j>=1; j--) ac[i][j] = (dp[i][j] + ac[i-1][j])%MOD;
    }
    for (int i=1; i<=n; i++) ans = (ans + ( (((long long)dp[i][s] )*(n-i+1LL)))%MOD )%MOD;
    cout << ans << endl;
}
