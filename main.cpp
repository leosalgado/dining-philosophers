#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex print_mutex;
std::vector<std::mutex> chopsticks(5);

void philosopher(int id) {
  /* guarantees only 1 thread has accesss to the shared resource "cout" and
   * releases after function ends */
  std::lock_guard<std::mutex> guard(print_mutex);
  std::cout << "Philosopher " << id << std::endl;
}

int main() {

  std::thread t1(philosopher, 1);
  std::thread t2(philosopher, 2);
  std::thread t3(philosopher, 3);
  std::thread t4(philosopher, 4);
  std::thread t5(philosopher, 5);

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();

  return 0;
}
