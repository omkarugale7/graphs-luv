/*Editor: Omkar Ugale
Time : . 28th april 2022 */
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
void dfs(vector<vector<int>> &v, vector<int> &weights, vector<int> &sum, int vertex, int parent)
{
    sum[vertex] += weights[vertex];
    for (auto child : v[vertex])
    {
        if (child == parent)
            continue;
        dfs(v, weights, sum, child, vertex);
        sum[vertex] += sum[child];
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> weights(n + 1);
    for (int i = 0; i <= n; i++)
    {
        cin >> weights[i];
    }
    vector<int> sum(n + 1, 0);
    dfs(v, weights, sum, 1, 0);
    for (int i = 0; i <= n; i++)
    {
        cout << sum[i] << " "; // these are basically subtree sums
    }
    cout << endl;
    // now we want product
    int firstpart, nextpart, ans = 0;
    for (int i = 0; i <= n; i++)
    {
        firstpart = sum[i];
        nextpart = sum[1] - firstpart;
        ans = max(ans, firstpart * nextpart);
    }
    cout << ans << endl;
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
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13