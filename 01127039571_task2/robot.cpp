#include "robot.h"
#include <iostream>
using namespace std;
void clean(){}//declaring functions for the robot to be used in chosefunc function
void drive(){}//i could used just a variable to know hich func to do but i have done this method to make the code more useful for future applications
void solve(){}
void cook(){}
void hair(){}
robot::robot()//to intialize the robot
{
    norent=0;
    func=0;

}
void robot::setName(){//to set the name
    cout<<"enter the name of robot\n";
    cin>>name;
}
void robot::setPrice(){//to set the price
    cout<<"enter the price per day\n";
    cin>>price;
}
void robot::rent(){//to set the rent
    rented=1;
}
void robot::unrent(){//to reset the rent
    rented =0;
}
void robot::chooseFunc(){//to chose the function of the robot
    cout<<"\n1-Cleaner Robot\n2-Driver Robot\n3-Assignment Solver Robot\n4-Cook Robot\n5-Hairstylist Robot\n";
    cin>>func;
    switch(func){
        case 1: clean(); break;//those function must be a combination between HW and SW so i leave it to be defienf when it will be realy used with HW
        case 2: drive(); break;
        case 3: solve(); break;
        case 4: cook(); break;
        case 5: hair(); break;
}
}
void robot::disp(){//to display the information about the robot
    cout<<"name:"<<name<<"  price:"<<price<<"  func id:"<<func<<"  is rented:"<<boolalpha<<rented;
    for(int o=0;o<norent;o++){
        cout<<" "<<date[o]<<" ";
    }
    cout<<endl;
}
void robot::savedate(){//to save the date of renting of the robot
    int repeat=1;
    while(repeat){
    cout<<"\nenter the date (in the format: 01/12/2022) you want to rent robot on\n";//to check if the user has enterd a vaild date in thesame format
    cin>>date[norent];
    if((date[norent][2]=='/')&&(date[norent][5]=='/')){
        repeat=0;//i could have used break insted of this var but i prefer this method IDK why +_+
    }
    else{
        cout<<"Error date format"<<endl;
    }
    }
    norent++;
}
