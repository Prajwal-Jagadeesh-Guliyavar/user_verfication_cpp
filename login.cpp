#include <bits/stdc++.h>
using namespace std;

class temp {
    string keyname, keyemail, key;
    string username, useremail, password;
    fstream file;

    public:
        void logIN();
        void signUP();
        void forgotPassword();
} obj;

void temp::signUP() {
    cout << "----------------------SIGNUP---------------------------" << endl;
    cout << "\nEnter the username (do not use special characters like *,&,%,@): ";
    cin.ignore(); // clearing the input buffer
    getline(cin, username);
    cout << "Enter the user email: ";
    getline(cin, useremail);
    cout << "Enter the password: ";
    getline(cin, password);

    // Opening the file to write
    file.open("userDATA.txt", ios::out | ios::app);
    // Writing the records in the file
    file << username << "*" << useremail << "*" << password << endl;
    file.close();
} // EOF

void temp::logIN() {
    cout<<endl;
    cout << "-----------------------LOGIN---------------------------" << endl;
    cout << "\nEnter the username: ";
    cin.ignore();
    getline(cin, keyname);
    cout << "Enter the password: ";
    getline(cin, key);

    // open the file to read
    file.open("userDATA.txt", ios::in);
    if (!file) {
        cout << "Error: Unable to open the file.\n";
        return;
    }

    bool found = false;

    // reading the records
    while (getline(file, username, '*') && 
           getline(file, useremail, '*') && 
           getline(file, password, '\n')) {

        if (username == keyname) {
            found = true;
            if (password == key) {
                cout << "User Authentication is Successful!\n";
                cout << "User Name  : " << username << endl;
                cout << "User Email : " << useremail << endl;
                file.close(); // Close file after successful login
                return;
            } else {
                cout << "Incorrect password! Would you like to reset it? [y/n]: ";
                char choice;
                cin >> choice;
                file.close(); // Close file before calling forgotPassword
                if (choice == 'y' || choice == 'Y') {
                    forgotPassword();
                } else {
                    cout << "Login attempt failed.\n";
                }
                return;
            }
        }
    }

    if (!found) {
        cout << "Username not found.\n";
    }

    file.close(); // Ensure the file is closed if no match is found
}


void temp::forgotPassword() {
    char chose;
    string newkey1, newkey2;
    bool found = false;
    cout<<endl;
    cout << "---------------------RESET PASSWORD----------------------" << endl;
    cout << "\nEnter the username: ";
    cin.ignore(); // To clear any leftover newline in the input buffer
    getline(cin, keyname);
    cout << "Enter the user email: ";
    getline(cin, keyemail);

    // Open the file for reading
    file.open("userDATA.txt", ios::in);
    if (!file) {
        cout << "Error: Could not open the file.\n";
        return;
    }

    string fileContent = ""; // To store updated file content
    string tempusername, tempuseremail, temppassword;
    while (getline(file, tempusername, '*') &&
           getline(file, tempuseremail, '*') &&
           getline(file, temppassword, '\n')) {

        if (tempusername == keyname && tempuseremail == keyemail) {
            found = true;
            cout << "Account found..........!\n";

            cout << "\nDo you want to change your password? [y/n]: ";
            cin >> chose;
            cin.ignore(); // ignore the newline
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
    return;
}

int main() {
    int ch;
    for(;;){
        cout << "\n1- Sign UP\n2- Log IN\n3- Forgot Password\n4- Exit\nEnter your choice: \t";
        cin >> ch;
        cout << endl;

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
                //break;

            default:
                cout << "Invalid choice.............!" << endl;
        }
    }

    return 0;
}