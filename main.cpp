#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex print_mutex;
std::vector<std::mutex> chopsticks(5);

void philosopher(int id) {
  std::lock_guard<std::mutex> guard(print_mutex);
  std::cout << "Philosopher " << id << " is thinking..." << std::endl;
}

int main() {
  const int num_philosophers = 5;

  std::vector<std::thread> philosophers;

  for (int i = 0; i < num_philosophers; i++) {
    philosophers.emplace_back(philosopher, i);
  }

  for (auto& p : philosophers) {
    p.join();
  }

  return 0;
}
