#include <bits/stdc++.h>
#define max 11
#define vertex 9
#define edge 9
using namespace std;
void BFS (vector<int> adj[], int s)

{
    bool visited[max];
    for(int i = 1; i <= vertex; i++)
        visited[i] = false;

    queue <int> q;
    visited[s] = true;
    q.push(s);

    vector <int> ::iterator it;
    cout<<"BFS Order: ";
    while(!q.empty())
    {
        s = q.front();
        cout << s << " ";
        q.pop();

        for (it = adj[s].begin(); it != adj[s].end(); ++it)
        {
            if (!visited[*it])
            {
                visited[*it] = true;
                // cout<<""<<*i<<endl;
                q.push(*it);
            }
        }
    }
    cout<<endl;

}

void DFS (vector<int> adj[], int s)

{
    bool visited[max];
    for(int i = 1; i <= vertex; i++)
        visited[i] = false;

    stack <int> st;

    st.push(s);


    vector <int> ::iterator it;
    cout<<"DFS Order: ";
    while(!st.empty())
    {
        s = st.top();
        cout << s << " ";
        st.pop();

        if (!visited[s])
        {
            visited[s] = true;
            for (it = adj[s].begin(); it != adj[s].end(); ++it)
            {
                if (!visited[*it])
                {
                //cout<<*i<<endl;
                    st.push(*it);
                }
            }
        }

    }

}



int main()

{
    int m,n;
    cout<<"Enter number of vertex: ";
    cin>>m;
    cout<<"Enter number of edges: ";
    cin>>n;

    int u,v;
    cout<<"Enter EDGES : "<<endl;
    vector <int> adj [max];

    for (int i = 1; i <= n; ++i)
    {
        cin>> u;
        cin>>v;
        adj[u].push_back(v);  // for directed graph
        //adj[v].push_back(u);

    }


    BFS (adj, 3);
    DFS (adj, 3);


}



/*
Sample input output :
Enter number of vertex : 9
Enter number of edges : 9
Enter ages EDGES :
9
9
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
