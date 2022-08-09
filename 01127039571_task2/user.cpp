#include "user.h"
user::user()//intialize user
{
    numused=0;
}
void user::setname(){//function to set the name
    cout<<"enter the user name\n";
    cin>>name;
}
void user::setmail(){//function to set the mail of user
    cout<<"enter the email\n";
    cin>>email;
}
void user::setnum(){//function to set the phone number of user
    cout<<"enter the telephone number\n";
    cin>>num;
}
void user::disp(){//function to display the info about the user
    cout<<"name:"<<name<<"  email:"<<email<<"  phone num:"<<num;
    for(int o=0;o<numused;o++){//to display the times that he has rent any robot
        cout<<" "<<robouse[o]<<" ";
    }
    cout<<endl;
}
void user::robused(string x){//function to store every rent in the renting array
    robouse[numused]=x;
    numused++;
}
