//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    01-08-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

int main()
{
      queue<int> que;
      que.push(10);
      que.push(100);
      que.push(1000);

      cout << "Queue Front " << que.front() << endl;
      cout << "Queue size  " << que.size() << endl;
      cout << endl;

      if (que.empty())
      {
            cout << "This queue is empty" << endl;
      }
      else
      {
            cout << "This queue is not empty" << endl;
      }

      que.pop();
      cout << "Queue size  " << que.size() << endl;
      cout << "Queue Front " << que.front() << endl;
      cout << endl;

      que.pop();
      que.pop();
      cout << "Queue size  " << que.size() << endl;
      cout << "Queue Front " << que.front() << endl;
      if (que.empty())
      {
            cout << "This queue is empty" << endl;
      }
      cout << endl;

      return 0;
      ;
}