#include "../googletest/googlemock/include/gmock/gmock.h"

long long toDoTask5(long long , long long , std::string, std::string);

TEST(Task5, Test1) {
    std::string s1 = "a", s2 = "b";
    ASSERT_EQ(toDoTask5(100000000L, 10000L, s1, s2), 1152);
}

TEST(Task5, Test2) {
    std::string s1 = "a", s2 = "a";
    ASSERT_EQ(toDoTask5(100000000L, 10000L, s1, s2), 576);
}

TEST(Task5, Test3) {
    std::string s1 = "ab", s2 = "ba";
    ASSERT_EQ(toDoTask5(100000000L, 10000L, s1, s2), 3552);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}