/* Total ways of dividing numbers of sequence 1,2,3,...,n into two equal subsets (Using 0/1 Knapsack Method)
	Problem Link: https://cses.fi/problemset/task/1093 		*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007
#define FOR(i,x) for(int i = 0; i < x; i++)
#define For(i,x,y) for(int i = x; i <= y; i++)
#define rep(i,x,y) for(int i = x; i >= y; i--)
#define um unordered_map
#define vint(x) vector<int>x
#define vl(x) vector<long>x
#define vll(x) vector<long long>x  
#define pb push_back
#define oset tree <int, null_type , less , rb_tree_tag, tree_order_statistics_node_update>
const int mx = 3*1e5;;
ll power(ll a,ll b)
{
    if(b == 0)
    return 1;
    if(b&1)
    return (a%mod * power((a%mod * a%mod)%mod, (b-1)/2)%mod)%mod;
    return power((a%mod * a%mod)%mod, b/2)%mod;
}
ll fact(ll a)
{
    if(a == 0)
    return 1;
    return (a%mod * fact(a-1)%mod)%mod;
}
bool sortthis(pair<ll,ll> &a, pair<ll,ll> &b)
{
    if(a.second > b.second)
    return true;
    return false;
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
	    ll s = n*(n+1)/2;
	    if(s&1)
	    {
	    	cout<<0<<"\n";
	    	continue;
		}
	    ll dp[n+1][s/2+1];
	    memset(dp,0,sizeof(dp));
	    for(int i = 0; i <= n; i++)
	    dp[i][0] = 1;
		For(i,1,n)
		{
			For(j,1,s/2)
			{
				if(i <= j)
				dp[i][j] = dp[i-1][j - i];
				dp[i][j] += dp[i-1][j];
			}
		}
		cout<<dp[n-1][s/2]<<"\n";
	}
}
