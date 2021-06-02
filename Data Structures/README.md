## Running the files using CMake (on Mac)
10
​
11
- Add CMake to the path variable by running the following command in the Terminal:
12
  ```
13
  PATH="/Applications/CMake.app/Contents/bin":"$PATH
14
  ```
15
  
16
- Then, generate the build and configuration files (it uses the CMakeLists.txt file that enlists the the source, targets and executables) with this command:
17
​
18
  ```
19
  cmake .
20
  ```
21
  
22
- This should create all the necessary configuration files and the executable. Each ADT should have a "unittests.cpp" file that tests the ADT and by running the   ```make``` command, the executable for this "unittests" file is created.
23
​
24
- Then run the generated executable. So, you should technically be running ```./unittests```. This runs and checks if all the unit test cases have passed as required.
25
​
