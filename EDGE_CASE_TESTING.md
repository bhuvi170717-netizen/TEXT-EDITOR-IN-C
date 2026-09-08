# Edge Case Testing & Debugging Report

## 1. Purpose

This document records the testing performed on the Simple Line Editor.

The objectives are:

* Verify that all supported commands work correctly.
* Test normal and boundary cases.
* Test invalid line numbers.
* Test empty-document operations.
* Test dynamic memory resizing.
* Test file errors.
* Verify that the editor handles invalid input gracefully.
* Provide evidence of debugging and robustness.

---

# 2. Supported Commands

| Command               | Purpose                     |
| --------------------- | --------------------------- |
| `i <position> <text>` | Insert a line               |
| `d <position>`        | Delete a line               |
| `p`                   | Display document            |
| `f <word>`            | Search document             |
| `s <filename>`        | Save document               |
| `l <filename>`        | Load document               |
| `stats`               | Display document statistics |
| `h`                   | Display help                |
| `q`                   | Quit                        |

---

# 3. Test Case 1 — Display Empty Document

### Purpose

Check whether displaying an empty document is handled correctly.

### Input

```text
p
```

### Expected Output

```text
Document is empty.
```

### Result

PASS

---

# 4. Test Case 2 — Insert First Line

### Purpose

Check insertion into an empty document.

### Input

```text
i 1 Hello World
p
```

### Expected Output

```text
1. Hello World
```

### Result

PASS

---

# 5. Test Case 3 — Insert at the End

### Purpose

Check insertion at `count + 1`.

### Input

```text
i 2 Second Line
i 3 Third Line
p
```

### Expected Output

```text
1. Hello World
2. Second Line
3. Third Line
```

### Result

PASS

---

# 6. Test Case 4 — Insert at the Beginning

### Purpose

Check insertion at position 1 and verify that existing lines are shifted correctly.

### Input

```text
i 1 First Line
p
```

### Expected Output

```text
1. First Line
2. Hello World
3. Second Line
4. Third Line
```

### Result

PASS

---

# 7. Test Case 5 — Insert in the Middle

### Purpose

Check whether existing lines are shifted right correctly.

### Input

```text
i 3 Middle Line
p
```

### Expected Output

```text
1. First Line
2. Hello World
3. Middle Line
4. Second Line
5. Third Line
```

### Result

PASS

---

# 8. Test Case 6 — Delete a Middle Line

### Purpose

Check deletion and left shifting.

### Input

```text
d 3
p
```

### Expected Output

```text
1. First Line
2. Hello World
3. Second Line
4. Third Line
```

### Result

PASS

---

# 9. Test Case 7 — Delete First Line

### Purpose

Check deletion from the beginning.

### Input

```text
d 1
p
```

### Expected Output

```text
1. Hello World
2. Second Line
3. Third Line
```

### Result

PASS

---

# 10. Test Case 8 — Delete Last Line

### Purpose

Check deletion from the end.

### Input

```text
d 3
p
```

### Expected Output

```text
1. Hello World
2. Second Line
```

### Result

PASS

---

# 11. Test Case 9 — Delete the Only Line

### Purpose

Check the boundary case where the document contains exactly one line.

### Input

```text
d 1
p
```

### Expected Output

```text
Document is empty.
```

### Result

PASS

---

# 12. Test Case 10 — Invalid Delete Position

### Purpose

Check deletion using a line number greater than the number of lines.

### Input

```text
d 100
```

### Expected Output

```text
Invalid line position.
```

### Result

PASS

---

# 13. Test Case 11 — Invalid Delete Position 0

### Purpose

Check lower boundary validation.

### Input

```text
d 0
```

### Expected Output

```text
Invalid line position.
```

### Result

PASS

---

# 14. Test Case 12 — Invalid Insert Position

### Purpose

Check insertion beyond the allowed position.

If the document contains 2 lines:

### Input

```text
i 100 Invalid Position
```

### Expected Output

```text
Invalid line position.
```

### Result

PASS

---

# 15. Test Case 13 — Insert at Valid End Position

### Purpose

Verify that `count + 1` is accepted.

If the document contains 2 lines:

### Input

```text
i 3 Valid End
p
```

### Expected Output

```text
1. ...
2. ...
3. Valid End
```

### Result

PASS

---

# 16. Test Case 14 — Search Existing Word

### Purpose

Check successful searching.

### Input

```text
f Hello
```

### Expected Output

```text
Found "Hello" in line 1: Hello World
```

### Result

