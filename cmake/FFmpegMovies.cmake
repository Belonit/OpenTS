include(ExternalProject)

find_program(OPENTS_FFMPEG_BASH bash REQUIRED)
find_program(OPENTS_FFMPEG_MAKE make REQUIRED)
set(OPENTS_FFMPEG_BUILD_JOBS 4 CACHE STRING "Parallel jobs used to build FFmpeg")

set(OPENTS_FFMPEG_SOURCE_DIR "${PROJECT_SOURCE_DIR}/thirdparty/ffmpeg")
if(NOT EXISTS "${OPENTS_FFMPEG_SOURCE_DIR}/configure")
    message(FATAL_ERROR
        "thirdparty/ffmpeg is empty. Fetch the submodules with:\n"
        "  git submodule update --init --recursive")
endif()

if(CMAKE_C_COMPILER_ID MATCHES "Clang")
    find_program(OPENTS_FFMPEG_NM llvm-nm REQUIRED)
    set(OPENTS_FFMPEG_AR "${PROJECT_SOURCE_DIR}/cmake/ffmpeg-llvm-lib.sh")
    set(OPENTS_FFMPEG_CROSS_OPTION --enable-cross-compile)

    list(JOIN CMAKE_C_STANDARD_INCLUDE_DIRECTORIES ";" OPENTS_FFMPEG_INCLUDE)
    set(OPENTS_FFMPEG_CC "${CMAKE_BINARY_DIR}/thirdparty/ffmpeg-clang-cl.sh")
    file(WRITE "${OPENTS_FFMPEG_CC}"
        "#!/usr/bin/env bash\n"
        "export INCLUDE='${OPENTS_FFMPEG_INCLUDE}'\n"
        "exec '${CMAKE_C_COMPILER}' /clang:--target=i686-pc-windows-msvc \"$@\"\n")
    file(CHMOD "${OPENTS_FFMPEG_CC}"
        PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE
                    WORLD_READ WORLD_EXECUTE)

    set(OPENTS_FFMPEG_LD "${CMAKE_BINARY_DIR}/thirdparty/ffmpeg-lld-link.sh")
    file(WRITE "${OPENTS_FFMPEG_LD}"
        "#!/usr/bin/env bash\n"
        "exec '${CMAKE_LINKER}' ${CMAKE_EXE_LINKER_FLAGS} \"$@\"\n")
    file(CHMOD "${OPENTS_FFMPEG_LD}"
        PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE
                    WORLD_READ WORLD_EXECUTE)
else()
    get_filename_component(OPENTS_FFMPEG_COMPILER_DIR "${CMAKE_C_COMPILER}" DIRECTORY)
    find_program(OPENTS_FFMPEG_NM dumpbin
        HINTS "${OPENTS_FFMPEG_COMPILER_DIR}"
        REQUIRED)
    set(OPENTS_FFMPEG_AR "${CMAKE_AR}")
    set(OPENTS_FFMPEG_CROSS_OPTION)
    set(OPENTS_FFMPEG_CC "${CMAKE_C_COMPILER}")
    set(OPENTS_FFMPEG_LD "${CMAKE_LINKER}")
endif()

set(OPENTS_FFMPEG_ENV "${CMAKE_COMMAND}" -E env)

set(OPENTS_FFMPEG_CONFIGURE_OPTIONS
    --toolchain=msvc
    ${OPENTS_FFMPEG_CROSS_OPTION}
    --target-os=win32
    --arch=x86_32
    "--cc=${OPENTS_FFMPEG_CC}"
    "--ld=${OPENTS_FFMPEG_LD}"
    "--ar=${OPENTS_FFMPEG_AR}"
    "--nm=${OPENTS_FFMPEG_NM}"
    --disable-x86asm
    --disable-inline-asm
    --disable-programs
    --disable-doc
    --disable-network
    --disable-autodetect
    --disable-everything
    --enable-avformat
    --enable-avcodec
    --enable-avutil
    --enable-swscale
    --enable-swresample
    --disable-avdevice
    --disable-avfilter
    --enable-demuxer=wsvqa
    --enable-demuxer=bink
    --enable-demuxer=matroska
    --enable-decoder=vqa
    --enable-decoder=bink
    --enable-decoder=binkaudio_dct
    --enable-decoder=binkaudio_rdft
    --enable-decoder=adpcm_ima_ws
    --enable-decoder=ws_snd1
    --enable-decoder=pcm_u8
    --enable-decoder=pcm_s16le
    --enable-decoder=vp8
    --enable-decoder=vp9
    --enable-decoder=opus
    --enable-decoder=vorbis
    --enable-static
    --disable-shared
    --enable-small
)

function(opents_add_ffmpeg_movies configuration runtime_flags)
    string(TOLOWER "${configuration}" config_name)
    set(build_dir "${CMAKE_BINARY_DIR}/thirdparty/ffmpeg-movies/${config_name}")
    ExternalProject_Add(FFmpegMovies${configuration}
        PREFIX "${CMAKE_BINARY_DIR}/thirdparty/ffmpeg-movies-${config_name}"
        SOURCE_DIR "${OPENTS_FFMPEG_SOURCE_DIR}"
        BINARY_DIR "${build_dir}"
        CONFIGURE_COMMAND
            ${OPENTS_FFMPEG_ENV}
            "${OPENTS_FFMPEG_BASH}" "${OPENTS_FFMPEG_SOURCE_DIR}/configure"
            ${OPENTS_FFMPEG_CONFIGURE_OPTIONS}
            "--extra-cflags=${runtime_flags}"
        BUILD_COMMAND
            ${OPENTS_FFMPEG_ENV}
            "${OPENTS_FFMPEG_MAKE}" "-j${OPENTS_FFMPEG_BUILD_JOBS}"
        INSTALL_COMMAND ""
        BUILD_BYPRODUCTS
            "${build_dir}/libavformat/avformat.lib"
            "${build_dir}/libavcodec/avcodec.lib"
            "${build_dir}/libavutil/avutil.lib"
            "${build_dir}/libswscale/swscale.lib"
            "${build_dir}/libswresample/swresample.lib"
    )

    foreach(library avformat avcodec avutil swscale swresample)
        add_library(FFmpegMovies${configuration}_${library} STATIC IMPORTED GLOBAL)
        set_target_properties(FFmpegMovies${configuration}_${library} PROPERTIES
            IMPORTED_LOCATION "${build_dir}/lib${library}/${library}.lib"
            INTERFACE_INCLUDE_DIRECTORIES
                "${OPENTS_FFMPEG_SOURCE_DIR};${build_dir}"
        )
        add_dependencies(FFmpegMovies${configuration}_${library} FFmpegMovies${configuration})
    endforeach()
    set_property(TARGET FFmpegMovies${configuration}_avutil PROPERTY
        INTERFACE_LINK_LIBRARIES "$<$<PLATFORM_ID:Windows>:bcrypt>")
endfunction()

get_property(OPENTS_FFMPEG_MULTI_CONFIG GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if(OPENTS_FFMPEG_MULTI_CONFIG)
    opents_add_ffmpeg_movies(Debug "/MTd /Od /Zi")
    opents_add_ffmpeg_movies(Release "/MT /O2")
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    opents_add_ffmpeg_movies(Debug "/MTd /Od /Zi")
else()
    opents_add_ffmpeg_movies(Release "/MT /O2")
endif()
