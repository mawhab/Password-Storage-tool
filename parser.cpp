#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
using namespace std;

void Read();

void Append();

string encrypt(string s);

string decrypt(string s);

void ReadAll();

int parser(){
    int ans;
    cout << "1 Read" << endl;
    cout << "2 Write" << endl;
    cout << "3 Quit" << endl;
    cin >> ans;
    cin.ignore();
    if(ans == 1)
        Read();
    else if(ans == 2)
        Append();
    else if(ans == 3)
        return 0;
    else if(ans == 9)
        ReadAll();
    else
        cout << " Command not recognised." << endl;
    return 1;
}

typedef struct{
    string username, email, password, website;
} entry;

void Read(){
    bool found = false;
    vector<entry> mine;
    entry temp;
    ifstream file;
    file.open("stored.txt");
    while(file >> temp.website >> temp.username >> temp.email >> temp.password){
        temp.password = decrypt(temp.password);
        mine.push_back(temp);
    }
    cout << "Please enter website: " << endl;
    file.close();
    string web;
    cin >> web;
    cin.sync();
    for(auto x: mine){
        if(x.website.compare(web) == 0 || x.website.find(web) != string::npos){
            cout << x.website << " " << x.username << " " << x.email << " " << x.password << endl;
            found = true;
        }
    }
    if(!found)
        cout << "Website not found" << endl;

}


void Append(){
    cout << "Please enter website, username, email, password: " << endl;
    string user, web, email, pass;
    cin >> web >> user >> email >> pass;
    pass = encrypt(pass);
    ofstream file;
    file.open("stored.txt", ios_base::app);
    file << web << " " << user << " " << email << " " << pass << endl;
    file.close();
}

string encrypt(string s){
    for(int i=0; i<s.length(); i++)
        s[i] += 13;
    return s;
}



string decrypt(string s){
    for(int i=0; i<s.length(); i++)
        s[i] -= 13;
    return s;
}


void Register(){
    string s, p;
    cin >> s >> p;
    p = encrypt(p);
    ofstream file;
    file.open("user.txt");
    file << s << " " << p << endl;
    file.close();
}

bool login(){
    string s, p, user_s, user_p;
    ifstream file;
    file.open("user.txt");
    file >> s >> p;
    file.close();
    p = decrypt(p);
    cin >> user_s >> user_p;
    if((user_s.compare(s)==0) && (user_p.compare(p)==0)){
        system("CLS");
        return true;
    }else{
        return false;
    }
}


void ReadAll(){
    string web, user, email, pass;
    ifstream file;
    file.open("stored.txt");
    while(file >> web >> user >> email >> pass){
        pass = decrypt(pass);
        cout << web << " " << user << " " << email << " " << pass << endl;
    }
    file.close();
}