set(SRC
    main.cpp
    main.js
)
add_executable(Installer WIN32 ${SRC} ${COMMON})

target_include_directories(Installer PRIVATE ../Common)
set_property(TARGET Installer PROPERTY VS_DPI_AWARE "PerMonitor")
set_property(TARGET Installer PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_definitions(Installer PRIVATE $<$<CONFIG:Debug>:UNICODE DEBUG NOMINMAX _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS SK_DEBUG WIN32 WINDOWS>)
target_compile_definitions(Installer PRIVATE $<$<CONFIG:Release>:UNICODE NDEBUG NOMINMAX _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS SK_RELEASE WIN32 WINDOWS>)
TARGET_LINK_LIBRARIES(Installer skia modules__bentleyottmann modules__skcms modules__skottie modules__skresources modules__sksg modules__skshaper modules__svg pathkit third_party__expat third_party__harfbuzz third_party__libjpeg-turbo_libjpeg third_party__libpng third_party__libwebp third_party__libwebp_libwebp_sse41 third_party__wuffs third_party__zlib third_party__zlib_compression_utils_portable libuv qjs dwmapi winmm kernel32 user32 shell32 imm32 gdi32 usp10 ws2_32 dbghelp userenv iphlpapi)
