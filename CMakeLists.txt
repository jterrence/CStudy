cmake_minimum_required(VERSION 3.6)
project(CStudy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


SET(EXECUTABLE_OUTPUT_PATH ${CStudy_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${CStudy_SOURCE_DIR}/lib)
SET(RUNTIME_OUTPUT_DIRECTORY ${CStudy_SOURCE_DIR}/bin)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CStudy_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CStudy_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CStudy_SOURCE_DIR}/bin)

#设置include目录
SET(CStudyIncludes ${CStudy_SOURCE_DIR}/rvalue/include
        ${CStudy_SOURCE_DIR}/construct/include
        ${CStudy_SOURCE_DIR}/move/include
        ${CStudy_SOURCE_DIR}/lambda/include
        ${CStudy_SOURCE_DIR}/function/include
        ${CStudy_SOURCE_DIR}/thread/include)
#添加子目录
add_subdirectory(rvalue)
add_subdirectory(construct)
add_subdirectory(move)
add_subdirectory(lambda)
add_subdirectory(function)
add_subdirectory(thread)

INCLUDE_DIRECTORIES(
        ${CStudyIncludes}
)
aux_source_directory(. DIR_SRCS)
add_executable(CStudy ${DIR_SRCS})
target_link_libraries(CStudy rvalue construct move lambda function thread)