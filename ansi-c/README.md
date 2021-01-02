# ansi-c

core C concepts 

## How to Run

`git clone ...`, then `cd ansi-c`

- `brew install gcc` or `xcode-select --install` for compiler
- `brew install cmake` to compile w/ cmake
- then,
    - `cd ansi-c`,
    - `cmake --build cmake-build-debug --target all -- -j 3`, and Run w/ `./cmake-build-debug/getInput`

if you want, you can run w/ `gcc src/xxx.c -o xxx && ./xxx`.
