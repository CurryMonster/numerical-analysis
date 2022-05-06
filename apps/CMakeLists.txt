add_executable(app app.cpp)

target_compile_features(app PUBLIC cxx_std_17)

target_include_directories(app PUBLIC Matrix)

target_link_libraries(app PUBLIC Matrix)