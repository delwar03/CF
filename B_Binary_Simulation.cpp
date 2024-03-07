#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005],seg[4*100005];
void build (int ind,int low,int high)
 {
    if (low==high) 
    {
        seg[ind]=s[low-1]-'0'; return;
    }
    int mid=(low+high)/2;
    build (2*ind ,low ,mid);
    build (2*ind+1,mid+1,high);
    seg[ind]=seg[2*ind]+seg[2*ind+1];
 }
 int sm;
 int query (int ind ,int low ,int high,int l)
  {
    if (l<=low && l>=high)
     { 
        sm+=seg[ind];
        return sm;
     }
    if (l<low ||l>high) return 0;
     sm+=seg[ind];
    int mid=(low+high)/2;
     int left=   query(2*ind ,low ,mid,l);
     int right=  query (2*ind+1,mid+1,high,l);
     return  sm=left+right;

  }
void update (int ind,int low,int high,int l,int r) {

    if (r<low  || high<l) return ;
    if (l<=low && high<=r) { seg[ind]++; return;}

    int mid=(low+high)/2;
    update(2*ind ,low ,mid,l,r);
    update (2*ind+1,mid+1,high,l,r );
}   

signed main() {

    int cs=1;
    int t;cin>>t;
    while (t--) {
        memset (seg ,0,sizeof(seg));
         
        cin>>s;
        int q;cin>>q;
        cout<<"Case "<<cs++<<":"<<"\n";
      
        while (q--) {
            char c; cin>>c;
            if (c == 'I') {
                int x, y; cin>>x>>y;
                update (1,1,s.size(),x,y);
            } else {
                int x; cin>>x;
                sm=0;
                int ans=query (1,1,s.size(),x);
                if (ans%2==0) cout<<s[x-1]<<"\n";
                else {
                    if (s[x-1]=='1') cout<<0<<"\n";
                    else cout<<1<<"\n";
                }
            }
        }
   }
     
}