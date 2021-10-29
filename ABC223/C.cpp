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

const int EPS = 1e-7;
vector<array<int, 2>> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    v.resize(n);

    double totalTime = 0.0;
    for (auto &x : v)
    {
        cin >> x[0] >> x[1];
        totalTime += (1. * x[0]) / (1. * x[1]);
    }

    cout << fixed << setprecision(10);
    double dist = 0.0, currTime = 0.0;
    double target = totalTime / 2.0;

    for (int i = 0; i < n; ++i)
    {
        double needTime = (1.0 * v[i][0]) / v[i][1];

        if ((needTime + currTime) - target > EPS)
        {
            double tempoRestante = target - currTime;
            double dx = (1.0 * v[i][0] * tempoRestante) / needTime;
            cout << dist + dx << "\n";
            return 0;
        }
        else
            currTime += needTime, dist += v[i][0];
    }
}