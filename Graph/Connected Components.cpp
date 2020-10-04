/* Code to print number of connected components in an undirected graph */

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>v[], bool vis[], int node) 
{
    stack<int> s;
    vis[node] = true;
    s.push(node);
    while(!s.empty())
    {
        int p = s.top();
        s.pop();
        for(int i = 0; i < v[p].size(); i++)
        {
            if(vis[v[p][i]] == false)
            {
                int y = v[p][i];
                s.push(y);
                vis[y] = true;
            }
        }
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int>v[n+1];
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bool vis[n+1] = {false};
    int c = 0;
    for(int i = 1; i <= n ; i++)
    {
        if(vis[i] == false)
        {
            ++c;
            dfs(v,vis,i);
        }
    }
    cout<<c<<endl;
}
