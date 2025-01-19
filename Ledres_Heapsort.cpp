// Ledres, Racy Jhanna
// BSIS - 2A

#include <iostream>
using namespace std;

void heapSorting(int arr[],int s);
void heapify(int arr[], int s, int i);
void printing(int arr[], int s);

int main()
{
    int arr[] = {4,17,10,12,23,16}; // 1
    int n = sizeof(arr)/sizeof(arr[0]); // 1

    cout<<" Unsorted array: "; // 1
      printing(arr,n);

    heapSorting(arr,n);

    cout<<"\n Sorted array: "; // 1
      printing(arr,n);

}
void heapify(int arr[], int s, int i) // 7 + log n
{
    int largest = i; // 1
    int left = 2 * i + 1; // 1
    int right = 2 * i + 2; // 1

    if (left < s && arr[left]>arr[largest]) // 1
    {
        largest = left;
    }

    if (right < s && arr[right] > arr[largest]) // 1
    {
        largest = right;
    }

    if (largest != i ){ // 1

        swap(arr[i], arr[largest]); // 1
        heapify(arr,s,largest); // log n (since the amount of time is reduced by halves)
    }
}
void heapSorting(int arr[],int s) // 3*n * log n + 3*n * log n
{
    int i;
    for (i = s/2 - 1; i >=0; i--) // 3*n
        heapify(arr,s,i); // log n

    for (i = s - 1; i > 0; i--) // 3*n * log n =
    {
        swap(arr[0],arr[i]); // 1

        heapify(arr,i,0); // log n
    }
}

void printing(int arr[], int s) // 3*n + 1
{
      for (int i = 0; i < s; ++i) // 3*n
      {
        cout << arr[i] << " "; // 1
      }

}
// for printing function : f(n) = 3*n + 1 => O(n)
// for heapify function : f(n) = 7 + log n  => O (log n)
// for heapsorting function: f(n) = 3*n * log n + 3*n * log n
//                                = 3n * log n  + 3n * log n
//                                = 6n * log n
//                                = n * log n => O(n log n)

//overall, f(n) = 0(n) + O(log n) + O(n log n) = O(n log n) => Linearithmic Time

