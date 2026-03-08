#ifndef RHCR2_H
#define RHCR2_H

#include <fstream>
#include <random>
#include <utility>

struct Position {
  int x, y;
};

/*
 * Will run RHC 3 times.
 *
 * sol1: sp, z, p, seed
 * sol2: sol1, z/20, p, seed
 * sol3: sol2, z/400, p, seed
 *
 * returns; {(sol1, f(sol1), (sol2, f(sol2)), (sol3, f(sol3))}
 */
class RHCR2 {
private:
  // ensure seed is static with all iterations for program lifetime
  static std::mt19937 gen;
  static unsigned int seed;

  // the output file, always a RESULTS.md
  static std::ofstream resultsFile;

  // type for solution
  using Sol = std::pair<Position, double>;

  // default is -1 until an experiment is ran
  int fRan = -1;

  // reseed for new experiment set
  static void reseed();

  // generate random neighbor pair
  Position generateRandomNeighborPair(const Position &currMinPos, const int &z);

  // calculates strength of x,y coord with pre-defined test formula
  double ffrog(const Position &pos);

  // will compare curr_pos ffrog value p times
  // if there is a ffrog value after p iterations, recurse with currMinPos.
  // keep going until currMin == originalMin
  Sol RHC(const Position &curr_pos, const double &z, int const &p);

public:
  RHCR2();

  // will run 3 iterations of RHC, and return results of each in Sol type
  std::vector<Sol> runExperiment(const Position &sp, const double &z,
                                 const int &p);

  // get seed
  std::string getSeed();

  // get number of f calls
  std::string getFRan();

  // user ability to insert into ifstream file
  std::ofstream &rin();
};

#endif // RHCR2_H
