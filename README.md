# Learning ZMQ

### Why ZeroMQ?
- A high performance and brokerless messenging library to pub/sub data across programs.
- Available in multiple programming languages.

### Debian/Ubuntu Requirements
- `apt-get install libczmq-dev`
- gcc, g++ (ver 7.4 on my machine Ubuntu 18.04)

### C 
Compile: `gcc -Wall filename.c -o filename -lzmq`

### C++
- Need header C++ binding for `libzmq`. ([cppzmq](https://github.com/zeromq/cppzmq))
- `libczmq-dev` actually already included `zmq.hpp`
- Compile: `g++ -o filename filename.cpp -lzmq`

### Python
- Need pzmq library: `pip install pyzmq`
- More setting to set https://stackoverflow.com/questions/48278859/how-to-have-limited-zmq-zeromq-pyzmq-queue-buffer-size-in-python

### Reference
- [ZeroMQ - Faruk Akgul](https://www.packtpub.com/networking-and-servers/zeromq)
- [zeromq.org](https://zeromq.org/get-started/)

