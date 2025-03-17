#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

struct Line {
    int a, b;

    Line(int a, int b) : a(a), b(b) {}

    int value(int x) {
        return a * x + b;
    }

    pair<int, int> intersect(const Line& he) const {
        // (c2 - c1) / (m1 - m2)
        int f = he.b - b;
        int s = a - he.a; // (f / s)
        if(s < 0) {
            f = -f;
            s = -s;
        }
        return {f, s};
    }
};

void solve() {
    int n, c; cin>>n>>c;
    vector<int> h(n);
    for(auto &x : h) cin>>x;

    vector<Line> lines;
    vector<int> dp(n, INF);

    int start = 0;

    for(int i = 0; i < n; i++) {

        while(start <= (int) lines.size() - 2) {
            Line L1 = lines[start]; 
            Line L2 = lines[start + 1];
            if(L1.value(h[i]) >= L2.value(h[i])) { // for the minimum perpose
                start++;
            } else {
                break;
            }
        }

        dp[i] = 0;

        if(i) {
            dp[i] = lines[start].value(h[i]) + h[i] * h[i] + c;
        }

        Line L3(-2 * h[i], dp[i] + h[i] * h[i]);

        while(start <= (int) lines.size() - 2) {
            Line L1 = lines.end()[-2];
            Line L2 = lines.end()[-1];

            auto f = L1.intersect(L2);
            auto s = L2.intersect(L3);

            // (f.first / f.second) < (s.first / s.second) -> pera nai
            if(f.first * s.second >= f.second * s.first) {
                lines.pop_back();
            } else {
                break;
            }
        }
        lines.push_back(L3);
    }

    cout<<dp[n - 1]<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 