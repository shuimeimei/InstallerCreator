set(SRC
    main.cpp
)
add_executable(InstallerCreator WIN32 ${SRC} ${COMMON})
target_include_directories(InstallerCreator PRIVATE ../Common)
TARGET_LINK_LIBRARIES(InstallerCreator skia modules__bentleyottmann modules__skcms modules__skottie modules__skresources modules__sksg modules__skshaper modules__svg pathkit third_party__expat third_party__harfbuzz third_party__libjpeg-turbo_libjpeg third_party__libpng third_party__libwebp third_party__libwebp_libwebp_sse41 third_party__wuffs third_party__zlib third_party__zlib_compression_utils_portable libuv qjs dwmapi winmm kernel32 user32 shell32 imm32 gdi32 usp10 ws2_32 dbghelp userenv iphlpapi)
