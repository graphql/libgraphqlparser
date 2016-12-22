ADD_SUBDIRECTORY(googletest-release-1.8.0/googletest)

ENABLE_TESTING()

INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

FILE(COPY valgrind.supp DESTINATION .)

ADD_EXECUTABLE(runTests ParserTests.cpp JsonVisitorTests.cpp BuildCAPI.c)

TARGET_LINK_LIBRARIES(runTests gtest gtest_main)

TARGET_LINK_LIBRARIES(runTests graphqlparser)

ADD_TEST(gtest_tests runTests)
