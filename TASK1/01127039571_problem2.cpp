#include <iostream>

using namespace std;

int main()
{
    int q,hp,P,H;
    cin>>q;
    while(q--)
    {
        cin>>hp>>P>>H;
        while(P--){
            hp=(hp/2)+10;
        }
        while(H--){
            hp-=10;
        }
        if(hp<=0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}
