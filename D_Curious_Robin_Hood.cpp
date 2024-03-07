#include<bits/stdc++.h>
using namespace std;

int a[100005],seg[4*100005];
void build (int ind,int low,int high)
 {
    if (low==high) 
    {
        seg[ind]=a[low]; return;
    }
    int mid=(low+high)/2;
    build (2*ind+1 ,low ,mid);
    build (2*ind+2,mid+1,high);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
 }
 int query (int ind ,int low ,int high,int l,int r)
  {
    if (l<=low && r>=high) return seg[ind];
    if (r<low ||l>high) return 0;
    int mid=(low+high)/2;
     int left=   query(2*ind+1 ,low ,mid,l,r);
     int right=  query (2*ind+2,mid+1,high,l,r);
     return  left+right;

  }
  void update (int ind,int low,int high,int pos,int val)
   {
      if (high<pos || pos <low) return ;
      if (pos<=low && high<=pos)
       {
           a[low]+=val;
           seg[ind]=a[low]; return;
       }
      int mid=(low+high)/2;
      update(2*ind+1 ,low ,mid,pos,val);
      update (2*ind+2,mid+1,high,pos ,val);
      seg[ind]=seg[2*ind+1]+seg[2*ind+2];

   }   

class ST {

public:
    vector<int> seg, lazy;
    
    ST(int n) {
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }

    void build(int ind, int low, int high, vector<int> &a) {
        if(low == high) {
            seg[ind] = a[low];
            return;
        }

        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, a);
        build(2 * ind + 2, mid + 1, high, a);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    void update(int ind, int low, int high, int l, int r, int val) {

        if(lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if(high != low) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if(l > high || r < low) return;

        if(l <= low && r >= high) {
            seg[ind] += (high - low + 1) * val;

            if(high != low) {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }

        int mid = low + (high - low) / 2;
        update(2 * ind + 1, low, mid, l, r, val);
        update(2 * ind + 2, mid + 1, high, l, r, val);
        
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }


    int query(int ind, int low, int high, int l, int r) {

        if(lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            
            if(high != low) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if(l > high || r < low) return 0;

        else if(l <= low && r >= high) return seg[ind];

        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
};

signed main()
 {
    int cs=1;
    int t;cin>>t;
    while (t--)

   {
        memset (seg ,0,sizeof(seg));
        int n,q;cin>>n>>q;
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        build (0 ,0,n-1);
        cout<<"Case "<<cs++<<":"<<"\n";
      
       while (q--)
      {
         int x; cin>>x;
         if (x==1)
          {
             int y;cin>>y;
             cout<<query (0,0,n-1,y,y)<<"\n";
             a[y]=0;
             update (0,0,n-1,y,0);
          }
          else if (x==2)
           {
              int y,z;cin>>y>>z;
              update (0,0,n-1,y,z);
           }
          else if (x==3)
           {
            int y,z;cin>>y>>z;
            cout<<query (0,0,n-1,y,z)<<"\n";

           }
       }
   }
 }