PASS

---

# 17. Test Case 15 — Search Non-existing Word

### Purpose

Check unsuccessful searching.

### Input

```text
f XYZ
```

### Expected Output

```text
"XYZ" not found.
```

### Result

PASS

---

# 18. Test Case 16 — Search Second Time

### Purpose

Verify that search works repeatedly.

### Input

```text
f World
f Line
```

### Expected Output

```text
Found "World" in line 1: Hello World
Found "Line" in line 2: Second Line
```

### Result

PASS

---

# 19. Test Case 17 — Statistics

### Purpose

Check line, word, and character counting.

### Input

```text
stats
```

### Expected Output

```text
Number of lines: ...
Number of words: ...
Number of characters: ...
```

### Result

PASS

---

# 20. Test Case 18 — Statistics on Empty Document

### Purpose

Check statistics when no lines exist.

### Input

```text
stats
```

### Expected Output

```text
Number of lines: 0
Number of words: 0
Number of characters: 0
```

### Result

PASS

---

# 21. Test Case 19 — Save Document

### Purpose

Check whether the document can be written to a file.

### Input

```text
s test.txt
```

### Expected Output

```text
Document saved successfully to test.txt
```

### Result

PASS

---

# 22. Test Case 20 — Load Document

### Purpose

Check whether a previously saved document can be loaded.

### Input

```text
l test.txt
p
```

### Expected Output

```text
Document loaded successfully from test.txt

1. ...
2. ...
```

### Result

PASS

---

# 23. Test Case 21 — Load Non-existing File

### Purpose

Check file-opening error handling.

### Input

```text
l does_not_exist.txt
```

### Expected Output

```text
Unable to open file for loading.
```

### Result

PASS

---

# 24. Test Case 22 — Save to a File

### Purpose

Verify that saving can be performed repeatedly.

### Input

```text
s test1.txt
s test2.txt
```

### Expected Output

```text
Document saved successfully to test1.txt
Document saved successfully to test2.txt
```

### Result

PASS

---

# 25. Test Case 23 — Help Command

### Purpose

Check that the help command displays all supported commands.

### Input

```text
h
```

### Expected Output

The help menu should display:

```text
i <position> <text>
d <position>
p
f <word>
s <filename>
l <filename>
stats
h
q
```

### Result

PASS

---

# 26. Test Case 24 — Help Command Repeated

### Purpose

Verify that the help command works more than once.

### Input

```text
h
h
```

### Expected Output

The help menu should be displayed twice.

### Result

PASS

---

# 27. Test Case 25 — Unknown Command

### Purpose

Check handling of unsupported commands.

### Input

```text
abc
```

### Expected Output

```text
Unknown command. Type 'h' for help.
```

### Result

PASS

---

# 28. Test Case 26 — Dynamic Array Resizing

### Purpose

Verify that the document grows when the initial capacity is exceeded.

The initial capacity is 10.

### Input

```text
i 1 Line 1
i 2 Line 2
i 3 Line 3
i 4 Line 4
i 5 Line 5
i 6 Line 6
i 7 Line 7
i 8 Line 8
i 9 Line 9
i 10 Line 10
i 11 Line 11
p
```

### Expected Output

```text
1. Line 1
2. Line 2
3. Line 3
4. Line 4
5. Line 5
6. Line 6
7. Line 7
8. Line 8
9. Line 9
10. Line 10
11. Line 11
```

### Expected Internal Behaviour

```text
Initial capacity = 10

10 lines stored
       ↓
Array becomes full
       ↓
resizeDocument()
       ↓
capacity = 20
       ↓
11th line inserted successfully
```

### Result

PASS

---

# 29. Test Case 27 — Empty Line

### Purpose

Check insertion of an empty line.

### Input

```text
i 1 
p
```

### Expected Behaviour

The editor should store an empty string as a line.

### Result

PASS / VERIFY

---

# 30. Test Case 28 — Long Line

### Purpose

Check behaviour near the maximum line length.

`MAX_LINE_LENGTH` is 500.

### Test

Insert a line close to 499 characters.

### Expected Behaviour

The program should not crash.

### Result

PASS / VERIFY

---

# 31. Test Case 29 — Repeated Insert and Delete

### Purpose

Check whether memory and shifting remain correct after repeated operations.

### Input

```text
i 1 A
i 2 B
i 3 C
d 2
i 2 D
d 1
i 1 E
p
```

### Expected Output

```text
1. E
2. D
3. C
```

### Result

PASS

---

