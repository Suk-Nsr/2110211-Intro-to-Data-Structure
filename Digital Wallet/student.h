#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <string>
#include <unordered_map>
#include <deque>

using namespace std;

struct Chunk {
  int amount;
  size_t expire;
};

class DigitalWallet {
  unordered_map<string, deque<Chunk>> wallets;
  long long total_give = 0;
  long long total_spent = 0;
  long long total_expired = 0;

  void purge(size_t time, string person_id) {
    while (!wallets[person_id].empty() && wallets[person_id].front().expire < time) {
      total_expired += wallets[person_id].front().amount;
      wallets[person_id].pop_front();
    }
  }
 public:
  void add_money(size_t time, string person_id, int amount, size_t duration) {
    wallets[person_id].push_back({amount, time + duration});
    total_give += amount;
  }

  bool use_money(size_t time, string person_id, int amount) {
    purge(time, person_id);

    long long balance = 0;
    for (Chunk &i : wallets[person_id]) {
      balance += i.amount;
    }
    if (balance < amount) {
      return false;
    }

    int need = amount;
    while (need > 0) {
      if (wallets[person_id].front().amount <= need) {
        need -= wallets[person_id].front().amount;
        wallets[person_id].pop_front();
      } else {
        wallets[person_id].front().amount -= need;
        need = 0;
      }
    }
    total_spent += amount;
    return true;
  }

  int current_money(size_t time, string person_id) {
    purge(time, person_id);
    int sum = 0;
    for (Chunk &i : wallets[person_id]) {
      sum += i.amount;
    }
    return sum;
  }

  void status(size_t time, long long &tg, long long &ts,long long &te) {
    for (auto &i : wallets) {
      purge(time, i.first);
    }
    tg = total_give;
    ts = total_spent;
    te = total_expired;
  }
};

#endif
