//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    08-08-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    stack<int> s;

    s.push(10);
    s.push(100);
    s.pop();
    s.push(1000);

    cout << s.empty() << endl;
    cout << s.top() << endl;
    cout << s.size() << endl;

    return 0;
}
