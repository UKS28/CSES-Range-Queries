#include <bits/stdc++.h> 
using namespace std;
#define int       long long int

 
const int maxn = 2e5+10;
vector<int>t(maxn<<2),a(maxn);
int n,m;
void build(int si,int l,int r){
	if( l == r ){
        t[si]=a[l];return;
    }
	int m=(l+r)>>1;
	build(2*si,l,m);
	build(2*si+1,m+1,r);
	t[si]=min(t[2*si],t[2*si+1]);
}
void update(int si,int l,int r,int pos,int new_val){
	if(l==r){
        t[si]=new_val;
        return;
    }
	int m=(l+r)>>1;
	if(pos<=m)update(si<<1,l,m,pos,new_val);
	else update(2*si+1,m+1,r,pos,new_val);
	t[si]=min(t[2*si],t[2*si+1]);
}
int query(int si,int tl,int tr,int l,int r){
	
    if (r < tl || tr < l) return INT_MAX;
		// complete overlap
		// [l low high r]
		if (tl >= l && tr <= r) return t[si];

		int mid = (tr + tl) >> 1;
		int left = query(2 * si , tl, mid, l, r);
		int right = query(2 * si + 1, mid + 1, tr, l, r);
		return min(left,right);
}
	
int32_t main(){
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	build(1,1,n);

	for(int i=1;i<=m;i++){
		int x,y,z;cin>>x>>y>>z;
		if(x==1)
           update(1,1,n,y,z);
		else 
           cout<<query(1,1,n,y,z)<<endl;
	}
}
