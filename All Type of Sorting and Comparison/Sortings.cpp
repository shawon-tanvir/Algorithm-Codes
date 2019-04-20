#include<bits/stdc++.h>
#include<stdlib.h>
#include<limits>
#include<time.h>
#include<fstream>
#define n 100000

using namespace std;

void bubblesort(int ara[n])
{
    int k,temp;
    k=n;
    while(k!=0){
        temp=0;
        for(int j=0;j<k-1;j++){
            if(ara[j]>ara[j+1]){
                swap(ara[j],ara[j+1]);
                temp=j+1;
            }
        }
        k=temp;
    }
}
void bubblesortcheck(int ara[]){
    /*for(int i=0;i<n;i++){
        cout<<ara[i]<<" ";
    }
    cout<<endl;
    */
    int ara2[n];
    for(int i=0;i<n;i++)
         ara2[i]=ara[i];

    double start,end,time_diff;
    start=clock();
    bubblesort(ara2);
    end=clock();
    time_diff=((double)(end-start))/CLOCKS_PER_SEC;
    cout <<"Time for Soring: " << 1000*time_diff << endl;

    std::fstream fs;
    fs.open ("bubble.txt",fstream::in | fstream::out | fstream::app);

    fs << n<<"  "<<time_diff<<endl;

    fs.close();

    /*for(int i=0;i<n;i++){
        cout << ara2[i] <<" ";
    }
    cout<<endl;
    */
}
void selection(int ara[n]){

    int t;
    for(int j=n-1;j>0;j--){
        t=0;
        for(int k=1;k<=j;k++){
            if(ara[t]<ara[k]){
                t=k;
            }
        }
        swap(ara[t],ara[j]);
    }

}
void selectioncheck(int ara[]){
    /*for(int i=0;i<n;i++)
        cout<<ara[i]<<" ";
    cout<<endl;
    */
    int ara2[n];
    for(int i=0;i<n;i++)
         ara2[i]=ara[i];

    double start,end,time_diff;
    start=clock();
    selection(ara2);
    end=clock();
    time_diff=((double)(end-start))/CLOCKS_PER_SEC;
    cout <<"Time for Soring: " << 1000*time_diff << endl;

    std::fstream fs;
    fs.open ("selection.txt",fstream::in | fstream::out | fstream::app);

    fs << n<<"  "<<time_diff<<endl;

    fs.close();

    /*for(int i=0;i<n;i++){
        cout << ara2[i] <<" ";
    }
    cout<<endl;
    */
}

void insertion(int ara[n])
{
    int k,temp,c=0,s=0;
    int i,j,t=0;
    ara[-1]=std::numeric_limits<int>::min();
    for(int i=1;i<n;i++)
    {
        t=ara[i];
        j=i-1;
        c++;
        while(t<ara[j])
        {
            ara[j+1]=ara[j];
            j=j-1;
            s++;
        }
        ara[j+1]=t;

    }
}

void insertioncheck(int ara[]){
    /*for(int i=0;i<n;i++)
        cout<<ara[i]<<" ";
    cout<<endl;
    */
    int ara2[n];
    for(int i=0;i<n;i++)
         ara2[i]=ara[i];

    double start,end,time_diff;
    start=clock();
    insertion(ara2);
    end=clock();
    time_diff=((double)(end-start))/CLOCKS_PER_SEC;
    cout <<"Time for Soring: " << 1000*time_diff << endl;

    std::fstream fs;
    fs.open ("insertion.txt",fstream::in | fstream::out | fstream::app);

    fs << n<<"  "<<time_diff<<endl;

    fs.close();

    /*for(int i=0;i<n;i++){
        cout << ara2[i] <<" ";
    }
    cout<<endl;
    */
}

void Merge(int ara[],int p,int q,int r){
    int n1;
    int n2;
    n1=q-p+1;
    n2=r-q;

    int L[n1+2];
    int R[n2+2];
    for(int i=1;i<=n1;i++){
        L[i]=ara[p+i-1];
    }
    for(int i=1;i<=n2;i++){
        R[i]=ara[q+i];
    }
    L[n1+1]=std::numeric_limits<int>::max();
    R[n2+1]=std::numeric_limits<int>::max();

    for(int i=1,j=1,k=p;k<=r;k++){
        if(L[i]<=R[j]){
            ara[k]=L[i];
            i++;
        }
        else{
            ara[k]=R[j];
            j++;
        }
    }
}
void Merge_sort(int ara[n],int p,int r){
    int q;
    if(p<r){
        q=(p+r)/2;
        Merge_sort(ara,p,q);
        Merge_sort(ara,q+1,r);
        Merge(ara,p,q,r);
    }
}

void Merge_sortcheck(int ara[]){
    /*for(int i=0;i<n;i++)
        cout<<ara[i]<<" ";
    cout<<endl;
    */
    int ara2[n];
    for(int i=0;i<n;i++)
         ara2[i]=ara[i];

    double start,end,time_diff;
    start=clock();
    Merge_sort(ara2,0,n-1);
    end=clock();
    time_diff=((double)(end-start))/CLOCKS_PER_SEC;
    cout <<"Time for Soring: " << 1000*time_diff << endl;

    std::fstream fs;
    fs.open ("merge.txt",fstream::in | fstream::out | fstream::app);

    fs << n<<"  "<<time_diff<<endl;

    fs.close();

    /*for(int i=0;i<n;i++){
        cout << ara2[i] <<" ";
    }
    cout<<endl;
    */
}


void Quick(int arr[n],int f,int l){

    int i = f, j = l;
      int tmp;
      int pivot = arr[(f + l) / 2];

      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (f < j)
            Quick(arr, f, j);
      if (i < l)
            Quick(arr, i, l);
}


void Quickcheck(int ara[]){
    /*for(int i=0;i<n;i++)
        cout<<ara[i]<<" ";
    cout<<endl;
    */
    int ara2[n];
    for(int i=0;i<n;i++)
         ara2[i]=ara[i];

    double start,end,time_diff;
    start=clock();
    Quick(ara2,0,n-1);
    end=clock();
    time_diff=((double)(end-start))/CLOCKS_PER_SEC;
    cout <<"Time for Soring: " << 1000*time_diff << endl;

    std::fstream fs;
    fs.open ("quick.txt",fstream::in | fstream::out | fstream::app);

    fs << n<<"  "<<time_diff<<endl;

    fs.close();

    /*for(int i=0;i<n;i++){
        cout << ara2[i] <<" " ;
    }
    cout<<endl;
    */
}

int main()
{
    srand(time(NULL));
    /*5 separate runs for all algorithms once*/
    for(int i=1;i<=5;i++)
        {
            /*declare an array of MAX number of elements */

            int unsorted_array [n];

            /*store MAX number of random integers in the array */
            for(int i=0;i<n;i++)
                unsorted_array[i] = (int)rand();

            bubblesortcheck(unsorted_array);
            selectioncheck(unsorted_array);
            insertioncheck(unsorted_array);
            Merge_sortcheck(unsorted_array);
            Quickcheck(unsorted_array);

        }
}
