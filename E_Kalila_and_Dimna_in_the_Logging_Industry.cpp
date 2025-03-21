#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;

struct ConvexHullDynamic
{
	static const int INF=1e18;

	struct Line
	{
		int a, b; //y = ax + b
		double xLeft; //Stores the intersection wiith previous line in the convex hull. First line has -INF

		enum Type {line, maxQuery, minQuery} type;
		int val;

		explicit Line(int aa=0, int bb=0): a(aa), b(bb), xLeft(-INF), type(Type::line), val(0) {}

		int valueAt(int x) const
		{
			return a*x + b;
		}
		friend bool isParallel(const Line &l1, const Line &l2)
		{
			return l1.a == l2.a;
		}
		friend double intersectX(const Line &l1, const Line &l2)
		{
			return isParallel(l1, l2)?INF:1.0*(l2.b-l1.b)/(l1.a-l2.a);
		}
		bool operator<(const Line& l2) const
		{
			if(l2.type == line)
				return this->a < l2.a;
			if(l2.type == maxQuery)
				return this->xLeft < l2.val;
			if(l2.type == minQuery)
				return this->xLeft > l2.val;
		}
	};

	bool isMax;
	set<Line> hull;

	bool hasPrev(set<Line>::iterator it)
	{
		return it!=hull.begin();
	}	
	bool hasNext(set<Line>::iterator it)
	{
		return it!=hull.end() && next(it)!=hull.end();
	}
	bool irrelevant(const Line &l1, const Line &l2, const Line &l3)
	{
		return intersectX(l1, l3) <= intersectX(l1, l2);
	}
	bool irrelevant(set<Line>::iterator it)
	{
		return hasPrev(it) && hasNext(it) && ( 
			(isMax && irrelevant(*prev(it), *it, *next(it))) 
			|| (!isMax && irrelevant(*next(it), *it, *prev(it))));
	}
	//Updates xValue of line pointed by it
	set<Line>::iterator updateLeftBorder(set<Line>::iterator it)
	{
		if(isMax && !hasPrev(it) || !isMax && !hasNext(it))
			return it;
		double val=intersectX(*it, isMax?(*prev(it)):(*next(it)));
		Line temp(*it);
		it=hull.erase(it);
		temp.xLeft=val;
		it=hull.insert(it, temp);
		return it;
	}

	explicit ConvexHullDynamic(bool isMax): isMax(isMax) {}

	void addLine(int a, int b) //Add ax + b in logN time
	{
		Line l3=Line(a, b);
		auto it=hull.lower_bound(l3);

		//If parallel liune is already in set, one of the lines becomes irrelevant
		if(it!=hull.end() && isParallel(*it, l3))
		{
			if(isMax && it->b<b || !isMax && it->b>b)
				it=hull.erase(it);
			else
				return;
		}

		it=hull.insert(it, l3);
		if(irrelevant(it))
		{
			hull.erase(it);
			return;
		}

		//Remove lines which became irrelevant after inserting
		while(hasPrev(it) && irrelevant(prev(it)))
			hull.erase(prev(it));
		while(hasNext(it) && irrelevant(next(it)))
			hull.erase(next(it));

		//Update xLine
		it=updateLeftBorder(it);
		if(hasPrev(it))
			updateLeftBorder(prev(it));
		if(hasNext(it))
			updateLeftBorder(next(it));
	}

	int getBest(int x)
	{
		Line q;
		q.val=x;
		q.type = isMax?Line::Type::maxQuery : Line::Type::minQuery;

		auto bestLine=hull.lower_bound(q);
		if(isMax)
			--bestLine;
		return bestLine->valueAt(x);
	}
};


void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    ConvexHullDynamic CHT(false); // min CHT

    vector<int> dp(n, INF);

    for(int i = 0; i < n; i++) {
        dp[i] = (i == 0 ? 0 : CHT.getBest(a[i]));
        CHT.addLine(b[i], dp[i]);
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