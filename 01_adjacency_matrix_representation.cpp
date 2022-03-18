/*Editor: Omkar Ugale
Time : . 14th feb 2022 */
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const int N = 1e3 + 1;
int graph[N][N];
int main()
{
   int n, m; // n-> number of nodes and m-> number of edges
   cin >> n >> m;

   for (int i = 0; i < m; i++)
   {
      int a, b;
      cin >> a >> b;
      graph[a][b] = 1;
      graph[b][a] = 1;
   }
   for (int i = 0; i <= n; i++)
   {
      for (int j = 0; j <= n; j++)
      {
         cout << graph[i][j] << " ";
      }
      cout << endl;
   }

   return 0;
}