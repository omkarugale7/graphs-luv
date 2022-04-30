/*Editor: Omkar Ugale
Time : .  19th April 2022 */
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
void dfs(vector<vector<char>> &grid, int i, int j, int m, int n)
{
    cout << i << " " << j << " " << grid[i][j] << " z z  ";
    if (i < 0 || j < 0)
        return;
    if (j >= m || i >= n)
        return;
    if (grid[i][j] != '1')
        return;
    grid[i][j] = '0';
    cout << grid[i][j] << endl;
    dfs(grid, i - 1, j, m, n);
    dfs(grid, i + 1, j, m, n);
    dfs(grid, i, j - 1, m, n);
    dfs(grid, i, j + 1, m, n);
}
int numIslands(vector<vector<char>> &grid)
{
    int ans = 0, m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // cout << "yahaaya" << endl;
            if (grid[i][j] == '1')
            {
                ans++;
                cout << "yahaaya " << i << " " << j << " ans - " << ans << endl;
                dfs(grid, i, j, m, n);
            }
            cout << "k " << i << " " << j << endl;
        }
    }
    cout << "final ans = " << ans << endl;
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<char>> v(m, vector<char>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> v[i][j];
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << v[i][j] << " ";
            cout << endl;
        }
        int ans = numIslands(v);
        cout << ans << endl;
    }

    return 0;
}
// 1
// 4 5
// 1 1 0 0 0
// 1 1 0 0 0
// 0 0 1 0 0
// 0 0 0 1 1