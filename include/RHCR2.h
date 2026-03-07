#ifndef RHCR2_H
#define RHCR2_H

#include <random>

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
  static std::mt19937 gen(std::random_device);

  // generate random pair
  // since the seed is generated via
  Position generateRandomPair(int z1, int z2);

  // calculates strength of x,y coord with pre-defined test formula
  int ffrog(Position pos);

  // default is -1 until an experiment is ran
  int fRan = -1;

public:
  RHCR2();

  // print seed
  std::string getSeed();

  std::string getFRan();
  
  // return results of experiment, as well number of times f is ran
  std::vector<Position> runExperiment(Position sp, int z, int p);
};

#endif // RHCR2_H
