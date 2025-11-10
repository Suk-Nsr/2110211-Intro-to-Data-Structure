#include <iostream>
#include <string>
#include "queue.h"
#include "student.h"


using std::cin;
using std::cout;
using std::string;


class MS {
  public:
    string v;
    MS() : v() {}
    MS(int x) { v = std::string(3,'*') + std::to_string(x); }

    friend std::ostream& operator<<(std::ostream& os, const MS& ms) {
      os << ms.v;
      return os;
    }
};

template <typename T>
void test() {
  CP::queue<T> q;
  int a,b,c;
  cin >> a >> b >> c;
  int num = 1;
  for (int i = 0;i < a;i++,num++) {q.push(num); }
  for (int i = 0;i < b;i++) q.pop();
  for (int i = 0;i < c;i++,num++) q.push(num);
  int r,p1,p2,repeat;
  cin >> r;
  while(r--) {
    cin >> p1 >> p2 >> repeat;
    while(repeat--) {
      q.reverse(p1,p2);
    }
  }
  cout << "size = " << q.size() << "\n";
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << "\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);cin.tie(0);

  int type;
  cin >> type;
  if (type == 0) {
    test<int>();
  } else {
    test<MS>();
  }
}
