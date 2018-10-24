IF(UNIX)
  ADD_SUBDIRECTORY(googletest-release-1.8.0/googletest)
  INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
ELSEIF(WIN32)
  FIND_PACKAGE(GTest REQUIRED)
ENDIF()

ENABLE_TESTING()

FILE(COPY valgrind.supp DESTINATION .)

FILE(COPY kitchen-sink.graphql DESTINATION .)

FILE(COPY kitchen-sink.json DESTINATION .)

FILE(COPY schema-kitchen-sink.graphql DESTINATION .)

FILE(COPY schema-kitchen-sink.json DESTINATION .)

ADD_EXECUTABLE(runTests ParserTests.cpp JsonVisitorTests.cpp BuildCAPI.c)

IF(UNIX)
  TARGET_LINK_LIBRARIES(runTests gtest gtest_main)
ELSEIF(WIN32)
  TARGET_LINK_LIBRARIES(runTests GTest::GTest GTest::Main)
ENDIF()

TARGET_LINK_LIBRARIES(runTests graphqlparser)

ADD_TEST(gtest_tests runTests)
