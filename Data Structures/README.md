## Running the files using CMake (on Mac)

- Add CMake to the path variable by running the following command in the Terminal:
  ```
  PATH="/Applications/CMake.app/Contents/bin":"$PATH
  ```
  
- Then, generate the build and configuration files (it uses the CMakeLists.txt file that enlists the the source, targets and executables) with this command:

  ```
  cmake .
  ```
  
- This should create all the necessary configuration files and the executable. Each ADT should have a "unittests.cpp" file that tests the ADT and by running the   ```make``` command, the executable for this "unittests" file is created.

- Then run the generated executable. So, you should technically be running ```./unittests```. This runs and checks if all the unit test cases have passed as required.
