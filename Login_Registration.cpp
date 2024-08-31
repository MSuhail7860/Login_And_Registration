#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username.empty() || password.empty()) {
        cout << "Username and password cannot be empty!" << endl;
        return;
    }

    if (password.length() < 6) {
        cout << "Password must be at least 6 characters long!" << endl;
        return;
    }

    ofstream file(username + ".txt");
    if (file.is_open()) {
        file << password;
        file.close();
        cout << "Registration successful!" << endl;
    } else {
        cerr << "Error creating file! Check file path and permissions." << endl;
    }
}

void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file(username + ".txt");
    if (file.is_open()) {
        string storedPassword;
        getline(file, storedPassword);
        file.close();

        if (password == storedPassword) {
            cout << "Login successful!" << endl;
        } else {
            cout << "Invalid password!" << endl;
        }
    } else {
        cout << "Username does not exist!" << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;  
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter 1, 2, or 3." << endl;
        }
    }
    return 0;
}