/*Editor: Omkar Ugale
Time : .  19th April 2022 */
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
void dfs(vector<vector<int>> &image, int i, int j, int newcolor, int currentcolor)
{
    int n = image.size();
    int m = image[0].size();
    if (i < 0 || j < 0)
        return;
    if (j >= m || i >= n)
        return;
    if (image[i][j] != currentcolor)
        return;
    image[i][j] = newcolor;
    dfs(image, i - 1, j, newcolor, currentcolor);
    dfs(image, i + 1, j, newcolor, currentcolor);
    dfs(image, i, j - 1, newcolor, currentcolor);
    dfs(image, i, j + 1, newcolor, currentcolor);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int currentcolor = image[sr][sc];
    if(currentcolor!=newColor)
    dfs(image, sr, sc, newColor, currentcolor);
    return image;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> v[i][j];
        }
        int sourcerow, sourcecoloumn, newcolor;
        cin >> sourcerow >> sourcecoloumn >> newcolor;
        vector<vector<int>> ans = floodFill(v, sourcerow, sourcecoloumn, newcolor);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << v[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}