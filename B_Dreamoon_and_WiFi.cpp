#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
int fact[11];

int nCr(int n, int r) {
    return fact[n] / (fact[r] * fact[n - r]);
}

void solve() {
    string a, b; cin>>a>>b;
    int plus = 0, minus = 0;
    for(auto ch : a) {
        if(ch == '+') plus++;
        else if(ch == '-') minus++;
    }
    for(auto ch : b) {
        if(ch == '+') plus--;
        else if(ch == '-') minus--;
    }
    if(plus < 0 || minus < 0) {
        cout<<fixed<<setprecision(12)<<0.0<<endl;
        return;
    }
    int tot = plus + minus;
    int possible = nCr(tot, plus);
    // cout<<plus<<" "<<minus<<endl;
    // cout<<possible<<endl;
    cout<<fixed<<setprecision(12)<< 1.0 * possible / (1LL << tot) <<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fact[0] = fact[1] = 1;
    for(int i = 2; i <= 10; i++) {
        fact[i] = fact[i - 1] * i;
    }

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 