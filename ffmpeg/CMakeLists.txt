cmake_minimum_required(VERSION 3.0.0)
project(ffmpegStudy)
# set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-lbz2 -liconv -framework OpenGL -framework AppKit -framework Security -framework CoreFoundation -framework CoreVideo -framework CoreMedia -framework QuartzCore -framework CoreFoundation -framework VideoDecodeAcceleration -framework Cocoa -framework AudioToolbox -framework VideoToolbox -framework OpenCL")

# add source header files directories
# include_directories()

# add source files directories
# aux_source_directory()

# add target librires to be built
# add_library()

# add target executable files to be built
# add_executable()

# add depedencies
# target_link_libraries()



# Find all main*.cpp files and store in list mains

# some options / settings
# ... #

# some 3rd-party/customed include/link path
include_directories (../libs/ffmpeg/include/)
link_directories(../libs/ffmpeg/lib)

# add external libraries
set (EXTRA_LIBS ${EXTRA_LIBS} z iconv lzma avcodec avdevice avfilter avformat avutil swresample swscale)

aux_source_directory (. SRC_LIST)

# get source files holding main() function
execute_process (
	COMMAND echo ${SRC_LIST}
	COMMAND xargs egrep "main[ \t]*(.*)[ \t]*$" -l
	WORKING_DIRECTORY ..                      # NOTICE: Assumed build directory is ${SOURCE_DIR}/build, so 
# You may change the value of WORKING_DIRECTORY to suit your needs
	OUTPUT_VARIABLE TARGET_LIST
)
string (REGEX REPLACE "\n$" "" TARGET_LIST ${TARGET_LIST})

# count number of targets
execute_process (
	COMMAND echo ${TARGET_LIST}
	COMMAND wc -l
	OUTPUT_VARIABLE TARGET_NUM
)

# convert string from "./$1\n./$2\n..." to "$1 $2 ..."
string (REGEX REPLACE "[.]/" "" TARGET_LIST ${TARGET_LIST})
string (REGEX REPLACE "\n" " " TARGET_LIST ${TARGET_LIST})

enable_testing ()
foreach (i RANGE 1 ${TARGET_NUM})
	execute_process (
		COMMAND echo "${TARGET_LIST}"
		COMMAND cut -d " " -f ${i}
		OUTPUT_VARIABLE SRC
	)
	string (REGEX REPLACE "\n" "" SRC ${SRC})
	string (REGEX REPLACE "[.]cpp$" "" ELF ${SRC})
	add_executable (${ELF} ${SRC})
	target_link_libraries (${ELF} ${EXTRA_LIBS})
	add_test (${ELF}_Runs ${ELF})
endforeach (i)

# do sth more, like add more tests...#
