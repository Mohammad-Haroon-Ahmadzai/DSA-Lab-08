#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int r, c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c));
    cout << "Enter matrix:\n";
    for (auto &row : a)
        for (int &x : row) cin >> x;

    int lo = 0, hi = c - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2, mr = 0;
        for (int i = 1; i < r; i++) // max of middle column
            if (a[i][mid] > a[mr][mid]) mr = i;

        int left = mid > 0 ? a[mr][mid - 1] : INT_MIN;
        int right = mid < c - 1 ? a[mr][mid + 1] : INT_MIN;

        if (a[mr][mid] >= left && a[mr][mid] >= right)
        {
            cout << "Peak: " << a[mr][mid] << " at (" << mr << "," << mid << ")\n";
            return 0;
        }
        if (left > a[mr][mid]) hi = mid - 1;
        else lo = mid + 1;
    }
}
