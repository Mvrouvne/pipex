# pipex

## Overview

The **pipex** project involves recreating the behavior of Unix shell pipelines by connecting the output of one command to the input of another using a pipe.

## Features

- **Inter-process communication**: Implements pipes to transfer data between processes.
- **File redirection**: Reads input from a file and writes the final output to another file using redirections.
- **Command execution**: Uses the `execve` system call to execute commands.
- **Error handling**: Manages invalid commands, file access issues, and pipe creation errors.

### Example

This program replicates the shell behavior of the following command:

```bash
< infile cmd1 | cmd2 > outfile
