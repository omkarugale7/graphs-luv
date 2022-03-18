/*Editor: Omkar Ugale
Time : . 16th feb 2022 */
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const int N = 1e3 + 1;
vector<int> varr[N];
bool vis[N];
void dfs(int vertex)
{
   cout<<vertex<<endl;
   vis[vertex] = true;
   for (auto child : varr[vertex])
   {
      cout << "parent - " << vertex << " child - " << child << endl;
      if (vis[child])
         continue;
      dfs(child);
   }
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
   for (int i = 1; i <=n; i++)
   {
      cout << i << "-";
      for (int j = 0; j < varr[i].size(); j++)
         cout << varr[i][j] << " ";
      cout << endl;
   }
   dfs(1);

   return 0;
}