#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser() {
    string username, password;

    cout << "\nEnter Username: ";
    cin >> username;

    ifstream check(username + ".txt");
    if (check) {
        cout << "Username already exists!\n";
        return;
    }

    cout << "Enter Password: ";
    cin >> password;

    ofstream file(username + ".txt");
    file << username << endl;
    file << password << endl;
    file.close();

    cout << "Registration Successful!\n";
}

void loginUser() {
    string username, password;
    string storedUser, storedPass;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file(username + ".txt");

    if (!file) {
        cout << "User not found!\n";
        return;
    }

    getline(file, storedUser);
    getline(file, storedPass);

    if (username == storedUser && password == storedPass)
        cout << "Login Successful!\n";
    else
        cout << "Incorrect Password!\n";

    file.close();
}

int main() {

    int choice;

    do {
        cout << "\n===== LOGIN SYSTEM =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 3:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}
