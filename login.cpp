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