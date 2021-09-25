cmake_minimum_required(VERSION 3.0.0)
project(sample)

# add source header files directories
include_directories(./include)

# add source files directories
aux_source_directory(./src SRC)

# add target librires to be built
# add_library()

# add target executable files to be built
add_executable(sample ${SRC})

# add depedencies
# target_link_libraries()
