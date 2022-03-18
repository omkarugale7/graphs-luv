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
   vector<int> varr[n + 1];
   for (int i = 0; i < m; i++)
   {
      int a, b;
      cin >> a >> b;
      varr[a].push_back(b);
      varr[b].push_back(a);
      arr[a][b] = 1;
      arr[b][a] = 1;
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
         cout << varr[i][j] << " ";
      cout << endl;
   }

   return 0;
}