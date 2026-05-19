# Simple Shell (hsh)

## Description
This is a simple UNIX command interpreter written in C. It reads commands from the standard input, parses them, and executes them.

## Compilation
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Usage
Interactive Mode:
$ ./hsh
($) ls

Non-Interactive Mode:
$ echo "ls" | ./hsh

## Built-in Commands
* env: Prints the current environment variables.
* exit: Exits the shell safely.

## Authors
* Shatha Fayadh Alanzi
* Alzahraa Alhussain 
