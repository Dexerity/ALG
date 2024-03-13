#include <iostream>
#include <stack>

using namespace std;

//Hanoi tower complexity - M(N) = 2 * M(N - 1) + 1 -> M(N) = 2^N-1 + ... + 2^2 + 2^1 + 2^0 -> (2^N) - 1 -> [2^N]

struct Towers
{
    stack<int> A;
    stack<int> B;
    stack<int> C;

    int numDisks = 4;

    Towers()
    {
        for (int i = numDisks; i > 0; i--)
        {
            A.push(i);
        }
    }

    void solve()
    {
        solve(numDisks, A, C, B);
    }

    void solve(int n, stack<int> &from, stack<int> &aux, stack<int> &to)
    {
        if(n == 1)
        {
            moveDisks(A, C);
            return;
        }

        solve(n - 1, from, to, aux);
        moveDisks(from, to);
        solve(n - 1, aux, from, to);    
    }

    void moveDisks(stack<int> &from, stack<int> &to)
    {
        if(isMoveValid(from, to))
        {
            to.push(from.top());
            from.pop();
        }
        else
        {
            from.push(to.top());
            to.pop();
        }

        printTowers();
        cout << "-----" << endl;
    }

    bool isMoveValid(stack<int> &from, stack<int> &to)
    {
        if(!from.empty() && (to.empty() || from.top() < to.top()))
            return true;

        return false;
    }

    void printTowers()
    {
        printTowers(A, B, C);
    }

    void printTowers(stack<int> A, stack<int> B, stack<int> C)
    {
        for (int i = numDisks; i > 0; i--)
        {
            if (A.size() >= i)
            {
                cout << A.top() << " ";
                A.pop();
            }
            else
            {
                cout << "| ";
            }
            if (B.size() >= i)
            {
                cout << B.top() << " ";
                B.pop();
            }
            else
            {
                cout << "| ";
            }
            if (C.size() >= i)
            {
                cout << C.top() << " ";
                C.pop();
            }
            else
            {
                cout << "| ";
            }

            cout << endl;
        }
    }

};

int main(){
    Towers t;
    t.printTowers();
    t.solve();




    return 0;
}