#include <bits/stdc++.h>
using namespace std;

class temp{

    string username,useremail,password;
    fstream file;

    public:
        void logIN();
        void signUP();
        void forgotPassword();
} obj;

void temp :: signUP(){
    cout<<"\nEnter the username (do not use special characters like *,&,%,@): ";
    getline(cin,username);
    cout<<"\nEnter the user email : ";
    getline(cin,useremail);
    cout<<"\nEnter the password : ";
    getline(cin,password);
    
    //opening the file in the write mode
    file.open("userDATA.txt",ios::out|ios::app);
    //writing the data into the file
    file<<username<<"*"<<useremail<<"*"<<password<<endl;
    file.close();
}

int main(){

    int ch;
    cout<<"\n1.Log IN\n2.Sign UP\n3.Forgot Password\n4.Skadoosh\n Enter your choice :"<<endl;
    cin>>ch;
    switch(ch){
        case 1:

            break;

        case 2:

            break;
        case 3:
            break;
        case 4:
            break;
        default:
            cout<<"Invalid choice.............!"<<endl; 
    }

    return 0;
}