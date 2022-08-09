#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>

using namespace std;

class robot //creating class for robot obj
{
public:
    string name; //attributes for name , price,rented or not , date of rent and function to be done by robot
    float price;
    bool rented;
    string date[100];
    int norent;//new variable to store how many time this robot has been rented
public:
    int func;
    void setName();//declaring functions to deal with attributes;
    void setPrice();
    void rent();
    void unrent();
    void chooseFunc();
    robot();
    void disp();
    void savedate();
};

#endif // ROBOT_H
