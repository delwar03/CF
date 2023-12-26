       

        //  ▄████▄   ▒█████  ▓█████▄ ▓█████ 
        // ▒██▀ ▀█  ▒██▒  ██▒▒██▀ ██▌▓█   ▀ 
        // ▒▓█    ▄ ▒██░  ██▒░██   █▌▒███   
        // ▒▓▓▄ ▄██▒▒██   ██░░▓█▄   ▌▒▓█  ▄ 
        // ▒ ▓███▀ ░░ ████▓▒░░▒████▓ ░▒████▒
        // ░ ░▒ ▒  ░░ ▒░▒░▒░  ▒▒▓  ▒ ░░ ▒░ ░
        //   ░  ▒     ░ ▒ ▒░  ░ ▒  ▒  ░ ░  ░
        // ░        ░ ░ ░ ▒   ░ ░  ░    ░   
        // ░ ░          ░ ░     ░       ░  ░
        // ░                  ░             
 

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    if(n & 1) {cout<<"-1\n"; return;}

    deque<char> dq(s.begin(), s.end());
    int op = 0, l = 0;
    vector<int> ans;
    while(!dq.empty()) {
        if(dq.front() != dq.back()) {
            dq.pop_front();
            dq.pop_back();
            l++;
        } else {
            op++;
            if(op > 300) {cout<<"-1\n"; return;}
            if(dq.front() == '1') {
                ans.push_back(l);
                dq.push_front('1');
                dq.push_front('0');
            } else {
                ans.push_back(l + dq.size());
                dq.push_back('0');
                dq.push_back('1');
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto it : ans) cout<<it<<" "; cout<<endl;
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