# c-sandbox

core C and embedded C concepts

## How to Run

1st way
- `brew install cmake` to compile w/ cmake
- then, 
    - `cd ansi-c`,
    - `cmake --build cmake-build-debug --target getInput -- -j 3`, `./cmake-build-debug/getInput`

2nd way
- `brew install gcc` or `xcode-select --install` for compiler
- then, 
    - `cd ansi-c`, 
    - run `gcc src/xxx.c -o xxx && ./xxx`


### Notes

- `ansi-c` can be opened by idea, vscode or clion. It uses `gcc` or `clang` cmd line compilation.
- `embedded-c` is an STM32CubeIDE (eclipse project). So edit with this IDE.