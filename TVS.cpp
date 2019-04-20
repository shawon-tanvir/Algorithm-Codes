#include<bits/stdc++.h>
using namespace std;

void addedge(vector <pair<int,int> >tree[],int u,int v,int w){
    tree[u].push_back(make_pair(v,w));
}

void TVS(vector <pair<int,int> >tree[],int limit,int V){
    for (int u = 0; u < V; u++){
        if(u!=0){
            int delay=0;
            std::vector<pair<int,int> >::iterator it;
            //cout<<" For: "<<u+1<<endl;
            for (it = tree[u].begin(); it!=tree[u].end(); it++)
            {
                //int delay2=0;

                delay=max(delay,it->second);
                //cout<<"delay: "<<delay<<endl;
            }
            int parent;
            for (int k = 0; k < V; k++){
                for (it = tree[k].begin(); it!=tree[k].end(); it++){
                    if(it->first==u){
                       if((delay+it->second)>limit)
                            cout<<u+1<<" ";
                    }
                }
            }
            //cout << delay<<endl;
        }
    }
}

int main()
{
    int x;
    cin>>x;
    vector <pair<int,int> >tree[x];
    for(int i=0;i<x;i++){
        int u,v,w;
        cin>>u>>v>>w;
        addedge(tree,u-1,v-1,w);
    }
    std::vector<pair<int,int> >::iterator it;
    for (int k = 0; k < x; k++){
                for (it = tree[k].begin(); it!=tree[k].end(); it++){
                    cout<<k+1<<"  "<<it->first<<endl;
                }
            }
    int limit;
    cin>>limit;
    TVS(tree,limit,x);

}

/*
9
1 2 4
1 3 2
2 4 2
4 7 1
4 8 4
3 5 1
3 6 3
6 9 2
6 10 3
5

9
1 2 4
1 3 2
1 4 2
4 7 1
4 8 4
3 5 1
3 6 3
6 9 2
6 10 3
5


*/
