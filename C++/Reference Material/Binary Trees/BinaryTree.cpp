#include <iostream>

using namespace std;

class node{
    private:
        int value;
        node* parent;
        node* left;
        node* right;
    public:
        node(){
            value=0;
            parent=NULL;
            left=NULL;
            right=NULL;
        }

        node(int v){
            value=v;
            parent=NULL;
            left=NULL;
            right=NULL;
        }
        node(int v, node* p){
            value=v;
            parent=p;
            left=NULL;
            right=NULL;
        }

        //Destructor is unnecessary

        int getValue(){
            return value;
        }

        void setValue(int v){
            value=v;
        }

        node* getParent(){
            return parent;
        }

        void setParent(node* p){
            parent=p;
        }

        node* getLeft(){
            return left;
        }

        void setLeft(node* l){
            left=l;
        }

        node* getRight(){
            return right;
        }

        void setRight(node* r){
            right=r;
        }
};


class tree{
    private:
        node* root;
    public:
        tree(int rootValue){
            root=new node();
            root->setValue(rootValue);
        }

        ~tree(){
            removeAllNodes(root);
        }

        node* getRoot(){
            return root;
        }

        void setRoot(node* r){
            root=r;
        }

        void addNode(node* r, int v){
            if(r->getLeft()==NULL && v<=r->getValue()){
                r->setLeft(new node(v, r));
            }

            else if(r->getRight()==NULL && v>r->getValue()){
                r->setRight(new node(v, r));
            }

            else if(v<=r->getValue()){
                addNode(r->getLeft(), v);
            }
            else{ //Implicit that it's moving to the right child of the current node
                addNode(r->getRight(), v);
            }
        }

        node* findNode(node* r, int val){
            if(val<r->getValue()){
                if(r->getLeft()!=NULL){
                    if(val==r->getLeft()->getValue()){
                        return r->getLeft();
                    }
                    else{
                        findNode(r->getLeft(), val);
                    }
                }
                else{
                    cout<<"Value not found."<<endl;
                    return NULL;
                }
            }
            else{ //val > r->getValue()
                if(r->getRight()!=NULL){
                    if(val==r->getRight()->getValue()){
                        return r->getRight();
                    }
                    else{
                        findNode(r->getRight(), val);
                    }
                }
                else{
                    cout<<"Value not found."<<endl;
                    return NULL;
                }
            }
        }

        void removeSpecificNode(int v){
            if(v==root->getValue()){
                //remove root
                cout<<"Removing root..."<<endl;
                cout<<"Done!"<<endl;
            }
            else{
                cout<<"Finding the node..."<<endl;
                node* removeNode=findNode(root, v);
                //remove removeNode
                cout<<"Now removing the node with value: "<<removeNode->getValue()<<endl;
                cout<<"Done!"<<endl;
            }
        }
        void removeAllNodes(node* p){
            if(p->getLeft()==NULL && p->getRight()==NULL){
                delete p;
            }
            else{
                if(p->getLeft()!=NULL){
                    removeAllNodes(p->getLeft());
                }
                if(p->getRight()!=NULL){
                    removeAllNodes(p->getRight());
                }
            }
        }

        void printTree(node* current, int howDeep){
            for(int i=0; i<howDeep*4; i++){
                cout<<" ";
            }
            cout<<current->getValue()<<endl;
            if(current->getLeft()!=NULL){
                printTree(current->getLeft(), howDeep+1);
            }
            if(current->getRight()!=NULL){
                printTree(current->getRight(), howDeep+1);
            }
        }
};

string getOption(){
    string option="";
    cout<<"Choose from the following options:\n i:Insert a value\n r:Remove a value\n p:Print values in tree\n e:Exit the program"<<endl;
    cin>>option;
    while(option!="i"&&option!="r"&&option!="p"&&option!="e"){
        cout<<"Invalid input"<<endl;
        cout<<"Choose from the following options:\n i:Insert a value\n r:Remove a value\n p:Print values in tree\n e:Exit the program"<<endl;
        cin>>option;
    }
    return option;
}

int main(){
    int startValue=0;
    cout<<"Before any operations take place, please insert a value."<<endl;
    cin>>startValue;
    tree* ourTree=new tree(startValue);
    string option="";
    while(option!="e"){
        if(option=="i"){
            cout<<"Enter a value to insert:"<<endl;
            cin>>startValue;
            ourTree->addNode(ourTree->getRoot(), startValue);
        }
        else if(option=="r"){ //This function is not finished yet
            cout<<"Enter a value to remove:"<<endl;
            cin>>startValue;
            ourTree->removeSpecificNode(startValue);
        }
        else{
            ourTree->printTree(ourTree->getRoot(), 0);
        }
        option=getOption();
    }
    delete ourTree;
}
