#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

vector<int> bin = {
    1, 10, 11, 100, 101, 
    110, 111, 1000, 1001, 1010, 
    1011, 1100, 1101, 1110, 1111, 
    10000, 10001, 10010, 10011, 10100, 
    10101, 10110, 10111, 11000, 11001, 
    11010, 11011, 11100, 11101, 11110, 
    11111, 100000, 100001, 100010, 100011, 
    100100, 100101, 100110, 100111, 101000
};

void solve() {
    int n; cin>>n;
    for(int i = bin.size() - 1; i > 0 ; i--) {
        if(n % bin[i] == 0) {
            while(n % bin[i] == 0)
                n /= bin[i];
        }
    }
    if(n == 1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 