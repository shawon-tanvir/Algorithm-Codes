#include<bits/stdc++.h>
using namespace std;

void Insert(int ara[],int n)
{
    int i=n;
    int item=ara[n];
    while(i>0 && ara[i/2]>item){
        ara[i]=ara[i/2];
        i=i/2;
    }
    ara[i]=item;
}

void Adjust(int ara[],int i,int n){
    int j=i*2+1;
    int item=ara[i];
    while(j<=n){
        if(j<n && ara[j]>ara[j+1])
            j++;
        if(item<=ara[j])
            break;
        ara[j/2]=ara[j];
        j=2*j;
    }
    ara[j/2]=item;
}

int delmax(int ara[],int n){
    int x;
    if(n==0){
        return ara[0];
    }

    x=ara[0];
    ara[0]=ara[n];

    Adjust(ara,0,n);
    /*cout<<"After Adjust"<<endl;
    for(int i=0;i<n;i++){
        cout<<ara[i]<<" ";
    }
    cout<<endl;*/
    return x;

}

void addedge(vector <pair<int,int> >tree[],int u,int v,int w){
    tree[u].push_back(make_pair(v,w));
    //tree[v].push_back(make_pair(u,w));
}

int findedge(int parent[],int i){
    while(parent[i]!=-1){
        i=parent[i];
    }
    return i;
}
void uni(int parent[],int j,int i){
    if(i!=j){
        parent[j]=i;
        //return 1;
    }
    //return 0;
}

void kruskal(vector <pair<int,int> >tree[],int ara[],int n,int V){
    int i;
    for(i=0;i<n;i++){
        Insert(ara,i);
    }
    /*for(int i=0;i<n;i++){
        cout<<ara[i]<<" ";
    }
    cout<<endl;*/
    int parent[V];
    for(i=0;i<V;i++){
        parent[i]=-1;
    }
    i=0;
    int mincost=0;
    int del;
    int p=n-1;
    int c=1;
    std::vector<pair<int,int> >::iterator it;
    for(int i=0;i<V;i++){
            cout<<c++<<" ";
        }
    cout<<endl;
    while(i<n-1 && p!=-1){
        del=delmax(ara,p--);
        del=delmax(ara,p--);

        //cout<<del<<endl;
        //del=delmax(ara,p--);

        //cout<<del<<" ";
        int j,k;
        int cp1,cp2;
        bool flag=0;
        for (int ver = 0; ver < V; ver++){
            for (it = tree[ver].begin(); it!=tree[ver].end(); it++){
                //cout<<it->second<<" check "<<del<<endl;
                if(it->second==del){
                    if(flag==0){
                        cp1=ver;
                        cp2=it->first;
                        j=findedge(parent ,ver);
                        k=findedge(parent,it->first);
                        it->second=0;
                        flag=1;
                    }
                    else if(flag==1 && ver==cp2 && it->first==cp1)
                        it->second=0;
                    //cout<<j<<" vertex "<<k<<endl;
                }

            }
            //if(flag==1)
               // break;
            //break;
        }
        if(j!=k){
            i++;
            mincost=mincost+del;
            uni(parent,j,k);
        }
        cout<<del<<" "<<j+1<<" "<<k+1<<endl;
        for(int i=0;i<V;i++){
            cout<<parent[i]+1<<" ";
        }
        cout<<endl;

    }
    cout<<mincost<<endl;

}

int main()
{
    int x,v;
    cin>>v>>x;
    int ara[x];
    vector <pair<int,int> >tree[x];
    for(int i=0;i<x;i++){
        int u,v,w;
        cin>>u>>v>>w;
        ara[i]=w;
        addedge(tree,u-1,v-1,w);
    }
    for(int i=0;i<x;i++){
        cout<<ara[i]<<" ";
    }
    cout<<endl;
    kruskal(tree,ara,x,v);

}

/*

7 18
1 6 10
1 2 28
2 1 28
2 3 16
2 7 14
3 2 16
3 4 12
4 5 22
4 7 18

4 3 12
5 6 25
5 7 24
5 4 22
6 1 10
6 5 25
7 5 24
7 2 14
7 4 18

*/
