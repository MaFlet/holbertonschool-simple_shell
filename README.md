![Chutima Puthachon](https://github.com/user-attachments/assets/374c63d6-d591-44ee-b319-15219d4de2ff)

### :pencil2: Description
In this project, we will build a functional Unix shell from scratch, which will mimic some of the behaviors of a standard shell like bash or sh. The shell will be capable of reading user input, parsing commands, executing them, and managing any errors that occur. **The primary objective of this group project** is to collaboratively design and implement a simple Unix shell in C. This shell will be capable of interpreting and executing basic commands, managing built-in functions, handling errors, and working with the Unix PATH environment. Through this project, you will gain a deeper understanding of process control, file I/O, string manipulation, and memory management, all crucial concepts in Unix systems programming

### ✅ Requirement for the project
```Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
Your shell should not have any memory leaks
No more than 5 functions per file
All your header files should be include guarded
Use system calls only when you need to
```
### ✅ List of allowed functions and system calls
```all functions from string.h
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
printf (man 3 printf)
fprintf (man 3 fprintf)
vfprintf (man 3 vfprintf)
sprintf (man 3 sprintf)
putchar (man 3 putchar)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)
```

### :black_square_button: Usage

```
* ls	list files in current directory
* pwd   print working directory
* env	print the environment variables
* printenv	print the environment variables
* exit	terminate the program
```

### :eyeglasses: Testing
Your shell should work like this in interactive mode:
```
julien@ubuntu:/# ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
julien@ubuntu:/#
```
But also in non-interactive mode:
```
julien@ubuntu:/# echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
julien@ubuntu:/# cat test_ls_2
/bin/ls
/bin/ls
julien@ubuntu:/# cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
julien@ubuntu:/#
```

### :open_file_folder: File description
	1.	_getenv.c: Contains the implementation for retrieving environment variables.
	2.	_memmove.c: Implements a custom memory move function.
	3.	_strcspn.c: Provides the implementation for a string span function, which searches a string for the first occurrence of any character from a specified set.
	4.	_strcmp.c: Implements string comparison functionality.
	5.	_strdup.c: Provides an implementation for duplicating strings.
	6.	_strlen.c: Contains the implementation for calculating the length of a string.
	7.	_strncmp.c: Implements a function to compare a specified number of characters between two strings.
	8.	_strtrim.c: Provides a function for trimming leading and trailing whitespace from a string.
	9.	execute_command.c: Handles the execution of commands, including process creation and management.
	10.	find_path.c: Implements functionality for locating the correct path of executable files based on the PATH environment variable.
	11.	interactive_mode.c: Manages the shell behavior in interactive mode, where it reads and executes user commands in real-time.
	12.	main.c: The entry point of the shell program.
	13.	noninteractive_mode.c: Handles the shell behavior in non-interactive mode, such as when commands are piped or redirected to the shell.
	14.	read_command.c: Contains the implementation for reading user input and preparing it for execution.
	15.	tokenize_command.c: Implements the functionality for parsing and tokenizing commands into their constituent parts.
	16.	shell.h: The header file containing function prototypes, macro definitions, and global variables used across the shell program.

### :computer: Installation

1. Clone the repository to your local machine:

```
git clone https://github.com/MaFlet/holbertonschool-simple_shell.git
```

2. Navigate into the project directory:
```
cd holbertonschool-simple_shell
```
3. Compile the program:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```


### :pushpin: Examples

### Run the shell in interactive mode
```
./hsh
```
### Run the shell in non-interactive mode with a command
```
echo "/bin/ls" | ./hsh
```
### :crown: Authors

* Mary Fletcher
* Xi Qern Egan Leong
* Chutima Puthachon
