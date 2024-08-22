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
root@cb50096b54f74552ae459f3150c4da6d-2377118072:~/holbertonschool-simple_shell# ./hsh
cisfun$ ls
AUTHORS    _memmove.c  _strdup.c   _strtrim.c	      hsh		  man_1_simple_shell	 shell
README.md  _strcmp.c   _strlen.c   execute_command.c  interactive_mode.c  noninteractive_mode.c  shell.h
_getenv.c  _strcspn.c  _strncmp.c  find_path.c	      main.c		  read_command.c	 tokenize_command.c
cisfun$ /bin/ls
AUTHORS    _memmove.c  _strdup.c   _strtrim.c	      hsh		  man_1_simple_shell	 shell
README.md  _strcmp.c   _strlen.c   execute_command.c  interactive_mode.c  noninteractive_mode.c  shell.h
_getenv.c  _strcspn.c  _strncmp.c  find_path.c	      main.c		  read_command.c	 tokenize_command.c
cisfun$ ls -l /tmp
total 0
cisfun$ env
SHELL=/bin/bash
PWD=/root/holbertonschool-simple_shell
LOGNAME=root
MOTD_SHOWN=pam
HOME=/root
LANG=en_US.UTF-8
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.webp=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
SSH_CONNECTION=10.43.196.100 55666 10.42.81.222 22
LESSCLOSE=/usr/bin/lesspipe %s %s
TERM=xterm-256color
LESSOPEN=| /usr/bin/lesspipe %s
USER=root
SHLVL=1
SSH_CLIENT=10.43.196.100 55666 22
DEBUGINFOD_URLS=
LC_ALL=C.UTF-8
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
SSH_TTY=/dev/pts/0
_=./hsh
OLDPWD=/root
cisfun$ exit
root@cb50096b54f74552ae459f3150c4da6d-2377118072:~/holbertonschool-simple_shell# 
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
