#include<bits/stdc++.h>
#include<cstdlib>
#include<time.h>
#define ll unsigned long long
using namespace std;

bool basicprimality(int n){
    if(n==2 || n==3)
        return true;
    else{
        for(ll i=2;i<=n/2;i++){
            if(n%i==0)
                return false;

        }
        return true;
    }
}

ll binaryExponentiation(ll x,ll n){
    if(n==0)
        return 1;
    else if(n%2==0)
        return binaryExponentiation(x*x,n/2);
    else
        return x*binaryExponentiation(x*x,(n-1)/2);
}

bool FermatPrimality(int n){

    int k=5 ;
    while(k--){
    ll x;
    do{x=1+rand()%(n-1);
    }while(x==1);


    //cout<<x<<endl;
    ll e;
    e=binaryExponentiation(x,n-1);
    cout<<"e= "<<e<<endl;
    cout<<"e%n= "<<e%n<<endl;
    if((e)%n!=1)
        return false;

    }
    return true;

}



int main()
{
    ll n;
    bool bas,fer;
    int count1=0,count2=0,count3=0,count4=0;
    srand(unsigned (time(NULL)));
    for(int i=0;i<2;i++){
        n=5+rand()%30;
        //cout<<n<<" ";
        bas=basicprimality(n);
        fer=FermatPrimality(n);
        //cout<<bas<<" "<<fer<<endl;
        if(bas==1 && fer==1)
            count1++;
        else if(bas==1 && fer==0)
            count2++;
        else if(bas==0 && fer==1)
            count3++;
        else
            count4++;

    }
    cout<<endl<<"Basic and Fermat : "<<count1<<endl;
        cout<<"Basic and not Fermat : "<<count2<<endl;
        cout<<"Not Basic and Fermat : "<<count3<<endl;
        cout<<"Not Basic and not Fermat : "<<count4<<endl;

}
