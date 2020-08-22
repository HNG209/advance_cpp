#include<iostream>
#include<stdio.h>
#include<regex>
using namespace std;
int main(){
    cout << "looping time:";
    int t;
    cin >> t;
    while(t--){
        //password strength
        regex reg("^(?=.*[A-Z].*[A-Z])(?=.*[!@#$&*])(?=.*[0-9].*[0-9])(?=.*[a-z].*[a-z].*[a-z]).{8,100}$",std::regex_constants::ECMAScript);
        //email's validity
        regex reg1(R"([[:w:]]+@[[:w:]]+\.com)",std::regex_constants::ECMAScript);
        string pass;
        string email;
        cout << "-------------------REGISTER PANEL--------------------------\n";
        cout << "enter email:";
        cin >> email;
        bool email_valid = regex_match(email,reg1);
        while(!email_valid){
            cout << "email is not valid,please enter again:";
            cin >> email;
            email_valid = regex_match(email,reg1);
        }
        cout << "email is valid,let's continue\n";
        cout << "enter password:";
        cin >> pass;
        bool pass_valid = regex_match(pass,reg);
        while(!pass_valid){
            cout << "your password is not strong enough,please enter again:";
            cin >> pass;
            pass_valid = regex_match(pass,reg);
        }
        cout << "password is acceptable\n";
        cout << "----------------------------------------------------------\n";
        cout << "                    WELCOME USER                          \n";
        cout << "              EMAIL:" << email << "                       \n";
        cout << "              PASSWORD:" << pass << "                     \n";
        cout << "                    user authorized                       \n";
        cout << "----------------------------------------------------------\n";
    }
}