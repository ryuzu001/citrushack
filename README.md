Format Buddy
==============
This is a project done at [Citrus Hack 2018](http://citrushack.com). This was a joint collaboration between 
[Ryan Yuzuki](https://github.com/ryuzu001) and [Brandon Tran](https://github.com/regice). The idea came to me during the opening
presentation. They had encouraged us to create projects that would help other people. This project will help
developers write clean code without worring about readability or formatting. It's not perfect - we had 24 hours, after all, but 
it's a good honest effort on an idea we believe has a lot of merit. If we had more time, we would clean up the source code
(ironic, isn't it), squash the remaining bugs, and create a more portable version of the application. (Perhaps supporting
more languages that C++ would be nice too.)


This application was written in C++, as it's a language we're both familliar with and can use effectively. The source code can
be found in `main.cpp`. We had a few files we were using to test, which can be found in the folder `other src`. The tests performed 
can be found in the folder `tests` and the corresponding output in `program output`. Below are the problems that each test case
performs.

_____________________________

`test1` Big general test. Completely spaghetti-fied code that is not easy to read and contains quotations and comments galore.

`test2` A (failed) test that should preserve the spaces in both comments and quotes

`test3` Spaghetti-fied "Hello World" program

`test4` A program with no strings. Only comments, shows a bug with the way comments are handled.

`test5` "Hello World" on one line

`test6` "Hello World" on many lines

`test7` `test8` and `test9` are general catch-all tests. 

`test10.cpp` is a general test, with the case of testing if the outputted file is named correctly as well.

_____________

# Compiling

To compile, run the makefile with `make`. The makefile will generate a program, called `format`. To run `format`, use
the command `./format`.

# Difficulties and Challenges

We ran into the issue of comments. In C++, there are two ways to specify a comment - either with a `//` to start and a newline
character to end, or anything between the characters of `/*      */`. We did attempt to program for the first case, however
this was more difficult than expected in the way we parsed the input file string. In order to preserve comments (Anything
between two `"` characters would be ignored) we went through the file character by character, getting rid of any whitespace.
Whenever we ran into a `"` character, our program finds the next `"` character and continues from there - this way strings 
that contain spaces are still maintained. The difficulty arose when there were many strings and many comments in a file.
Sometimes there were multiple comments before a single string declaration. Other times it was the opposite. We were 
able to initially parse through the file and maintain newline characters after comments. However preserving spaces within
those comments was our downfall. You can check the commented code in `main.cpp` or `test.cpp` to see our attemps at maintaining
both comments and strings.

User Declared types are difficult to maintain. Our code as it stands does not respect user declared types. See this code from
test8_formatted:

    cout << "Enter number of deals (simulations): ";
	cin >> deals;
	cout << endl << endl;
	DecktempDeck;

This should be `Deck tempDeck` due to the user defined `Deck`. This is also evident by the top of test8_formatted as well, 

    #include"Deck.h"#include <ostream>
    #include <vector>

It does not recognize that the `include` operand for `Deck.h` specifies a `Deck`.

In addition, other challenges arose from `for` loops, `do while` loops and `/*     */` type comments.

    for(z = blockEnd;
	z > 0;
	--z){
	
(From test 7 - we programmed for a newline after every `;` character - we did not program for `;` inside loop declarations)


# Bugs

- for loops do not format correctly
- Comment spaces are not preserved, and result in odd formatting (See test4_formatted)
- User defined types are not preserved (See above)
- Multiline comments are ignored
- Including things other than standard classes results in a spacing error
- Use of the `<` or `>` characters can mess with formatting `i < a.size();` or `vector<int> v;`