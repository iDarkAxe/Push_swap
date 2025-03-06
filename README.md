# Push_swap #

Push_Swap is a sorting algorithm that uses two stacks, to sort one. 
It has multiple instructions, that cannot be modified so all algorithms uses the sames.
It works pretty well for 500+ numbers. You can try [Complexity, a Push_Swap tester](https://github.com/SimonCROS/push_swap_tester) for optimal testing.

For array of numbers less than 10, it's using a simple algorithm that search lowest numbers and stores them until there is only 4 numbers. It tidies them and pushes back the number from the second stack in the first. TADAA it WORKS.

For larger arrays, it uses a tweaked Radix Algorithm to work with negatives. It's not the fastest, not the prettiest but it's perfect for repetitive tasks as it performs each time exactly the same. The number of instructions is always the same for a fixed number of elements.

## Usage ##
The array of numbers can be both positive and negative numbers, up to MAX INT and MIN INT of your device (tested from a range of -2147483648 up to 2147483647).
The input should be perfect as any error of typing should be rejected.

"12 54 6 879 -9812 03123 -23545" is valid.

"4189 897- 15-46 notAnumber 47889" is invalid.

It should contain no letters, no special characters or anything that is not a number OR minus and plus character (+ and - is OK).

### Push_Swap ###
You can use $ARG or type directly your stack.
If you want to store the result, you can use
```sh
./push_swap $ARG
```
``$ARG`` can be a string or an array of string
```sh
ARG="1 2 4 3"
```
or 
```sh
ARG=""1" "2" "4" "3""
```
### Checker ###
The checker is used to determine if the result of Push_swap is True or False.
As the checker uses the same functions of push_swap, it's pretty impossible to find a flaw in one and not in the other.
Notes : this checker is performing faster as the one given in the exercise !
Checker needs the same $ARG as Push_Swap but needs a list of instructions in stdin.
```sh
./checker $ARG < PUSH_SWAP_RESULT
```
You can also use a pipe :
```sh
./push_swap $ARG | ./checker $ARG
```
## Compilation ##

Compiled on WSL Kali on Windows 10 but should work with your own compiler.
Use ``make`` for compiling push_swap
```sh
make
```
Use ``make checker`` for compiling checker
```sh
make checker
```

0 leak, 0 bug found at this moment.
