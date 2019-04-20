#include<bits/stdc++.h>
#include<string>
using namespace std;
int c[1001][1001];

int LCS(string X,string Y,int m,int n){
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0)
                c[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(X[i-1]==Y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
            }
            else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
            }
            else{
                c[i][j]=c[i][j-1];
            }
        }
    }
    return c[m][n];
}

int main()
{
    string X,Y;
    //int p=1;
    while(getline(cin, X)){
        getline(cin,Y);
        int m=X.size();
        int n=Y.size();
        //cout<<m<<" "<<n;
        int length=LCS(X,Y,m,n);
        cout<<length<<endl;
    }
    return 0;
}
/*
ABCBDAB
BDCABA

*/

