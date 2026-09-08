# Simple Line Editor — Help

## 1. Introduction

This is a simple command-line text editor written in C.

The editor stores text **line by line** using a dynamically allocated array of strings.

You can insert, delete, display, search, save, and load lines. The editor also provides document statistics and a built-in help command.

---

## 2. How to Start

Compile the program using:

```bash
gcc editor.c -o editor
```

Run the program:

```bash
./editor
```

On Windows:

```bash
gcc editor.c -o editor.exe
editor.exe
```

When the program starts, it displays the available commands.

---

## 3. Commands

### Insert a Line

```text
i <position> <text>
```

Inserts a new line at the specified position.

Example:

```text
i 1 Hello world
i 2 This is my second line
i 2 Inserted between the lines
```

The position must be between `1` and `count + 1`.

---

### Delete a Line

```text
d <position>
```

Deletes the line at the specified position.

Example:

```text
d 2
```

The position must refer to an existing line.

---

### Display Document

```text
p
```

Displays all lines currently stored in the document.

Example output:

```text
1. Hello world
2. This is my second line
3. C programming is interesting
```

If there are no lines:

```text
Document is empty.
```

---

### Search

```text
f <word>
```

Searches for a word or substring in all lines.

Example:

```text
f programming
```

Possible output:

```text
Found "programming" in line 3: C programming is interesting
```

The search is case-sensitive.

---

### Save Document

```text
s <filename>
```

Saves the current document to a text file.

Example:

```text
s document.txt
```

If successful:

```text
Document saved successfully to document.txt
```

If the file cannot be opened:

```text
Unable to open file for saving.
```

---

### Load Document

```text
l <filename>
```

Loads the contents of an existing text file into the editor.

Example:

```text
l document.txt
```

The current document is cleared before the file contents are loaded.

---

### Document Statistics

```text
stats
```

Displays the number of lines, words, and characters in the current document.

Example:

```text
Number of lines: 3
Number of words: 12
Number of characters: 67
```

---

### Help

```text
h
```

Displays the list of available commands.

---

### Quit

```text
q
```

Exits the editor.

Before exiting, the program releases the dynamically allocated memory used by the document.

---

## 4. Command Summary

| Command               | Description                 |
| --------------------- | --------------------------- |
| `i <position> <text>` | Insert a line               |
| `d <position>`        | Delete a line               |
| `p`                   | Display document            |
| `f <word>`            | Search document             |
| `s <filename>`        | Save document               |
| `l <filename>`        | Load document               |
| `stats`               | Display document statistics |
| `h`                   | Display help                |
| `q`                   | Quit the editor             |

---

## 5. Important Notes

* Line positions start from **1**.
* A new line can be inserted at positions from `1` to `count + 1`.
* Deletion is allowed only for existing line positions.
* The editor automatically increases its storage capacity when the document becomes full.
* Lines are dynamically allocated in memory.
* The document is saved as a normal text file.
* Loading a file replaces the current document contents.
* Search is case-sensitive.
* The maximum input line length is **499 characters** plus the null terminator.

---

## 6. Example Session

```text
Enter command: i 1 Hello world

Enter command: i 2 Welcome to the C line editor

Enter command: i 3 Dynamic memory is useful

Enter command: p

1. Hello world
2. Welcome to the C line editor
3. Dynamic memory is useful

Enter command: f memory

Found "memory" in line 3: Dynamic memory is useful

Enter command: stats

Number of lines: 3
Number of words: 10
Number of characters: 67

Enter command: d 2

Enter command: p

1. Hello world
2. Dynamic memory is useful

Enter command: s document.txt

Document saved successfully to document.txt

Enter command: q

Exiting editor...
```

---

## 7. Error Messages

### Invalid line position

```text
Invalid line position.
```

This occurs when an invalid position is supplied for insertion or deletion.

### Empty document

```text
Document is empty.
```

This is displayed when `p` is used while there are no lines.

### File error

```text
Unable to open file for saving.
```

or

```text
Unable to open file for loading.
```

This occurs when the specified file cannot be opened.

### Memory allocation error

```text
Memory allocation failed.
```

This occurs if dynamic memory allocation fails.

### Unknown command

```text
Unknown command. Type 'h' for help.
```

This occurs when an unsupported command is entered.

---

