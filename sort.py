from argparse import ArgumentParser
from random import randint
from timeit import timeit
from columns import prtcols


def get_args():
    parser = ArgumentParser(
        description='Sort a list using a variety of algorithms. ' +
        'Defaults to creating a list of 10 thousand elements, randomly, ' +
        'from a pool of integers between 0 and 1 million and sorting them ' +
        'with a custom quick sort algorithm.'
    )

    group = parser.add_mutually_exclusive_group(required=True)
    group.add_argument('-b', '--bubble', action='store_true',
                       help="Use bubble sort.")
    group.add_argument('-i', '--insertion', action='store_true',
                       help="Use insertion sort.")
    group.add_argument('-m', '--merge', action='store_true',
                       help="Use merge sort.")
    group.add_argument('-p', '--python', action='store_true',
                       help="Use Python's built in sort.")
    group.add_argument('-q', '--quick', action='store_true',
                       help="Use quick sort.")
    group.add_argument('-s', '--selection', action='store_true',
                       help="Use selection sort.")

    parser.add_argument("-c", "--custom", nargs='+', type=int,
                        help="Enter a custom array.")
    parser.add_argument("-M", "--max", type=int, default='1_000_000',
                        help="Maximum number in list.")
    parser.add_argument("-S", "--size", type=int, default='10_000',
                        help="Size of list.")
    parser.add_argument('-v', '--verbose', action='store_true',
                        help="Print sorted list.")

    return parser.parse_args()


def merge(arr):
    pass


def insertion(arr):
    for i in range(1, len(arr)):
        e = arr[i]  # marker for current element whilst traversing previous.
        j = i - 1   # marker for index of previous element
        # move current element back to beginning of list if it's smaller than
        # previous, by swapping it with the previous element until we are back
        # at the beginning of the list.
        while j >= 0 and e < arr[j]:
            arr[j + 1], arr[j] = arr[j], e
            j -= 1  # decrement marker to reverse traverse list
    return arr


def bubble(arr):
    for i in range(len(arr)):
        swapped = False
        for j in range(len(arr) - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break

    return arr


def quick(arr):
    if len(arr) < 2:
        return arr
    else:
        index = int(len(arr) / 2)  # mid point is faster than random element
        # index = randint(0, len(arr) - 1)  # slower than mid point of array
        pivot = arr[index]  # pivot less list!
        pivotlest = arr[:index] + arr[index + 1:]
        less = [i for i in pivotlest if i <= pivot]
        greater = [i for i in pivotlest if i > pivot]
        return quick(less) + [pivot] + quick(greater)


def find_smallest(arr):
    smallest = arr[0]
    smallest_index = 0
    for i in range(1, len(arr)):
        if arr[i] < smallest:
            smallest = arr[i]
            smallest_index = i
    return smallest_index


def selection(arr):
    new_arr = []
    for i in range(len(arr)):
        smallest = find_smallest(arr)
        new_arr.append(arr.pop(smallest))
    return new_arr


def mysort():
    args = get_args()

    if args.custom:
        arr = args.custom
    else:
        arr = [randint(0, args.max) for i in range(0, args.size)]
        arr = sorted(arr, reverse=True)  # make as hard as possible..

    # make a copy as some of the sorting functions mutate the list.
    original_arr = list(arr)

    do_sort = {
        'bubble': bubble,
        'insertion': insertion,
        'merge': merge,
        'python': sorted,
        'quick': quick,
        'selection': selection,
    }
    arg_dict = vars(args)
    sort_type = [key for key, value in arg_dict.items()
                 if key in do_sort and value][0]
    sorted_arr = do_sort[sort_type](arr)

    if args.verbose:
        print("\nOriginal array:\n")
        prtcols(original_arr, 42)
        print("\nSorted array:\n")
        prtcols(sorted_arr, 42)

    print(
        "\nType: {} Sort".format(sort_type.capitalize()) +
        "\nLength: {:,}".format(len(original_arr))
    )


def customsort(arr):
    freq = {}
    for i in arr:
        if i in freq:
            freq[i] += 1
        else:
            freq[i] = 1


def main():
    speed = timeit(
        "mysort()", setup="from __main__ import mysort", number=1
    )
    print("Time: {} seconds\n".format(round(speed, 8)))


if __name__ == '__main__':
    main()
