#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void bfs(vector<vector<int>> &graph, int visited[], int level[], queue<int> q, int vertex)
{
    q.push(vertex);
    visited[vertex] = 1;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        cout<<temp<<" ";
        for (auto it : graph[temp])
        {
            if (visited[it])
                continue;
            q.push(it);
            visited[it] = 1;
            level[it] = level[temp] + 1;  
        }
    }
    cout<<endl;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    int visited[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<int> q;
    int level[n + 1] = {0};
    bfs(graph, visited, level, q, 1);
    for (int i = 1; i <= n; i++)
    {
        cout << visited[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << level[i] << endl;
    }
    cout << endl;
}
// 13
// 1 2
// 1 3
// 1 13
// 2 5
// 3 4
// 5 6
// 5 7
// 5 8
// 8 12
// 4 9
// 4 10
// 10 11