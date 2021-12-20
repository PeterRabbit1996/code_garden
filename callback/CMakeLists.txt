cmake_minimum_required(VERSION 3.0.0)
project(dllStaticTest)

add_definitions(-std=c++11)

# add source header files directories
include_directories(
	./Player/include
	./sdk/include
	./sample/include)

# add source files directories
aux_source_directory(./Player PLAYER)
aux_source_directory(./sdk SDK)
aux_source_directory(./sample SAMPLE)

# add target librires to be built
add_library(PLAYER STATIC ${PLAYER})
add_library(sdk SHARED ${SDK})

# add target executable files to be built
add_executable(sample ${SAMPLE})

# add depedencies
target_link_libraries(sdk PLAYER)
target_link_libraries(sample sdk)
