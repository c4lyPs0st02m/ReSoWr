# ReSoWr

ReSoWr (Read Sort Write) - designed to read multiple input files, sort their contents in lexicographical order, and write it in a single output file.

## Description

ReSoWr is the equivalent of the command "cat file1 file2 .. fileN | sort > output.txt" in Linux, written in C++. It works with default input files (file1.txt, .., file5.txt) and with input files directly provided by the user. The lexicographical sorting of the contents of the input files is realized using the Merge Sort algorithm.

## Installation

1) Get a clone of a repository.
2) Go to AddDLLFiles folder, copy .dll files and paste them directly into the ReSoWr folder.
3) Go to ReSoWr folder and run ReSoWr.exe file.
4) Enjoy! :)

Note: The present output.txt file contains sorted contents of all of the provided default input files.

### Requirements

Programming language: C++ (GCC 8.1.0 and higher);
OS: Windows 10 x64;
Additional files (you can find them in the AddDLLFiles folder): libgcc_s_seh-1.dll, libstdc++-6.dll, libwinpthread-1.dll.

## License

[MIT](https://choosealicense.com/licenses/mit/)
Copyright 2022 Viola Mazurenko All Rights Reserved.
