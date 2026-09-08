# Simple Line Editor in C

A simple command-line text editor developed in **C** using dynamic memory allocation and an array of strings.

The project demonstrates practical use of **structures, pointers, dynamic memory allocation, strings, file handling, and modular programming**.

---

## 📌 Project Overview

The **Simple Line Editor** allows users to create and manage a text document line by line through a command-line interface.

Each line is dynamically stored in memory, and the document automatically increases its storage capacity when required.

### Core Features

* Insert a line at a specific position
* Delete a line
* Display the complete document

### Bonus Features

* Search for a word or substring
* Save the document to a file
* Load a document from a file
* Display document statistics
* Built-in help system

---

## 🛠️ Technologies Used

* **Language:** C
* **Compiler:** GCC
* **Version Control:** Git
* **Repository Hosting:** GitHub

### C Concepts Used

* Structures
* Pointers
* Double pointers
* Dynamic memory allocation
* `malloc()`
* `realloc()`
* `free()`
* Strings
* Arrays
* Functions
* File handling
* Command-line input processing

---

## 🧠 Data Structure

The document is represented using the following structure:

```c
typedef struct {
    char **lines;
    int count;
    int capacity;
} Document;
```

### Members

| Member     | Purpose                                     |
| ---------- | ------------------------------------------- |
| `lines`    | Dynamically allocated array of strings      |
| `count`    | Number of lines currently stored            |
| `capacity` | Number of line pointers currently allocated |

The editor initially allocates space for **10 lines**.

When the document becomes full, the capacity is doubled using `realloc()`.

Example:

```text
10 → 20 → 40 → 80 → ...
```

---

## 📂 Project Structure

```text
TEXT-EDITOR-IN-C/
│
├── editor.c
├── editor.h
├── HELP.md
├── README.md
└── .gitignore
```

### `editor.c`

Contains the implementation of the editor, including document management, core operations, bonus features, and the command-line interface.

### `editor.h`

Contains the `Document` structure and function prototypes.

### `HELP.md`

Contains detailed instructions for using the editor and descriptions of all commands.

### `README.md`

Provides an overview of the project, features, design, and usage.

---

## ⚙️ Core Functions

### `initDocument()`

Initializes an empty document and dynamically allocates the initial array of line pointers.

### `resizeDocument()`

Doubles the document capacity when the allocated array becomes full.

### `insertLine()`

Inserts a new line at the specified position and shifts existing lines when necessary.

### `deleteLine()`

Deletes a line, frees its allocated memory, and shifts the remaining lines.

### `displayDocument()`

Displays all lines currently stored in the document.

---

## ⭐ Bonus Functions

### `searchDocument()`

Searches all lines for a specified word or substring.

### `saveDocument()`

Writes the current document to a text file.

### `loadDocument()`

Loads lines from a text file into the document.

### `documentStatistics()`

Displays:

* Number of lines
* Number of words
* Number of characters

### `showHelp()`

Displays the available commands and their usage.

---

## 💻 Compilation

Make sure GCC is installed.

Compile the program using:

```bash
gcc editor.c -o editor
```

Run:

```bash
./editor
```

### Windows

```bash
gcc editor.c -o editor.exe
editor.exe
```

---

## 🎮 Available Commands

| Command               | Description        |
| --------------------- | ------------------ |
| `i <position> <text>` | Insert a line      |
| `d <position>`        | Delete a line      |
| `p`                   | Display document   |
| `f <word>`            | Search document    |
| `s <filename>`        | Save document      |
| `l <filename>`        | Load document      |
| `stats`               | Display statistics |
| `h`                   | Display help       |
| `q`                   | Quit               |

---

## ▶️ Example Usage

Start the program:

```text
=====================================
        SIMPLE LINE EDITOR
=====================================
```

### Insert lines

```text
Enter command: i 1 Hello world

Enter command: i 2 Welcome to C programming

Enter command: i 3 Dynamic memory is powerful
```

