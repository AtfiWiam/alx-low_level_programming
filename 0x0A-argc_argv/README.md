# 0x0A. C - argc, argv

## Arguments to main
> For those writing programs which will run in a hosted environment, arguments to main provide a useful opportunity to give parameters to programs. Typically, this facility is used to direct the way the program goes about its task. It's particularly common to provide file names to a program through its arguments.

### The declaration of main looks like this:
```c
int main(int argc, char *argv[]);
```
### Or like this:
```c
int main(int argc, char **argv);
```

### Files:

1. 0-whatsmyname.c
   - Program that prints its name, followed by a new line.
     - If you rename the program, it will print the new name, without having to compile it again

2. 1-args.c
   - Program that prints the number of arguments passed into it.

3. 2-args.c
   - Program that print all arguments it receives.

4. 3-mul.c
   - Program that print the result of two integer number.

5. 4.add.c
   - Program that adds positive numbers and print the result.

6. 100-change.c
   - Program that prints the minimum number of coins to make change for an amount of money.
     - Usage: ./change cents
     - where cents is the amount of cents you need to give back
