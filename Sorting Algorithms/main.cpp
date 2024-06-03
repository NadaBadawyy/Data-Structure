#include <iostream>
#include "vector"
using namespace std;
template<class t>
void selectionsort(t arr[], int n){
    int min;
    for (int i = 0; i < n; ++i) {
        min=i;
        for (int j = i+1; j < n; ++j) {
            if(arr[j]<arr[min])
                min=j;
        }
        if(min!=i){
            swap(arr[i],arr[min]);
        }
    }
}
template<class t>
void bubblesort(t arr[], int n){
    bool f=1;
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                f=0;
            }
        }
        if(f==1)
            break;  // there is no swapping the array is sorted
    }
}


template<class t>
void insertionsort(t arr,int n ){
    t key;
    int j;
    for (int i = 1; i <n ; ++i) { //10 30 40| 20
        key=arr[i];
        j=i-1;
        while(j>=0&&key<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

template<class t>
void merge(t arr[] , int l, int m, int r){
int i,j,k;
 int n1=m-l+1;//5
 int n2=r-m;//4
t*left=new t[n1];
t*right=new t[n2];

for (int n = 0; n < n1; ++n) {
        left[n]=arr[n+l];
    }
for (int n = 0; n < n2; ++n) {
        right[n]=arr[m+1+n];
    }
i=j=0;
k=l;
while(i<n1&&j<n2){
    if(left[i]<=right[j]){
        arr[k]=left[i];
        i++;
    }
    else {
        arr[k]=right[j];
        j++;
    }
    k++;
}
while(i<n1){
 arr[k]=left[i];
 i++;
 k++;
}
while(j<n2){
    arr[k]=right[j];
    j++;
    k++;
}
}
template<class t>
void mergesort(t arr[], int l, int r){
    if(l<r){
        int m=(r+l)/2;
        mergesort(arr, l, m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

template<class t>
void quicksort(t arr[], int l, int r){
    int i=l, j=r;
    t pivot=arr[(l+r)/2];
    //partition
    while(i<=j){
        while(arr[i]<pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<=j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    //recursion
    if(l<j)
        quicksort(arr, l,j);
    if(r>i)
        quicksort(arr,i, r);
}


template<class t>
void heapify(t arr[],int n,int root){
 int l=root*2+1;
 int r= root*2+2, max =root;
 if(l<n&&arr[l]>arr[max])
     max=l;
 if(r<n&&arr[r]>arr[max])
     max=r;
 if(root!=max){
     swap(arr[root], arr[max]);
     heapify(arr, n,max);
 }

}
template<class t>
void buildheap(t arr[], int n){
    for(int i=n/2-1; i>=0;i--){
        heapify(arr, n,i);
    }
}
template<class t>
void heapsort(t arr[], int n){
    buildheap(arr, n);
    for(int i=n-1; i>=0; i--){
        swap(arr[0], arr[i]);
        heapify(arr,i,0);
    }
}


void countsort(int arr[], int n ){
    int maxx=INT_MIN;
    for (int i = 0; i < n; ++i) {
        if(arr[i]>maxx)
            maxx=arr[i];
    }
    maxx++;
    int freq[maxx];
    for (int i = 0; i < maxx; ++i) {
        freq[i]=0;
    }
    for (int i = 0; i < n; ++i) {
        freq[arr[i]]++;
    }
    int prefix[maxx];
    for (int i = 0; i < maxx; ++i) {
        prefix[i]=freq[i];
        if(i>0){
            prefix[i]+=prefix[i-1];
        }
    }
    int sortedarr[n];
    for (int i = n-1; i >=0;--i) {
        int x=--prefix[arr[i]];
        sortedarr[x]=arr[i];
    }
    for (int i = 0; i < n; ++i) {
         arr[i]=sortedarr[i];
    }
}

template<class t>
void print(t arr[], int n){
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout<<endl;
}
int main() {
    int arr[]={1,3,2,7,0,9,7,1};
    int n=sizeof (arr)/sizeof (arr[0]);
    quicksort(arr,0,n-1);
    print(arr, n);
}
