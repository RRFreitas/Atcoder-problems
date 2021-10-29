#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<string> tds;
    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i < n; ++i)
    {
        string left = s.substr(i, n);
        int l = i;
        string right = s.substr(0, l);
        tds.pb(left + right);
    }
    sort(ALL(tds));
    cout << tds[0] << "\n"
         << tds.back() << "\n";
}