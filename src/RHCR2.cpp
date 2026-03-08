#include "RHCR2.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <random>
#include <stdexcept>

// happy existing definition :)
RHCR2::RHCR2() {}

unsigned int RHCR2::seed = std::random_device{}();
std::mt19937 RHCR2::gen(seed);

std::ofstream RHCR2::resultsFile("RESULTS.md", std::ios::out);

void RHCR2::cap512(double &pnt) {
  if (pnt > 512)
    pnt = 512;
  if (pnt < -512)
    pnt = -512;
}

Position RHCR2::generateRandomNeighborPair(const Position &currMinPos,
                                           const double &z) {
  std::uniform_real_distribution<double> x(z * -1, z), y(z * -1, z);

  double xp = currMinPos.x + x(gen);
  double yp = currMinPos.y + y(gen);
  cap512(xp);
  cap512(yp);

  return Position{.x = xp, .y = yp};
}

double RHCR2::ffrog(const Position &pos) {
  double x = pos.x, y = pos.y;

  fRan += 1; // count number of times ffrog is called

  return (x * cos(sqrt(std::abs(x + y + 1))) * sin(sqrt(std::abs(y - x + 1)))) +
         ((1 + y) * sin(sqrt(std::abs(x + y + 1))) *
          cos(sqrt(std::abs(y - x + 1))));
}

RHCR2::Sol RHCR2::RHC(const Position &curr_pos, const double &z, const int &p) {
  double originalMin = ffrog(curr_pos);
  double currMin = originalMin;
  Position currMinPos = curr_pos;

  for (int i = 0; i < p; i++) {
    // calculate potential new min, and see if its lower than curr min
    Position potentialNewMinPosition =
        generateRandomNeighborPair(currMinPos, z);
    double potentialNewMin = ffrog(potentialNewMinPosition);
    if (potentialNewMin < currMin) {
      currMin = potentialNewMin;
      currMinPos = potentialNewMinPosition;
    }
  }

  return std::abs(currMin - originalMin) < 1e-9 ? Sol(currMinPos, currMin)
                                                : RHC(currMinPos, z, p);
};

std::vector<RHCR2::Sol> RHCR2::runExperiment(const Position &sp,
                                             const double &z, const int &p) {
  fRan = 0; // set to 0 for counting

  // ensure the domain x,y element of [-512, 512] is respected
  if (sp.x > 512 || sp.y > 512 || sp.x < -512 || sp.y < -512) {
    throw std::domain_error("sp.x: " + std::to_string(sp.x) +
                            " | sp.y: " + std::to_string(sp.y) +
                            ". Please ensure x,y element of [-512, 512]");
  }

  Position curr_pos = sp;
  std::vector<Sol> ret;
  double zDiv = 1;

  resultsFile << std::endl
              << "----------\n#### EXPERIMENT" << std::endl
              << "**Initial**" << std::endl
              << "- sp: **(" << curr_pos.x << ", " << curr_pos.y << ")**"
              << std::endl
              << "- strength: **" << ffrog(curr_pos) << "**" << std::endl
              << "- z: **" << z / zDiv << "**" << std::endl
              << "- *(const)* p: **" << p << "**" << std::endl;

  for (int i = 0; i < 3; i++) {
    Sol sol = RHC(curr_pos, z / zDiv, p);
    ret.push_back(sol);

    resultsFile << std::endl
                << "iter " << i + 1 << ", sol: {POS: (" << sol.first.x << ", "
                << sol.first.y << "), STRENGTH: " << sol.second << "}. sp: ("
                << curr_pos.x << ", " << curr_pos.y << "). z: (" << z / zDiv
                << "), current fRuns: (" << fRan << ")" << std::endl;

    // new values for new run
    curr_pos = sol.first;
    if (i != 2)
      zDiv *= 20; // will multiply to 20, then 400
  }

  resultsFile << std::endl
              << "#### EXPERIMENT" << std::endl
              << "**Final**" << std::endl
              << "- sp: **(" << curr_pos.x << ", " << curr_pos.y << ")**"
              << std::endl
              << "- strength: **" << ffrog(curr_pos) << "**" << std::endl
              << "- z: **" << z / zDiv << "**" << std::endl
              << "- *(const)* p: **" << p << "**" << std::endl
              << "- total fRuns: **" << fRan << "**" << std::endl
              << "----------" << std::endl;

  return ret;
};

void RHCR2::reseed() {
  seed = std::random_device{}();
  gen.seed(seed);
}

std::string RHCR2::getSeed() { return std::to_string(seed); };

std::string RHCR2::getFRan() { return std::to_string(fRan); };

std::ofstream &RHCR2::rin() { return resultsFile; };
