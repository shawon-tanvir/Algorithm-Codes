#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int c[101][101]={};
char b[101][101]={};
int result[101];
int k=0;
void Print_LCS(char X[101][31],int m,int n){
    if(m==0 || n==0)
        return;
    if(b[m][n]=='D'){

        Print_LCS(X,m-1,n-1);
        result[k++]=m-1;

    }
    else if(b[m][n]=='U'){
        Print_LCS(X,m-1,n);
    }
    else
        Print_LCS(X,m,n-1);
}

int LCS(char X[101][31],char Y[101][31],int m,int n){

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(!strcmp(X[i-1],Y[j-1])){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='D';
            }
            else{
                if(c[i-1][j]>=c[i][j-1]){
                    c[i][j]=c[i-1][j];
                    b[i][j]='U';
                }
                else{
                    c[i][j]=c[i][j-1];
                    b[i][j]='L';
                }
            }
        }
    }
    return c[m][n];
}

int main()
{
    while(1){
        char X[101][31],Y[101][31];
        int i=0;
        while(1){

            if(scanf("%s",X[i])!=1)
                return 0;
            if(!strcmp(X[i],"#")){
                break;
            }
            i++;
        }
        int m=i;
        i=0;
        while(1){
            if(scanf("%s",Y[i])!=1)
                return 0;
            if(!strcmp(Y[i],"#")){
                break;
            }
            i++;
        }
        int n=i;
        //cout<<m<<" "<<n;
        int length=LCS(X,Y,m,n);
        Print_LCS(X,m,n);
        result[length]=100007;
        printf("%s",X[result[0]]);
        for(int i=1;result[i]!=100007;i++){
            printf(" %s",X[result[i]]);
        }
        cout<<endl;
    }
    return 0;
}

