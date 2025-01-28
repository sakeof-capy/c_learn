int arr[10]

arr
Address of the first element

*arr
Value of the first element

arr[5] is value of the fifth element (the gay mode, the same ass *(arr+5))
arr + 5 is address of the fifth element
*(arr + 5) is value of the fifth element (chad mode, the same ass arr[5])

When static array is created, it is treated as array with a pointer to its first element.
Meaning sizeof(arr) / sizeof(arr[0]) returns its actual size.
But when the array is passed to a function, it loses its "array" component,
and starts behaving as a regular pointer.
Meaning sizeof(arr) / sizeof(arr[0]) starts returning 
(size of pointer) / sizeof(arr[0]) = 8 / sizeof(arr[0]) 
(for 64-bit)