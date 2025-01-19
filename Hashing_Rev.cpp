
// Closed Hashing using Linear probing
// If u want to use Quadratic probing just add ^2 to i
#include <iostream>
#define bucket_size 10

using namespace std;

class HashTable{

private:
    int table[bucket_size];

public:
    HashTable(){
    for(int i = 0; i< bucket_size; i++){
        table[i] = -1;
    }}

    int Hash(int x){
    return(x % bucket_size);}

    void insertData(int x);
    void deleteData(int x);
    int locate(int x);
    void display();
};


void HashTable::insertData(int x){
int index;
for (int i = 0; i < bucket_size; i++)
{
    index = Hash(x + i);
    if (table[index] > 0){
        continue;}
    else{
        table[index] = x;
        return;
    }
}

   cout<<"Table is full"; system("pause");

}


void HashTable::deleteData(int x){
int index;
for (int i = 0; i < bucket_size; i++)
{
    index = Hash(x + i);
    if (table[index] == x){
        table[index] = -1;
        return;}
}

    cout<<"data not found..."; system("pause");
}

void HashTable::display(){

for (int i = 0; i< bucket_size; i++){

    if(table[i] > -1){
        cout<<table[i]<<" ";
    }
    else{
        cout<<"_ ";
    }
};
}

int HashTable::locate(int x){
int index;
for(int i = 0; i< bucket_size; i++)
{
  index = Hash(x + i);

  if (table[index] == x)
  {
      return index;
  }

}

    cout<<"data not found...";system("pause");
    return -1;
}

int main (){
     HashTable ht;
    ht.insertData(5);
    ht.insertData(15);
    ht.insertData(20);
    ht.insertData(37);

    cout << "Hash table contents:" << endl;
    ht.display();

    int index = ht.locate(15);
    if (index != -1) {
        cout << "\n 15 found at index: " << index << endl;
    }

    ht.deleteData(15);
    cout << "\n After deleting 15:" << endl;
    ht.display();

    return 0;

}
