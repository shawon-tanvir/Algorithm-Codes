#include <bits/stdc++.h>
#define MAXTOTAL 10000
using namespace std;
int nway[MAXTOTAL+1];
int coin[4] = { 7,2,3,6 };
int parent[MAXTOTAL+1];
int main()
{
    int i,j,n,v,c;
    //scanf("%d",&n);
    n=20;
    v = 4;
    for(int i=0;i<=n;i++){
        nway[i]=20;
    }
    for(int i=0;i<=n;i++){
        parent[i]=-1;
    }
    nway[0] = 0;

    for(int i=0;i<=n;i++){
        cout<<nway[i]<<" ";
    }
    cout<<endl;
    for (i=0; i<v; i++) {
        c = coin[i];
        for (j=c; j<=n; j++){
            int p=nway[j];
            int q=1+nway[j-c];
            if(p==q || p<q)
                continue;
            //nway[j] =min(nway[j],1+nway[j-c]);
            else{
                nway[j] =q;
                parent[j]=i;
            }
        }
    }
    for(int i=0;i<=n;i++){
        cout<<nway[i]<<" ";
    }
    cout<<endl;

    printf("%d\n",nway[n-1]);
    i=n-1;
    while(1){
        cout<<coin[parent[i]]<<" ";
        if(n-coin[parent[i]]!=0){
            int x=i;
            i=n-coin[parent[i]];
            n=n-coin[parent[x]];
        }
        else
            break;
    }
    return 0;
}

