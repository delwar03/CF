#include <bits/stdc++.h> 
using namespace std; 

// Header files, namespaces, 
// macros as defined above 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 


#define int long long
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int q; cin>>q;
    ordered_set o_st;
    while(q--) {
        char ch;
        int x; 
        cin>>ch>>x;
        if(ch == 'I') o_st.insert(x);
        else if(ch == 'D') {
            if(o_st.find(x) != o_st.end()) o_st.erase(x);
        }
        else if(ch == 'C') {
            int ans = o_st.order_of_key(x);
            cout<<ans<<endl;
        } else {
            if(x > o_st.size()) {
                cout<<"invalid"<<endl;
            } else {
                auto it = o_st.find_by_order(x - 1);
                cout<<*it<<endl;
            }
        }
    }
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