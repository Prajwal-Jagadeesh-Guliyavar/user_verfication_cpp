#include <bits/stdc++.h>
using namespace std;

class temp{
    string keyname,keyemail,key;
    string username,useremail,password;
    fstream file;

    public:
        void logIN();
        void signUP();
        void forgotPassword();
} obj;

void temp::signUP() {
    cout << "\nEnter the username (do not use special characters like *,&,%,@): ";
    cin.ignore(); // clearing the input buffer
    getline(cin, username);
    cout << "\nEnter the user email: ";
    getline(cin, useremail);
    cout << "\nEnter the password: ";
    getline(cin, password);

    // Opening the file to write
    file.open("userDATA.txt", ios::out | ios::app);
    // Writing the records in the file
    file << username << "*" << useremail << "*" << password << endl;
    file.close();
} // EOF


void temp::logIN() {
    cout << "---------------------LOGIN---------------------------" << endl;
    cout << "\nEnter the username: ";
    cin.ignore();
    getline(cin, keyname);
    cout << "\nEnter the password: ";
    getline(cin, key);

    // open the file to read
    file.open("userDATA.txt", ios::in);
    if (!file) {
        cout << "Error: Unable to open the file.\n";
        return;
    }

    bool yeah = false;

    // reading the records
    while (getline(file, username, '*') && 
           getline(file, useremail, '*') && 
           getline(file, password, '\n')) {

        // User verification
        if (username == keyname && password == key) {
            cout << "User Authentication is Successful!\n";
            cout << "User Name  : " << username << endl;
            cout << "User Email : " << useremail << endl;
            yeah = true;
            break; // Exit the loop as user is authenticated
        }
    }

    if (!yeah) {
        cout << "Sorry\nEither your Username or Password is incorrect\n\t............Please Try Again............" << endl;
    }

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


int main() {
    int ch;
    cout << "\n1.Sign UP\n2.Log IN\n3.Forgot Password\n4.Skadoosh\nEnter your choice: \t";
    cin >> ch;
    cout<<endl;

    switch (ch) {
        case 1:
            obj.signUP();
            break;

        case 2:
            obj.logIN();
            break;

        case 3:
            obj.forgotPassword();
            break;

        case 4:
            exit(0); // Exit the program
            break;

        default:
            cout << "Invalid choice.............!" << endl;
    }

    return 0;
}