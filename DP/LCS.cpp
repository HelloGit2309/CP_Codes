/* Given  to strings a and b. Finding the longest common subsequence between them */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007
#define FOR(i,x) for(int i = 0; i < x; i++)
#define For(x,y) for(int i = x; i <= y; i++)
#define vint(x) vector<int>x
#define vl(x) vector<long>x
#define vll(x) vector<long long>x
#define pb push_back
#define oset tree <int, null_type , less , rb_tree_tag, tree_order_statistics_node_update>
const int mx = 1e6;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a,b;
	cin>>a>>b;
	int n = a.length();
	int m = b.length();
	map<int,map<int,int>> dp;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i-1] == b[j-1])
			dp[i][j] = dp[i-1][j-1] + 1;
			else
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout<<dp[n][m];
}
