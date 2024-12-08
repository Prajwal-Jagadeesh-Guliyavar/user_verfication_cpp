#include <bits/stdc++.h>
using namespace std;

class temp{
    string keyname,keyemail,key;
    string username,useremail,password;
    fstream file;

    public:
        void logIN();
        void signUP(string,string,string);
        void forgotPassword();
} obj;

void temp :: signUP(string username, string useremail, string password){
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
}//EOF

void temp::logIN(){
    //string keyname,key;

    cout<<"---------------------LOGIN---------------------------"<<endl;
    cout<<"\nEnter the username : ";
    getline(cin,keyname);
    cout<<"\nEnter the password : ";
    getline(cin,key);
    //opening the file in the read mode
    file.open("userDATA.txt", ios::in);

    //reading the record of the file
    getline(file, username, '*');
    getline(file, useremail, '*');
    getline(file, password, '\n');

    //looping till the end of the file
    while(!file.eof()){
        
        //user verification
        if(username == keyname){
            if(password == key){
                cout<<"user Authentication is Successfull \n";
                cout<<"User Name  : "<<username<<endl;
                cout<<"User Email : "<<useremail<<endl;
            }
        }
        //reading the next records in the newline
        getline(file, username, '*');
        getline(file, useremail, '*');
        getline(file, password, '\n');

    }
    cout<<"Sorry\nEither your Username or Password is incorrect\n\t............Please Try Again............"<<endl;
    file.close();
}//EOF

void temp::forgotPassword() {
    char chose;
    string newkey1, newkey2;
    bool found = false;

    cout << "\nEnter the username: ";
    cin.ignore(); // To clear any leftover newline in the input buffer
    getline(cin, keyname);
    cout << "\nEnter the user email: ";
    getline(cin, keyemail);

    // Open the file for reading
    file.open("userDATA.txt", ios::in);
    if (!file) {
        cout << "Error: Could not open the file.\n";
        return;
    }

    string fileContent = ""; // To store updated file content
    string tempusername, tempuseremail, temppassword;
    while (!file.eof()) {
        // Read a record
        getline(file, tempusername, '*');
        getline(file, tempuseremail, '*');
        getline(file, temppassword, '\n');

        if (file.fail()) {
            break; // Handle trailing newline or invalid reads
        }

        // Check for matching username and email
        if (tempusername == keyname && tempuseremail == keyemail) {
            found = true;
            cout << "Account found..........!\n";

            cout << "\nDo you want to change your password? [y/n]: ";
            cin >> chose;
            cin.ignore();//ignore the newline
            if (chose == 'y') {
                cout << "\nEnter the new password: ";
                getline(cin, newkey1);
                cout << "\nRe-enter the new password: ";
                getline(cin, newkey2);

                if (newkey1 == newkey2) {
                    temppassword = newkey2; // Update password
                    cout << "Password updated successfully....:).....!\n";
                } else {
                    cout << "Passwords do not match, operation terminated :( \n";
                    file.close();
                    return;
                }
            }
        }

        // Append the updated record to the file content
        fileContent += tempusername + "*" + tempuseremail + "*" + temppassword + "\n";
    }
    file.close();

    if (!found) {
        cout << "No record found with the provided username and email..........?\n";
        return;
    }

    // Rewrite the file with updated content
    file.open("userDATA.txt", ios::out | ios::trunc);
    file << fileContent;
    file.close();
}


int main(){

    int ch;
    string username,useremail,password;
    cout<<"\n1.Log IN\n2.Sign UP\n3.Forgot Password\n4.Skadoosh\n Enter your choice :"<<endl;
    cin>>ch;
    switch(ch){
        case 1:
            cout<<"\nEnter the username (do not use special characters like *,&,%,@): ";
            getline(cin,username);
            cout<<"\nEnter the user email : ";
            getline(cin,useremail);
            cout<<"\nEnter the password : ";
            getline(cin,password);
            obj.signUP(username,useremail,password);

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