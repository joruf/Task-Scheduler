#include "scheduler.h"

Scheduler::Scheduler(unsigned int intervalMs)
    : interval(std::chrono::milliseconds(intervalMs)), lastExecution(std::chrono::steady_clock::now() - interval) {}

void Scheduler::run(std::function<void()> func) {
  auto now = std::chrono::steady_clock::now();
  if (now - lastExecution >= interval) {
    lastExecution = now;
    func();
  }
}
