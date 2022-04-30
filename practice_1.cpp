/*Editor: Omkar Ugale
Time : .  13th April 2022 */
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const int N = 1e3 + 1;
int graph[N][N];
bool visarr[N] = {0};
vector<pair<int, int>> varr[N + 1];
void dfs(int a)
{
    cout << a << endl;
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
    cout << "ouput the nodes of which weight you want - ";
    int aa, bb;
    cin >> aa >> bb;
    cout << graph[aa][bb] << endl;
    for (auto it : varr[aa])
    {
        if (it.first == bb)
            cout << it.second <<endl;
    }
    dfs(1);
    return 0;
}
// 5 5
// 2 3 6
// 3 4 7
// 4 5 8
// 5 1 9
// 1 3 10