/*Editor: Omkar Ugale
Time : . 19th feb 2022 */
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e3 + 1;
vector<int> graph[N];
bool VisArr[N];
bool dfs(int vertex, int parent)
{
   VisArr[vertex] = true;
   bool isLoopExists = false;
   cout << vertex << endl;
   for (auto child : graph[vertex])
   {
      cout << "parent - " << vertex << " child - " << child << endl;
      if (VisArr[child] && child == parent)
         continue;
      if (VisArr[child])
         return true;

      isLoopExists |= dfs(child, vertex);
   }
   return isLoopExists;
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
   bool isLoopExists = false;
   for (int i = 1; i <= n; i++)
   {
      if (!VisArr[i])
      {
         if(dfs(i,0))
         {
            isLoopExists = true;
            break;
         }
      }
      else
         continue;
   }
   cout<<isLoopExists<<endl;
   return 0;
}
// 8 5
// 1 2
// 2 3
// 2 4
// 3 5
// 6 7
/*
8 6
1 2
2 3
2 4
3 5
6 7
1 5
*/