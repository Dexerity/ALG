#include <iostream>
using namespace std;

int maxArr(int *arr, int N);
bool isUnique(int *arr, int N);
int factorial(int x);
//factorial complexity - M(N) = M(N - i) + i -> i = N -> M(0) + N -> N

int main() {
    int N = 10;
    int* arr = new int[N] {1,2,3,4,50,6,7,8,9,10};
    
    cout<<maxArr(arr, N)<<endl;
    
    if (isUnique(arr, N))       
        cout<<"Is Unique"<<endl;
    else
        cout<<"Is not Unique"<<endl;

    cout << factorial(10) << endl;
    


    return 0;
}

int maxArr(int *arr, int N)
{
    int max = arr[0];

    for (int i = 0; i < N; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }

    return max;
}

bool isUnique(int* arr, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (arr[i] == arr[j] && i != j)
            {
                return false;
            }
            
        }
    }

    return true;
}

int factorial(int x)
{
    if (x == 0)
        return 1;
    else
        return x * factorial(x - 1);
}