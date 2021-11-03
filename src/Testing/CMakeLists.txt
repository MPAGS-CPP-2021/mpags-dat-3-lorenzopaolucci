# - Build for testing of MPAGSCipher library

add_executable(testHello testHello.cpp)
add_test(NAME test-hello COMMAND testHello)

# - Create Interface Library for Catch
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_compile_features(Catch INTERFACE cxx_noexcept)

# - Catch based test
add_executable(testCatch testCatch.cpp)
target_link_libraries(testCatch Catch)
add_test(NAME test-catch COMMAND testCatch -s)

# - TransformChar test
add_executable(testTransformChar testTransformChar.cpp)
target_link_libraries(testTransformChar MPAGSCipher Catch)
add_test(NAME test-transformChar COMMAND testTransformChar)

# - ProcessCommandLine test 
add_executable(testProcessCommandLine testProcessCommandLine.cpp)
target_link_libraries(testProcessCommandLine MPAGSCipher Catch)
add_test(NAME test-ProcessCommandLine COMMAND testProcessCommandLine)

# - CaesarCipher class test 
add_executable(testCaesarCipher testCaesarCipher.cpp)
target_link_libraries(testCaesarCipher MPAGSCipher Catch)
add_test(NAME test-CaesarCipher COMMAND testCaesarCipher)