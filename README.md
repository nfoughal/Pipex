# Pipex

Pipex is a 42 Network project that replicates the Unix shell's piping behavior using C and system calls like `fork`, `execve`, `pipe`, and `dup2`.

## 🧠 Project Goals

- Understand how Unix pipelines work under the hood
- Use low-level system calls to execute commands
- Manage multiple processes and file descriptors properly

## 🔧 How It Works

Pipex mimics the behavior of shell piping:
```bash
< infile cmd1 | cmd2 > outfile
```

Usage example:
```bash
./pipex infile "ls -l" "wc -l" outfile
```

This runs `ls -l` with input from `infile`, pipes its output to `wc -l`, and writes the final result to `outfile`.


## 📁 Project Structure

- `pipex.c`: Entry point and core logic
- `pipex_utils.c`: Helper functions
- `exec.c`: Handles command execution
- `error.c`: Error handling

## 🛠️ Requirements

- GCC
- Unix/Linux system
- Make

## 🧪 Testing

To compile and test:
```bash
make
./pipex infile "grep a" "wc -l" outfile
```

Check the content of `outfile` to see the result.

## 📚 Learning Outcomes

- Deeper understanding of Unix processes and piping
- Improved skills in working with file descriptors
- Introduction to system-level programming in C

## 👨‍💻 Author

**Nabil Foughali**  
[GitHub Profile](https://github.com/nfoughal)

---

> Developed as part of the 42 Network at 1337 Khouribga
