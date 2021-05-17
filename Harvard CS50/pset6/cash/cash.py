from cs50 import get_float
from math import floor


def main():
    while True:
        s = get_float("Change owed: ")
        m = int(round(s * 100))

        if m > 0:
            break

    q = m // 25
    d = (m % 25) // 10
    n = ((m % 25) % 10) // 5
    p = ((m % 25) % 10) % 5

    print(f"{q + d + n + p}")


if __name__ == "__main__":
    main()