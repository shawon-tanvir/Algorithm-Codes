#include <bits/stdc++.h>
#define MAXTOTAL 10000
using namespace std;
long long nway[MAXTOTAL+1];
int coin[5] = { 50,25,10,5,1 };
int main()
{
    int i,j,n,v,c;
    scanf("%d",&n);
    v = 5;
    nway[0] = 1;
    for (i=0; i<v; i++)
    {
        c = coin[i];
        for (j=c; j<=n; j++)
            nway[j] += nway[j-c];
        for(int i=0;i<=n;i++){
        cout<<nway[i]<<" ";
        }
        cout<<endl;
    }


    printf("%lld\n",nway[n]);
}
