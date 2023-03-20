#include <bits/stdc++.h>
using namespace std;
#define ll        long long int
// binary search + segment tree (range sum)
const ll maxN=2e5+10;
// building segment tree on summationation 
vector<ll> tree(maxN<<2),v(maxN,1);
void build(ll si, ll ss, ll se)
{
    if(ss==se){tree[si]=v[ss];return;}

    ll mid=(ss+se)/2;
    build(2*si,ss,mid);
    build(2*si+1,mid+1,se);
    tree[si]=tree[2*si]+tree[2*si+1];
}

ll query(ll si,ll ss, ll se, ll ql, ll qh)
{
    if(ss>qh || se<ql)return 0;
    if(ss>=ql && se<=qh) return tree[si];

    ll mid=(ss+se)/2;
    return query(2*si,ss,mid,ql,qh)+query(2*si+1,mid+1,se,ql,qh);
}

void update(ll si,ll ss, ll se, ll pos)
{
    if(ss==se)
    {
        tree[si]=0;
        return;
    }

    ll mid=(ss+se)/2;
    if(pos<=mid) update(2*si,ss,mid,pos);
    else update(2*si+1,mid+1,se,pos);
    tree[si]=tree[2*si]+tree[2*si+1];
}

int main()
{
    ll n;
    cin>>n;
    vector<ll> A(n+1);
    for(ll i=1;i<=n;i++)cin>>A[i];
    
    build(1,1,n);
    ll q=n; 
    while(q--)
    {
        ll pos;
        cin>>pos;
        // cout<<"for position "<<pos<<"::"<<endl;
        ll l=1,h=n;
        ll ans=-1;
        while(l<=h)
        {
            ll mid=l+(h-l)/2;
            // cout<<mid<<" "<<query(1,1,n,1,mid)<<endl;
            if(query(1,1,n,1,mid)==pos && v[mid]==1)
            {
              ans=mid;
              h=mid-1;
            }
            else if(query(1,1,n,1,mid)>pos)  
                   h=mid-1;
            else
                   l=mid+1;
        }
        update(1,1,n,ans);
        cout<<A[ans]<<" ";
        // cout<<ans<<"    ";
    }
}