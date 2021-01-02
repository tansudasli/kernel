# socket-programming

core socket programming in C

## How to Run

`git clone ...`,

- `brew install gcc` or `xcode-select --install` for compiler
- `brew install cmake` to compile w/ cmake
- then,
    - `cd socket-programming`,
    - `cmake --build cmake-build-debug --target all -- -j 3`, and 
    - Run w/ `./cmake-build-debug/tcp_client` and `./cmake-build-debug/tcp_server`