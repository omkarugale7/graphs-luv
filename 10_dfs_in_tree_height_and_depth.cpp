/*Editor: Omkar Ugale
Time : . 28th march 2022 */
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
void dfs(vector<vector<int>> &arr, vector<int> &depth, vector<int> &height, int vertice, int parent)
{
    for (auto child : arr[vertice])
    {
        if (child == parent)
            continue;
        depth[child] = (depth[vertice] + 1);
        dfs(arr, depth, height, child, vertice);
        height[vertice] = max(height[vertice], height[child] + 1);
    }
}
int main()
{
    int n, m;
    cin >> n >> m; // as this is tree there's no need of m because in a tree with n nodes it will be having n-1 edges
    vector<vector<int>> arr(n + 1);
    vector<int> depth(n + 1, 0);
    vector<int> height(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[b].push_back(a);
        arr[a].push_back(b);
    }
    dfs(arr, depth, height, 1, 0);
    for (int i = 1; i <= n; i++)
        cout << depth[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << height[i] << " ";
    cout << endl;
    return 0;
}

// 13 12
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
