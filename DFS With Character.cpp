#include <bits/stdc++.h>
#define max 11
#define vertex 9
#define edge 9
using namespace std;
void BFS (vector<int> adj[], int s,vector<pair<int,string> > num[max])

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
        vector<pair<int,string> >::iterator itr;
        bool f1=false,f2=false;
        for(int l=1;l<=vertex;l++){
            for(itr=num[l].begin();itr!=num[l].end();itr++){
                if(itr->first!=s){
                    continue;
                    //c=k-1;
                }
                else if(itr->first==s){
                    cout<<itr->second<<" ";
                    f2=true;
                    break;
                }
            }
            if(f2==true)
                break;
        }
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

void DFS (vector<int> adj[], int s,vector<pair<int,string> > num[max])

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
        vector<pair<int,string> >::iterator itr;
        bool f1=false,f2=false;
        for(int l=1;l<=vertex;l++){
            for(itr=num[l].begin();itr!=num[l].end();itr++){
                if(itr->first!=s){
                    continue;
                    //c=k-1;
                }
                else if(itr->first==s){
                    cout<<itr->second<<" ";
                    f2=true;
                    break;
                }
            }
            if(f2==true)
                break;
        }
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
    cout<<"Enter EDGES : "<<endl;
    string u,v;

    vector <int> adj [max];
    vector<pair<int,string> > num[max];
    vector<pair<int,int> > pa[max];
    int k=1;
    int ser=1;
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
        //cout<<"ser= "<<ser<<" k= "<<k<<endl;

    }
    vector<pair<int,int> >::iterator it1;
    for(int j=1;j<ser;j++){
        for(it1=pa[j].begin();it1!=pa[j].end();it1++){
            adj[it1->first].push_back(it1->second);
        }
    }




    BFS (adj, 1,num);
    DFS (adj, 1,num);


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

arc1 b
b c
arc1 e
arc1 d
d g
g hi
hi i
b f
e g
*/

