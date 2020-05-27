#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#include "parser.h"

using namespace std;
bool logged;
int main(){
    system("COLOR F4");
    string s;
    cin >> s;
    if(s.compare("regis") == 0){
        Register();
        logged = true;
    }else if(s.compare("login") == 0)
        logged = login();
    else{
        return 0;
    }
    if(logged)
        while(parser());
    return 0;
}