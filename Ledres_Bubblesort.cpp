// Ledres, Racy Jhanna
// BSIS - 2A

#include <iostream>

using namespace std;
int main()
{
    int i, j, temp; // 1
    int arr[] = {1,10,45,19,65,100,80,50}; // 1
    int n = sizeof(arr)/sizeof(arr[0]); // 1


    for (i = 0; i<n; i++) // 3*n * 12n = 3n * 12n = 36n^2
    {
        for(j = i+1; j<=n; j++) // 3*n * 4 = 12n
        {
            if(arr[i] > arr[j]) // 1
            {
                temp = arr[i]; // 1
                arr[i]= arr[j]; // 1
                arr[j] = temp; // 1
            }
        }
    }

    cout<<"Bubble Sort: ";

    for (i = 0; i<n; i++) // 3*n
    {
        cout<<arr[i]<<" "; // 1
    }

    return 0;
}


// f(n) =  3 + 36n^2 + 3n => O(n^2) -> Quadratic time


