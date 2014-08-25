#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class node{
    private:
        string name;
        node* next;
        node* prev;

    public:
        node(){
            name = "";
            next = NULL;
            prev = NULL;
        }

        //Destructor is unnecessary

        string getName(){
            return name;
        }

        void setName(string s){
            name = s;
        }

        node* getNext(){
            return next;
        }

        void setNext(node* n){
            next = n;
        }

        node* getPrev(){
            return prev;
        }

        void setPrev(node* p){
            prev = p;
        }
};

int h(string x, int M){
    int xlength = x.size()+1;
    char *ch = new char[xlength];
    ch[x.size()]=0;

    memcpy(ch, x.c_str(), x.size());
    int sum = 0;
    for(int i =0; i<x.length(); i++){
        sum+=ch[i];
    }
    return sum%M;
}

string getOption(){
    string opt;
    cout<<"Select an option:\n i(insert name if that name does not already exist)\n d(delete name)\n f(find name in the table)\n p(print table contents)\n e(exit program)"<<endl;
    cin>>opt;
    while(opt!="i"&&opt!="d"&&opt!="f"&&opt!="p"&&opt!="e"){
        cout<<"Invalid input!\n Please enter a valid option: "<<endl;
        cin>>opt;
    }
    return opt;
}

node* findName(node* hT[], string n){
    int index=h(n,50);
    node* temp = new node();
    temp = hT[index];
        while(temp->getNext()!=NULL&&temp->getName()!=n){
            temp=temp->getNext();
        }
    if(temp->getName()==n){
        cout<<"Name was found."<<endl;
    }
    else{
        cout<<"Name was not found."<<endl;
    }
    return temp;
}

void insertName(node* hT[], string n){
    node* temp = findName(hT, n);
    if(temp->getName()!=n && temp->getPrev()==NULL){
        temp->setName(n);
    }
    else if(temp->getName()!=n && temp->getPrev()!=NULL){
        node* addNode = new node();
        addNode->setName(n);
        temp->setNext(addNode);
        addNode->setPrev(temp);
    }
}

void deleteName(node* hT[], string n){
    node* temp = findName(hT, n);
    if(temp->getName()==n){
        if(temp->getNext()==NULL && temp->getPrev()==NULL){
            temp->setName("");
        }
        else if(temp->getNext()!=NULL && temp->getPrev()==NULL){
            temp=temp->getNext();
        }
        else if(temp->getNext()==NULL && temp->getPrev()!=NULL){
            temp->getPrev()->setNext(NULL);
            delete temp;
        }
        else{
            temp->getPrev()->setNext(temp->getNext());
            temp->getNext()->setPrev(temp->getPrev());
            delete temp;
        }
    }
}

void printName(node* hT[]){
    node* temp=new node();
    for(int i = 0; i < 50; i++){
        temp=hT[i];
        if(temp->getName()!=""&&temp->getNext()==NULL){
            cout<<temp->getName()<<endl;
        }
        else{
            while(temp->getNext()!=NULL){
                cout<<temp->getName()<<endl;
                temp=temp->getNext();
            }
        }
    }
}

int main(){
    int hashTableSize=50;
    string name;
    node* hashTable[hashTableSize];
    for(int i =0; i<hashTableSize;i++){
        hashTable[i]=new node();
    }
    string option;
    option = getOption();
    while(option!="e"){
        if(option=="i"){
            cout<<"Enter a name to insert: "<<endl;
            cin.ignore();
            getline(cin, name);
            insertName(hashTable, name);
        }
        else if(option=="d"){
            cout<<"Enter a name to delete: "<<endl;
            cin.ignore();
            getline(cin, name);
            deleteName(hashTable, name);
        }
        else if(option=="f"){
            cout<<"Enter a name to find: "<<endl;
            cin.ignore();
            getline(cin, name);
            findName(hashTable, name);
        }
        else{ //Implicit that this will be print name
            printName(hashTable);
        }
        option=getOption();
    }
    return 0;
}
