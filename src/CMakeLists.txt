add_library(Matrix STATIC "matrix.cpp" "matrix.h")

target_include_directories(Matrix PUBLIC ${numerical-analysis_SOURCE_DIR}/src)

target_compile_features(Matrix PUBLIC cxx_std_17)