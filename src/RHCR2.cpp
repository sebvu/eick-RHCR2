#include "RHCR2.h"

Position RHCR2::generateRandomPair(int z) {
  std::uniform_int_distribution<> x(z * -1, z), y(z * -1, z);

  return Position { .x = x(gen), .y = y(gen) };
}

int RHCR2::ffrog(Position pos) {
  int x = pos.x, y = pos.y;
}

