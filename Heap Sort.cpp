#include<bits/stdc++.h>
#include<time.h>
#define maxnum 10
using namespace std;
int arafinal[maxnum];
int z=maxnum,a=maxnum;

void Insert(int ara[],int n)
{
    int i=n;
    int item=ara[n];
    while(i>0 && ara[i/2]<item){
        ara[i]=ara[i/2];
        i=i/2;
    }
    ara[i]=item;
}

void Adjust(int ara[],int i,int n){
    int j=i*2+1;
    int item=ara[i];
    while(j<=n){
        if(j<n && ara[j]<ara[j+1])
            j++;
        if(item>=ara[j])
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
    cout<<"Before Adjust"<<endl;
    for(int i=0;i<z;i++){
        cout<<ara[i]<<" ";
    }
    cout<<endl;
    Adjust(ara,0,n);
    return x;

}
void heapsort(int ara[],int n)
{
    int k=0;
    for(int i=0;i<n;i++){
        Insert(ara,i);
    }
    for(int i=0;i<maxnum;i++){
        cout<<ara[i]<<" ";
    }
    cout<<endl;
    for(int i=n-1;i>=0;i--){
        z--;
        arafinal[k++]=delmax(ara,i);
        a--;
        cout<<"After Adjust"<<endl;
        for(int i=0;i<a;i++){
            cout<<ara[i]<<" ";
        }

        cout<<endl;

    }


}

int main()
{
    int ara[maxnum];//={6,9,1,4,10,15,12,11,3,20};
    srand(time(NULL));
    for(int i=0;i<maxnum;i++){
        ara[i]=rand();
    }
    for(int i=0;i<maxnum;i++){
        cout<<ara[i]<<" ";
    }
    cout<<endl;
    heapsort(ara,maxnum);
    for(int i=0;i<maxnum;i++){
        cout<<arafinal[i]<<" ";
    }
    cout<<endl;

}
