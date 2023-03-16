#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const ll N=2e5+1;
vector<ll> v(N),tree(N<<2);

void build(ll si,ll ss,ll se){
   if(ss==se){
    tree[si]=v[ss];
    return;
   }
   ll mid=(ss+se)>>1;
   build(2*si,ss,mid);
   build(2*si+1,mid+1,se);
   tree[si]=tree[2*si]^tree[2*si+1];
}

void update(ll si,ll ss,ll se,ll pos,ll val){
   if(ss==se)
   {
    tree[si]=val;
    return;
   }
   ll mid=(ss+se)>>1;

   if(pos<=mid)
     update(2*si,ss,mid,pos,val);
   else 
     update(2*si+1,mid+1,se,pos,val);  
   
   tree[si]=tree[2*si]^tree[2*si+1];
}


ll query(ll si,ll ss,ll se,ll low,ll high){
  
  if(ss>high || se<low) return 0;
  if(ss>=low && se<=high)return tree[si];

  ll mid=(ss+se)>>1;
  ll left=query(2*si,ss,mid,low,high);
  ll right=query(2*si+1,mid+1,se,low,high);
  return (left^right);
}

int main(){
   ll n, q;
   cin>>n>>q;

   for(int i=1;i<=n;i++)cin>>v[i];
   build(1,1,n);
//    cout<<tree[1]<<endl;
   for(int i=1;i<=q;i++)
   {
    ll low,high;
    cin>>low>>high;
    ll ans=query(1,1,n,low,high);
    // if(low!=1)
    //   ans^=query(1,1,n,1,low-1);
     cout<<ans<<endl;
    
   }

}