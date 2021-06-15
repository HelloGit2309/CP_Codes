// Longest Increasing Subsequence in O(n) complexity
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007
#define FOR(i,x) for(ll i = 0; i < x; i++)
#define For(i,x,y) for(ll i = x; i <= y; i++)
#define rep(i,x,y) for(int i = x; i >= y; i--)
#define vint(x) vector<int>x
#define vl(x) vector<long>x
#define vll(x) vector<long long>x
#define um unordered_map
#define pb push_back
#define pll pair<ll,ll>
#define mone cout<<-1<<"\n"
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define nl cout<<"\n"
#define oset tree <int, null_type , less , rb_tree_tag, tree_order_statistics_node_update>
#define INF 1000000000000000000
const ll mx = 1e5;
/*ll numinv[mx+1];
void InverseofNumber(ll p)
{
    numinv[0] = numinv[1] = 1;
    for (ll i = 2; i <= mx; i++)
        numinv[i] = numinv[mod % i] * (mod - mod / i) % mod;
}
ll fac[mx+1] = {0}, infac[mx+1] = {0};
ll comb(ll n, ll r)
{
	if(r > n)
	return 0;
	return (fac[n]%mod * infac[r]%mod * infac[n-r]%mod)%mod;
}*/
ll power(ll a,ll b)
{
    if(b == 0)
    return 1;
    if(b&1)
    return (a%mod * power((a%mod * a%mod)%mod, (b-1)/2)%mod)%mod;
    return power((a%mod * a%mod)%mod, b/2)%mod;
}
ll fact(ll a, ll b)
{
    if(a == b)
    return 1;
    return (a%mod * fact(a-1,b)%mod)%mod;
}
bool sortthis(pair<ll,ll> &a,pair<ll,ll> &b)
{
    return (a.first > b.first);
}
bool prime(ll n)
{
	if(n == 2)
	return true;
	if(n%2 == 0 || n == 1)
	return false;
	for(ll i = 3; (i*i) <= n; i += 2)
	{
		if(n%i == 0)
		return false;
	}
	return true;
}
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	t=1;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    vector<ll>v;
	    FOR(i,n)
	    {
	    	ll a;
	    	cin>>a;
	    	auto it = lower_bound(v.begin(), v.end(), a);
	    	if(it == v.end())
	    	v.pb(a);
	    	else
	    	*it = a;
		}
		cout<<v.size()<<"\n";
	}
}
