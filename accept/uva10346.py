# implement
import sys

def solve(n, k):
    if n < k:
        return n
    t = n // k
    return t * k + solve(n % k + t, k)

def main():
    for n, k in map(lambda s: list(map(int, s.split())), sys.stdin):
        print(solve(n, k))

if __name__ == '__main__':
    main()
