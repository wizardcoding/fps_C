#include <iostream>
#include <fstream>
using namespace std;

class temp {
    string userName, Email, password;
    string searchName, searchPass, searchEmail;
    fstream file;
    public:
    void login();
    void signUp();
    void forgotPassword();
}obj;

int main() {
    char choice;

    cout << "\n1- login";
    cout << "\n2- Sign-up";
    cout << "\n3- Forgot Password";
    cout << "\n4- Exit";
    cout << "\nEnter Choice : ";
    cin >> choice;

    switch(choice) {
        case '1' :
        obj.login();
            break;

        case '2' :
        obj.signUp();
            break;

        case '3' :
        obj.forgotPassword();
            break;

        case '4' :
        return 0;
            break;

        default :
            cout << "Indio !!!\n";
            cin >> choice;
            break;
    }
    return 0; 
}
void temp::signUp() {
    cout << "\nEnter User: ";
    getline(cin, userName);
    cout << "\nEnter Password: ";
    getline(cin, password);
    cout << "\nEnter Email: ";
    getline(cin, Email);

    file.open("loginData.txt", ios::out | ios::app);
    file << userName << "*" << password << "*" << Email << "*"<<endl;
    file.close();
}

void temp::login() {
    string searchName, searchPass;

    cout << "--------------Indio--------------------" << endl;
    cout << "Enter user name : " << endl;
    getline(cin, searchName);
    cout << "Enter Password : " << endl;
    getline(cin, searchPass);

    file.open("loginData.txt", ios::in);
    getline(file, userName, '*');
    getline(file, Email, '*');
    getline(file, password, '\n');

    while(!file.eof()) {
        if(userName == searchName) {
            if(password == searchPass) {
                cout << "\nLogin success.... pito rata panzona...";
                cout << "\nUsername :: " << userName << endl;
                cout << "\nEmail :: " << Email << endl;
            }
        }else {
            cout << "Password incorrect.";
        }

        getline(file, userName, '*');
        getline(file, Email, '*');
        getline(file, password, '\n');
    }

    file.close();
}

void temp::forgotPassword() {
    cout << "\n enter your userName :: ";
    getline(cin, searchName);
    cout << "\nEnter your Email Address :: ";
    getline(cin, searchEmail);

    file.open("loginData.txt", ios::in);
    getline(file, userName, '*');
    getline(file, Email, '*');
    getline(file, password, '\n');
    while(!file.eof()) {
       if(userName == searchName) {
            if(Email == searchEmail) {
                cout << "\nAccount found...\n";
                cout << "Your Password :: " << password << endl;
            }else {
                cout << "Not found...\n";
            }
       }else {
        cout << "\n not found...\n";
       }
    }
    file.close();
}