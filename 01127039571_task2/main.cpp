#include <iostream>
#include<robot.h>
#include <ctime>//i was hopping to use time in my programm but my info about that is not enough to start using it
#include "user.h"
void add_robot();
void add_user();
void dispuser();
void disprobot();
void searchuser();
void searchrobot();
int showavail();
void rent();
int i=3;// counter for robots to add in the array
int j=3; // counter for users
robot a[100];//i made this var global to access them without using call by ref in the program i know it's worse in excution but easily to apply
user b[100];
using namespace std;
int main()
{
    int x;
    a[0].name= "robo1"; a[0].price=90.50;a[0].rented=0;a[0].func=1;// creating 3 obj from each class as the ex
    a[1].name="robo2"; a[1].price=70.50;a[1].rented=0;a[1].func=2;
    a[2].name="robo3"; a[2].price=80.50;a[2].rented=0;a[2].func=3;
    b[0].name="Alien0";b[0].email="an0@y.com";b[0].num="010";
    b[1].name="Alien1";b[1].email="an1@y.com";b[1].num="011";
    b[2].name="Alien2";b[2].email="an2@y.com";b[2].num="012";
    while(true){
    cout<<"Enter NO.function to do?\n1-Add Robot\n2-Add User\n3-Disp All users\n4-Disp all Robots\n5-Search robot by name\n6-Search User by name\n7-Rent\n8-Exit\n";
    cin>>x;
    switch(x){
    case 1: add_robot();break;
    case 2: add_user();break;
    case 3: dispuser();break;
    case 4: disprobot();break;
    case 5: searchrobot();break;
    case 6: searchuser();break;
    case 7: rent();break;
    case 8: return 0;
    default:cout<<"\nerror\n";
    }
}
    return 0;
}
void add_robot(){//creating function to add a new robot ti=o the array
    a[i].setName();
    a[i].setPrice();
    a[i].chooseFunc();
    i++;
}
void add_user(){//creating function to add a new user to the array of users
    b[j].setname();
    b[j].setmail();
    b[j].setnum();
    j++;
}
void dispuser(){//function to display every used user in the array of users;
    for(int q=0;q<j;q++){
        cout<<q<<"-";
        b[q].disp();
    }
}
void disprobot(){//function to display every used robot in the array of robots
         for(int q=0;q<i;q++){
            a[q].disp();
    }
}
void searchuser(){//function to search a name whithin the array of users
        string search;
        cout<<"\nenter  the name to search\n";
        cin>>search;
          for(int q =0; q< j; q++){
              if(b[q].name.find(search, 0) != std::string::npos){
                  b[q].disp();
              }
          }
    }
void searchrobot(){//function to search a name whithin the array of users
        string search;
        cout<<"\nenter  the name to search\n";
         cin>> search;
          for(int q =0; q< i; q++){
              if(a[q].name.find(search, 0) != std::string::npos){
                  a[q].disp();
              }
          }
    }
int showavail(){//to show the available robot to rent
    int num;
    for(int k=0;k<i;k++){
        if(a[k].rented==0)
            cout<<k <<"-"<<a[k].name<<endl;
    }
   cout<<"enter the number of the robot to rent"<<endl;
    cin>>num;
    return num;
}
void rent(){//this function is a combination of other functions to make the rent
    int x,y;
    dispuser();
    cout<<"enter the No of the user to rent\n";
    cin>>y;
    x=showavail();
    a[x].savedate();
    b[y].robused(a[x].name);
    a[x].rent();
    cout<<"\nrent successfull\n";
}
