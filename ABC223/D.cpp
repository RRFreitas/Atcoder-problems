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

    const int N = 2e5 + 7;

    int n, m;
    cin >> n >> m;
    vector<int> g[n];
    int lv[n];
    memset(lv, 0, sizeof(lv));

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        // a->b

        lv[b]++;
        g[a].pb(b);
    }

    priority_queue<int, vector<int>, greater<int>> fila;
    for (int i = 0; i < n; ++i)
        if (lv[i] == 0)
            fila.push(i);

    vector<int> ans;
    while (!fila.empty())
    {
        int x = fila.top();
        fila.pop();
        for (int &y : g[x])
        {
            lv[y]--;
            if (lv[y] == 0)
                fila.push(y);
        }

        ans.pb(x);
    }

    if (sz(ans) != n)
        cout << "-1\n";
    else
    {
        for (int &x : ans)
            cout << x + 1 << " ";
        cout << "\n";
    }
}