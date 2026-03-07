#include "RHCR2.h"
#include <cmath>

unsigned int RHCR2::seed = std::random_device{}();
std::mt19937 RHCR2::gen(seed);

Position RHCR2::generateRandomNeighborPair(const Position &curr_pos, const int &z) {
  std::uniform_int_distribution<> x(z * -1, z), y(z * -1, z);

  return Position{.x = curr_pos.x + x(gen), .y = curr_pos.y + y(gen)};
}

double RHCR2::ffrog(const Position &pos) {
  int x = pos.x, y = pos.y;

  return (x * cos(sqrt(abs(x + y + 1))) * sin(sqrt(abs(y - x + 1)))) +
         ((1 + y) * sin(sqrt(abs(x + y + 1))) * cos(sqrt(abs(y - x + 1))));
}

Position RHCR2::RHC(const Position &curr_p, const double &z, const int &p) {
  double lowestVal;
};

std::vector<RHCR2::Sol> RHCR2::runExperiment(const Position &sp,
                                             const double &z, const int &p) {
  Position curr_sp;
  std::vector<Sol> ret;
  int zDiv = 1;

  for (int i = 0; i < 3; i++) {
    Sol sol;
  }

  return ret;
};

std::string RHCR2::getSeed() { return std::to_string(seed); };

std::string RHCR2::getFRan() { return std::to_string(fRan); };
