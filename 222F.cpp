#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define pi acos(-1)
#define debug(a) cout<<a<<'\n'
#define maxn 400009 /// I want stay reverof withma youlu
#define MOD 1000000007
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

const ll INF = 1e15 + 9;

ll n,m;
vector<pii> adj[maxn];
ll dis[maxn];
ll vis[maxn];
vector<ll> price;
void addedge(ll a,ll b,ll c){
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
}
void INFINITAR(){
    for(ll i=0;i<maxn;i++){
        dis[i]=-INF;
        vis[i] = -1;
    }
}
vector<ll> dijkstra(int x){
    INFINITAR();
    dis[x] = 0;
    priority_queue<pii> pq;
    pq.push({0,x});
    while(!pq.empty()){
        auto f=pq.top();
        pq.pop();
        vis[f.S] = 1;
        if(dis[f.second]>f.first)continue;
        for(auto e: adj[f.second]){
            if(vis[e.F] == -1 && f.first+e.second > dis[e.first]){
                dis[e.first]=f.first+e.second;
                pq.push({dis[e.first],e.first});
            }
        }
    }
    vector<ll> ret;
    rep(i,0,maxn){
        ret.pb(dis[i]);
    }
    return ret;
}
void solvetask(){
    vector<ll> vet;
    cin>>n;
    ll cte = n+1;
    m = n-1;
    while(m--){
        ll x,y,we;
        cin>>x>>y>>we;
        addedge(x,y,we);
    }
    price.resize(n+1);
    rep(i,1,n+1){
        cin>>price[i];
    }
    rep(i,1,n+1){
        adj[i].pb({i + cte,price[i]});
        adj[i+cte].pb({i,price[i]});
    }
    dijkstra(1);
    ll maior = -INF;
    ll t = -1;
    rep(i,1,maxn){
//        cout<<i<<" "<<dis[i]<<endl;
        if(dis[i] > maior){
            t = i;
            maior = dis[i];
        }
    }
//    cout<<"---------------\n";

    dijkstra(t);
    maior = -INF;
    ll s = -1;
    rep(i,1,maxn){
//        cout<<i<<" "<<dis[i]<<endl;
        if(dis[i] > maior){
            s = i;
            maior = dis[i];
        }
    }
//    cout<<s<<" "<<t<<endl;
    vector<ll> ds = dijkstra(s);
    vector<ll> dt = dijkstra(t);
    rep(i,1,n+1){
        if(s == i + cte) cout<<dt[i]<<"\n";
        else if(t == i + cte) cout<<ds[i]<<"\n";
        else cout<<max(ds[i],dt[i])<<"\n";
        
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
//    cin>>t;
    while(t--) solvetask();
    return 0;
}



