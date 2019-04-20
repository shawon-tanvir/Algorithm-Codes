#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int adj[m+1][m+1];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(i==j)
                adj[i][j]=0;
            else
                adj[i][j]=50;
        }
    }

    for(int i=1;i<=n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u][v]=w;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cout<<adj[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cout<<adj[i][j]<<"\t";
        }
        cout<<endl;
    }

}

/*
5 9
1 2 3
1 5 -4
1 3 8
2 5 7
2 4 1
3 2 4
4 3 -5
4 1 2
5 4 6

*/
