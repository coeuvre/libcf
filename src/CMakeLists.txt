file(GLOB libcf_source_files "*.c")
file(GLOB libcf_public_header "${libcf_SOURCE_DIR}/include/cf/*.h")

include_directories(${libcf_SOURCE_DIR}/include)

add_library(libcf STATIC ${libcf_source_files})
set_target_properties(libcf PROPERTIES OUTPUT_NAME cf)
