#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x): data(x), next(NULL){}
};


class MyQ {

private:
    Node *fRont;
    bool isEmpty();


public:
    MyQ(): fRont(NULL){}
    void enqueue(int x);
    void dequ();
    void display();
};



bool MyQ::isEmpty(){
    return(fRont==NULL);
}

void MyQ::enqueue(int x){
Node *newNodeQ = new Node(x);
Node *p, *q;
p=q=fRont;


while (p!=NULL)
{
    q=p;
    p=p->next;
}

if (fRont == NULL)
{
    newNodeQ->next=fRont;
    fRont = newNodeQ;
}

else
{
    q->next = newNodeQ;
    newNodeQ->next = p;
}
}

void MyQ::dequ(){
Node *temp;
    if (isEmpty())
    {
       cout<<"The Queue is empty...\n";
       system("pause");
    }

    else
    {
        temp = fRont;
        fRont = fRont->next;
        delete(temp);
    }
}

void MyQ::display()
{ Node *p;
  p=fRont;
    int i = 1;
    if (isEmpty())
    {
        cout<<"The queue is empty...\n";
        system("pause");
    }

    cout<<"The queue contains: "<<endl;
    while (p!= NULL){
        cout<<i++<<"). "<<p->data<<endl;
        p = p->next;
    }
    system("pause");
}

int menu(){
int ch;
system("cls");
cout <<"STUDENT RECORD MENU \n";
cout <<"1. Enqueue \n";
cout <<"2. Dequeue \n";
cout <<"3. Display \n";
cout <<"4. Exit \n";
cout <<"\nPlease Select (1-4): ";
cin>>ch;
return ch;
}

int main(){
    MyQ Q;
    int d;
while(true){
    switch(menu()){
    case 1 : system("cls");cout<<"Input data ";cin >> d; Q.enqueue(d); break;
    case 2 : system("cls"); Q.dequ(); cout<<"Dequeued Successfully..\n"; system("pause"); break;
    case 3 : Q.display(); break;
    case 4 : exit(0);
    default:cout<<"Invalid Input\n.";system("pause");}}
   return 0;
}
