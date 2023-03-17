#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const ll N=2e5+1;
vector<ll> v(N),tree(N<<2),lazy(N<<2);


void build(ll si,ll ss, ll se){
  if(ss==se){
     tree[si]=v[ss];
     return;
  }

  ll mid=(ss+se)>>1;
  build(2*si,ss,mid);
  build(2*si+1,mid+1,se);
  tree[si]=tree[2*si]+tree[2*si+1];
}

void update(ll si,ll ss,ll se,ll qs,ll qe,ll val ){
    if(lazy[si]!=0){
        ll dx=lazy[si];
        lazy[si]=0;

        tree[si]+=(se-ss+1)*dx;

        if(ss!=se){
            lazy[2*si]+=dx;
            lazy[2*si+1]+=dx;
        }
    }

    if(ss>qe || se<qs) return ;
    if(ss>=qs && se<=qe) {
        ll dx=(se-ss+1)*val;
        tree[si]+=dx;

        if(ss!=se){
            lazy[2*si]+=val;
            lazy[2*si+1]+=val;
        }
        return;
    }
    ll mid=(ss+se)/2;
    update(2*si,ss,mid,qs,qe,val);
    update(2*si+1,mid+1,se,qs,qe,val);
 
}

ll query(ll si,ll ss, ll se,ll qs,ll qe){
    if(lazy[si]!=0){
        ll dx=lazy[si];
        lazy[si]=0;

        tree[si]+=(se-ss+1)*dx;

        if(ss!=se){
            lazy[2*si]+=dx;
            lazy[2*si+1]+=dx;
        }
    }

    if(ss>qe || se<qs) return 0;
    if(ss>=qs && se<=qe) return tree[si];
    ll mid=(ss+se)/2;
    return query(2*si,ss,mid,qs,qe) +query(2*si+1,mid+1,se,qs,qe);
}


int main(){
    ll n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>v[i];
    build(1,1,n);
    // cout<<tree[1]<<endl;
    for(int i=1;i<=q;i++){
        ll type;
        cin>>type;

        if(type==1){
          ll a,b,u;
          cin>>a>>b>>u;
          update(1,1,n,a,b,u);
        }
        else
        {
            ll idx;
            cin>>idx;
           cout<<query(1,1,n,idx,idx)<<endl; 
        }
    }
}


