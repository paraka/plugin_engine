cmake_minimum_required(VERSION 2.8)

project (Example)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
   message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

set(CMAKE_SHARED_LINKER_FLAGS "-ldl")
set(CMAKE_EXE_LINKER_FLAGS "-ldl")

link_directories(${CMAKE_BINARY_DIR}/../Engine/)
add_library(LIB_ENGINE SHARED IMPORTED)
set_target_properties(LIB_ENGINE PROPERTIES IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/../../Engine/libEngine.so)
add_dependencies(LIB_ENGINE Example)
add_executable(App App.cpp)
target_link_libraries(App LIB_ENGINE)
