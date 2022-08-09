#include <iostream>
using namespace std;
int count(int *arr, int n){
    int x=0;
    if(*(arr)>(*(arr+1))){
        x++;
    }
    for(int k=2;k<n;k++){
        if((*(arr+k)>*(arr+k-1))&&(*(arr)>(*(arr+k)))){
            x++;
        }
        else{
            x++;
            return x;
        }
    }
    return x;
}
int main()
{
    int q,n;
    cin>>q;
    cin>>n;
    int arr[n];
    int out[n];
    while(q--){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int j=0;j<n;j++){
       out[j]=count(&arr[j],n-j);
    }
    for(int l=0;l<n;l++){
        cout<<out[l];
    }
    cout<<"\n";}
    return 0;
}
