#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define pi acos(-1)
#define debug(a) cout<<a<<'\n'
#define maxn 1009 /// I want stay reverof withma youlu
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

vector<pii> adj[maxn];
ll dp[1003][100003];
vector<ll> qtds;
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

ll pth(ll x, ll pai,ll end){
    if(x == end) return 1;
    for(auto e: adj[x]){
        if(e.F!=pai){
            if(pth(e.F,x,end)){
                qtds[e.S]++;
                return 1;
            }
        }
    }
    return 0;
}
void solvetask(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> seq(m);
    rep(i,0,m)cin>>seq[i];
    ll ed = n-1;
    qtds.resize(ed);
    while(ed--){
        ll x,y;
        cin>>x>>y;
        adj[x].pb({y,ed});
        adj[y].pb({x,ed});
    }

    rep(i,0,m-1){
        pth(seq[i],-1,seq[i+1]);
    }
    ll soma = 0;
    rep(i,0,sz(qtds)){
        soma+=qtds[i];
    }
    dp[0][0] = 1;

    rep(i,1,sz(qtds)+1){
        rep(j,0,soma+1){
            if(j >= qtds[i-1]){
                dp[i][j] = add(dp[i][j],dp[i-1][j-qtds[i-1]]);
            }
            dp[i][j] = add(dp[i][j],dp[i-1][j]);
        }
    }
    ll ans = 0;
    rep(i,0,soma+1){
        if((soma - i) - i == k){
            ans = add(ans,dp[sz(qtds)][i]);
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
//    cin>>t;
    while(t--) solvetask();
    return 0;
}

/// dp[id][red][blue] = number of ways to color edges until edge id with red reds and blue blues 

