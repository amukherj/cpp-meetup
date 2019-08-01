#include <bits/stdc++.h>
using namespace std;

template<typename TryLockable>
struct DemoLockable {
  DemoLockable(string name) : name(name), lck() {}

  void lock() {
    lck.lock();
    cout << "Locked " << name << '\n';
  }

  void unlock() {
    lck.unlock();
    cout << "Unlocked " << name << '\n';
  }

  bool try_lock() {
    auto result = lck.try_lock();
    if (result) {
      cout << "could lock " << name << '\n';
    } else {
      cout << "couldn't lock " << name << '\n';
    }

    return result;
  }

  string name;
  TryLockable lck;
};

int main() {
  DemoLockable<mutex> lock1("l1"), lock2("l2"), lock3("l3");
  {
    scoped_lock multi_lock(lock1, lock2, lock3);
    this_thread::sleep_for(chrono::seconds(2));
  }
}
