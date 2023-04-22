To compile the files needed for the reference BLAS you need the following files:

refBLAS.hpp
level1.cpp
level1.hpp
level2.cpp
level2.hpp
level3.cpp
level3.cpp
problem6.cpp

Step 1. compile each of the leveled functions by creating the object file levelX.o where X is the level number.

Do this step using the below command in a bash terminal for all three levels:
g++ -c -fPIC levelX.cpp -o levelX.o

Step 2. Consolidate in shared library called librefBLAS.so using the following command: 
g++ -shared -o librefBLAS.so level1.o level2.o level3.o

Step 3. Link the "main" file (in this case problem6.cpp) to the library using:
g++ -o xrefmain refmain.cpp -L. librefBLAS.so

Step 4. Run using ./xproblem6. For speed, I used the experiments from the previous problem to test the library but with n<=10 for levels 2 and 3 to save time. 
