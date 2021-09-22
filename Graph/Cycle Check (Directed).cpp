/* Code to check cycle in a directed graph */

#include<bits/stdc++.h>
using namespace std;
bool isCycle(vector<int>v[], bool vis[], bool cv[], int node) // dfs search technique to check if a particular node comes again in a path forming a cycle
{
	if (cv[node])
		return true;
	if (vis[node])
		return false;
	cv[node] = true;
	vis[node] = true;
	for (int i = 0; i < v[node].size(); i++)
	{
		int y = v[node][i];
		if (isCycle(v, vis, cv, y))
			return true;
	}
	cv[node] = false;
	return false;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int>v[n + 1];
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	bool vis[n + 1] = {false};
	bool cv[n + 1] = {false};
	int flag = 0;
	for (int i = 1; i <= n ; i++)  // loop to check cycles in all the connected components of the graph
	{
		if (vis[i] == false)
		{
			if (isCycle(v, vis, cv, i))
				flag = 1;
		}
		if (flag)
			break;
	}
	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}