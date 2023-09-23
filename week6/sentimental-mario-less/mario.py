from cs50 import get_int


def main():
    n = get_height()
    print_pyramid(n)


def get_height():
    while True:
        try:
            n = get_int("Height: ")
            if 1 <= n and n <= 8:
                return n
            else:
                print("Height must be between 1 and 8.")
        except ValueError:
            print("Invalid input. Please enter a number between 1 and 8.")


def print_pyramid(n):
    for i in range(n):
        for j in range(n - i - 1):
            print(" ", end="")
        for k in range(i + 1):
            print("#", end="")
        print()


main()
