/*Editor: Omkar Ugale
Time : . 18th feb 2022 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e3 + 1;
vector<int> graph[N];
int VisArr[N];
vector<vector<int>> connected_components;
vector<int> curr_comp;
void dfs(int vertex)
{
   VisArr[vertex] = 1;
   curr_comp.push_back(vertex);
   cout << vertex << endl;
   for (auto child : graph[vertex])
   {
      cout << "parent - " << vertex << " child - " << child << endl;
      if (VisArr[child])
         continue;
      dfs(child);
   }
}
int main()
{
   int n, e; // n -> nodes , m-> edges
   cin >> n >> e;
   for (int i = 0; i < e; i++)
   {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
   }
   for (int i = 1; i <= n; i++)
   {
      cout << i << " - ";
      for (int j = 0; j < graph[i].size(); j++)
      {
         cout << graph[i][j] << " ";
      }
      cout << endl;
   }
   int ans = 0;
   for (int i = 1; i <= n; i++)
   {
      if (!VisArr[i])
      {
         curr_comp.clear();
         dfs(i);
         connected_components.push_back(curr_comp);
         cout << "this ones done\n";
         cout << endl;
         ans++;
      }
      else
         continue;
   }
   cout << "no. of CCs - " << connected_components.size() << endl;
   cout << "connected components - " << endl;
   for (auto comp : connected_components)
   {
      for (auto element : comp)
         cout << element << " ";
      cout << endl;
   }
   return 0;
}
// 8 5
// 1 2
// 2 3
// 2 4
// 3 5
// 6 7