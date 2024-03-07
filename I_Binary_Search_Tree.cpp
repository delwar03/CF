#include <bits/stdc++.h> 
using namespace std; 

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
#define int long long
#define endl '\n'
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
ordered_set o_st;

void solve() {
    
    
    int q; cin>>q;
    while(q--) {
        int ty, x; cin>>ty>>x;
        if(ty == 1) {
            o_st.insert(-x);
        } else {
            if(o_st.find(-x) == o_st.end()) cout<<"Data tidak ada"<<endl;
            else cout<<o_st.order_of_key(-x) + 1<<endl;
        }
    }
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