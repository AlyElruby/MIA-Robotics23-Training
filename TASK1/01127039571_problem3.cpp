#include <iostream>
#include<map>
#include<string.h>
#include<vector>
using namespace std;
int main()
{
    int q;
    string s;
    cin>>q;
    while(q--){
    cin>>s;
    vector<char>x;
        int i=0;
        char a;
        int n=s.length();
        string d;
        map<string,char>m;
        m["1"]='a';  m["2"]='b';  m["3"]='c';  m["4"]='d';  m["5"]='e';  m["6"]='f';  m["7"]='g';  m["8"]='h';  m["9"]='i';  m["10&"]='j';  m["11&"]='k';
        m["12&"]='l';  m["13&"]='m'; m["14&"]='n';  m["15&"]='o'; m["16&"]='p';  m["17&"]='q'; m["18&"]='r';  m["19&"]='s'; m["20&"]='t';  m["21&"]='u';
        m["22&"]='v';  m["23&"]='w'; m["24&"]='x';  m["25&"]='y'; m["26&"]='z';
        while(i<n){
            d.clear();
        if(s[i+2]=='&'){
            d.push_back(s[i]);
            d.push_back(s[i+1]);
            d.push_back(s[i+2]);
            a=m[d];
            i+=3;
            x.push_back(a);
        }
        else{
            d=s[i];
            a=m[d];
            x.push_back(a);
            i++;
        }
        }
        for(auto v:x)
          {  cout<<v;}
        cout<<"\n";
    }
    return 0;
}
