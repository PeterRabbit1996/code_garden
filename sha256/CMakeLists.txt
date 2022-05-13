set(PROJECT_NAME "sha256")
cmake_minimum_required(VERSION 3.0)
project(${PROJECT_NAME})

# set(CMAKE_CXX_STANDARD 11)
add_definitions(-std=c++11)

# add source header files directories
include_directories(
	./src/include)

# add source files directories
aux_source_directory(./src SRC)

# add target executable files to be built
add_executable(${PROJECT_NAME} ${SRC})

# set(INSTALL_HEAD_FILES ./logger/include/logger.h ./sdk/include/sdk.h)

# install(FILES ${INSTALL_HEAD_FILES} DESTINATION include)
# install(TARGETS sample sdk logger
#         EXPORT TCTargets
#         LIBRARY DESTINATION lib
#         ARCHIVE DESTINATION lib
#         RUNTIME DESTINATION bin
#         )
