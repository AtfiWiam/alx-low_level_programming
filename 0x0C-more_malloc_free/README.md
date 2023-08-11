# 0x0C. C - More malloc, free

### Files:

1. 0-malloc_checked.c
   - Function that allocates memory using malloc.
     - Returns a pointer to the allocated memory
     - if malloc fails, the malloc_checked function should cause normal process termination with a status value of 98.

2. 1-string_nconcat.c
   - Function that concatenates two strings.
     - The returned pointer shall point to a newly allocated space in memory, which contains s1, followed by the first n bytes of s2, and null terminated.
     - If n is greater or equal to the length of s2 then use the entire string s2.

3. 2-calloc.c
   - Function that allocates memory for an array, using malloc.
     - The _calloc function allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory.
     - If nmemb or size is 0, then _calloc returns NULL.
     - If malloc fails, then _calloc returns NULL.
     - The memory is set to zero.

4. 3-array_range.c
   - Function that creates an array of integers.
     - The array created should contain all the values from min (included) to max (included), ordered from min to max.
     - Return: the pointer to the newly created array.
     - If min > max, return NULL.
     - If malloc fails, return NULL.

5. 100-realloc.c
   - Function that reallocates a memory block using malloc and free.
     - where ptr is a pointer to the memory previously allocated with a call to malloc: malloc(old_size).
     - old_size is the size, in bytes, of the allocated space for ptr.
     - and new_size is the new size, in bytes of the new memory block.
     - The contents will be copied to the newly allocated space, in the range from the start of ptr up to the minimum of the old and new sizes.
     - If new_size > old_size, the “added” memory should not be initialized.
     - If new_size == old_size do not do anything and return ptr.
     - If ptr is NULL, then the call is equivalent to malloc(new_size), for all values of old_size and new_size.
     - If new_size is equal to zero, and ptr is not NULL, then the call is equivalent to free(ptr). Return NULL.

6. 101-mul.c
   - Program that multiplies two positive numbers.

