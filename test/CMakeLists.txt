ADD_SUBDIRECTORY(gtest-1.7.0)

ENABLE_TESTING()

INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

ADD_EXECUTABLE(runTests ParserTests.cpp)

TARGET_LINK_LIBRARIES(runTests gtest gtest_main)

TARGET_LINK_LIBRARIES(runTests graphqlparser)

ADD_TEST(gtest_tests runTests)
