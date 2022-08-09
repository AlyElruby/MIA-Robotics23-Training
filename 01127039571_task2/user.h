#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;

class user
{
public:
    string name;
    string num;
    string email;
    string robouse[100];
    int numused;//number of how many u have rented from our company
    void setname();
    void setmail();
    void setnum();
    user();
    void disp();
    void robused(string);
};

#endif // USER_H
