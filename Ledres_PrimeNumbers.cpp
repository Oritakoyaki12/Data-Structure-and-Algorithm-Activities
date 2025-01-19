// Ledres, Racy Jhanna
// BSIS - 2A

#include <iostream>

using namespace std;

bool isPrimeNum(int n) // 1 + 3n
{
    if (n <=1){ // 1
        return false;
    }

    for (int i = 2; i<n; i++) // 3*n *1 = 3n
    {
        if (n %i == 0) // 1
        {
            return false;
        }
    }

    return true;
}
int main () // 1 + 1 + 9n^2 + 1
{
    int n = 20; // 1

    cout<<"Prime numbers from 2 to "<<n<<": "; // 1
    for (int i = 2; i<=n; i++) // 3*n * 3n + 1 = 9n^2 + 1
    {
        if (isPrimeNum(i)) // 1 + 3n * 1 = 3n + 1
        {
            cout<<i<<" "; // 1
        }
    }
}

//for bool isprime function: 1 + 3n => O(n)
//for main function: 9n^2 + 1 => O(n^2)

// f(n) = O(n) + O(n^2) => O(n^2) -> Quadratic Time
