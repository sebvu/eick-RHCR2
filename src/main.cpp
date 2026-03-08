#include <RHCR2.h>
#include <iostream>

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

  // the output file will be in RESULTS.md located in your /bin folder in
  // creation of RHCR2 obj um.. no clue if it'll consistently generate the
  // file.. don't have checks for that lol

  RHCR2 *r = new RHCR2(); // please check class definition

  r->rin()
      << "# AUTOMATICALLY GENERATED RHCR2 RESULTS REPORT" << std::endl
      << std::endl
      << "- made by Jester <3" << std::endl
      << std::endl
      << "## Pre-list of experiments:" << std::endl
      << std::endl
      << "These are the main experiments, as per 4368-T2, that will be "
         "ran twice for a total of 32 runs both with **unique seeds 1 "
         "and 2** listed further down in this file.\n\nFor the student-defined "
         "experiments, please refer to the very bottom of this file."
      << std::endl
      << std::endl
      << "- **1:** sp = (-300, -500), z = 12, p = 150" << std::endl
      << "- **2:** sp = (-300, -500), z = 12, p = 400" << std::endl
      << "- **3:** sp = (-300, -500), z = 60, p = 150" << std::endl
      << "- **4:** sp = (-300, -500), z = 60, p = 400" << std::endl
      << "- **5:** sp = (0, 0), z = 12, p = 150" << std::endl
      << "- **6:** sp = (0, 0), z = 12, p = 400" << std::endl
      << "- **7:** sp = (0, 0), z = 60, p = 150" << std::endl
      << "- **8:** sp = (0, 0), z = 60, p = 400" << std::endl
      << "- **9:** sp = (-222, 222), z = 12, p = 150" << std::endl
      << "- **10:** sp = (-222, 222), z = 12, p = 400" << std::endl
      << "- **11:** sp = (-222, 222), z = 60, p = 150" << std::endl
      << "- **12:** sp = (-222, 222), z = 60, p = 400" << std::endl
      << "- **13:** sp = (-510, 400), z = 12, p = 150" << std::endl
      << "- **14:** sp = (-510, 400), z = 12, p = 400" << std::endl
      << "- **15:** sp = (-510, 400), z = 60, p = 150" << std::endl
      << "- **16:** sp = (-510, 400), z = 60, p = 400" << std::endl;

  for (int i = 0; i < 2; i++) {
    if (i == 1) // only reseed for second run to avoid unecessary reseed
      r->reseed();

    r->rin() << std::endl
             << "## SEED " << i + 1 << ": " << r->getSeed() << std::endl;

    r->rin() << std::endl << "### -300, -500 series experiments" << std::endl;
    r->runExperiment(Position{.x = -300, .y = -500}, 12, 150);
    r->runExperiment(Position{.x = -300, .y = -500}, 12, 400);
    r->runExperiment(Position{.x = -300, .y = -500}, 60, 150);
    r->runExperiment(Position{.x = -300, .y = -500}, 60, 400);

    r->rin() << std::endl << "### 0, 0 series experiments" << std::endl;
    r->runExperiment(Position{.x = 0, .y = 0}, 12, 150);
    r->runExperiment(Position{.x = 0, .y = 0}, 12, 400);
    r->runExperiment(Position{.x = 0, .y = 0}, 60, 150);
    r->runExperiment(Position{.x = 0, .y = 0}, 60, 400);

    r->rin() << std::endl << "### -222, 222 series experiments" << std::endl;
    r->runExperiment(Position{.x = -222, .y = 222}, 12, 150);
    r->runExperiment(Position{.x = -222, .y = 222}, 12, 400);
    r->runExperiment(Position{.x = -222, .y = 222}, 60, 150);
    r->runExperiment(Position{.x = -222, .y = 222}, 60, 400);

    r->rin() << std::endl << "### -510, 400 series experiments" << std::endl;
    r->runExperiment(Position{.x = -510, .y = 400}, 12, 150);
    r->runExperiment(Position{.x = -510, .y = 400}, 12, 400);
    r->runExperiment(Position{.x = -510, .y = 400}, 60, 150);
    r->runExperiment(Position{.x = -510, .y = 400}, 60, 400);
  }

  r->rin() << std::endl << "## My Experiment Sets" << std::endl;
  r->runExperiment(Position{.x = 0, .y = 0}, 50, 800);
  r->runExperiment(Position{.x = -510, .y = 400}, 20, 700);
}
