#include "RHCR2.h"
#include <cmath>

unsigned int RHCR2::seed = std::random_device{}();
std::mt19937 RHCR2::gen(seed);

Position RHCR2::generateRandomNeighborPair(const Position &curr_pos,
                                           const int &z) {
  std::uniform_int_distribution<> x(z * -1, z), y(z * -1, z);

  return Position{.x = curr_pos.x + x(gen), .y = curr_pos.y + y(gen)};
}

double RHCR2::ffrog(const Position &pos) {
  int x = pos.x, y = pos.y;

  fRan += 1;

  return (x * cos(sqrt(abs(x + y + 1))) * sin(sqrt(abs(y - x + 1)))) +
         ((1 + y) * sin(sqrt(abs(x + y + 1))) * cos(sqrt(abs(y - x + 1))));
}

RHCR2::Sol RHCR2::RHC(const Position &curr_pos, const double &z, const int &p) {
  double originalMin = ffrog(curr_pos);
  double currMin = originalMin;
  Position currMinPos = curr_pos;

  for (int i = 0; i < p; i++) {
    // calculate potential new min, and see if its lower than curr min
    Position potentialNewMinPosition = generateRandomNeighborPair(curr_pos, z);
    double potentialNewMin = ffrog(potentialNewMinPosition);
    if (potentialNewMin < currMin) {
      currMin = potentialNewMin;
      currMinPos = potentialNewMinPosition;
    }
  }

  return currMin == originalMin ? RHC(currMinPos, z, p)
                                : Sol(currMinPos, currMin);
};

std::vector<RHCR2::Sol> RHCR2::runExperiment(const Position &sp,
                                             const double &z, const int &p) {
  fRan = 0; // set to 0 for counting

  Position curr_pos = sp;
  std::vector<Sol> ret;
  int zDiv = 1;

  for (int i = 0; i < 3; i++) {
    Sol sol = RHC(curr_pos, z / zDiv, p);
    ret.push_back(sol);
    zDiv *= 20; // will multiply to 20, then 400
  }

  return ret;
};

std::string RHCR2::getSeed() { return std::to_string(seed); };

std::string RHCR2::getFRan() { return std::to_string(fRan); };
