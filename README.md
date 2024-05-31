#Word Range Queries using AVL Trees

##Introduction

This project implements an optimized data structure based on AVL trees for efficient insertion and range queries on large-scale text data. The objective is to handle up to two million operations in under one minute, ensuring high performance and scalability.

##Features

Efficient Insertions: Uses a self-balancing AVL tree to maintain optimal performance for word insertions.
Range Queries: Supports fast range queries by leveraging subtree size, maximum, and minimum value properties stored in AVL tree nodes.
High Performance: Optimized to handle up to two million insertions and queries within one minute.
Custom Algorithm: Implements a custom range query algorithm to achieve logarithmic time complexity.

##Getting Started

###Prerequisites

C++ compiler (e.g., g++)
Make

###Installation

1. Clone the repository:
    sh
    Copy code
    git clone https://github.com/your-username/wordrange-avl.git
    cd wordrange-avl
2. Build the project:
    sh
    Copy code
    make
###Usage

Run the executable with the following command
sh
Copy code
./wordrange <input_file> <output_file>
<input_file>: Path to the input file containing words and queries.
<output_file>: Path to the output file where results will be saved.
Input File Format
Each line of the input file should be one of the following formats:

i <WORD>: Insert the word into the data structure.
r <WORD1> <WORD2>: Count the number of words that are lexicographically between WORD1 and WORD2.
Output File Format
For each range query, the output file will contain the number of words in the specified range, each on a new line.

###Example

Input File (input.txt)
css
Copy code
i apple
i banana
i cherry
r a b
r apple cherry
r banana cherry
Output File (output.txt)
Copy code
2
3
2

###Testing

Run the provided test cases to ensure the correctness and performance of the data structure.

###Provided Test Cases

simple-input.txt, simple-output.txt: Inserts a few numbers to check if basic functionality works correctly.
allwords-basic.txt, allwords-basic-output.txt: Inserts all words from a large dataset and computes a few range queries.
allwords-more-range.txt, allwords-more-range-output.txt: Challenges the code with 1.8 million operations.

###Implementation Details

Data Structure
AVL Tree: A self-balancing binary search tree that maintains its height balanced using rotations.
Node Properties: Each node stores additional properties such as subtree size, maximum, and minimum values to speed up range queries.
Algorithms
Insertion: Inserts words into the AVL tree while maintaining balance.
Range Queries: Efficiently counts the number of words within a specified lexicographical range using subtree properties.

##References

AVL Trees Wikipedia

##License

This project is licensed under the Apache License 2.0. See the LICENSE file for details.

