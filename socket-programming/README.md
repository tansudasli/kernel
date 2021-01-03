# socket-programming

core socket programming in C

- `/tcp` - IP and Port based network socketing 
- `/internal` - Domain based socketing (Internal, linux file based)
- `/http` - Http based socketing

## How to Run

`git clone ...`,

- `brew install gcc` or `xcode-select --install` for compiler
- `brew install cmake` to compile w/ cmake
- then,
    - `cd socket-programming`,
    - `cmake --build cmake-build-debug --target all -- -j 3`, and 
    - Run w/ `./cmake-build-debug/tcp_client` and `./cmake-build-debug/tcp_server`
  