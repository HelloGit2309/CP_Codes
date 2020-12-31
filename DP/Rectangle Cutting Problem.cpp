/* proble link : [https://cses.fi/problemset/task/1744]
	My Solution is O(A*B(A+B))  */
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
	int a,b;
	cin>>a>>b;
	int dp[a+1][b+1] = {{0}};
	For(i,1,a)
	{
		For(j,1,b)
		{
			if(i == j)
			continue;
			dp[i][j] = INT_MAX;
			for(int k = 1; k < i; k++)	// checking all horizontal cuts
			dp[i][j] = min(dp[i][j], 1+dp[i-k][j] + dp[k][j]);
			for(int k = 1; k < j; k++)	// checking all vertical cuts
			dp[i][j] = min(dp[i][j], 1+dp[i][j-k]+dp[i][k]);
		}
	}
	cout<<dp[a][b];
}
