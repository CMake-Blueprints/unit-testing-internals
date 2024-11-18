add_executable(mylib_integration_tests) # TODO: Add source files
target_link_libraries(mylib_integration_tests PRIVATE mylib)

add_test(NAME integration_tests COMMAND mylib_integration_tests)
