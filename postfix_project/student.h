#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>
#include <stack>

using namespace std;

int eval_postfix(vector<pair<int, int>> v)
{
  std::stack<int> postfix;
  int a, b, c;

  for (auto x : v)
  {
    if (x.first == 1)
    {
      postfix.push(x.second);
    } else {
      a = postfix.top();
      postfix.pop();
      b = postfix.top();
      postfix.pop();
      if (x.second == 0)
      {
        c = b + a;
        postfix.push(c);
      } else if (x.second == 1)
      {
        c = b - a;
        postfix.push(c);
      } else if (x.second == 2)
      {
        c = b * a;
        postfix.push(c);
      } else {
        c = b / a;
        postfix.push(c);
      }
    }
  }
  return (postfix.top());
}

#endif
