#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include <iostream>
using namespace std;

#define ll long long
#define endl '\n'
const int mod=1e9+7;

int Pow(int a,ll b){
	int r=1; while(b){
		if(b&1)r=1LL*r*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}return r;
}


const int mx=1e6+2;
int F[mx]={1},P[mx]={1},k=1;
void precal(){
	int f=1,p=1;
	for(int i=1;i<=1000000005;i++){
		f=1LL*f*i%mod;
		p=1LL*p*f%mod;
		if(i%1000==0){
			F[k]=f;
			P[k]=p;
			k++;
		}
	}
}

int get(int n){
	int nn=n/1000,p=P[nn],f=F[nn];
	for(int i=nn*1000+1;i<=n;i++){
		f=1LL*f*i%mod;
		p=1LL*p*f%mod;
	}
	return 1LL*Pow(f,n+2)*Pow(p,mod-2)%mod;
}

int get(int l,int r){
	return 1LL*get(r)*Pow(get(l-1),mod-2)%mod;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	precal();
	int t; cin>>t; while(t--){
		int l,r; cin>>l>>r;
		cout<<get(l,r)<<endl;
	}
}