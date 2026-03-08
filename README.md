Eick Assignment 2: Randomized Hill Climbing w/Resampling

## Instructions

This project uses Makefile. 

**ALWAYS** look at files you plan on running on your machine. Seriously. I could brick your computer!! Grr

```sh
git clone git@github.com:sebvu/eick-RHCR2.git (or https, doesn't matter)
cd ./eick-RHCR2.git
make
cd ./bin
./exec-main
```

If done correctly, a RESULTS.md will appear in `./bin` after executing `./exec-main`. Not the most beautiful format in the world, but it works.

## Extra

If you plan to look at the code, and are using clangd LSP or some other LSP that's heuristics rely on a compile_commands.json, use `bear` and run the following command.

```sh
bear -- make
```

