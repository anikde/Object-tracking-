cmake_minimum_required(VERSION 3.7)
project(obb_detect)

#set(CMAKE_CXX_STANDARD 11)

set(EXE_NAME "runn")

find_package( OpenCV REQUIRED )
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${OpenCV_INCLUDE_DIR}
)

file(GLOB HEADER_FILES ./include/*.h)

file(GLOB SOURCES ./*.cpp)

add_executable(${EXE_NAME} ${SOURCES} ${HEADER_FILES})

set_target_properties(
        ${EXE_NAME}
        PROPERTIES
        POSITION_INDEPENDENT_CODE ON
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)


target_link_libraries(
        ${EXE_NAME}
        ${OpenCV_LIBS}
)

#set(SOURCE_FILES main.cpp)
#add_executable(obb_detect ${SOURCE_FILES})