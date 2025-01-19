#include <iostream>
#define MAX 5
using namespace std;

struct Que {
   int data[MAX];
   int f,r,ctr;
   Que() : f(-1), r(-1),ctr(0){}
};
class MyQ {
private:
    Que Q;
    bool isfull();
    bool isempty();
public:
    void enque(int x);
    void dequ();
    void display();
    int fRont();
    int rear();
};
bool MyQ::isfull(){
   return (Q.ctr==MAX);
}
bool MyQ::isempty(){
   return (Q.ctr==0);
}
int MyQ::fRont(){
  return Q.data[Q.f];
}
int MyQ::rear(){
  return Q.data[Q.r];
}
void MyQ::enque(int x){
if (isfull()){
    cout<<"Queue is full.\n";
    system("pause");
}
else {
    if (Q.ctr==0){ // If the queue is empty
        Q.r=Q.f=0;
    }
    else{
    Q.r = Q.r+1;
    if (Q.r==MAX)
        Q.r=0;
      }
    Q.data[Q.r]= x;
    Q.ctr++;
   }
}

void MyQ:: dequ(){

    if (isempty())
    {
        cout<<"The Queue is empty..."<<endl;
    }

    else{

        if (Q.f == Q.r)// if there's only one element sa stack
        {
            Q.f = -1;
            Q.r = -1;
        }

        else
        {
            Q.f = (Q.f+1)% MAX;
        }
         Q.ctr --;
    }
}

void MyQ::display()
{
    int c = 1;
    if (isempty())
    {
        cout<<"The queue is empty..."<<endl;
        system("pause");
    }
    else{
    cout<<"The queue contains: "<<endl;
    for (int i = Q.f; i<=Q.r; i++)
    {
        cout<<c++<<"). "<<"["<<i<<"] "<<Q.data[i]<<endl;
    }
    system("pause");}
}
int menu(){
int ch;
system("cls");
cout <<"MENU \n";
cout <<"1. Enqueue \n";
cout <<"2. Dequeue \n";
cout <<"3. Front \n";
cout <<"4. Rear \n";
cout <<"5. Display All \n";
cout <<"6. Exit \n";
cout <<"\nPlease Select (1-4): ";
cin>>ch;
return ch;
}

int main(){
MyQ Q;
int d;

while(true){
    switch(menu()){
    case 1 : system("cls");cout<<"Input data ";cin >> d; Q.enque(d); break;
    case 2 : system("cls"); Q.dequ(); cout<<"Dequeued Successfully..\n"; system("pause"); break;
    case 3 : cout<<"Front Element: "<< Q.fRont();cout<<"\n"; system("pause"); break;
    case 4 : cout<<"Rear Element: "<< Q.rear();cout<<"\n"; system("pause"); break;
    case 5 : Q.display(); break;
    case 6 : exit(0);
    default:cout<<"Invalid Input\n.";system("pause");}
}
return 0;
}
