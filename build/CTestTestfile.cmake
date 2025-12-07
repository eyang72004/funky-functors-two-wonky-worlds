# CMake generated Testfile for 
# Source directory: C:/Users/eyang/Downloads/funkyFunctorsAttempt
# Build directory: C:/Users/eyang/Downloads/funkyFunctorsAttempt/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[functor_laws_tests]=] "C:/Users/eyang/Downloads/funkyFunctorsAttempt/build/Debug/functor_laws_tests.exe")
  set_tests_properties([=[functor_laws_tests]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/eyang/Downloads/funkyFunctorsAttempt/CMakeLists.txt;42;add_test;C:/Users/eyang/Downloads/funkyFunctorsAttempt/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[functor_laws_tests]=] "C:/Users/eyang/Downloads/funkyFunctorsAttempt/build/Release/functor_laws_tests.exe")
  set_tests_properties([=[functor_laws_tests]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/eyang/Downloads/funkyFunctorsAttempt/CMakeLists.txt;42;add_test;C:/Users/eyang/Downloads/funkyFunctorsAttempt/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[functor_laws_tests]=] "C:/Users/eyang/Downloads/funkyFunctorsAttempt/build/MinSizeRel/functor_laws_tests.exe")
  set_tests_properties([=[functor_laws_tests]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/eyang/Downloads/funkyFunctorsAttempt/CMakeLists.txt;42;add_test;C:/Users/eyang/Downloads/funkyFunctorsAttempt/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[functor_laws_tests]=] "C:/Users/eyang/Downloads/funkyFunctorsAttempt/build/RelWithDebInfo/functor_laws_tests.exe")
  set_tests_properties([=[functor_laws_tests]=] PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/eyang/Downloads/funkyFunctorsAttempt/CMakeLists.txt;42;add_test;C:/Users/eyang/Downloads/funkyFunctorsAttempt/CMakeLists.txt;0;")
else()
  add_test([=[functor_laws_tests]=] NOT_AVAILABLE)
endif()
