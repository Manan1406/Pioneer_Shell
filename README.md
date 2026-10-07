# Pioneer Shell (pish)

A high-performance Unix shell implementation in C featuring process management, built-in command execution, and persistent command history tracking.

## Project Overview

Pioneer Shell is a fully functional command-line interpreter that demonstrates core systems programming concepts including process management (fork/exec/waitpid), interactive and batch mode operation, persistent file I/O, and robust error handling. Built for UC San Diego's CSE 29: Systems Programming and Software Tools course.

**Status:** Production-ready | **Language:** C | **Lines of Code:** 200+ | **Test Coverage:** Manual + Integration

## Key Features

1. **Dual-Mode Operation**
   - Interactive mode: Real-time command execution with user prompts
   - Batch mode: Execute commands from a script file

2. **Process Management**
   - Fork/exec/waitpid system calls for subprocess execution
   - Signal handling and process control
   - Support for foreground and background processes

3. **Built-in Commands**
   - `cd` - Change working directory
   - `exit` - Terminate shell
   - `history` - Display command history
   - External command execution via PATH resolution

4. **Persistent History**
   - Automatic history logging to `.pish_history` file
   - History preservation across sessions
   - Command recall and execution

5. **Robust Error Handling**
   - Comprehensive error messages
   - Graceful failure recovery
   - Input validation and sanitization

## Technical Implementation

### Architecture
- **Main Shell Loop:** Prompt-read-execute cycle with signal handling
- **Command Parsing:** Tokenization and argument extraction
- **Process Execution:** Fork-exec pattern with proper parent-child communication
- **History Management:** File-based persistent storage with in-memory caching

### System Calls Used
- `fork()` - Process creation
- `execvp()` - Program execution
- `waitpid()` - Process synchronization
- `open()`, `read()`, `write()` - File I/O for history
- `signal()`, `sigaction()` - Signal handling

## Getting Started

### Prerequisites
- GCC compiler or compatible C compiler
- Unix/Linux operating system (macOS compatible)
- Standard C library (libc)

### Compilation
```bash
gcc -o pish pioneer_shell.c
```

### Usage

**Interactive Mode:**
```bash
./pish
pish> ls -la
pish> cd /tmp
pish> history
pish> exit
```

**Batch Mode:**
```bash
./pish < commands.txt
```

## File Structure
```
Pioneer_Shell/
├── pioneer_shell.c    # Main shell implementation
├── README.md          # This file
└── test_commands.txt  # Sample batch mode commands
```

## Example Commands

```bash
# List files
pish> ls -l

# Change directory
pish> cd /home

# View command history
pish> history

# Execute background process
pish> sleep 10 &

# Run batch script
./pish < script.txt
```

## Implementation Highlights

- **Signal Safety:** Handles SIGCHLD for proper zombie process cleanup
- **Memory Management:** No memory leaks; proper resource deallocation
- **Edge Cases:** Handles empty input, very long commands, special characters
- **POSIX Compliance:** Follows standard Unix shell conventions

## Testing

The implementation has been tested with:
- Interactive command execution
- Batch mode script processing
- History persistence across sessions
- Edge cases (empty commands, long inputs, special characters)
- Process termination and signal handling

## Limitations & Future Enhancements

### Current Limitations
- No piping or redirection operators
- Limited job control features
- No command substitution

### Potential Enhancements
- Pipe (`|`) and redirection (`>`, `<`, `>>`) support
- Variable expansion and environment variable handling
- Job control with `fg`/`bg` commands
- Alias support
- Tab completion

## Author
Built as a programming assignment for UC San Diego's CSE 29 course.

## License
Educational project - UC San Diego CSE 29

---

**Last Updated:** 2025 | **Status:** Complete and Tested
