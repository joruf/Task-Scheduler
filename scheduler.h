/**
 * @file scheduler.h
 * @brief Lightweight task scheduler for periodic function execution.
 *
 * Provides simple time-based scheduling with millisecond precision.
 * Each scheduler instance runs a given function at its specified interval.
 * Uses C++11 chrono for time tracking.
 *
 * Example:
 * @code
 * Scheduler scheduler_1(500); // time in ms
 * Scheduler scheduler_2(1000);
 *
 * void loop() {
 *     scheduler_1.run([]() {
 *         Serial.println("Scheduler 1 executed");
 *     });
 *
 *     scheduler_2.run([]() {
 *         Serial.println("Scheduler 2 executed");
 *     });
 * }
 * @endcode
 */

#pragma once

#include <chrono>
#include <functional>

class Scheduler {
 public:
  explicit Scheduler(unsigned int intervalMs);

  void run(std::function<void()> func);

 private:
  std::chrono::milliseconds interval;
  std::chrono::steady_clock::time_point lastExecution;
};
