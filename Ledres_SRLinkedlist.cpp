#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct StudeInfo {
    string name;
    int q1, q2, q3;
    StudeInfo* next; // self referential node
    StudeInfo(string n,int q1, int q2, int q3): name(n), q1(q1), q2(q2), q3(q3), next(NULL){}
};

class studeList{
private:
    StudeInfo *head; // initializing the head

    float ave(int q1,int q2,int q3){
    float ave = (q1+q2+q3)/3.0;
    return ave;}

    public:
    studeList() : head(NULL){} // initialize the head of the node to null
    void addRec(string nm, int q1, int q2, int q3);
    void delRec(string nm);
    void display();
    void save();
    void retrieve();
};

int menu(){
int ch;
system("cls");
cout <<"STUDENT RECORD MENU \n";
cout <<"1. Add Record \n";
cout <<"2. Delete Record \n";
cout <<"3. Display \n";
cout <<"4. Exit \n";
cout <<"\nPlease Select (1-4): ";
cin>>ch;
return ch;
}

int main(){
   studeList SR;
string n;
int q1,q2,q3;
SR.retrieve();
while(true){
    switch(menu()){
    case 1 : system("cls");cout<<"Input Name: ";cin >> n;
                           cout<<"Input Q1: "; cin>>q1;
                           cout<<"Input Q2: "; cin>>q2;
                           cout<<"Input Q3: "; cin>>q3;
                           SR.addRec(n,q1,q2,q3); break;
    case 2 : system("cls");cout<<"Input name: ";cin >> n; SR.delRec(n);break;
    case 3 : SR.display();break;
    case 4 : SR.save(); exit(0);
    default:cout<<"Invalid Input\n.";system("pause");}
}
return 0;
}
void studeList::addRec(string nm, int q1, int q2, int q3){
    StudeInfo *newSr = new StudeInfo(nm,q1,q2,q3); //create ng new node
    StudeInfo *p, *q; // create ng pointer p and q for the loop and conditions
    p = q = head;

    while(p!=NULL && nm > p->name){
        q=p;
        p=p->next;}
    if (p!=NULL && p->name == nm)
    {
        cout<<"Name already exist.."<<endl;
        system("pause");
        delete newSr;
        return;
    }

    if (p==head){
        newSr->next = head;
        head = newSr;}

    else{
        newSr->next = p;
         q->next = newSr;}
};
 void studeList:: delRec(string nm){

    StudeInfo *p, *q;
    p = q = head;

    while(p!=NULL&& nm !=p->name)
    {
        q=p;
        p=p->next;}

   if (p==NULL){
        cout<<"Not found.\n";
        system("pause");}

    if (head==p)
        head=p->next;

    else
        q->next = p->next;

    delete(p);
 };

void studeList:: display(){
    StudeInfo *p, *q;
    p = q = head;
        system("cls");
         cout<<"Name:\t Q1\t Q2\t Q3\t AVE \t REMARK\n";
        while(p!=NULL){
          float a = ave(p->q1, p->q2, p->q3);
          cout<<p->name<<"\t"<<p->q1<<"\t"<<p->q2<<"\t"<<p->q3<<"\t"<<fixed<<setprecision(2)<<a;
          if (a > 75)
            cout<<"\tPASSED"<<endl;
          else
            cout<<"\tFAILED"<<endl;
            p = p->next;
        }
    system("pause");
    };

  void studeList:: save(){
    StudeInfo *p, *q;
    p = q = head;
    fstream fp;
    fp.open("StudentRecord.txt", ios::out| ios::trunc);
    if (!fp)
        cout<<"\n File error. \n";

    else
    {
        while(p!=NULL){
            fp<<p->name<<' '<<p->q1<<' '<<p->q2<<' '<<p->q3<<endl;
            p= p->next;
        }

        fp.close();
        cout<<"Data saved to file successfully.\n";
        system("pause");
    }
    };

    void studeList:: retrieve(){
    fstream fp;
    fp.open("StudentRecord.txt", ios:: in);

    if(!fp){
        cout<<"\n\t\t\t File Error.\n";
        system("pause");
        return;}
    else{
    string n;
    int q1,q2,q3;
    while (fp >> n >> q1 >> q2 >> q3){
        addRec(n,q1,q2,q3);}
    fp.close();
    cout << "Data retrieved from file successfully.\n";
    system("pause");}
    };

