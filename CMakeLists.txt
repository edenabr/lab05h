cmake_minimum_required(VERSION 3.10)

project(lab05h)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" ON)

add_subdirectory(banking)

if(BUILD_TESTS)
  enable_testing()

  set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

  add_subdirectory(third-party/gtest)

  if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    foreach(_target gtest gtest_main gmock gmock_main)
      if(TARGET ${_target})
        target_compile_options(${_target} PRIVATE -Wno-error)
      endif()
    endforeach()
  endif()

  set(TEST_SOURCES
      tests/test_account.cpp
      tests/test_transaction.cpp
  )

  add_executable(check ${TEST_SOURCES})

  target_link_libraries(check
      banking
      gtest_main
      gmock
  )

  add_test(NAME check COMMAND $<TARGET_FILE:check>)
endif()