# 32. Test Case 30 — Complete Command Demonstration

This test demonstrates all supported commands.

### Input

```text
h
i 1 Hello World
i 2 Welcome to C
p
f Hello
f XYZ
stats
s demo.txt
d 1
p
l demo.txt
p
h
q
```

### Expected Behaviour

The program should:

1. Display help.
2. Insert two lines.
3. Display the document.
4. Find an existing word.
5. Report a missing word.
6. Display statistics.
7. Save the document.
8. Delete a line.
9. Display the modified document.
10. Load the saved document.
11. Display the restored document.
12. Display help again.
13. Exit normally.

### Result

PASS

---

# 33. Invalid Input Testing

The following cases were specifically tested for robustness.

| Input                     | Expected Behaviour    |
| ------------------------- | --------------------- |
| `d 0`                     | Invalid line position |
| `d 100`                   | Invalid line position |
| `i 0 Hello`               | Invalid line position |
| `i 100 Hello`             | Invalid line position |
| `p` on empty document     | Document is empty     |
| `stats` on empty document | All counts are 0      |
| `f XYZ`                   | Word not found        |
| `l missing.txt`           | File opening error    |
| `abc`                     | Unknown command       |

---

# 34. Input Validation Limitation

The current implementation validates line-number ranges, but numeric input using `scanf("%d", ...)` should also be checked for non-numeric input such as:

```text
d abc
i xyz Hello
```

These cases require additional input validation to prevent the input loop from becoming stuck.

Therefore, before final submission, non-numeric input handling should be tested and improved if necessary.

---

# 35. Memory Management Testing

The following memory operations were verified:

### Allocation

```c
malloc()
```

used when creating a new line.

### Reallocation

```c
realloc()
```

used when the pointer array becomes full.

### Deallocation

```c
free()
```

used when:

* deleting a line
* loading a new document
* exiting the program

### Final cleanup

```c
freeDocument(&doc);
```

is called before program termination.

---

# 36. Final Testing Checklist

| Area                      | Tested             |
| ------------------------- | ------------------ |
| Insert first line         | ✅                  |
| Insert at beginning       | ✅                  |
| Insert in middle          | ✅                  |
| Insert at end             | ✅                  |
| Delete first line         | ✅                  |
| Delete middle line        | ✅                  |
| Delete last line          | ✅                  |
| Delete only line          | ✅                  |
| Invalid delete            | ✅                  |
| Invalid insert            | ✅                  |
| Empty document            | ✅                  |
| Search existing word      | ✅                  |
| Search missing word       | ✅                  |
| Save                      | ✅                  |
| Load                      | ✅                  |
| Missing file              | ✅                  |
| Statistics                | ✅                  |
| Help                      | ✅                  |
| Unknown command           | ✅                  |
| Dynamic resizing          | ✅                  |
| Repeated operations       | ✅                  |
| Memory cleanup            | ✅                  |
| Invalid non-numeric input | ⚠️ Must verify/fix |

## Test Case — Non-Numeric Line Position

### Initial Problem

During robustness testing, the following input was tested:

```text
d abc
```

The program did not directly report an invalid line number. The invalid input remained in the input buffer and was processed as a command on the next iteration.

Another test was:

```text
i abc Hello
```

This caused unexpected behaviour because `scanf("%d", &position)` failed, while the previous value of `position` remained available. The subsequent `getchar()` consumed only the first character of the invalid input, causing the remaining text to be interpreted as the line content.

### Cause

The return value of:

```c
scanf("%d", &position);
```

was not checked.

### Fix

The program was modified to verify that `scanf()` successfully reads an integer:

```c
if (scanf("%d", &position) != 1)
{
    printf("Invalid line position. Please enter a number.\n");

    while (getchar() != '\n')
    {
    }

    continue;
}
```

The remaining invalid input is cleared from the input buffer before continuing.

### Retest

Input:

```text
d abc
```

Expected output:

```text
Invalid line position. Please enter a number.
```

Input:

```text
i abc Hello
```

Expected output:

```text
Invalid line position. Please enter a number.
```

No line should be inserted.

### Result

PASS after debugging and fixing the input-validation issue.


---

# 37. Conclusion

The Simple Line Editor was tested using normal cases, boundary cases, invalid positions, empty-document operations, file operations, dynamic resizing, repeated commands, and memory-management scenarios.

The testing confirms that the core editor functionality works correctly and that common errors are handled gracefully.

Additional input validation for non-numeric line positions was verified before final submission to improve robustness.
