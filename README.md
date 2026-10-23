# 🧮 Arbitrary Precision Calculator in C

## 📌 Project Overview

The Arbitrary Precision Calculator is a command-line application written in **C** that performs arithmetic operations on integers of any length. It represents each number using a **doubly linked list of digits**, overcoming the fixed size limitations of built-in integer data types such as `int` and `long long`.

The calculator supports addition, subtraction, multiplication, and integer division, including operations on negative numbers.

## ✨ Features

- 🔢 **Arbitrary-Length Integers:** Handles numbers with any number of digits, limited by available memory.
- ➕ **Addition:** Performs digit-by-digit addition with carry handling.
- ➖ **Subtraction:** Performs digit-by-digit subtraction with borrow handling.
- ✖️ **Multiplication:** Uses long multiplication and shifted partial products.
- ➗ **Division:** Calculates the integer quotient using repeated subtraction.
- ➖ **Negative Numbers:** Supports positive and negative operands.
- ✅ **Input Validation:** Detects invalid operands, operators, and argument counts.
- 🚫 **Division by Zero Detection:** Displays an error when the divisor is zero.
- 🔍 **Leading Zero Handling:** Treats inputs such as `007` as `7`.
- 🧹 **Memory Management:** Frees dynamically allocated linked-list nodes after use.

## 🧱 Data Structure

The calculator uses a **doubly linked list (DLL)** to store each digit of a number.

### Structure Definition

```c
typedef struct node
{
    int data;           // One digit (0-9)
    struct node *prev;
    struct node *next;
} Dlist;
```

### Number Representation

Each number is stored with its most significant digit at the head and its least significant digit at the tail.

For example, the number `1234` is represented as:

```text
head -> 1 <-> 2 <-> 3 <-> 4 <- tail
```

Arithmetic operations begin at the tail and traverse backward using the `prev` pointer, similar to manual arithmetic.

## 📁 Project Structure

| File | Purpose |
|---|---|
| `main.c` | Processes command-line arguments, handles signs, calls operations, prints results, and frees memory. |
| `DLL.h` | Defines the node structure, macros, and function prototypes. |
| `validate_CLA.c` | Validates argument count, operands, and operators. |
| `slicing_input_dll.c` | Converts an input string into a linked list of digits. |
| `insert_first.c` | Inserts a digit at the beginning of a list. |
| `insert_last.c` | Inserts a digit at the end of a list. |
| `delete_list.c` | Frees all nodes in a linked list. |
| `print_list.c` | Prints the result, including a negative sign when needed. |
| `compare_lists.c` | Compares the magnitudes of two numbers. |
| `addition.c` | Implements addition with carry handling. |
| `subtraction.c` | Implements subtraction with borrow handling. |
| `multiplication.c` | Implements multiplication using shifted partial products. |
| `division.c` | Implements integer division using repeated subtraction. |

## 🚀 Usage

Run the program using the following command:

```bash
./a.out <num1> <operator> <num2>
```

### Supported Operators

| Operator | Operation |
|---|---|
| `+` | ➕ Addition |
| `-` | ➖ Subtraction |
| `x` or `X` | ✖️ Multiplication |
| `/` | ➗ Integer division (quotient only) |

## 💻 Examples

### ➕ Addition

```bash
$ ./a.out 1233457 + 542114
Result : 1775571
```

### ➖ Subtraction

```bash
$ ./a.out 3 - 8
Result : -5
```

### ✖️ Multiplication

```bash
$ ./a.out 62345 x 64
Result : 3990080
```

### ➖ Negative Operands

```bash
$ ./a.out -234 x 5
Result : -1170
```

### ➗ Division

```bash
$ ./a.out 3456 / 23
Result : 150
```

### 🚫 Division by Zero

```bash
$ ./a.out 23456 / 0
ERROR: Division by zero is not possible
```

## ⚙️ How Each Operation Works

- ➕ **Addition:** Adds digits from the tail, maintains a carry, and inserts each result digit at the front of the result list. The process continues until both lists and the carry are exhausted.
- ➖ **Subtraction:** Subtracts digits with borrow handling. The magnitudes are compared first, and leading zeros are removed from the result.
- ✖️ **Multiplication:** Multiplies one operand by each digit of the other operand, shifts partial products by appending zeros, and adds them to the running result.
- ➗ **Division:** Processes the dividend one digit at a time, builds a remainder, and repeatedly subtracts the divisor to determine each quotient digit.

## ➕ Sign Handling Rules

| Operation | Sign rule |
|---|---|
| Addition with same signs | Result keeps the operands' sign. |
| Addition with different signs | Result takes the sign of the operand with the larger magnitude. |
| Subtraction with different signs | Adds magnitudes and keeps the sign of the first operand. |
| Subtraction with same signs | Subtracts magnitudes; the result sign depends on their magnitudes and operand signs. |
| Multiplication and division | Positive if operand signs match; negative otherwise. |

**Note:** Zero is always displayed without a negative sign.

## ⚠️ Error Handling

### Invalid Operand

```bash
$ ./a.out 5abc + 3
ERROR: 5abc is invalid operand
```

### Invalid Operator

```bash
$ ./a.out 5 ++ 3
ERROR: ++ is invalid operator
```

### Invalid Number of Arguments

```bash
$ ./a.out 5 + 3 4
ERROR: Invalid number of arguments
```

## 🧪 Test Cases

```bash
./a.out 999 + 5       # 1004
./a.out 5 + -8        # -3
./a.out -5 + -3       # -8
./a.out 3 - 8         # -5
./a.out -3 - -8       # 5
./a.out 1000 - 1      # 999
./a.out 12 - 12       # 0
./a.out 234 x 90      # 21060
./a.out 234 x 0       # 0
./a.out 999 x 999     # 998001
./a.out 3456 / 23     # 150
./a.out -45 / 9       # -5
./a.out 5 / 9         # 0
./a.out 23456 / 0     # Division by zero error
```


## 🛠️ Technologies Used

- 💻 C Programming
- 🔗 Doubly Linked Lists
- 👉 Pointers
- 🧠 Dynamic Memory Allocation
- 🔤 String Manipulation
- ⚙️ Command-Line Argument Handling
- 🧪 Input Validation and Error Handling

## 👩‍💻 Author

**Shruti Khamitkar**
