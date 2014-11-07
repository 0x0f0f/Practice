import string
def search(s, sub):
    flag = True
    cnt = 0
    index = -1
    while(flag):
        index = string.find(s, sub, index +1)
        if index == -1:
            break
        cnt = cnt + 1
    return cnt

if __name__ == '__main__':
    s = raw_input()
    sub = raw_input()
    print search(s, sub)
