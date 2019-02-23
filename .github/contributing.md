## Contributing

> Please note that this project is released with a [Contributor Code of Conduct](code-of-conduct.md). By participating in this project you agree to abide by its terms.

##  See

- [General Rules](#general-rules)
- [All ▲lgorithms Structure](#all-lgorithms-structure)
- [Adding new algorithms](#adding-new-algorithms)
- [Style](#style)
- [Adding Documentation](#adding-documentation)
- [Run it online](#run-it-online)

### General Rules

- As much as possible, try to follow the existing format of markdown and code.

### All ▲lgorithms Structure

> We follow this structure

- Directories and files are all in lower case letter.
- Directories are separated by a minus or hyphen (`-`) following `kebeab-case` style. In libraries this may change to follow the standards of the programming language
- Files are separated by an underscore (`_`) following the `snake_case` style. This could change to follow style standards on some languages like Java where we are using `CamelCase` style.

```
├── sorting
│   │── merge_sort.cpp
│   └── insertion_sort.cpp
├── searches
│   │── binary_search.cpp
│   └── linear_search.cpp
└── math
    ├── third-algorithm.cpp
    └── fourth_algorithm.cpp
```

### Adding new algorithms

- Make your pull requests to be **specific** and **focused**. Instead of contributing "several algorithms" all at once contribute them all one by one separately (i.e. one pull request for "Binary Search", another one
for "Bubble Sort" and so on).
- Describe what you do in code using **comments**.

### Style

We are following the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html), make sure you use it in your algorithms implementations.

If you are lazy to read the Google C++ Style Guide, we already tough about you. You must use the [Tutorial Point Formatter](https://www.tutorialspoint.com/online_c_formatter.htm). **This is only to help you get started, you should double check it again**. See the below example:

##### Important

Use:

```c++
if()
{
}
```

Instead of:

```c++
if() {
}
```

Each `.cpp` file should have the following header

```cpp
//
// Binary search works for a sorted array.
// More documentation about the algorithm
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/
// https://github.com/allalgorithms/cpp
//
// Contributed by: Carlos Abraham Hernandez
// Github: @abranhe
//
#include <iostream>
```

If the algorithm is modified, this should be included there also.

```cpp
// https://github.com/allalgorithms/cpp
//
// Contributed by: Carlos Abraham Hernandez
// Github: @abranhe
//
// Modified by: Your Name
// Github: @yourgithubusername
//
```

If the algorithm have been modified by multiple contributors, that should be included as follow.

```cpp
// https://github.com/allalgorithms/cpp
//
// Contributed by: Carlos Abraham Hernandez
// Github: @abranhe
//
// Modifiers:
// Your Name, @yourgithubusername
// Your friend's name, @yourfriendongithub
//
...
```

C style should be on the [C repository](https://github.com/allalgorithms/c) so:

```cpp
#include <stdio.h>
```

Should not be included, use instead

```cpp
#include <cstdio>
```

### Adding Documentation

Please make sure if you add an algorithm, you also add the required documentation for it on [github.com/abranhe/algorithms](https://github.com/abranhe/algorithms), following the [template](https://github.com/abranhe/algorithms/blob/master/.github/category-template/algorithm-template/readme.md).


### Run it online

On the documentation make sure you add a run it online [Repl.it](https://repl.it/).

If you are modifying an algorithm make sure you add a benchmark using [Repl.it](https://repl.it/).


#### Lastly and not less important:

Make sure you start ⭐️ and follow [@abranhe](https://git.io/abranhe)
