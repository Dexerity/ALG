#include <iostream>

using namespace std;

bool sequenceSearchIter(int* arr, int N, int value);
bool sequenceSearchRec(int* arr, int N, int value);
void bubbleSort(int* arr, int N);
void printArr(int* arr, int N);

int main(){
    int N = 100000;
    int* arr = new int[N];
    
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % N;
    }
    
    printArr(arr, N);

    time_t startTime = time(nullptr);
    bubbleSort(arr, N);
    time_t endTime = time(nullptr);
    
    printArr(arr, N);

    cout << "Bubble sort time: " << endTime - startTime << " seconds" << endl;


    delete[] arr;

    return 0;
}

bool sequenceSearchIter(int* arr, int N, int value)
{
    for (int i = 0; i < N; i++)
    {
        if(arr[i] == value)
        {
            return true;
        }
    }
    return false;
}

bool sequenceSearchRec(int* arr, int N, int value)
{
    if(N <= 0)
        return false;

    if(arr[N - 1] == value)
        return true;

    return sequenceSearchRec(arr, N - 1, value);
}

void bubbleSort(int* arr, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArr(int* arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}