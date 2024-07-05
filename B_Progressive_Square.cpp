#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
const int INF = 1e15 + 10;

void solve() {
    int n, c, d; cin>>n>>c>>d;
    multiset<int> st;
    for(int i = 0; i < n * n; i++) {
        int x; cin>>x;
        st.insert(x);
    }
    int arr[n][n] = {};
    arr[0][0] = *st.begin();
    for(int i = 1; i < n; i++) arr[i][0] = arr[i - 1][0] + c;

    for(int i = 0; i < n; i++) {
        for(int j = 1; j < n; j++) {
            arr[i][j] = arr[i][j - 1] + d;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!st.count(arr[i][j])) {
                cout<<"NO"<<endl;
                return;
            } else {
                st.erase(st.find(arr[i][j]));
            }
        }
    }
    cout<<"YES"<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": \n";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 