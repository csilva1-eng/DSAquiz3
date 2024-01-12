# codespaces info
This is a C++ codespaces image that also includes a systemwide installation of catch 2 v3.4.0. 

To use this yourself (clone the codespace??? will have to look into)

#TODO - summarize the below into a series of concrete steps for students

See the CMakeTools documentation for information on how to use it: https://code.visualstudio.com/docs/cpp/cmake-linux

## Important Instructions (from initial project document, will need updating for the new paradigm)

1. You can code your project in *src* directory. Feel free to create any header files and cpp files for your implementation. 

2. You are recommended to test your own code by building unit tests in *test-unit/test.cpp*
    - To run the tests, use the following command, 
        `g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test`
    - You will have to comment main() when unit testing your code because catch uses its own main().

3. You will submit the all files in src folder on Gradescope to test your code. If you are using multiple header files, you will have to include them directly in main.cpp once you are done with all your testing. **Remember, your code must pass tests on Gradescope to receive credit.**

4. Instructions on how to test io based tests through command line are given in *test-io/readme-io.md*.