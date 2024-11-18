# Unit Testing of Internal Functions

This project showcases how to reuse the compiled object files of a library for C/C++ unit tests. This avoids needing to expose these implementation details while avoiding unnecessary recompilation of the library code.

Note that the object files used in the test still need to be linked a second time.

## Key Points

- The `mylib_unit_test` target specifies `$<TARGET_OBJECTS:mylib>` as a source file, which expands to the full list of object files of the `mylib` target.

- The compile definitions and include directories of the `mylib` target are manually added to the `mylib_unit_test` target.

    This ensures that private headers are found and eliminates warnings related to importing local symbols (e.g. [LNK4049](https://learn.microsoft.com/en-us/cpp/error-messages/tool-errors/linker-tools-warning-lnk4049?view=msvc-170), [LNK4217](https://learn.microsoft.com/en-us/cpp/error-messages/tool-errors/linker-tools-warning-lnk4217?view=msvc-170) on MSVC).

- Finally, the `mylib/src` directory is explicitly added to the `PRIVATE` include directories of the `mylib` target.

    This normally would not be necessary, but is required for the `mylib_unit_test` target to be able to locate the private headers.

These changes are generally sufficient even when additional dependencies are required by the library being tested. Depending on the complexity of your project, you may need to match additional target properties from the `mylib` target.

It can also be helpful to introduce an `INTERFACE` target in front of the library and test to ensure the same properties are applied to both.

## Project Structure

- `mylib/include`: Public header files of the library
- `mylib/src`: Implementation header and source files
- `mylib/tests`: Unit tests for the library (reuses the  existing object files)
- `tests`: Integration tests for the library (links against the regular library)

## Building the Project

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Running the Tests

```bash
ctest
```
