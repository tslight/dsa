from argparse import ArgumentParser
import sys
import timeit


def get_args():
    parser = ArgumentParser(
        description='Search for an item in a list. ' +
        'Defaults to a sorted list of 10 million elements ' +
        'and searches for the last element.'
    )
    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument('-b', '--binary', action='store_true',
                       help="Use binary search.")
    group.add_argument('-r', '--recursive', action='store_true',
                       help="Use recursive binary search.")
    group.add_argument('-s', '--simple', action='store_true',
                       help="Use simple search.")
    parser.add_argument("-m", "--max", type=int, default='10_000_000',
                        help="Max number in range.")
    parser.add_argument("-i", "--increment", type=int, default=1,
                        help="Number to increment each element in list by.")
    parser.add_argument("-n", "--number", type=int, default=None,
                        help="Number to search for in list.")
    return parser.parse_args()


def simple(mylist, item):
    count = 0
    for e in mylist:
        count += 1
        if e == item:
            return (True, count)
    return (False, count)


def binary(mylist, item):
    low = 0
    count = 0
    high = len(mylist) - 1

    while low <= high:
        mid = int((low + high) / 2)
        guess = mylist[mid]
        count += 1
        if guess == item:
            return (True, count)
        elif guess > item:
            high = mid - 1
        else:
            low = mid + 1
    return (False, count)


def recursive_binary(arr, element, count):
    count += 1
    low = 0
    high = len(arr) - 1
    mid = int((low + high) / 2)
    if element == arr[mid]:
        return (True, count)
    elif high == 0:
        return (False, count)
    elif element > arr[mid]:
        return recursive_binary(arr[mid + 1:], element, count)
    elif element < arr[mid]:
        return recursive_binary(arr[:mid - 1], element, count)


def search():
    args = get_args()
    if args.number is None:
        args.number = args.max - 1
    mylist = list(range(0, args.max, args.increment))

    if args.binary:
        found, count = binary(mylist, args.number)
        search_type = "Binary"
    elif args.recursive:
        found, count = recursive_binary(mylist, args.number, 0)
        search_type = "Recursive Binary"
    else:
        found, count = simple(mylist, args.number)
        search_type = "Simple"

    print(
        "\nType: {} Search\n".format(search_type) +
        "Found: {}\n".format(str(found)) +
        "Number: {:,}\n".format(args.number) +
        "Length: {:,}\n".format(len(mylist)) +
        "Steps: {:,}".format(count)
    )


def main():
    speed = timeit.timeit(
        "search()", setup="from __main__ import search", number=1
    )
    print("Time: {} seconds\n".format(round(speed, 8)))


if __name__ == '__main__':
    main()
