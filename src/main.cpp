#include <RHCR2.h>
#include <iostream>
#include <fstream>

int main() {
  /*
  the following experiment demands the following combination of params
  where x,y ∈ [-512, 512].

  seed1 will be reported for first 16 iterations experiments,
  that same 16 will be reported with seed2

  the last two experiments are my choice

  (16 total combinations)
  sp = (-300,-500), (0,0),(-222,-222), (-510,400)
  p = 150 and 400; z = 12 and 60
  */


  // the output file for results
  RHCR2 *r = new RHCR2(); // please check class definition

  r->rin() << "hi";

}
