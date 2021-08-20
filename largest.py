from random import randint
from sys import argv
from columns import prtcols


def get_largest(mylist):
    if len(mylist) == 2:
        return mylist[0] if mylist[0] > mylist[1] else mylist[1]
    rest = get_largest(mylist[1:])
    return mylist[0] if mylist[0] > rest else rest


def main():
    try:
        size = int(argv[1])
    except ValueError:
        print("Invalid argument. Enter an integer.")
        exit(1)

    mylist = [randint(1, (size * 100)) for i in range(0, size)]
    print("Number of elements: {}".format(len(mylist)))
    mylist = sorted(mylist, reverse=True)
    largest = get_largest(mylist)
    prtcols(sorted(mylist))
    print("Largest element: {}".format(largest))


if __name__ == '__main__':
    main()
