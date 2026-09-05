add_executable(MovieScheduler
    movieschedulertest.cpp
)

target_include_directories(MovieScheduler PRIVATE ${CMAKE_SOURCE_DIR}/code)
target_compile_features(MovieScheduler PRIVATE cxx_std_20)

add_test(NAME movie_scheduler COMMAND MovieScheduler)
