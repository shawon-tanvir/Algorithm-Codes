#include<bits/stdc++.h>
using namespace std;

int Fractional_Knapsack(int arav[], int araw[],double sorted[], int W,int n){

    int load = 0;
    int sum=0;
    int i = 0;
    while (load < W && i< n-1){
        if (arav[i]<= W - load){
            sum+=araw[i];
            load+=arav[i];
        }
        else{
            int k;
            k=(W-load);
            load+=k;
            sum+=k*sorted[i];
        }
        //cout<<load<<endl;
        //cout<<sum<<endl;
        i++;
    }
    //cout<<sum<<endl;
    return sum;
}

int main()
{
    int n,W;
    cin>>n;
    int araw[n],arav[n];
    double araratio[n], sorted[n];

    for(int i=0;i<n;i++)
        cin>>araw[i];
    for(int i=0;i<n;i++)
        cin>>arav[i];
    cin>>W;
    for(int i=0;i<n;i++){
        araratio[i]=(double)((double)araw[i]/(double)arav[i]);

    }
    for(int i=0;i<n;i++){
        sorted[i]=(double)(araratio[i]);
    }
    /*for(int i=0;i<n;i++)
        cout<<araratio[i]<<" ";
    cout<<endl;*/
    sort(sorted, sorted+n, greater<int>());
    /*for(int i=0;i<n;i++)
        cout<<sorted[i]<<" ";
    cout<<endl;*/
    int k=0;
    for(int i=0;i<n;i++){
        for(int l=0;l<n;l++){
            if(araratio[l]==sorted[i]){
                swap(araw[k],araw[l]);
                /*for(int i=0;i<n;i++){
                    cout<<araw[i]<<" ";
                }*/
                cout<<endl;
                swap(arav[k],arav[l]);
                swap(araratio[k],araratio[l]);
                k++;
                break;
            }

        }
    }
    /*for(int i=0;i<n;i++){
        cout<<araw[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arav[i]<<" ";
    }
    cout<<endl;*/
    cout<<Fractional_Knapsack(arav, araw,sorted, W,n);


}
