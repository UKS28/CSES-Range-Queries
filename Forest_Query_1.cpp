#include <bits/stdc++.h>
using namespace std;
// #define ll       long long int
#define ll long long int

ll query(vector<vector<ll>> &v,ll x1,ll y1, ll x2,ll y2)
{
    return (v[x2][y2]+v[x1-1][y1-1]-v[x2][y1-1]-v[x1-1][y2]);
}


int main(){
   ll n,q;
   cin>>n>>q;

   vector<vector<ll>> v(n+1,vector<ll> (n+1,0));

   for(int i=1;i<=n;i++)
   {
    for(int j=1;j<=n;j++)
    {
        char ch;
        cin>>ch;
        if(ch=='*')v[i][j]=1;
        v[i][j]+=v[i][j-1];
    }
   }

   for(int i=1;i<=n;i++)
   {
    for(int j=1;j<=n;j++)
    {
        v[i][j]+=v[i-1][j];
    }
   }

   while(q--)
   {
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<query(v,x1,y1,x2,y2)<<endl;

   }



}