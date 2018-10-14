#include <iostream>

using namespace std;

int main()
{
    int a[] = {1,6,4,7,8,3,9,2,5};
    int n = sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++){
        int value = a[i];
        int hole = i;
        while(hole>0 && a[hole-1]>value){
            a[hole] = a[hole-1];
            hole--;
        }
        a[hole]=value;
    }
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }

    return 0;
}