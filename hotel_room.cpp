#include <bits/stdc++.h>
using namespace std;
#define ll      long long int

const ll maxn = 2e5+10;
vector<ll>tree(maxn<<2),v(maxn);

void build(ll si,ll ss,ll se){
   if(ss==se){
    tree[si]=v[ss];
    return;
   }
   ll mid=(ss+se)/2;
   build(2*si,ss,mid);
   build(2*si+1,mid+1,se);
   tree[si]=max(tree[2*si],tree[2*si+1]);
}

ll query(ll si,ll ss,ll se,ll room){
   if(tree[si]<room)return 0;

   if(ss==se){
    tree[si]-=room;
    return ss;
   }
   ll mid=(ss+se)/2;
   ll left=query(2*si,ss,mid,room);
   if(left==0) left=query(2*si+1,mid+1,se,room);
   tree[si]=max(tree[2*si],tree[2*si+1]);

   return left;
   
}

int main(){
    ll n,q;
    cin>>n>>q;
    for(ll i=1;i<=n;i++)cin>>v[i];
     build(1,1,n);
    // cout<<tree[1]<<endl;
    // for(int i=8;i<=15;i++)cout<<tree[i]<<"  ";
     while(q--){
       ll room;
       cin>>room;
       cout<<query(1,1,n,room)<<"  ";
     
     }



}



