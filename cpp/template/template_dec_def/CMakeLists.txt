cmake_minimum_required(VERSION 3.0.0)
project(dllStaticTest)

# add source header files directories
include_directories(
	./)

# add source files directories
aux_source_directory(./ SRC)

# add target executable files to be built
add_executable(sample ${SRC})
