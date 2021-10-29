#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define pi acos(-1)
#define debug(a) cout<<a<<'\n'
#define maxn 200009 /// I want stay reverof withma youlu
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

ll points[52];
char predict[102][102];
vector<ll> ranks;

bool comp(ll a,ll b){
    if(points[a] > points[b]) return true;
    else if(points[a] == points[b] && a < b) return true;
    else return false;
}

void game(ll a, ll b, ll m){
    char c = predict[a][m],w = predict[b][m];
    if(c == 'G' && w == 'G') return;
    if(c == 'C' && w == 'C') return;
    if(c == 'P' && w == 'P') return;
    if(c == 'G' && w == 'C') points[a]++;
    if(c == 'C' && w == 'G') points[b]++;
    if(c == 'P' && w == 'G') points[a]++;
    if(c == 'G' && w == 'P') points[b]++;
    if(c == 'C' && w == 'P') points[a]++;
    if(c == 'P' && w == 'C') points[b]++;
}
void solvetask(){
    /// 2N players
    ll n,m;
    cin>>n>>m;
    n*=2;
    rep(i,0,n){
        rep(j,0,m){
            cin>>predict[i][j];
        }
    }
    rep(i,0,n) ranks.pb(i); 
    rep(i,0,m){
       sort(all(ranks),comp); 
       rep(j,0,n/2){
           game(ranks[2*j],ranks[2*j+1],i);
       }
    }
    sort(all(ranks),comp);
    rep(i,0,sz(ranks)){
        cout<<ranks[i]+1<<"\n";
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



