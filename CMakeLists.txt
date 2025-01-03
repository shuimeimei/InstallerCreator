cmake_minimum_required(VERSION 3.18)
project(InstallerCreator)
include(Common/CMakeLists.txt)
add_definitions(-DUNICODE -D_UNICODE) # 添加UNICODE编译选项
add_definitions(-DNOMINMAX) #修正skia使用std::min的编译问题
set(SKIA_INCLUDE_PATH "d:\\code\\public\\third_party\\skia_m132" CACHE PATH "Skia include path,default:D:/sdk/skia" FORCE)

if(NOT IS_DIRECTORY "${SKIA_INCLUDE_PATH}")
    message(FATAL_ERROR "The path ${SKIA_INCLUDE_PATH} does not exist.")
endif()

set(SKIA_LIB_PATH "d:\\code\\public\\third_party\\skia_m132\\lib\\x64-Debug" CACHE PATH "Skia lib path,default:D:/sdk/skia/out" FORCE)

if(NOT IS_DIRECTORY "${SKIA_LIB_PATH}")
    message(FATAL_ERROR "The path ${SKIA_LIB_PATH} does not exist.")
endif()

set(QUICKJS_INCLUDE_PATH "D:\\code\\quickjs" CACHE PATH "QuickJS include path,default:D:/sdk/quickjs" FORCE)

if(NOT IS_DIRECTORY "${QUICKJS_INCLUDE_PATH}")
    message(FATAL_ERROR "The path ${QUICKJS_INCLUDE_PATH} does not exist.")
endif()

set(QUICKJS_LIB_PATH "D:\\code\\quickjs\\out\\build\\x64-Debug" CACHE PATH "Skia lib path,default:D:/sdk/quickjs/build" FORCE)

if(NOT IS_DIRECTORY "${QUICKJS_LIB_PATH}")
    message(FATAL_ERROR "The path ${QUICKJS_LIB_PATH} does not exist.")
endif()

set(LIBUV_INCLUDE_PATH "D:\\code\\libuv\\include" CACHE PATH "QuickJS include path,default:D:/sdk/libuv/include" FORCE)

if(NOT IS_DIRECTORY "${LIBUV_INCLUDE_PATH}")
    message(FATAL_ERROR "The path ${LIBUV_INCLUDE_PATH} does not exist.")
endif()

set(LIBUV_LIB_PATH "D:\\code\\libuv\\out\\build\\x64-Debug" CACHE PATH "Skia lib path,default:D:/sdk/libuv/build" FORCE)

if(NOT IS_DIRECTORY "${LIBUV_LIB_PATH}")
    message(FATAL_ERROR "The path ${LIBUV_LIB_PATH} does not exist.")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "/utf-8")
set(CMAKE_C_FLAGS "/utf-8")
link_directories("${SKIA_LIB_PATH};${QUICKJS_LIB_PATH};${LIBUV_LIB_PATH};")
include_directories("${SKIA_INCLUDE_PATH};${QUICKJS_INCLUDE_PATH};${LIBUV_INCLUDE_PATH};")

add_subdirectory(Common)
add_subdirectory(Installer)
add_subdirectory(InstallerCreator)
add_subdirectory(Uninstaller)
