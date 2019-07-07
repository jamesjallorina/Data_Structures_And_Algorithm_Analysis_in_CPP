# To compile this with cmake 
# 1. Go to path=<source_path>
# 2. Create a build directory outside the source directory
# 3. Following are the steps to compile
#	a. mkdir build
#	b. cd build
#	c. cmake ../<source_path>
#	d. make
# The final executable is in the build directory <source_path>
project(test_list)

add_executable(test_list test_list.cxx)
