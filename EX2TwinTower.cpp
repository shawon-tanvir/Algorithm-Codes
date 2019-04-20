#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int c[101][101]={};
char b[101][101]={};

int LCS(int X[101],int Y[101],int m,int n){

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(X[i-1]==Y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
            }
            else{
                if(c[i-1][j]>=c[i][j-1]){
                    c[i][j]=c[i-1][j];
                }
                else{
                    c[i][j]=c[i][j-1];
                }
            }
        }
    }
    return c[m][n];
}

int main()
{
    int p=1;
    while(1){
        int n1,n2;
        cin>>n1>>n2;
        if(n1==0 && n2==0)
            return 0;
        int X[101],Y[101];
        int i=0;
        for(int i=0;i<n1;i++){
            cin>>X[i];
        }
        for(int i=0;i<n2;i++){
            cin>>Y[i];
        }

        //cout<<m<<" "<<n;
        int length=LCS(X,Y,n1,n2);

        cout<<"Twin Towers #"<<p++<<endl;
        cout<<"Number of Tiles : "<<length<<endl;
        cout<<endl;
    }
    return 0;
}


