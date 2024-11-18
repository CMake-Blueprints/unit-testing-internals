add_executable(mylib_unit_tests)
target_sources(mylib_unit_tests PRIVATE
  # TODO: add source files
  $<TARGET_OBJECTS:mylib>
)

# Copy properties from mylib to ensure compatible object files
set(PROPERTIES_TO_COPY
  COMPILE_DEFINITIONS
  INCLUDE_DIRECTORIES
)
foreach(PROPERTY IN LISTS PROPERTIES_TO_COPY)
  set_property(TARGET mylib_unit_tests APPEND PROPERTY
    ${PROPERTY} $<TARGET_PROPERTY:mylib,${PROPERTY}>
  )
endforeach()

add_test(NAME unit_tests COMMAND mylib_unit_tests)
