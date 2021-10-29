#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, p;
    string s;
    cin >> n >> p >> s;
    long long ans = 0;
    if (p == 2 || p == 5){
        for (int i=0; i<n; i++) if ( (s[i] - '0') % p == 0) ans += i+1;
    } else{
        map<int, int> freq;
        freq[0] = 1;
        int ac = 0, pot = 1;
        for (int i=n-1; i>=0; i--){
            ac = ((s[i] - '0')*pot + ac)%p;
            ans += freq[ac]++;
            pot = (pot*10)%p;
        }
    }
    cout << ans << endl;

}
