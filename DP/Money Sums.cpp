/*   We have n coins with certain values. Task is to find all money sums we can create using these coins 
	Problem Link: [https://cses.fi/problemset/task/1745]	*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007
#define FOR(i,x) for(int i = 0; i < x; i++)
#define For(i,x,y) for(int i = x; i <= y; i++)
#define vint(x) vector<int>x
#define vl(x) vector<long>x
#define vll(x) vector<long long>x
#define pb push_back
#define oset tree <int, null_type , less , rb_tree_tag, tree_order_statistics_node_update>
const int mx = 1e6;
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	ll arr[n];
	FOR(i,n)
	cin>>arr[i];
	sort(arr, arr+n);
	ll s = 0;
	unordered_map<ll,ll>hash;
	vector<ll>v;
	FOR(i,n)
	s = arr[i] + s;
	v.pb(s);
	hash[s] = 1;
	FOR(i,n)
	{
		if(hash[arr[i]] == 0)
		{
			v.pb(arr[i]);
			hash[arr[i]] = 1;
		}
		vector<ll> p;
		FOR(j,v.size())
		{
			if(arr[i] < v[j])
			{
				ll z = v[j] - arr[i];
				if(hash[z] == 0)
				p.pb(z);
				hash[z] = 1;
			}
		}
		FOR(j,p.size())
		v.pb(p[j]);
	}
	sort(v.begin(), v.end());
	cout<<v.size()<<"\n";
	FOR(i,v.size())
	cout<<v[i]<<" ";
}

