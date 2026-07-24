# Mini Grep 

A small command-line text search utility written in modern C++17.

It works much like the Unix `grep` command. Given a keyword and a file, it scans the file line by line and prints every matching line. The implementation keeps memory usage low by streaming the file instead of loading it all at once.

## What this project explores

This project was mainly built to practice a few core C++ and systems programming concepts:

* **Move semantics (`std::move`)** for transferring string ownership without unnecessary copies.
* **`std::string_view`** for working with text without allocating new strings.
* **Const correctness and references** to avoid accidental copies while keeping interfaces clear.
* **File streaming with `std::ifstream`** so large files are processed one line at a time instead of being read entirely into memory.
* **Separation of responsibilities**, with searching, file handling, and program flow split into different components.

## Project structure

```text
.
├── TextSearcher.hpp    # search logic
├── FileReader.hpp      # file reading
├── main.cpp            # entry point
└── README.md
```

## Building

You'll need a compiler with C++17 support (GCC, Clang, or MSVC).

Compile the project with:

```bash
g++ -std=c++17 -Wall -Wextra -O2 main.cpp -o minigrep
```

`-O2` enables compiler optimizations while keeping compile times reasonable.

## Usage

Pass the search term first, followed by the file you want to search.

```bash
./minigrep "search_term" path/to/file.txt
```

Example:

```bash
./minigrep "string" FileReader.hpp
```

## Example output

```cpp
#include <string>
#include <string_view>
std::vector<std::string> search_in_file(std::string_view file_path,const TextSearcher& searcher) {
std::vector<std::string> results;
std::string current_line;
```
