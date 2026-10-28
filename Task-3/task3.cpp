#include <iostream>
#include <stack>
using namespace std;

// Makes the only legal move between pegs a and b
void move(stack<int> &a, stack<int> &b, char A, char B)
{
    if (b.empty() || (!a.empty() && a.top() < b.top()))
    {
        cout << "Move disk " << a.top() << " from " << A << " to " << B << "\n";
        b.push(a.top());
        a.pop();
    }
    else
    {
        cout << "Move disk " << b.top() << " from " << B << " to " << A << "\n";
        a.push(b.top());
        b.pop();
    }
}

int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    stack<int> s, d, a;
    char S = 'A', D = 'C', X = 'B';
    if (n % 2 == 0) swap(D, X), swap(d, a); // even N: swap dest and aux

    for (int i = n; i >= 1; i--) s.push(i);

    int total = (1 << n) - 1;
    for (int i = 1; i <= total; i++)
    {
        if (i % 3 == 1) move(s, d, S, D);
        else if (i % 3 == 2) move(s, a, S, X);
        else move(a, d, X, D);
    }
}
