#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    string s, t; cin>>s>>t;
    int n = s.size();
    vector<int> freq(26, 0), maxIdx(26, -1), minIdx(26, -1);
    for(int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
        if(minIdx[s[i] - 'a'] == -1) minIdx[s[i] - 'a'] = i;
        maxIdx[s[i] - 'a'] = i;
    }

    int prv = -1;

    for(int i = 0; i < 3; i++) {
        if(i == 2) {
            if(t[i] == 'X' || (freq[t[i] - 'A'] && prv < maxIdx[t[i] - 'A'])) {
                continue;
            } else {
                cout<<"No"<<endl;
                return;
            }
        } else {
            if(freq[t[i] - 'A'] && (prv == -1 || prv < maxIdx[t[i] - 'A'])) {
                freq[t[i] - 'A']--;
                prv = minIdx[t[i] - 'A'];
            } else {
                cout<<"No"<<endl;
                return;
            }
        }
    }
    cout<<"Yes"<<endl;
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
