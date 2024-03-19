# PIPEX

PIPEX is a project that involves handling pipes in Unix-like operating systems. The goal of this project is to create a program that replicates the behavior of a specific shell command, allowing users to redirect input/output and chain commands together using pipes.

## Description 

PIPEX takes two input files and two shell commands as arguments. It then creates a pipeline between the commands, redirecting the input from the first file and outputting the result to the second file. The program behaves similarly to the shell command "< file1 cmd1 | cmd2 > file2".

# Features

Handles pipes: PIPEX creates a pipeline between two commands, allowing the output of the first command to serve as input to the second command.
Supports input/output redirection: The program takes input from the first file and writes the output to the second file.
Error handling: PIPEX thoroughly handles errors and ensures that the program does not quit unexpectedly. It follows the same error handling principles as the shell command it emulates.
Memory management: The program ensures that there are no memory leaks, managing memory allocation and deallocation efficiently.
Bonus features:
 - Multiple pipes: Supports multiple pipes, allowing users to chain multiple commands together.
 - Here documents (<< and >>): Supports here documents when the first parameter is "here_doc", allowing users to append output to a file.

# Usage

To use PIPEX, run the following command in the terminal:

```
make
```

This will compile the program and create an executable file called "pipex". You can then run the program using the following syntax:

```

./pipex file1 cmd1 cmd2 file2

```

Replace "file1" with the input file, "cmd1" with the first shell command, "cmd2" with the second shell command, and "file2" with the output file. For example:

```

./pipex infile "ls -l" "wc -l" outfile

```

This will create a pipeline between the "ls -l" and "wc -l" commands, redirecting the input from "infile" and writing the output to "outfile".

- file1: Input file name.
- cmd1: First shell command with parameters.
- cmd2: Second shell command with parameters.
- file2: Output file name.

# Requirements

- Makefile: Provided Makefile should compile the source files without relinking.
- Error handling: Thorough error handling should be implemented to prevent unexpected program termination.
- Memory management: The program must be free of memory leaks.
- Functionality: The program should replicate the behavior of the shell command < file1 cmd1 | cmd2 > file2.

# Bonus Features

- Multiple pipes: The program should support multiple pipes, allowing users to chain multiple commands together.
- Here documents (<< and >>): The program should support here documents when the first parameter is "here_doc", allowing users to append output to a file.


## Additional Requirements

- Support multiple pipes:
  - The program should support multiple pipes, allowing users to chain multiple commands together.
  - For example, the following command should be supported: "cmd1 | cmd2 | cmd3".
- Here documents (<< and >>):
  - The program should support here documents when the first parameter is "here_doc".
  - For example, the following command should be supported: "here_doc LIMITER cmd1 | cmd2 >> file".
- Error handling:
  - The program should thoroughly handle errors and ensure that it does not quit unexpectedly.
  - It should follow the same error handling principles as the shell command it emulates.
- Memory management:
  - The program should ensure that there are no memory leaks, managing memory allocation and deallocation efficiently.

# Usage

To use PIPEX, run the following command in the terminal:

```
make
```

This will compile the program and create an executable file called "pipex". You can then run the program using the following syntax:

```

./pipex file1 cmd1 cmd2 file2

```

Replace "file1" with the input file, "cmd1" with the first shell command, "cmd2" with the second shell command, and "file2" with the output file. For example:

```

./pipex infile "ls -l" "wc -l" outfile

```

This will create a pipeline between the "ls -l" and "wc -l" commands, redirecting the input from "infile" and writing the output to "outfile".

- file1: Input file name.
- cmd1: First shell command with parameters.
- cmd2: Second shell command with parameters.
- file2: Output file name.

# Acknowledgments
- Inspired by the concept of input/output redirection and command execution using pipes in Unix-like systems.
