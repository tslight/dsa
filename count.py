from random import randint
from sys import argv
from columns import prtcols


def count(mylist):
    if mylist == []:
        return 0
    else:
        return 1 + count(mylist[1:])


def main():
    try:
        size = int(argv[1])
    except ValueError:
        print("Invalid argument. Enter an integer.")
        exit(1)

    mylist = [randint(1, (size * 100)) for i in range(0, size)]
    print("Number of elements: {}".format(len(mylist)))
    number = count(mylist)
    prtcols(mylist)
    print("Number of elements: {}".format(number))


if __name__ == '__main__':
    main()
