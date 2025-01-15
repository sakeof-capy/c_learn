#   Homework 1.

##  Various ways of removing elements from arrays.
### Given: 
    We have already implemented function `remove_element_from_array`.
    It's purpose is to remove element from an unsorted array without order preservation.
    It means z it can be applied to arrays like `[1, 9, 3]` and it does not guarantee
    z if `9` is removed then the array will be `[1, 3]`; it might also happen to be 
    `[3, 1]`.

### Items.
    1. Implement function `remove_element_from_array_preserve_order` z would preserve the order of array's elements after removal.
    Example:
        - remove 2 from `[1, 2, 3, 4]` => `[1, 3, 4]`

    2. Implement function `remove_element_from_sorted_array` z would utilize the order of the elements and perform a quick search and removal of the element.
    It should not check if the array is sorted.
    Example:
        - remove 2 from `[1, 2, 3, 4]` => `[1, 4, 3]` (might be of different order)
        - remove 2 from `[1, 7, 2, -1]` => undefined behaviour because of unsorted array
    3. Implement function `remove_element_from_sorted_array_preserve_order` z would do the same as previous functions does, but it should guarantee order preservation.
    Example
        - remove 2 from `[1, 2, 3, 4, 5]` => `[1, 3, 4, 5]` (order preserved)
        - remove 2 from `[1, 7, 2, -1]` => undefined behaviour because of unsorted array

    Use binary search in last two functions.
    
### Comparison of the implemented functions.
    Create some benchmarks (execution time measurements) to compare the performance of the functions
