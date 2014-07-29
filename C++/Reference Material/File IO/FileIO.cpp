#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
    string line;
    int counter=0;
    string part;
    ifstream file("inventory.txt");
    while(getline(file,line)){
        part=line;
        istringstream ss(part);
        string token;
        while(getline(ss,token,';')){
            cout<<token<<endl;
            counter++;
        }
        counter=0;
    }
    return 0;
}
