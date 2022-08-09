#include <iostream>

using namespace std;

int main()
{
    int r=5;
    int c=13;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(((i==0)||(i==r-1))&&((j==0)||(j==5)||(j==8)||(j==9)||(j==10)||(j==11)||(j==12))){
                cout<<"*";
            }
            else if((i==((r+1)/2)-1)&&((j==0)||(j==1)||(j==2)||(j==3)||(j==4)||(j==5)||(j==10))){
                 cout<<"*";
            }
            else if(((i!=0)||(i!=r-1)||(i==((r+1)/2)-1))&&((j==0)||(j==5)||(j==10))){
                 cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
