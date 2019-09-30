#include<iostream>
using namespace std;

void merging(int arr[] , int l, int m, int r){

    int i,j,k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1],R[n2];

    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1+ j];
    }

    i = j = 0;
    k = l;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]= L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }

}

void mergesort(int arr[] , int l , int r){
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);

        merging(arr, l, m, r);
    }

}

void printArray(int a[] , int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Given array is"<<endl;
    printArray(arr, arr_size);


    mergesort(arr, 0, arr_size - 1);

    cout<<"Sorted array is"<<endl;
    printArray(arr, arr_size);
    return 0;
}
