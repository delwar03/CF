#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

int n, m;
int dp[1005][1LL << 11];

void get_next_mask(int row, int cur_mask, int next_mask, vector<int>& next_masks) {
    if(row == n) {
        next_masks.push_back(next_mask);
        return;
    }
    
    if((cur_mask & (1LL << row)))
        get_next_mask(row + 1, cur_mask, next_mask, next_masks);
    
    if(row < n - 1) 
        if((cur_mask & (1LL << row)) == 0 && (cur_mask & (1LL << (row + 1))) == 0)
            get_next_mask(row + 2, cur_mask, next_mask, next_masks);
    
    if((cur_mask & (1LL << row)) == 0)
        get_next_mask(row + 1, cur_mask, (next_mask | (1LL << row)), next_masks);
}

int calc(int col, int mask) {
    if(col == m) {
        if(mask == 0)
            return 1;
        return 0;
    }
    
    int &ans = dp[col][mask];
    if(~ans)
        return ans;
        
    ans = 0;
    vector<int> next_masks;
    get_next_mask(0, mask, 0, next_masks);
    
    for(auto next_mask : next_masks) {
        ans = (ans + calc(col + 1, next_mask)) % M;
    }
    return ans;
}


void solve() {
    cin>>n>>m;
    memset(dp, -1, sizeof dp);
    cout<<calc(0, 0)<<endl; // dp(col, mask)
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
i/p: 
o/p: 
*/ 