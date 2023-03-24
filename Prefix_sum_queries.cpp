#include <bits/stdc++.h>
using namespace std;
#include <cstdlib> 
#define loop      for(int i=1;i<=n;i++)
#define pb        push_back
#define ll        long long int


const ll maxN=2e5+10;
// first wil store maxprefix, second will store sum;

vector<pair<ll,ll>> tree(maxN<<2);
vector<ll> arr(maxN);

void build(ll si, ll ss ,ll se)
{
    if(ss==se)
    {
        tree[si].first=arr[ss];
        tree[si].second=arr[ss];
        return ;
    }
    ll mid=(ss+se)>>1;
    build(2*si,ss,mid);
    build(2*si+1,mid+1,se);
    tree[si].first=max(tree[2*si].first ,tree[2*si].second+tree[2*si+1].first);
    tree[si].second=tree[2*si].second+tree[2*si+1].second;
    return;
}

void update(ll si,ll ss, ll se,ll pos, ll val)
{
    if(ss==se)
    {
        tree[si].first=val;
        tree[si].second=val;
        arr[ss]=val;
        return ;
    }
    ll mid=(ss+se)>>1;
    if(pos<=mid)
    update(2*si,ss,mid,pos,val);
    else 
    update(2*si+1,mid+1,se,pos,val);
    tree[si].first=max(tree[2*si].first ,tree[2*si].second+tree[2*si+1].first);
    tree[si].second=tree[2*si].second+tree[2*si+1].second;
    return;
}

pair<ll,ll>  query(ll si,ll ss, ll se,ll qs,ll qe)
{
    if(ss>qe|| se<qs)
     return {0,0};

    if(ss>=qs && se<=qe)
    return tree[si];

    ll mid=(ss+se)>>1;
    pair<ll,ll> left=query(2*si,ss,mid,qs,qe);  
    pair<ll,ll> right=query(2*si+1,mid+1,se,qs,qe);
    pair<ll,ll> ans={0,0};
    ans.first=max(left.first,left.second+right.first);
    ans.second=left.second+right.second;
    return ans;
}


int main()
{
    ll n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>arr[i];
    build(1,1,n);
    // cout<<tree[1].first<<" "<<tree[1].second<<endl;
    while(q--)
    {
        ll type;
        cin>>type;
        if(type==1)
        {
            ll pos,val;
            cin>>pos>>val;
            update(1,1,n,pos,val);
        }
        else
        {
            ll a,b;
            cin>>a>>b;
            cout<<max(0ll,query(1,1,n,a,b).first)<<endl;
        }

    }

}