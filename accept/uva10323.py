# implement
import sys

def main():
    MAX = 6227020800
    MIN = 10000

    fac = [1]
    while True:
        r = len(fac) * fac[len(fac) - 1]
        if r > MAX:
            break
        fac.append(r)

    for x in map(int, sys.stdin):
        if x >= 0:
            x = abs(x)
            if x >= len(fac):
                print("Overflow!")
            elif fac[x] < MIN:
                print("Underflow!")
            else:
                print(fac[x])
        else: # -1! is positive infinite
            if x & 1 != 0:
                print("Overflow!")
            else:
                print("Underflow!")

if __name__ == "__main__":
    main()
