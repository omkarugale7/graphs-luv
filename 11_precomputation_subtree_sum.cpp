/*Editor: Omkar Ugale
Time : . 28th march 2022 */
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
void dfs(vector<vector<int>> &arr, vector<int> &sum, vector<int> &evens, int vertice, int parent)
{
    sum[vertice] = vertice;
    evens[vertice] = (vertice-1) % 2;
    for (auto child : arr[vertice])
    {
        if (child == parent)
            continue;
        dfs(arr, sum, evens, child, vertice);
        evens[vertice] += evens[child];
        sum[vertice] += sum[child];
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    vector<int> sum(n + 1);
    vector<int> no_of_evens(n + 1);
    dfs(arr, sum, no_of_evens, 1, 0);
    for (int i = 0; i <= n; i++)
    {
        cout << sum[i] << " ";
    }
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << no_of_evens[i] << " ";
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
