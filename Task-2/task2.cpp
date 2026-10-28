#include <iostream>
#include <algorithm>
using namespace std;

int n, b[20][20];
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool ok(int x, int y) { return x >= 0 && y >= 0 && x < n && y < n && b[x][y] == 0; }

int degree(int x, int y)
{
    int c = 0;
    for (int i = 0; i < 8; i++) if (ok(x + dx[i], y + dy[i])) c++;
    return c;
}

bool solve(int x, int y, int step)
{
    b[x][y] = step;
    if (step == n * n) return true;

    pair<int, int> mv[8]; // (degree, move index)
    int k = 0;
    for (int i = 0; i < 8; i++)
        if (ok(x + dx[i], y + dy[i]))
            mv[k++] = {degree(x + dx[i], y + dy[i]), i};

    sort(mv, mv + k); // fewest onward moves first

    for (int j = 0; j < k; j++)
        if (solve(x + dx[mv[j].second], y + dy[mv[j].second], step + 1))
            return true;

    b[x][y] = 0; // backtrack
    return false;
}

int main()
{
    int x, y;
    cout << "Enter N: ";
    cin >> n;
    cout << "Enter start x and y (0-based): ";
    cin >> x >> y;

    if (solve(x, y, 1))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) cout << b[i][j] << "\t";
            cout << "\n";
        }
    }
    else cout << "No tour found\n";
}
