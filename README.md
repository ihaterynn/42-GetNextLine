# Get Next Line (42 Project)

**Get Next Line** is a function that reads a file descriptor and returns the next line each time it is called.  
It handles files with any `BUFFER_SIZE`, preserves leftover data between calls, and correctly returns the last line even if it doesn’t end with a newline.

---

## 📦 Files

- **get_next_line.c**  
  Implements the main logic: `get_next_line()`, `read_line()`, `extract_line()`, `clear_buffer()`.
- **get_next_line_utils.c**  
  Helper functions: `ft_strlen`, `ft_strdup`, `ft_strjoin`, `ft_strchr`, `ft_calloc`, `ft_substr`.
- **get_next_line.h**  
  Declarations and `BUFFER_SIZE` macro.
- **main.c**  
  Simple test harness that calls `get_next_line()` three times on `test.txt`.

---

## ⚙️ Compile & Run

```bash
# Compile with warnings as errors
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl_test

# Run the test executable
./gnl_test
