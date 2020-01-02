#! /usr/bin/env python3

import zmq

def main():
    ctx = zmq.Context()
    s = ctx.socket(zmq.SUB)
    s.connect("tcp://localhost:4040")
    s.setsockopt(zmq.SUBSCRIBE,'')


    for i in range(5):
        string = s.recv()
        print (string)

if __name__ == '__main__':
    main()
