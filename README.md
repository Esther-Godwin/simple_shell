//This is an ALX team project
// To create a simple shell that implements commands/ function
List of allowed functions and system calls for this project includes;
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
The Tasks includes;
1 - Write a beautiful code that passes the Betty checks
2 - Write a UNIX command line interpreter.
3 - Handle command lines with arguments
4 - Handle the PATH
fork must not be called if the command doesn’t exist
5 - Implement the exit built-in, that exits the shell
6 - Implement the env built-in, that prints the current environment
7 - Write your own getline function
Use a buffer to read many chars at once and call the least possible the read system call
You will need to use static variables
You are not allowed to use getline
8 - Implement the setenv and unsetenv builtin commands
9 - Implement the builtin command cd
10 - Handle the commands separator
11 - Handle the && and || shell logical operators
12 - Implement the alias builtin command
13 - Implement the alias builtin command
14 - Handle comments (#) 
