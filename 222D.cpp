#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define pi acos(-1)
#define debug(a) cout<<a<<'\n'
#define maxn 200009 /// I want stay reverof withma youlu
#define MOD 998244353
#define F first
#define S second
#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define per(i, b, a) for(ll i = b-1; i>=a ; i--)
#define sz(x) (ll)((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back 
#define pf push_front
using namespace std;

ll mul(ll a,ll b){
    return a*b%MOD;
}
ll fpw(ll a, ll b){
    ll calc=1;
    for(;b>=1LL;b/=2LL){
        if((b&1LL))calc=mul(calc,a);
        if(b!=1)a=mul(a,a);
    }
    return calc;
}
ll add(ll a,ll b){
    if(a+b>=MOD)return a+b-MOD;
    else return a+b;
}
ll sub(ll a,ll b){
    if(a-b<0)return a-b+MOD;
    else return a-b;
}
void solvetask(){
    ll n;
    cin>>n;
    vector<ll> vet(n),vet2(n);
    rep(i,0,n)cin>>vet[i];
    rep(i,0,n)cin>>vet2[i];
    vector<ll> dp(3002,1);
    rep(i,0,n){
        vector<ll> newdp(3002,0);
        rep(j,vet[i],vet2[i]+1){
            newdp[j] = 1;
            newdp[j] = mul(newdp[j],dp[j]);
        }
        if(i!=n-1)rep(j,vet[i]+1,3001)newdp[j] = add(newdp[j],newdp[j-1]);
        dp = newdp;
    }
    ll ans = 0;
//    rep(i,vet[n-1],vet2[n-1]+1)cout<<dp[i]<<"\n";
    rep(i,vet[n-1],vet2[n-1]+1) ans = add(ans,dp[i]);
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
//    cin>>t;
    while(t--) solvetask();
    return 0;
}