## 8. Recommended Usage Order

A typical workflow is:

```text
1. Insert lines
2. Display the document
3. Search if required
4. Check statistics
5. Save the document
6. Load a saved document when needed
7. Quit
```

For a quick reminder of commands, enter:

```text
h
```

# Command Examples

The following examples demonstrate every command supported by the Simple Line Editor at least twice.

---

## 1. Insert — `i`

### Example 1: Insert at the beginning

```text
i 1 Hello World
```

Output:

```text
1. Hello World
```

### Example 2: Insert at the end

If the document currently contains:

```text
1. Hello World
2. Welcome to C
```

Use:

```text
i 3 Dynamic Memory
```

Output:

```text
1. Hello World
2. Welcome to C
3. Dynamic Memory
```

---

## 2. Delete — `d`

### Example 1: Delete a middle line

If the document contains:

```text
1. Hello
2. Welcome
3. C Programming
```

Use:

```text
d 2
```

Output after displaying:

```text
1. Hello
2. C Programming
```

### Example 2: Delete the only line

If the document contains:

```text
1. Hello
```

Use:

```text
d 1
```

Then:

```text
p
```

Output:

```text
Document is empty.
```

---

## 3. Display — `p`

### Example 1: Display a non-empty document

```text
p
```

Output:

```text
1. Hello World
2. Welcome to C
3. Dynamic Memory
```

### Example 2: Display an empty document

```text
p
```

Output:

```text
Document is empty.
```

---

## 4. Search — `f`

### Example 1: Search for an existing word

If the document contains:

```text
1. Hello World
2. Welcome to C
```

Use:

```text
f Hello
```

Output:

```text
Found "Hello" in line 1: Hello World
```

### Example 2: Search for a word that does not exist

```text
f Python
```

Output:

```text
"Python" not found.
```

---

## 5. Save — `s`

### Example 1: Save the document

```text
s document.txt
```

Output:

```text
Document saved successfully to document.txt
```

### Example 2: Save to another file

```text
s backup.txt
```

Output:

```text
Document saved successfully to backup.txt
```

---

## 6. Load — `l`

### Example 1: Load an existing file

If `document.txt` exists:

```text
l document.txt
```

Output:

```text
Document loaded successfully from document.txt
```

### Example 2: Load another existing file

If `backup.txt` exists:

```text
l backup.txt
```

Output:

```text
Document loaded successfully from backup.txt
```

If the file does not exist, the program displays:

```text
Unable to open file for loading.
```

---

## 7. Statistics — `stats`

### Example 1: Statistics for a populated document

If the document contains:

```text
1. Hello World
2. Welcome to C
```

Use:

```text
stats
```

Output:

```text
Number of lines: 2
Number of words: 5
Number of characters: 24
```

### Example 2: Statistics for an empty document

```text
stats
```

Output:

```text
Number of lines: 0
Number of words: 0
Number of characters: 0
```

---

## 8. Help — `h`

### Example 1: Display help

```text
h
```

Output:

```text
========== TEXT EDITOR HELP ==========

i <position> <text>  - Insert a line
d <position>         - Delete a line
p                    - Display document
f <word>             - Search document
s <filename>         - Save document
l <filename>         - Load document
stats                - Show statistics
h                    - Show help
q                    - Quit

======================================
```

### Example 2: Display help again

```text
h
```

The same help menu is displayed again.

This confirms that the help command can be used repeatedly.

---

## 9. Quit — `q`

The quit command terminates the editor, so the two examples are performed in separate program runs.

### Example 1

```text
q
```

Output:

```text
Exiting editor...
```

### Example 2

Start the editor again and enter:

```text
q
```

Output:

```text
Exiting editor...
```

---

# Command Coverage

| Command | Example 1          | Example 2             |
| ------- | ------------------ | --------------------- |
| `i`     | Beginning          | End                   |
| `d`     | Middle line        | Only line             |
| `p`     | Non-empty document | Empty document        |
| `f`     | Existing word      | Missing word          |
| `s`     | `document.txt`     | `backup.txt`          |
| `l`     | Existing file      | Another existing file |
| `stats` | Populated document | Empty document        |
| `h`     | First use          | Repeated use          |
| `q`     | First program run  | Second program run    |

All supported commands have at least two usage examples.

