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

const long long int maxn = 2e5 + 100;
pii sg[4 * maxn];
int lazy[4 * maxn];

void propagra(int no, int ini, int fim)
{
    if (!lazy[no])
        return;
    sg[no].s += lazy[no] * (fim - ini + 1);
    sg[no].f += lazy[no];

    if (ini < fim)
    {
        lazy[2 * no] += lazy[no];
        lazy[2 * no + 1] += lazy[no];
    }
    lazy[no] = 0;
}

pii join(pii a, pii b)
{
    int sum = a.s + b.s;
    int menor = min(a.f, b.f);
    return {menor, sum};
}

void upt(int no, int ini, int fim, int l, int r, int val)
{
    propagra(no, ini, fim);
    if (r < ini || l > fim)
        return;
    if (l <= ini && fim <= r)
    {
        lazy[no] += val;
        propagra(no, ini, fim);
        return;
    }

    int mid = (ini + fim) / 2;
    upt(2 * no, ini, mid, l, r, val);
    upt(2 * no + 1, mid + 1, fim, l, r, val);

    sg[no] = join(sg[2 * no], sg[2 * no + 1]);
}

pii query(int no, int ini, int fim, int l, int r)
{
    propagra(no, ini, fim);
    if (r < ini || l > fim)
        return {INT_MAX, 0};
    if (l <= ini && fim <= r)
        return sg[no];

    int mid = (ini + fim) / 2;
    pii left = query(2 * no, ini, mid, l, r);
    pii right = query(2 * no + 1, mid + 1, fim, l, r);

    return join(left, right);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = "#" + s;

    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == '(')
            upt(1, 1, n, i, n, 1);
        else
            upt(1, 1, n, i, n, -1);
    }

    for (int i = 0; i < q; ++i)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1)
        {
            if (s[a] == s[b])
                continue;

            if (s[a] == '(')
                upt(1, 1, n, a, n, -2), upt(1, 1, n, b, n, 2);
            else
                upt(1, 1, n, a, n, 2), upt(1, 1, n, b, n, -2);

            swap(s[a], s[b]);
        }
        else
        {
            auto ans = query(1, 1, n, a, b);
            auto x = query(1, 1, n, a, a);
            auto y = query(1, 1, n, b, b);

            if (s[a] == ')' || ans.f + 1 < x.s || y.s - x.s != -1)
                cout << "No\n";
            else
                cout << "Yes\n";
        }
    }
}