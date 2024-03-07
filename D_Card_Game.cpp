#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    char ch; cin>>ch;
    vector<string> c, d, h, s, special;
    int f = 1;
    for(int i = 0; i < 2 * n; i++) {
        string str; cin>>str;
        if(str[1] == ch) {
            special.push_back(str);
        } else {
            if(str[1] == 'C') c.push_back(str);
            if(str[1] == 'D') d.push_back(str);
            if(str[1] == 'H') h.push_back(str);
            if(str[1] == 'S') s.push_back(str);
        }
    }
    int pp = c.size() % 2;
    pp += d.size() % 2;
    pp += h.size() % 2;
    pp += s.size() % 2;
    
    if(special.size() < pp) {
        cout<<"IMPOSSIBLE"<<endl;
    } else {
        sort(c.begin(), c.end());
        sort(d.begin(), d.end());
        sort(h.begin(), h.end());
        sort(s.begin(), s.end());
        sort(special.begin(), special.end());
        
        int c_sz = c.size() / 2;
        int d_sz = d.size() / 2;
        int h_sz = h.size() / 2;
        int s_sz = s.size() / 2;
        int ind = 0;

        int it1 = 0;
        int it2 = c.size();
        for(int i = 0; i < c_sz; i++) {
            cout<<c[it1++]<<" "<<c[--it2]<<endl;
        }
        if(c.size() & 1) cout<<c[it1]<<" "<<special[ind++]<<endl;

        it1 = 0;
        it2 = d.size();
        for(int i = 0; i < d_sz; i++) {
            cout<<d[it1++]<<" "<<d[--it2]<<endl;
        }
        if(d.size() & 1) cout<<d[it1]<<" "<<special[ind++]<<endl;

        it1 = 0;
        it2 = h.size();
        for(int i = 0; i < h_sz; i++) {
            cout<<h[it1++]<<" "<<h[--it2]<<endl;
        }
        if(h.size() & 1) cout<<h[it1]<<" "<<special[ind++]<<endl;

        it1 = 0;
        it2 = s.size();
        for(int i = 0; i < s_sz; i++) {
            cout<<s[it1++]<<" "<<s[--it2]<<endl;
        }
        if(s.size() & 1) cout<<s[it1]<<" "<<special[ind++]<<endl;

        int ind2 = special.size() - 1;
        while(ind < ind2) cout<<special[ind++]<<" "<<special[ind2--]<<endl;
        // for(auto it : vec) cout<<it<<" "; cout<<endl;

    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 