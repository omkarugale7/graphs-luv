// finding cycles in the graph
/*Editor: Omkar Ugale
Time : .  15th April 2022 */
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const int N = 1e3 + 1;
vector<int> varr[N];
int visarr[N];
bool dfs(int vertex, int parent)
{
    visarr[vertex] = true;
    bool LoopExists = false;
    for (auto it : varr[vertex])
    {
        if (visarr[it] && parent == it) // it is child of vertex so vertex ka child visited hai and parent and child same hai
            continue;                   // this means ki the node it is actually the parent so we ignore it
        if (visarr[it])
            return true;
        LoopExists |= dfs(it, vertex);
    }
    return LoopExists;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        varr[a].push_back(b);
        varr[b].push_back(a);
    }
    bool IsloopExists = false;
    for (int i = 1; i <= n; i++)
    {
        if (visarr[i])
            continue;
        if (dfs(i, 0))
        {
            IsloopExists = true;
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for (auto it : varr[i])
        {
            cout << it << "  ";
        }
        cout << endl;
    }
    if (IsloopExists)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}
// 8 5
// 1 2
// 2 3
// 2 4
// 3 5
// 6 7
// 
// 
// 8 6
// 1 2
// 2 3
// 2 4
// 3 5  

// 6 7
// 1 5