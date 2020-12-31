//  Given a string and subsequence. This code prints the count of occurence of that sequence in the string.
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
	string s, b;
	cin>>s>>b;
	ll n = s.length(), m = b.length();
    ll dp[m+1][n+1] = {{0}};
    for(int i = 0; i <= n; i++)	// Empty string case
    dp[0][i] = 1;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s[j-1] == b[i-1])
            dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            else
            dp[i][j] = dp[i][j-1];
        }
    }
    cout<<dp[m][n];
}
