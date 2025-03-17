#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int q; cin>>q;
    priority_queue<int> maxHeap; // left
    priority_queue<int, vector<int>, greater<int>> minHeap; // right
    int sm_l = 0, sm_r = 0, sm_b = 0;

    // 1 3 5 6 9 10

    while(q--) {
        int type; cin>>type;
        if(type == 1) {
            int a, b; cin>>a>>b;
            sm_b += b;
            maxHeap.push(a);
            sm_l += a;
            while(maxHeap.size() > minHeap.size() + 1) {
                int tmp = maxHeap.top();
                maxHeap.pop();
                minHeap.push(tmp);
                sm_l -= tmp;
                sm_r += tmp;
            }
            while(minHeap.size() && maxHeap.size() && maxHeap.top() > minHeap.top()) {
                int tmp_l = maxHeap.top(), tmp_r = minHeap.top();
                maxHeap.pop(); minHeap.pop();
                maxHeap.push(tmp_r); minHeap.push(tmp_l);
                sm_l -= tmp_l; sm_l += tmp_r;
                sm_r += tmp_l; sm_r -= tmp_r;
            }
        } else {
            int ans = sm_b, med = maxHeap.top();
            ans += med * (maxHeap.size() - minHeap.size());
            ans += (sm_r - sm_l);
            cout<<med<<" "<<ans<<endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/