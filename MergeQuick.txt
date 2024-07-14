#include<bits/stdc++.h>
using namespace std;
int mer=0;
int qick=0;

void merge(int arr[],int l,int m,int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    
    int L[n1],R[n2];
    
    for(int i=0;i<n1;i++)
        L[i]=arr[l+i];
    for(int j=0;j<n2;j++)
        R[j]=arr[m+1+j];
        
        i=0;
        j=0;
        k=l;
        while(i<n1&&j<n2){
            if(L[i]<=R[j]){
                arr[k]=L[i];
                i++;
            }
            else{
                arr[k]=R[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            arr[k]=L[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k]=R[j];
            j++;
            k++;
        }
    
}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        mer++;
        int m=l+(r-1)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        
        merge(arr,l,m,r);
    }
}

int partition(int a[],int low,int high){
    int pivot=a[low];
    int i=low+1;
    int j=high;
    int temp;
    
    do{
        while(a[i]<=pivot)
            i++;
        while(a[j]>=pivot){
            j--;
        }
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}

void quickSort(int a[],int low,int high){
    int pIndex;
    if(low<high){
        qick++;
        pIndex=partition(a,low,high);
        quickSort(a,low,pIndex-1);
        quickSort(a,pIndex+1,high);
    }
}

void cmp(int a[],int n){
    qick=mer=0;
    quickSort(a,0,n-1);
    mergeSort(a,0,n-1);
    cout<<n<<"\t"<<mer<<"\t"<<qick<<"\t"<<n*n<<"\t"<<n*log2(n);
}

int main(){
    int n;
    cin>>n;
    cout<<"n\tmerge\tquick\tn^2\tnlogn";
    while(n--){
        int sz=rand();
        int arr[sz];
        for(int i=0;i<sz;i++)
            arr[i]=rand();
        cmp(arr,sz);
        
    }
    return 0;
}




























