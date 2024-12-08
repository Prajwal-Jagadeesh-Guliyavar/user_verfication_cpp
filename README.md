# user_verfication_cpp
first repository on github
# User Authentication System

This is a simple C++ program that allows users to **Sign Up**, **Log In**, and recover their account in case they forget their password. The program uses file handling to store and retrieve user data.

---

## Features

1. **Sign Up**  
   Users can create an account by providing:
   - A username (no special characters like `*`, `&`, `%`, `@` allowed).
   - An email address.
   - A password.  
   The data is stored securely in a text file (`userDATA.txt`).

2. **Log In**  
   Users can log in to their account by providing:
   - Their username.
   - Their password.  
   If the credentials match, the program authenticates the user. If the password is incorrect, it provides an option to reset it.

3. **Forgot Password**  
   Users can reset their password by verifying their:
   - Username.
   - Registered email address.  
   Upon successful verification, the user can set a new password.

4. **Persistent Storage**  
   User data is stored in a plain text file (`userDATA.txt`), ensuring data is preserved between program executions.

5. **Menu Options**  
   The program provides a user-friendly menu-driven interface with the following choices:
   - **Sign Up**: Create a new account.
   - **Log In**: Access an existing account.
   - **Forgot Password**: Recover or reset your password.
   - **Exit**: Quit the application.

---

## How It Works

### Code Breakdown

- **Classes and Methods**:  
  - The `temp` class encapsulates the logic for sign-up, login, and password recovery.
  - Methods:
    - `signUP()`: Handles new user registration.
    - `logIN()`: Validates user credentials and allows access.
    - `forgotPassword()`: Resets the password upon successful verification.

- **File Handling**:  
  User data is stored in `userDATA.txt` in the following format:
  ```
  username*useremail*password
  ```
  Each record is stored on a new line.

- **Input Validation**:  
  The program ensures usernames do not contain special characters to maintain data integrity.

---

## How to Compile and Run

### Compile
Use any C++ compiler (e.g., GCC):
```bash
g++ -o auth_system main.cpp
```

### Run
Run the compiled executable:
```bash
./auth_system
```

---

## Example Usage

### 1. Sign Up
```
Enter the username (do not use special characters like *,&,%,@): johndoe
Enter the user email: johndoe@example.com
Enter the password: mysecurepassword
```

### 2. Log In
```
Enter the username: johndoe
Enter the password: mysecurepassword
User Authentication is Successful!
User Name : johndoe
User Email : johndoe@example.com
```

### 3. Forgot Password
```
Enter the username: johndoe
Enter the user email: johndoe@example.com
Account found..........!
Do you want to change your password? [y/n]: y
Enter the new password: newpassword123
Re-enter the new password: newpassword123
Password updated successfully....:).....!
```

---

## Note

- The program uses plain text for storage, which is not secure for sensitive information in real-world applications. Consider using encryption for enhanced security.
- Ensure the `userDATA.txt` file is present in the same directory as the program or it will create one automatically.
