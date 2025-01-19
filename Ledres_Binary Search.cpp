// Ledres, Racy Jhanna
// BSIS - 2A

#include <iostream>

using namespace std;


int main ()
{
    int arr[] = {10,20,30,40,45,50,60,70,75,80,90}; // 1
    int n; // 1
    n = sizeof(arr)/sizeof(arr[0]); // 1

    int targetVal = arr[8]; // 1
    int low = 0; // 1
    int high = n - 1; // 1
    int mid; // 1
    bool found = false; // 1

    while (low<=high) // O(log n) // since each iteration the search process is halved
    {
        mid = (low + high) / 2; // 1

        if (targetVal == arr[mid]) // 1
        {
            cout<<"The target value "<<arr[mid]<<" is found at index "<<mid<< endl; // 1
            found = true; // 1
            break;
        }

        else if (targetVal > arr[mid]) // 1
        {
            low = mid + 1;// 1
        }

        else
        {
            high = mid - 1; // 1
        }
    }

    if (!found) // 1
    {
        cout<<"The target value "<<targetVal<<" is not found..."<<endl; // 1
    }
};

// f(n) = 8 + log n + 8 = 16 + log n => O(log n) -> Logarithmic time
