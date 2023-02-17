#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int a, i = 0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string cred[2], cp[2];

    cout << "         SECURITY SYSTEM             " << endl;
    cout << "_________________________________________" << endl
         << endl;
    cout << "|          1. REGISTER                   |" << endl;
    cout << "|          2. LOG IN                     |" << endl;
    cout << "|          3. Change password            |" << endl;
    cout << "|__________4. END PROGRAM_________________|" << endl;

    cout << endl;

    do
    {
        cout << endl
             << endl;
        cout << "Enter your choice : ";
        cin >> a;
        switch (a)
        {
        case 1:
        {
            cout << "___________________________________" << endl;
            cout << "|-----------Register--------------|" << endl;
            cout << "|_________________________________|" << endl;
            cout << "Please enter username : ";
            cin >> name;
            cout << "Please enter the Password : ";
            cin >> password0;
            cout << "Please enter your age : ";
            cin >> age;

            ofstream of1; // offstream is used to write in a file
            of1.open("file.txt");
            if (of1.is_open())
            {
                of1 << name << "\n";
                of1 << password0;
                cout << "Registration is successful" << endl;
            }
            break;
        }
        case 2:
        {
            i = 0;

            cout << "________________________________" << endl
                 << endl;
            cout << "|-----------Log in--------------|" << endl;
            cout << "________________________________" << endl
                 << endl;

                        ifstream of2;
            of2.open("file.txt");
            cout << "Please enter the username : ";
            cin >> user;
            cout << "Please enter the password : ";
            cin >> pass;

            if (of2.is_open())
            {
                while (!of2.eof())
                {
                    while (getline(of2, text))
                    {                            /// getline read the file line by line
                        istringstream iss(text); // isstringstream is used as an extraction operation
                        iss >> word;
                        cred[i] = word; // here username is stored at 0th index and password is stored at 1st index
                        i++;
                    }
                    // if user is matched
                    if (user == cred[0] && pass == cred[i])
                    {
                        cout << "-----Log in sucessfull-----";
                        cout << endl
                             << endl;

                        cout << "Details : " << name << endl;

                        cout << "Username : " << pass << endl;
                        cout << "Age : " << age << endl;
                    }

                    else
                    {
                        cout << endl
                             << endl;
                        cout << "Incorrect Credentials" << endl;
                        cout << "|     1. Press 2 to Log in               |" << endl;
                        cout << "|     2. Press 3 to change password      |" << endl;
                        break;
                    }
                }
            }
            break;
        }

        case 3:
        {
            i = 0;
            cout << "----------------Change Password-----------------" << endl;

            ifstream of0;
            of0.open("file.txt");
            cout << "Enter the old password : ";
            cin >> old;

            if (of0.is_open())
            {
                while (of0.eof())
                {
                    while (getline(of0, text))
                    {
                        istringstream iss(text);
                        iss >> word1; // here we storing the data in word1
                        cp[i] = word1;
                        i++;
                    }
                    if (old == cp[1])
                    {
                        of0.close();

                        ofstream of1;
                        if (of1.is_open())
                        {
                            cout << "Enter Your New Password : ";
                            cin >> password1;
                            cout << "Enter Your New Password Again : ";
                            cin >> password2;

                            if (password1 == password2)
                            {
                                of1 << cp[0] << "\n";
                                of1 << password1;
                                cout << "Password change successfully" << endl;
                            }

                            else
                            {
                                of1 << cp[0] << "\n";
                                of1 << old;
                                cout << "Password doesn't match" << endl;
                            }
                        }
                    }
                    else
                    {
                        cout << "Please enter a valid Password " << endl;
                        break;
                    }
                }
            }
            break;
        }

        case 4:
        {
            cout << "___________Thank You!_____________";
            break;
        }

            default :
            {
                cout << "Enter a valid choice ";
            }
        } 
    }while(a!=4);

    return 0;
}
