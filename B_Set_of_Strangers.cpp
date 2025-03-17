#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define inf 1e18 + 10
#define mod 1e9 + 7
const int N = 5000;   
int n, m;

bool isvalid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void solve() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));  
    set<int> st;
    int mx = -inf;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            mx = max (mx , a[i][j]);
        }
    }
    vector < int > vis (mx + 1,0);
   // cerr << mx <<"\n";
   
    int mn = inf;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp = a[i][j];

            if (vis[tmp] == 2) continue;  

            if (vis[tmp] == 0) {  
                vis[tmp] = 1;
                cnt++;  
            } 
            else if (vis[tmp] == 1) {  
                if (isvalid(i - 1, j) && a[i - 1][j] == tmp) {
                    vis[tmp] = 2;
                } 
                if (isvalid(i, j - 1) && a[i][j - 1] == tmp) {
                    vis[tmp] = 2;
                } 
                if (isvalid(i + 1, j) && a[i + 1][j] == tmp) {
                    vis[tmp] = 2;
                } 
                if (isvalid(i, j + 1) && a[i][j + 1] == tmp) {
                    vis[tmp] = 2;
                }
            }
        }
    } 
    //for (int i=0 ; i<= mx ;i++) cerr << vis[i] <<" "; cerr <<"\n";
    cnt=0;
    vector < int > v;
    for (int i=0 ; i<=mx  ; i++) v.push_back (vis[i]);   
    sort (v.rbegin () , v.rend ());   
    for (int i= 1 ; i <  v.size();i++) {
        cnt+= v[i];
    }    
    cout << cnt <<"\n";  
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
