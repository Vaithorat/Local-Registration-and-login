#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn()
{
    string username, password, un, pw; //to compare these two
    
    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> password;

    ifstream read(username+ ".txt"); //to access the document where data is stored to be crosschecked
    getline(read, un); //to read the stored username
    getline (read,pw); //to read the stored password

    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main ()
{
    int choice; //registry function ie. registration
    cout << "1. Registration \n2. Login \n Your choice: "; cin >> choice;
    if (choice ==1) //if user is registering
    {
        string username, password;
        cout << "Select username: "; cin >> username;
        cout << "Enter password: "; cin >> password;
        
        ofstream file; //to write to our database file
        file.open (username + ".txt"); //location of database
        file << username << endl << password;
        file.close();
        
        main(); //goes back to registration or login
    }
    else if (choice ==2) //to login
    {
        bool status = IsLoggedIn(); //calls function to check credentials
       
        if (!status)
        {
            cout << "Wrong credentials" << endl;
        }
        else
        {
            cout << "Successfully logged in" << endl;
        }
    }
}
