# Tries

## Definition

A trie (or prefix tree) is a tree structure that holds a set of strings.  Trie nodes hold single characters, and a single root node holds the empty string (or nullptr).  Terminal nodes mark the end of the string.  Child nodes share a common prefix with a parent node.  

Tries are often used for quick and efficient storage of strings.  Their real-world applications include text autocomplete, spell checking, and dictionary/search programs.


## Project Goals

This project begins with a basic trie implementation and standard insert, remove, and search functions.  There are additional functions (word instances, replace all, Scrabble functions) that offer examples of trie uses and functionality as a data structure.


## Project Structure

The project files consist of the following:
* tries.h (header file)
* tries.cpp (main code)
* trie_tests.cpp (main code tests)
* scrabble.cpp (additional Scrabble-focused functions)
* scrabble_tests.cpp (Scrabble function tests)
* input.txt (used to test replace all)
* output.txt (used to test replace all)
* sample.txt (used to test word instance search)
* twl06.txt (dictionary file for Scrabble functions, found on freescrabbledictionary.com)
* two executables for test files


## Compilation Instructions

# Core Trie Functions
g++ -o test_program tries.cpp trie_tests.cpp

# Scrabble Functions
g++ -o test_scrabble tries.cpp scrabble.cpp scrabble_tests.cpp


## Walkthrough

1. tries.h
The header file defines the trie_node struct used throughout the program.  It consists of a fixed array of pointers, size 26 (the English alphabet) and a bool variable, end_of_word, which marks the end of a string.

The Trie class is defined next with several private helper functions as well as the public functions referenced above.  Finally, there is a standalone input validation function outside of the Trie class.

2. tries.cpp
The main trie code first checks for valid input using the input validation helper function and returns a bool.  Valid input must not be the empty string ("") or outside of the range of lowercase letters as defined by ASCII values.  

Following the trie constructor and destructor (and its trie deletion helper function), the core functions, insert, search, prefix search, and remove, are defined.  Insert processes the given word by character to determine its placement within the trie.  Search and prefix search also process the given word by letter; search takes note of the end of the word, while prefix search disregards this bool value (prefixes are shorter than words).  Remove utilizes a helper function that determines whether or not a node has children.  This is a factor in determining whether or not a particular node can be safely deleted (nodes with children cannot be deleted).  

There are two additional functions in this file: word_instances, which merely tallies the number of times a particular word appears in a text file, and replace_all, which can be used to make bulk edits to a text file by changing all instances of a specific word at once.  Both functions utilize strict interpretation of input, so punctuation and capitalization must be accounted for.

3. trie_tests.cpp
This test file tests all of the core functions (insert, search, prefix search, and remove) as well as the additional word instances and replace all functions.  It utilizes both the sample.txt file and the input.txt and output.txt files.  

4. scrabble.cpp
These functions aim to offer some utility to players of the word game, Scrabble.  They are in a separate file from the other functions in order to more clearly distinguish this very large trie containing all valid Scrabble words from smaller tries and trie operations.  

The program must first load the dictionary that contains all valid words that can be played in Scrabble.  This list is the file twl06.txt.  There is a basic word validation function (valid_word) which checks input against the dictionary.  The main function, find_words, takes a string of random letters (or a word) and returns all matching dicitionary words that can be formed from those letters.  It does this with the use of a helper function (generate_combinations) and recursion.  After validating input, the function iterates through the given string and tries out all possible combinations of letters by using substrings.  Each possible word is validated in the recursion.  Valid words are stored in a vector of strings, and this vector is returned when the function terminates.  

5. scrabble_tests.cpp 
These tests first check input against the given dictionary text file, demonstrating that input is only valid if the word consists of at least two letters, the letters of the word are lowercase, and that the word exists in the English language.  Find_words is tested first with a two letter string, then a three letter string, and finally a string of eight letters that spell many valid words.  

