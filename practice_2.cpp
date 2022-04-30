//finding connected components in graph
/*Editor: Omkar Ugale
Time : .  13th April 2022 */
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const int N = 1e3 + 1;
int graph[N][N];
bool visarr[N] = {0};
vector<pair<int, int>> varr[N + 1];
vector<int> temp;
vector<vector<int>> storing_connected_components;
void dfs(int a)
{
    temp.push_back(a);
    visarr[a] = true;
    for (auto b : varr[a])
    {
        cout << "parent - " << a << "  child - " << b.first << endl;
        if (visarr[b.first] == true)
            continue;
        dfs(b.first);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
        varr[a].push_back(make_pair(b, c));
        varr[b].push_back(make_pair(a, c));
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for (auto it : varr[i])
        {
            cout << it.first << "-" << it.second << "  ";
        }
        cout << endl;
    }
    // dfs(1);
    int connectedcomponents = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visarr[i])
            continue;
        else
        {
            temp.clear();
            connectedcomponents++;
            cout << "component started" << endl;
            dfs(i);
            cout << "component ended" << endl;
            storing_connected_components.push_back(temp);
        }
    }
    cout << connectedcomponents << endl;
    for (auto it : storing_connected_components)
    {
        for (auto k : it)
            cout << k << " ";
        cout << endl;
    }
    return 0;
}
// 8 5
// 1 2 1
// 2 3 1
// 3 4 1
// 3 5 1
// 6 7 1