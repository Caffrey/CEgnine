
#
cmake_minimum_required (VERSION 3.8)

project ("EngineMake")


#扫描项目文件
set(ProjectScrCpp "E:/test/Code/src/*.cpp")
set(ProjectScrH "E:/test/Code/src/*.h")
FILE(GLOB_RECURSE SC_FILES ${ProjectScrH} ${ProjectScrCpp})


IF(WIN32)
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS") 
ENDIF(WIN32)


#c++17 
if (MSVC_VERSION GREATER_EQUAL "1900")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
    if (_cpp_latest_flag_supported)
        add_compile_options("/std:c++latest")
    endif()
endif()

add_executable (CEngine ${SC_FILES})


target_compile_features(CEngine PRIVATE cxx_std_17)