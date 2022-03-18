/*Editor: Omkar Ugale
Time : . 14th feb 2022 */
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const int N = 1e3 + 1;
int arr[N][N]; // we're declaring it globally as value is initialized to 0 upon declaring globally.
int main()
{
   int n, m;
   cin >> n >> m;
   vector<pair<int, int>> varr[n + 1];
   for (int i = 0; i < m; i++)
   {
      int a, b, wt;
      cin >> a >> b >> wt;
      varr[a].push_back(make_pair(b, wt));
      varr[b].push_back(make_pair(a, wt));
      arr[a][b] = wt;
      arr[b][a] = wt;
   }
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
         cout << arr[i][j] << " ";
      cout << endl;
   }
   for (int i = 0; i < n; i++)
   {
      cout << i << "-";
      for (int j = 0; j < varr[i].size(); j++)
         cout << varr[i][j].first << " " << varr[i][j].second << "  ";
      cout << endl;
   }

   return 0;
}
// input
//  6 9
//  1 3 4
//  1 5 3
//  3 5 2
//  3 4 7
//  3 6 8
//  3 2 9
//  2 6 1
//  4 6 2
//  5 6 3