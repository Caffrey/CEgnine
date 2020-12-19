
#
cmake_minimum_required (VERSION 3.8)

project ("EngineMake")


#扫描项目文件
set(ProjectScrCpp "../Code/src/*.cpp")
set(ProjectScrH "../Code/src/*.h")
FILE(GLOB_RECURSE SC_FILES ${ProjectScrH} ${ProjectScrCpp})


IF(WIN32)
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS") 
ENDIF(WIN32)


add_executable (EngineMake ${SC_FILES})


target_compile_features(EngineMake PRIVATE cxx_std_17)