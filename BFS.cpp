#include <bits/stdc++.h>
#define max 10
#define vertex 9
#define edge 9
using namespace std;

void BFS (vector<int> adj[], int s)

{
    bool visited[max];
  for(int i = 0; i < vertex; i++)
        visited[i] = false;

 queue <int> q;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    vector <int> ::iterator i;
    while(!q.empty())
    {
        // Dequeue a vertex from queue and print it
        s = q.front();
        cout << s << " ";
        q.pop();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }

}



int main()

{
   int u,v;
  vector <int> adj [max];

  //cin<<

for (int i = 1; i <= edge; ++i) {
     cin>> u;
     cin>>v;
     adj[u].push_back(v);  // for directed graph
     // adj[v].push_back(u);

}


BFS (adj, 1);


}



/*
Sample input output :
Enter number of vertex : 9
Enter number of edges : 9
Enter ages EDGES :
1 2
2 3
1 5
1 4
4 7
7 8
8 9
2 6
5 7

*/

