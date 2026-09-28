#include <iostream>

// Homework 5 — Jesus
// CIS 5 Week 05 · Rule engine lite

int main() {
  int score = 0;
  int attendance = 0;

  std::cout << "Score 0-100? ";
  std::cin >> score;

  std::cout << "Attendance percent? ";
  std::cin >> attendance;

  // Edge values: score 69 / 70 / 71 and attendance 79 / 80 / 81.
  
  // Invalid values must be checked first because a score outside 0..100 is not a real decision and would ruin the rule chain.
  if (score < 0 || score > 100) {
    std::cout << "Result: invalid score\n";
  }
  // The pass rule uses && because both thresholds must be met at the same time for a full pass; || would allow a weak score or low attendance to pass too easily.
  else if (score >= 70 && attendance >= 80) {
    std::cout << "Result: pass\n";
  }
  // The warning rule uses || because meeting either target is enough to trigger a cautionary result when the score is not a full pass.
  else if (score >= 70 || attendance >= 80) {
    std::cout << "Result: warn — one target is strong enough\n";
  }
  else {
    std::cout << "Result: fail\n";
  }

  // The threshold is >= instead of > because exactly 70 or exactly 80 is still a valid qualifying value and should count as a pass or warning trigger.

  return 0;
}
