import sys


def factorial(number):
    if number == 1:
        return 1
    else:
        return number * factorial(number - 1)


def main():
    number = int(sys.argv[1])
    print("Factorial of {} is {}.".format(number, factorial(number)))


if __name__ == '__main__':
    main()
