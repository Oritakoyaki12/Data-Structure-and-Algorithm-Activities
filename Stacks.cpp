#include <iostream>
#define MAX 5

using namespace std;

struct sTack{
int data;
};
class MyStack {

private:
    sTack s[MAX];
    int top;
    bool isEmpty()
    {
        return (top == MAX);
    }
    bool isFull()
    {
        return (top == 0);
    }

public:
    MyStack(): top(MAX){}
    void push(int x)
    {
        bool found;
        if (isFull()){
            cout<<"Stack overflow...\n";
            system("pause");
        }
        else{
            for(int i = top; i<=MAX; i++)
            {
                if (x == s[i].data)
                {
                    found = true;
                    cout<<"Already in stack..\n";
                    system("pause");
                    break;
                }
            }
            if (!found)
                {
                    top--;
                    s[top].data = x;
                }

        }
    }
    void pop(){
        if(isEmpty()){
            cout<<"Empty stack...\n";
            system("pause");
        }
        else{
            s[top].data = 0;
            top++;
        }
    }

    int getTop(){
        return(s[top].data);
    }
    void display(){
    for(int i = top; i<MAX; i++)
    {
        //if(s[i].data!=0)

           cout<<s[i].data<<endl;

    }
    }
};

int menu(){
int ch;
system("cls");
cout <<"STUDENT RECORD MENU \n";
cout <<"1. Push \n";
cout <<"2. Pop \n";
cout <<"3. Top\n";
cout <<"4. Display All \n";
cout <<"5. Exit \n";
cout <<"\nPlease Select (1-5): ";
cin>>ch;
return ch;
}

int main(){
    MyStack MS;
    int num, t;

    while(true){
    switch(menu()){
    case 1 : system("cls");cout<<"Input Number: ";cin >> num; MS.push(num);break;
    case 2 : system("cls"); MS.pop(); cout<<"Pop successfully...\n"; break;
    case 3 : cout<<"Top number: "<<MS.getTop()<<endl; system("pause");break;
    case 4 : MS.display();system("pause");break;
    case 5 : exit(0);
    default:cout<<"Invalid Input\n.";system("pause");}
}
return 0;


}



