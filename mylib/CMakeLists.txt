add_library(mylib)

include(GenerateExportHeader)
generate_export_header(mylib
  EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/include/mylib/export.h
)

target_sources(mylib
  PUBLIC FILE_SET HEADERS
  BASE_DIRS include ${CMAKE_CURRENT_BINARY_DIR}/include
  FILES
    # TODO: Add public header files
    ${CMAKE_CURRENT_BINARY_DIR}/include/mylib/export.h
  PRIVATE
    # TODO: Add private header and source files
)
target_include_directories(mylib PRIVATE src)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
