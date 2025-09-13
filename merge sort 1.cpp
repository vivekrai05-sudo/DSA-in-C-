//merge arrays
#include <iostream>
using namespace std;
 
void merge(int*arr,int s,int e){
    int mid=(s+e)/2;
    int len1=mid-s+1;
    int len2=e-mid;
//assume to create arrays
    int*left=new int[len1];
    int*right =new int[len2];

    //copy values
    int k=s;
    for(int i=0;i<len1;i++){
        left[i]=arr[k];
        k++;
    }
     
    k=mid+1;
    for(int i=0; i<len2; i++){
    right[i]=arr[k];
    k++;
    }
//merge logic
int leftindex=0;
int rightindex=0;
int mainarrayindex=s;

while(leftindex<len1 && rightindex<len2){
    if(left[leftindex]<right[rightindex]){
        arr[mainarrayindex++]=left[leftindex++];
        
        
    }
    else{
        arr[mainarrayindex++]=right[rightindex++];
        
    }
}
//copy logic for left array
while(leftindex<len1){
    arr[mainarrayindex++]=left[leftindex++];
}
//copy logic for right array
while(rightindex<len2){
    arr[mainarrayindex++]=right[rightindex++];
}
}
void mergeSort(int*arr,int s,int e){
    //base case
     //s==e single element
     //s>e =invalid array
     if(s>=e)
     return;
     int mid=(s+e)/2;

     //left part sort krdo recursion bhayia
     mergeSort(arr,s,mid);

     //right part sort krdo recursion bhayia
     mergeSort(arr,mid+1,e); 
     
     //now merge two sorted array
     merge(arr,s,e);
}
int main() {
    int arr[]={2,2,2,2,2,4,5,13,2,12};
    int n=10;

    int s = 0;
    int e = n-1;
    //calling a merge function
    mergeSort(arr,s,e);
//printing the array
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;

}