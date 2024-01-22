//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    08-08-2023     *************************\


#include <bits/stdc++.h>
using namespace std;
#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

#define output(x) cout << x << endl // out
#define printarray(arr, len)      \
    for (int i = 0; i < len; i++) \
    {                             \
        cout << arr[i] << " ";    \
        if (i + 1 == len)         \
            cout << endl;         \
    } // array print
using namespace std;
int cnt = 0;

// src aux des
void TOH(int n, int a, int b, int c)
{
    if (n > 0)
    {
        TOH(n - 1, a, c, b);
        cout << a << " to " << c << endl;
        cnt++;
        TOH(n - 1, b, a, c);
    }
}

int32_t main()
{
    faster;

    TOH(3, 1, 2, 3);
    // disks--from--using--to
    cout << cnt << endl;

    return 0;
}
