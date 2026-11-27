# Coding rules for C++

These are the rules I follow in this project.

## 1. Variables and functions use camelCase with meaningful names

Use a name that explains what the variable or function does. One-letter names are allowed only for names given in the task.

```cpp
int studentTotal = 0;      // good
int student_total = 0;     // bad: not camelCase
int st = 0;                // bad: unclear name
```

## 2. Constants use UPPER_CASE (no "magic numbers")

```cpp
const int NUMBER_OF_SCORES = 5;
const int HIGHEST_SCORE = 100;
```

## 3. Indent with 4 spaces and always use braces

Do not use tabs. Put the code of every `if`, `for` and `while` in `{ }`, even if it is one line.

```cpp
if (value > HIGHEST_SCORE) {
    cout << "Invalid score" << endl;
}
```

## 4. Write comments for every logical block

Put a short comment at the top of the file (what the program does and who wrote it) and before each function and important block of code. Explain *why*, not only *what*.

```cpp
// Converts an average to a grade letter
char gradeFor(double average) {
    ...
}
```

## 5. One statement per line, maximum 80 characters per line

```cpp
pointsSum += score;        // good
count++; total += x;       // bad: two statements on one line
```
