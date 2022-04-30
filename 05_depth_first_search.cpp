/*Editor: Omkar Ugale
Time : . 16th feb 2022 */
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const int N = 1e3 + 1;
vector<int> varr[N];
bool vis[N];
void dfs(int vertex) // we will divide our dfs code into 4 sections
{
   /* what we will do here in this section is that after
   entering a vertex we will take some action upon it*/
   cout << vertex << endl; // action we took was printing the vertex and marking its value as true in visited array
   vis[vertex] = true;
   for (auto child : varr[vertex])
   {
      /*in this section we'll take action upon the child BEFORE entering the child node
      here before means we havent yet started the dfs*/
      cout << "parent - " << vertex << " child - " << child << endl;
      if (vis[child])
         continue;
      dfs(child);
      /*take action  upon the child AFTER exiting the node, after becuse dfs has ended*/
   }
   /*take action  upon the vertex BEFORE exiting the vertex , before because dfs of the vertex hasnt ended yet*/
}// time complexity of dfs is O(n+m)
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
   for (int i = 1; i <= n; i++)
   {
      cout << i << "-";
      for (int j = 0; j < varr[i].size(); j++)
         cout << varr[i][j] << " ";
      cout << endl;
   }
   dfs(1);

   return 0;
}