### Display document

```text
Enter command: p

1. Hello world
2. Welcome to C programming
3. Dynamic memory is powerful
```

### Search

```text
Enter command: f programming

Found "programming" in line 2: Welcome to C programming
```

### Statistics

```text
Enter command: stats

Number of lines: 3
Number of words: 9
Number of characters: 67
```

### Delete

```text
Enter command: d 2
```

### Save

```text
Enter command: s document.txt

Document saved successfully to document.txt
```

### Load

```text
Enter command: l document.txt

Document loaded successfully from document.txt
```

### Quit

```text
Enter command: q

Exiting editor...
```

---

## 🔄 How the Dynamic Array Works

The editor uses a dynamically allocated array of `char *`.

Conceptually:

```text
Document
   │
   ├── lines ──────┐
   │               │
   │               ▼
   │        ┌─────────────┐
   │        │ char *      │ ───► "First line"
   │        ├─────────────┤
   │        │ char *      │ ───► "Second line"
   │        ├─────────────┤
   │        │ char *      │ ───► "Third line"
   │        ├─────────────┤
   │        │     ...     │
   │        └─────────────┘
   │
   ├── count
   └── capacity
```

Each line is separately allocated using `malloc()`.

When the pointer array becomes full, `realloc()` is used to increase its capacity.

When a line is deleted, its allocated memory is released using `free()`.

Finally, `freeDocument()` releases all remaining line memory and the pointer array.

---

## 🔐 Memory Management

The project carefully manages dynamically allocated memory.

### Allocation

```c
malloc()
```

is used for:

* The array of line pointers
* Individual line strings

### Resizing

```c
realloc()
```

is used when the document reaches its capacity.

### Deallocation

```c
free()
```

is used when:

* A line is deleted
* The document is loaded from a new file
* The program exits

This prevents unnecessary memory usage and demonstrates proper dynamic memory management in C.

---

## 📄 File Handling

The editor supports saving and loading documents.

### Save

```text
s document.txt
```

The document is written line by line to the specified file.

### Load

```text
l document.txt
```

The existing document contents are cleared and replaced with the contents of the specified file.

---

## ⚠️ Limitations

This is a simple educational line editor and intentionally does not implement advanced text-editor features.

Current limitations include:

* Maximum input line length is 499 characters.
* Search is case-sensitive.
* Search accepts a single word/substring.
* There is no graphical user interface.
* There is no undo/redo functionality.
* Loading a file replaces the current document.

---

## 🧪 Testing

The following operations should be tested before submission:

1. Insert the first line.
2. Insert multiple lines.
3. Insert a line at the beginning.
4. Insert a line in the middle.
5. Insert a line at the end.
6. Delete the first line.
7. Delete a middle line.
8. Delete the last line.
9. Display an empty document.
10. Search for an existing word.
11. Search for a missing word.
12. Save a document.
13. Load a saved document.
14. Test invalid line positions.
15. Test the capacity expansion.
16. Check that memory is released when quitting.

---

## 👥 Team Collaboration

This project was developed collaboratively using **Git and GitHub**.

### Collaboration Workflow

```text
main
 │
 ├── teammate1-core
 │
 └── teammate2-bonus
```

Team members worked on separate branches to avoid conflicts.

Changes were:

1. Developed on individual branches
2. Committed using Git
3. Pushed to GitHub
4. Submitted through Pull Requests
5. Reviewed
6. Merged into `main`

This workflow helped demonstrate practical use of **Git branching, collaboration, code review, and pull requests**.

---

## 🎯 Learning Objectives

This project was created to practice and demonstrate:

* Dynamic memory allocation
* Pointer and pointer-to-pointer concepts
* Structures
* Arrays of strings
* Functions and modular programming
* String manipulation
* File I/O
* Input validation
* Memory management
* Git and GitHub collaboration

---

## 📜 License

This project was developed as an educational college project.
