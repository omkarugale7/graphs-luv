/*Editor: Omkar Ugale
Time : . 28th april 2022 */
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
void dfs(vector<vector<int>> &graph, int vertex, int parent, map<int, int> &ancestor)
{
    ancestor[vertex] = parent;
    for (auto child : graph[vertex])
    {
        if (child == parent)
            continue;
        dfs(graph, child, vertex, ancestor);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    map<int, int> ancestor;
    dfs(graph, 1, 0, ancestor);

    int q, r; // enter the numbers jinke common ancestor chahiye
    cin >> q >> r;
    vector<int> qrr;
    vector<int> rrr;
    int a = q;
    for (int i = 0; i < n; i++)
    {
        qrr.push_back(a);
        int b = ancestor[a];
        if (b == 0)
            break;
        a = b;
    }
    a = r;
    for (int i = 0; i < n; i++)
    {
        rrr.push_back(a);
        int b = ancestor[a];
        if (b == 0)
            break;
        a = b;
    }
    for (int i = 0; i < qrr.size(); i++)
    {
        cout << qrr[i] << " ";
    }
    cout << endl;
    int ans;
    for (int i = 0; i < rrr.size(); i++)
    {
        cout << rrr[i] << " ";
    }
    cout << endl;
    reverse(qrr.begin(), qrr.end());
    reverse(rrr.begin(), rrr.end());
    for (int i = 0; i < min(qrr.size(), rrr.size()); i++)
    {
        if (qrr[i] == rrr[i])
            ans = qrr[i];
        else
            break;
    }
    cout << ans << endl;

    return 0;
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