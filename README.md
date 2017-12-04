Structure
  
  Driver:
  
  driver.c driver.h

  String:
  
  string.c string.h

  Helpers:

  helperc. helpers.h

  t1:

  test file

  t2:

  test file
  
    
````
NOTE: The rest of the files such as .idea or CMakeLists.txt are files that CLion uses to compile my project.
They are not neeeded at all.
````

All of the parts of the shell are included in Driver with the exception of the tokenizing part of the assignment
which is included in String

NOTE: Helpers is used for fast failing memory alloc and realloc, and some macros that I rarely used. 
Idea borrowed from Binkley, however I did not copy paste his code. All I had was an .o .h file from last year.

• Compile

````
make clean && make
````

• Run

````
./shell [arg1,arg2...]
````
````
./shell
````

• How it works

In the initial stages of the development everything was centered around proper tokenizing and running functions 
such as echo() and cat() (not needed for the final shell).

Before reaching the mini shell part our program had to create a child process with a specified program using the tokenized args.
The function responsible for creating child processes is called sys_proc().

The final product, the mini shell, starts in main with or without pre-supplied arguments. run_shell() is executed which then decides 
to run the pre-supplied arguments or start the shell normally. 

It all begins with a infinite while loop only breakable by EOF or exit command. run_shell() calls parse_cmd() which waits for user input. User input 
is then obtained char by char. There is logic to detect EOF and ENTER. After the user input is obtained and formatted into a char array it is then passed to string_tokenize() 
which then returns an array of strings. The array of strings along with the number of strings is then passed to run_proc() which is 
an old function from the part 1 and 2 era. It is used still to do some pre-sys_proc() actions such as redirect and pipe detection.

The program reaches sys_proc(). The function takes 2 arguments. One being an array of commands
and the other specifying how many commands there are. These 2 arguments are passed down all the way from string_tokenize() 
or the real argv in case the user supplied arguments when it first ran the shell.

sys_proc() then forks to create a child process which runs the commands specified by the user. In case there is redirection a change of stdout
is made using dup2() function in the child process. Some arg sanitation is done before that to ensure that we select the right output file and
the right arguments are passed to execvp() which then replaces the program in the process with a new one specified by the user. The parent process
waits patiently for the child to finish and when redirection of output is finished the shell continues running in the neverending while loop.
Closing the file descriptors proved in the child *not* parent proved to be a critical point.

The same idea applies to piping except that it was more complex. Instead of 1 fork, 2 are needed. The reason for that I found to be that
the parent cannot run the first program specified in the args and then pipe the output to another child process. Instead, 2 child processes
are forked. Some arg sanitation determines which program runs where depending on what side of the pipe it is. The commands on the left
specify the input program which has to change stdout to be the input program on the right side of the pipe. The function pipe() is called 
ahead of time to create a "data transport utility array layer". Indexes in the array specify the stdout with 0 and stdin with 1. 

Using the elements in the "data transport utility array layer" the shell opens the appropriate "files" in order to send the data from input program
to output program. This is done with dup2(). The output of the input program has to change to output program. The input of the output program
has to change to the input program as well.

After these steps are done execvp is called in each child to run the designated programs on both sides of the pipe.

In the end the parent process has to close everything in the "data transport utility array layer" and then wait for children to finish their jobs.

The while loop runs again and waits for user input. Forever.
