#include <iostream>
#include <iomanip>
#include <fstream>
#define MAX 5
using namespace std;

struct StudeInfo {
    string name;
    int q1, q2, q3;
};

class studeList{
private:
    StudeInfo SRec[MAX]; // i used array of structures to efficiently manage data
    int last;
    bool isfull(){
    return last == MAX - 1;}

    bool isempty(){
    return last == -1;}

    int locate(string nm){
    for (int i=0;i<=last;i++)
    if(nm == SRec[i].name)
         return i;
    return -1;}

    float ave(int q1,int q2,int q3){
    float ave = (q1+q2+q3)/3.0;
    return ave;}

    public:
    studeList() : last(-1){}
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
    if(isfull()){
    cout<<"List is full.\n";
    system("pause");}

else {
    int p = locate(nm);
        if (p>0){
            cout<<"Name is already used..\n";
            system("pause");
        }
        else{
    int insert_post = 0;
    while (insert_post <=last && nm > SRec[insert_post].name)
    {
        insert_post++;
    }
    for (int i = last; i>=insert_post; i--)
    {
        SRec[i+1] = SRec[i];
    }

    SRec[insert_post].name = nm;
    SRec[insert_post].q1 = q1;
    SRec[insert_post].q2 = q2;
    SRec[insert_post].q3 = q3;
    last++;}
        }

};

 void studeList:: delRec(string nm){
     if (isempty()){
        cout<<"The student list is empty.\n";
        system("pause");}

     else
     {
        int p = locate(nm);
        if (p<0){
        cout<<"Name not found.\n";
        system("pause");
    }
    else {
        for (int i=p;i<last;i++){
            SRec[i] = SRec[i+1];
        }
        last--;
        }
    }
 };

void studeList:: display()
    {
        system("cls");
        if (isempty()){
            cout<<"The Student Record is empty..."<<endl;
            system("pause");}
        else{
         cout<<"Name:\t Q1\t Q2\t Q3\t AVE \t REMARK\n";
        for (int i=0; i<=last; i++)
        {
          float a = ave(SRec[i].q1, SRec[i].q2,SRec[i].q3);
          cout<<SRec[i].name<<"\t"<<SRec[i].q1<<"\t"<<SRec[i].q2<<"\t"<<SRec[i].q3<<"\t"<<fixed<<setprecision(2)<<a;
          if (a > 75)
            cout<<"\tPASSED"<<endl;
          else
            cout<<"\tFAILED"<<endl;
        }}
    system("pause");
    };

  void studeList:: save(){
    fstream fp;
    fp.open("StudentRecord.txt", ios::out| ios::trunc);
    if (!fp)
        cout<<"\n File error. \n";

    else
    {
        for (int i = 0; i<=last; i++)
        {
            fp<<SRec[i].name<<' '<<SRec[i].q1<<' '<<SRec[i].q2<<' '<<SRec[i].q3<<endl;
        }

        fp.close();
        cout<<"Data saved to file successfully.\n";
        system("pause");
    }
    }

    void studeList:: retrieve(){
    fstream fp;
    fp.open("StudentRecord.txt", ios:: in);

    if(!fp){
        cout<<"\n\t\t\t File Error.\n";
        system("pause");
        return;
    }
    else{
    string n;
    int q1,q2,q3;
    while (fp >> n >> q1 >> q2 >> q3){
        if (isfull()){
            cout<<"List is Full. cannot add more records.\n";
            break;
        }
        addRec(n,q1,q2,q3);
    }

    fp.close();
    cout << "Data retrieved from file successfully.\n";
    system("pause");
    }
    };

