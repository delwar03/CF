#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

// Extended GCD Algo
vector<int> e_gcd(int a, int b) {
        if(b == 0) return {1, 0, a};
        auto dash = e_gcd(b, a % b); // {x, y, gcd}
        return {dash[1], dash[0] - (a / b) * dash[1], dash[2]};
}

void solve() {
    string s; cin>>s;
    s[5] = s[13] = ' ';
    cout<<s<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p: 2
     3
     5 4
     7 6
     11 3
     4
     2 1
     3 2
     5 3
     7 1
o/p: Case 1: 69
     Case 2: 113
*/ 