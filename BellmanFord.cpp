#include<bits/stdc++.h>
//#define max 10
using namespace std;

bool Bellmanord(vector<pair<int,int> > adj[],vector<pair<int,string> > num[],int m,int s)
{
    vector<int> distance(10,std::numeric_limits<int>::max());
    int parent[m+1];
    distance[s]=0;

    vector <pair<int,int> > ::iterator it;
    for(int d=1;d<=m-1;d++){
        for(int i=1;i<=m;i++){
            for(it=adj[i].begin();it!=adj[i].end();it++){
                int v= it->first;
                int w= it->second;
                if(distance[v]>distance[i]+w){
                    distance[v]=distance[i]+w;
                    parent[v]=i;
                }
            }
        }
    }
    for(int i=1;i<=m-1;i++){
        for(it=adj[i].begin();it!=adj[i].end();it++){
            int v= it->first;
            int w= it->second;
            if(distance[v]>distance[i]+w){
                return false;
            }
            else{
                vector<pair<int,string> >::iterator itr;
                cout<<"From\tTo\tDistance"<<endl;
                for(int i=1;i<=m;i++){
                    cout<<"s\t";
                    for(int j=1;j<=m;j++){
                        for(itr=num[j].begin();itr!=num[j].end();itr++){
                            if(itr->first==i)
                                cout<<itr->second<<"\t"<<distance[i]<<endl;
                        }
                    }
                }
                return true;
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
    cout<<"Enter EDGES and weight : "<<endl;
    string u,v;
    int w;

    vector <pair<int,int> > adj [20];
    vector<pair<int,string> > num[20];
    vector<pair<int,int> > pa[20];
    int k=1;
    int ser=1;
    int weight[n+1];
    int wcount=1;
    for (int i = 1; i <= n; ++i)
    {
        int c,d;
        vector<pair<int,string> >::iterator it;
        cin>>u;
        int j;
        bool f1=false,f2=false;
        for(j=1;j<=ser+1;j++){
            for(it=num[j].begin();it!=num[j].end();it++){
                if(it->second!=u){
                    continue;
                    //c=k-1;
                }
                else if(it->second==u){
                    c=it->first;
                    f1=true;
                    break;
                }
            }
            if(f1==true)
                break;
        }
        if(j>ser){
            num[ser++].push_back(make_pair(k++,u));
            c=k-1;
        }
        //cout<<"c= "<<c<<endl;
        //int value1=u;
        //cout<<value1<<endl;
        cin>>v;
        int l;
        for(l=1;l<=ser+1;l++){
            for(it=num[l].begin();it!=num[l].end();it++){
                if(it->second!=v){
                    continue;
                    //c=k-1;
                }
                else if(it->second==v){
                    d=it->first;
                    f2=true;
                    break;
                }
            }
            if(f2==true)
                break;
        }
        if(l>ser){
            num[ser++].push_back(make_pair(k++,v));
            d=k-1;
        }
        //cout<<"d= "<<d<<endl;
        pa[i].push_back(make_pair(c,d));
        //int value2=v;
        //cout<<value1<<endl;
          // for directed graph
        //adj[v].push_back(u);
        //cout<<"ser= "<<ser<<" k= "<<k<<" wight= "<<wcount<<endl;
        cin>>w;
        weight[wcount++]=w;

    }
    wcount=1;
    vector<pair<int,int> >::iterator it1;
    for(int j=1;j<n+1;j++){
        for(it1=pa[j].begin();it1!=pa[j].end();it1++){
            adj[it1->first].push_back(make_pair(it1->second,weight[wcount++]));
        }
    }
    /*cout<<endl;
    vector<pair<int,int> > ::iterator it2;
    for(int j=1;j<n+1;j++){
        for(it2=adj[j].begin();it2!=adj[j].end();it2++){
            cout<<j<<" "<<it2->first<<" "<<it2->second<<endl;
        }
    }*/
    vector<pair<int,string> >::iterator itr;
    if(Bellmanord(adj,num,m,1)==false){
        cout<<"Negative Cycle";
        return 0;
    }

    else{
        return 0;
    }
}

/*
5 10
s t 6
s y 7
t y 8
t x 5
t z -4
y x -3
y z 9
x t -2
z s 2
z x 7

*/
