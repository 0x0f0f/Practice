#!/usr/bin/env python

from __future__ import division

def average(scores):
    return sum(scores) / len(scores)

def query(database, q):
    return average(database[q])


if __name__ == "__main__":
    n = raw_input()
    database = {}
    for i in xrange(int(n)):
        input = raw_input()
        input = input.split(" ")
        database[input[0]] = [float(input[1]), float(input[2]), float(input[3]) ]
    q = raw_input()
    print "%.02f" % query(database, q) 
