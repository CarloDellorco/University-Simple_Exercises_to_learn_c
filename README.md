# C Exercises: First Year Collection

A collection of small C programs written during my first year of the Computer Engineering ("Ingegneria Informatica") degree at **Politecnico di Milano**.

They cover the fundamentals of the language: input/output, control flow, arrays, strings, structs, enums, pointers, simple algorithms and common data structures. The code has been polished and it's fully working but some variables/comments are kept in italian.

## Index

| #  | File | Description |
|----|------|-------------|
| 1  | [`1-sum_and_average.c`](1-sum_and_average.c) | Reads three integers and prints their sum and average |
| 2  | [`2-alphabet.c`](2-alphabet.c) | Prints the first *n* letters of the alphabet (max 26) |
| 3  | [`3-bubble_sort.c`](3-bubble_sort.c) | Sorts an array of 10 integers with bubble sort |
| 4  | [`4-calculator.c`](4-calculator.c) | Menu-driven calculator (sum, subtraction, division, product) |
| 5  | [`5-areas_catalogue.c`](5-areas_catalogue.c) | Computes the area of a rectangle, triangle or square using a struct |
| 6  | [`6-students_catalogue.c`](6-students_catalogue.c) | Looks up a student by ID number and records their grade |
| 7  | [`7-is_it_vowel.c`](7-is_it_vowel.c) | Tells whether a character is a vowel, a consonant or not a letter |
| 8  | [`8-binary_converter.c`](8-binary_converter.c) | Converts a positive integer to binary |
| 9  | [`9-array_concatenation.c`](9-array_concatenation.c) | Concatenates two arrays into a single one |
| 10 | [`10-string_concatenation.c`](10-string_concatenation.c) | Joins two words into one string |
| 11 | [`11-butterfly_alphabet.c`](11-butterfly_alphabet.c) | Rewrites a sentence by wrapping every vowel as vowel + `f` + vowel |
| 12 | [`12-fibonacci.c`](12-fibonacci.c) | Prints the first *n* numbers of the Fibonacci sequence |
| 13 | [`13-Padovan_sequence.c`](13-Padovan_sequence.c) | Prints the first *n* numbers of the Padovan sequence |
| 14 | [`14-Floyd_triangle.c`](14-Floyd_triangle.c) | Prints Floyd's triangle with a chosen number of rows |
| 15 | [`15-look_in_a_table.c`](15-look_in_a_table.c) | Searches a value in a 2D table and returns its coordinates |
| 16 | [`16-employee_check.c`](16-employee_check.c) | Simulates yearly working days of 500 employees and flags those outside the allowed range |
| 17 | [`17-string_inverter.c`](17-string_inverter.c) | Reverses a string using pointers and a struct return value |
| 18 | [`18-string_occurencies.c`](18-string_occurencies.c) | Counts how many times each character appears up to a given position |
| 19 | [`19-almost_equals.c`](19-almost_equals.c) | Checks whether two words are equal or differ by one swap of adjacent characters |
| 20 | [`20-shrink_string.c`](20-shrink_string.c) | Keeps only the first occurrence of each character in a string, with two different implementations |
| 21 | [`21-anagrams.c`](21-anagrams.c) | Checks whether two sentences are anagrams by comparing letter frequencies |
| 22 | [`22-ramp_10.c`](22-ramp_10.c) | Prints the first *k* "ramp 10" numbers (command-line argument), using recursion on the digits |
| 23 | [`23-bucket.c`](23-bucket.c) | A "bucket" struct backed by a dynamically allocated array, filled with integers from input |
| 24 | [`24-search_client.c`](24-search_client.c) | Finds a client by license plate in a text file, checks the credit and updates the file |
| 25 | [`25-even_figures.c`](25-even_figures.c) | Reads a file and checks whether the even digits appear with the same frequency |
| 26 | [`26-anomaly_finder.c`](26-anomaly_finder.c) | Splits a sequence into blocks of *k* numbers and discards the "anomalous" ones (all equal or all different) |
| 27 | [`27-parsimonious_string_binder.c`](27-parsimonious_string_binder.c) | Concatenates two strings into a `malloc`'d string of exactly the needed size |
| 28 | [`28-couple_special_numbers.c`](28-couple_special_numbers.c) | Counts consecutive pairs of even numbers whose product is a perfect square |
| 29 | [`29-dominant_elements.c`](29-dominant_elements.c) | Counts the "dominant" elements of a square matrix |
| 30 | [`30-fill_the_blank.c`](30-fill_the_blank.c) | Recursively replaces every `*` in a string with `0` and `1`, printing all combinations |
| 31 | [`31-file_incremental.c`](31-file_incremental.c) | Extracts characters from a text file at cumulative offsets given by a sequence of numbers |
| 32 | [`32-wordplay.c`](32-wordplay.c) | Replaces every occurrence of a chosen character in a word with another word |
| 33 | [`33-hangman.c`](33-hangman.c) | A console version of the Hangman game |
| 34 | [`34-principal_diagonal.c`](34-principal_diagonal.c) | Checks whether the word on the principal diagonal of a matrix also appears in a row or column |
| 35 | [`35-base_5.c`](35-base_5.c) | Reads base-5 numbers written as words from a file and converts them to decimal, with sum and average |
| 36 | [`36-regular_matrix.c`](36-regular_matrix.c) | Checks whether a matrix of 2D points is "regular" by comparing path lengths along the diagonal, rows and columns |
| 37 | [`37-complete_deck.c`](37-complete_deck.c) | Checks that a file lists every card of a 52-card deck exactly once |
| 38 | [`38-mergesort.c`](38-mergesort.c) | Recursive merge sort on an array of integers |
| 39 | [`39-Caesar_cypher.c`](39-Caesar_cypher.c) | Encrypts a text file with a Caesar cipher and writes the result to a new file |
| 40 | [`40-fasten_words.c`](40-fasten_words.c) | Fastens two words by overlapping their common ending and beginning, then merges overlapping words in a linked list |
| 41 | [`41-MaxTriProd.c`](41-MaxTriProd.c) | Finds the maximum product of three elements of an array and computes its prefix sums |
| 42 | [`42-ramp_of_lists.c`](42-ramp_of_lists.c) | Splits a linked list into a list of increasing runs ("ramps") |
| 43 | [`43-character_removal.c`](43-character_removal.c) | Removes every occurrence of a character from a sentence, returning a new `malloc`'d string |
| 44 | [`44-save_list.c`](44-save_list.c) | Loads a linked list of records (date, temperature, description, vector) from a file and saves it to another file |
| 45 | [`45-decompose_int.c`](45-decompose_int.c) | Lists every way to write an integer as the sum of two different positive integers, using a linked list |
| 46 | [`46-flip_word.c`](46-flip_word.c) | Prints a word as it is and reversed, using recursion |
| 47 | [`47-recursive_strcmp.c`](47-recursive_strcmp.c) | A recursive, case-insensitive version of `strcmp` for alphabetical comparison |
| 48 | [`48-prefix_strings.c`](48-prefix_strings.c) | Recursively checks whether a string is a prefix of another, and shifts a string appending a character |
| 49 | [`49-int_series.c`](49-int_series.c) | Computes the maximum among the first *k* terms of an integer series defined by a recurrence |
| 50 | [`50-tartaglia.c`](50-tartaglia.c) | Prints Tartaglia's (Pascal's) triangle using a recursive binomial coefficient |
| 51 | [`51-tautogram.c`](51-tautogram.c) | Checks whether a sentence is a tautogram (all words start with the same letter) |
| 52 | [`52-disk_drop.c`](52-disk_drop.c) | A console game where you throw disks into holes whose sizes and capacities are loaded from a file |
| 53 | [`53-same_or_not(numbers).c`](53-same_or_not%28numbers%29.c) | Reads numbers with a sliding window and stops when *k* consecutive values are all equal or all different |
| 54 | [`54-list_intersection.c`](54-list_intersection.c) | Splits two linked lists of words into the words they share and the words that appear in only one |
| 55 | [`55-list_occurences.c`](55-list_occurences.c) | Analyses a linked list of integers: consecutive and non-consecutive occurrences, and values appearing at least three times |
## Topics covered

- **Basics:** variables, `printf`/`scanf`, arithmetic
- **Control flow:** `if`, `switch`, `while`, `do-while`, `for` 
- **Arrays:** sorting, concatenation, sequences, 2D tables 
- **Strings:** concatenation, inversion, character counting 
- **Structs and enums:** `typedef`, arrays of structs, structs as parameters and return values 
- **Pointers:** pointer arithmetic on strings 
- **Randomness:** `rand()` and `srand()` 
- **Memory Allocation:** `malloc()`, `calloc()` and `free()`

## Building and running

Every file is a standalone program with its own `main`. From the command line:

```bash
gcc 1-sum_and_average.c -o sum_and_average
./sum_and_average
```

In CLion, each file can be added as its own executable in `CMakeLists.txt`.

## Notes

These programs were written for learning purposes and may contain missing input checks or practices I would avoid today (for example `void main()`). They are kept here as a record of where I started.