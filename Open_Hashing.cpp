#include<iostream>
#define siZe 10
using namespace std;


struct Node {

    int data;
    Node *next;
    Node(int x): data(x), next(NULL){}
};


class hashTable{

    private:
    Node *bucket[siZe];
    int index;

    public:
        hashTable() {
        for (int i = 0; i < siZe; i++) {
            bucket[i] = nullptr;  // Initialize all slots to null
        }
    }
        int Hash(int x){
            return (x % siZe);
        }

        void insert_data(int x){
        Node *n = new Node(x);
        index = Hash(x);

        if (bucket[index] == NULL)
        {
            bucket[index] = n;
        }
        else {
            Node *p = bucket[index];
            while(p->next != NULL){
                p = p->next;
            }
            p->next = n; // If na reach na yung end, tsaka idadagdag
        }
        }

        void delete_data(int x){

        index = Hash(x);

        Node *p = bucket[index];
        Node *q = NULL;

    while(p!=NULL){
        if (p->data == x){
            if (q == NULL)
            {
                bucket[index] = p->next;
            }

            else{
                q->next = p->next;
            }

            delete(p);
            return;
        }

        q = p;
        p = p ->next;
        }
            cout << "Value " << x << " not found in the hash table!" << endl;
        }


    void display() {
        for (int i = 0; i < siZe; i++) {
            cout << "Index " << i << ": ";
            Node* p = bucket[i];
            while (p != nullptr) {
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
        }
    }
};



int main() {
    hashTable table;  // Create a hash table object

    // Insert data into the hash table
    table.insert_data(15);
    table.insert_data(25);
    table.insert_data(35);
    table.insert_data(5);
    table.insert_data(10);
    table.insert_data(30);

    // Display the hash table
    cout << "Hash table contents: " << endl;
    table.display();

    // Delete some data
    table.delete_data(25);  // Should delete 25
    table.delete_data(5);   // Should delete 5
    table.delete_data(100); // Should print a message that 100 is not found

    // Display the hash table after deletions
    cout << "Hash table contents after deletion: " << endl;
    table.display();

    return 0;
}

