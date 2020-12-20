
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


# third
include_directories(EngineMake "../Code/third")

#dx 12 
include_directories(EngineMake "C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um")
target_link_libraries(EngineMake d3d12.lib)
target_link_libraries(EngineMake dxgi.lib)
target_link_libraries(EngineMake d3dcompiler.lib)


target_compile_features(EngineMake PRIVATE cxx_std_17)