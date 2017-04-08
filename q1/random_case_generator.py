import sys
from random import randint

n = int(sys.argv[1])
print n
while n > 0:
    n -= 1
    print randint(1, 10**9),
print
