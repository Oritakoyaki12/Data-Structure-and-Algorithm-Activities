#include <iostream>
#include <fstream>

using namespace std;

struct tree{

char letter;
int freq;
tree* left;
tree* right;

    tree(char ch): letter(ch), freq(1), left(NULL), right(NULL) {}
};

class getFreq{

private:
    tree* Insert(tree* Node, char ch) { //this is a private function that inserts the character into the binary tree
        if (Node == nullptr) {
            return new tree(ch);
        }
        if (ch < Node->letter) {
            Node->left = Insert(Node->left, ch);
        } else if (ch > Node->letter) {
            Node->right = Insert(Node->right, ch);
        } else {
            Node->freq++;
        }
        return Node;
    }

public:
    tree *root;
    getFreq(): root(NULL){}


    void Insert(char ch); // this is a public method that calls the private method insert and assigns the value it returns to the root.
    void readfile();
    void displayNode(tree *n);
};

void getFreq::Insert(char ch) {
        root = Insert(root, ch);
    }

void getFreq::readfile(){
        ifstream file("filename.txt");
        if(!file){
            cout<<"Error opening file..."<<endl;
            return;
        }

        char c;
        while(file.get(c)){ // this reads character by character inside the file
            if(isprint(c)){
                Insert(c); //calling the function to insert it in the node
            }
        }
        file.close();
    };


void getFreq::displayNode(tree *n){

        if(n!= NULL){
            displayNode(n->left);
            cout << "    '" << n->letter << "'    \t " << n->freq << endl;
            displayNode(n->right);
        }
    };

int main(){

    getFreq LF;

    LF.readfile();

    cout<<" Character Frequencies\n";
    LF.displayNode(LF.root);

};

