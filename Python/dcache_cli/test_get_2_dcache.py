#!/usr/bin/env python
# -*- coding:utf-8 -*-

from random import Random

from pydcache import pydcache


def func_get(args):
    return args[0](args[1])


def func_set(args):
    return args[0](args[1], args[2])


def func_del(args):
    return args[0](args[1])

def produce_random_string(size):
    str = ''
    chars = '!@#$%^&*()~"AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0123456789'
    length = len(chars) - 1
    random = Random()
    for i in range(size):
        str+=chars[random.randint(0, length)]
    return str


if __name__ == '__main__':
    conf = {'cache_url': 'http://10.13.37.52:8080', 'cache_app': 'testconcurrent_app'}
    pydcache = pydcache(conf)
    # pool = Pool(200)

    # get_req = [(pydcache.get, keys+str(i)) for i in xrange(1, 500000)]
    # pprint(pool.map(func_get, get_req))
    for i in xrange(1, 500000):
        pydcache.get('keys'+str(i))

