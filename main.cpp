#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    system("Color 0A");

    cout << "\n\t\t\t\t\t---------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t|\t\tLogin & Registration System\t\t|" << endl;
    cout << "\t\t\t\t\t---------------------------------------------------------" << endl;

    cout << "\n\t\t\t\t\tDo you want to Register ? : [1]\n";
    cout << "\n\t\t\t\t\tor do you want to Login ? : [2]\n";

    cout << "\n\t\t\t\t\tYour choice : ";

    int option_chosen;

    cin >> option_chosen;

    ofstream file;

    ifstream fin;

    string user_name, user_password, user_confirm_password;

    switch (option_chosen) {
        case 1:

            cout << "\n\t\t\t\t\t---------------------------------------------------" << endl;
            cout << "\t\t\t\t\t|\t\tRegistration\tProcess\t\t  |" << endl;
            cout << "\t\t\t\t\t---------------------------------------------------" << endl;

            cout << "\n\t\t\t\t\tEnter your username: ";

            cin >> user_name;

            fin.open(user_name + ".txt");

            if (fin) {
                system("Color 04");
                cout << "\n\t\t\t\t\tUser with name '"+user_name+"' already exists!!\n\n";
                exit(0);
            }

            file.open(user_name + ".txt", ios::out);

            if (!file) {
                system("Color 04");
                cout << "\n\t\t\t\t\tAn error occurred. Please try again later!!";
                return 0;
            }

            while (file) {
                cout << "\n\t\t\t\t\tEnter a password: ";

                cin >> user_password;

                cout << "\n\t\t\t\t\tConfirm your password: ";

                cin >> user_confirm_password;

                cout << "\n\t\t\t\t\tYou've Successfully registered as a user!!\n\n";

                if (user_password != user_confirm_password)
                    cout << "\n\t\t\t\t\tYour both the passwords don't match. Try again!!" << endl;

                else
                    file << user_password;

                break;
            }

            file.close();

            break;

        case 2:

            cout << "\n\t\t\t\t\t---------------------------------------------" << endl;
            cout << "\t\t\t\t\t|\t\tLogin Process\t\t    |" << endl;
            cout << "\t\t\t\t\t---------------------------------------------" << endl;

            cout << "\n\t\t\t\t\tEnter your username: ";

            cin >> user_name;

            fin.open(user_name + ".txt");

            if (!fin) {
                system("Color 04");
                cout << "\n\t\t\t\t\tThere's no user with the username '" + user_name + "' in the database\n\n";
                exit(0);
            }

            cout << "\n\t\t\t\t\tEnter your password: ";

            cin >> user_confirm_password;

            while (fin) {
                getline(fin, user_password);
                break;
            }

            fin.close();

            if (user_password != user_confirm_password) {
                system("Color 04");
                cout << "\n\t\t\t\t\tYour password was incorrect. Try again!!\n\n";
            } else {
                cout << "\n\t\t\t\t\tYou've successfully logged in !!\n\n";
            }

            break;

        default:
            system("Color 04");
            cout << "\n\t\t\t\t\tPlease try again later !!\n\n";
            break;
    }

    return 0;
}
