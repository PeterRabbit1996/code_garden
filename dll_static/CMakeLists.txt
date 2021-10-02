cmake_minimum_required(VERSION 3.0.0)
project(dllStaticTest)

# add source header files directories
include_directories(
	./logger/include
	./sdk/include
	./sample/include)

# add source files directories
aux_source_directory(./logger LOGGER)
aux_source_directory(./sdk SDK)
aux_source_directory(./sample SAMPLE)

# add target librires to be built
add_library(logger STATIC ${LOGGER})
add_library(sdk SHARED ${SDK})

# add target executable files to be built
add_executable(sample ${SAMPLE})

# add depedencies
target_link_libraries(sdk logger)
target_link_libraries(sample sdk)

set(INSTALL_HEAD_FILES ./logger/include/logger.h ./sdk/include/sdk.h)

install(FILES ${INSTALL_HEAD_FILES} DESTINATION include)
install(TARGETS sample sdk logger
        EXPORT TCTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        )