#include <bits/stdc++.h>
using namespace std;
#include <cstdlib> 

#define pb        push_back
#define ll        long long int
class SGTree {
	vector<ll> seg;
public:
	SGTree(int n) {
		seg.resize(4 * n + 1);
	}

	void build(int i, int low, int high, vector<ll> &arr) {
		if (low == high) {
			seg[i] = arr[low];
			return;
		}

		int mid = (low + high) / 2;
		build(2 * i + 1, low, mid, arr);
		build(2 * i + 2, mid + 1, high, arr);
		seg[i] = seg[2 * i + 1]+ seg[2 * i + 2];
	}

	ll query(int i, int low, int high, int l, int r) {
		// no overlap
		// l r low high or low high l r
		if (r < low || high < l) return 0;

		// complete overlap
		// [l low high r]
		if (low >= l && high <= r) return seg[i];

		int mid = (low + high) >> 1;
		ll left = query(2 * i + 1, low, mid, l, r);
		ll right = query(2 * i + 2, mid + 1, high, l, r);
		return left + right;
	}
	void update(int i, int low, int high, int idx, int val) {
		if (low == high) {
			seg[idx] = val;
			return;
		}

		int mid = (low + high) >> 1;
		if (i <= mid) update(2 * i + 1, low, mid, idx, val);
		else update(2 * i + 2, mid + 1, high, idx, val);
		seg[i] = min(seg[2 * i + 1], seg[2 * i + 2]);
	}
};

int main()
{
    int n,q;
    cin>>n>>q;
    vector<ll> v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    SGTree st(n);
    st.build(0,0,n-1,v);

    while(q--)
    {
        ll l,h;
        cin>>l>>h;
        l--;h--;

        cout<<st.query(0,0,n-1,l,h)<<endl;
    }

} 