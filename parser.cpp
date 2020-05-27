#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

void Read();

void Append();

string encrypt(string s);

string decrypt(string s);

int parser(){
    char ans;
    cout << "Read, write, or quit? (r,w,q)" << endl;
    cin >> ans;
    cin.ignore();
    if(ans == 'r')
        Read();
    else if(ans == 'w')
        Append();
    else if(ans == 'q')
        return 0;
    else
        cout << " Command not recognised." << endl;
    return 1;
}

typedef struct{
    string username, email, password, website;
} entry;

void Read(){
    vector<entry> mine;
    entry temp;
    ifstream file;
    file.open("none.txt");
    while(file >> temp.website >> temp.username >> temp.email >> temp.password)
        temp.password = decrypt(temp.password);
        mine.push_back(temp);
    cout << "Please enter website: " << endl;
    file.close();
    string web;
    cin >> web;
    cin.sync();
    for(int i=0; i<mine.size(); i++){
        if(mine[i].website.compare(web) == 0){
            cout << mine[i].website << " " << mine[i].username << " " << mine[i].email << " " <<mine[i].password << endl;
            return;
        }
        cout << "Website not found" << endl;
    }

}


void Append(){
    cout << "Please enter website, username, email, password: " << endl;
    string user, web, email, pass;
    cin >> web >> user >> email >> pass;
    pass = encrypt(pass);
    ofstream file;
    file.open("none.txt");
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
    if((user_s.compare(s)==0) && (user_p.compare(p)==0))
        return true;
    else{
        return false;
    }
}