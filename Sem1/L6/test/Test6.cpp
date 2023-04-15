#include "../googletest/googlemock/include/gmock/gmock.h"

long long toDoTask6(std::string&);

TEST(Task6, Test1) {
    std::string s1 = "qWeRtYuIoPaSdF";
    ASSERT_EQ(toDoTask6(s1), 87178291200L);
}

TEST(Task6, Test2) {
    std::string s2 = "qwwwttuiopasdf";
    ASSERT_EQ(toDoTask6(s2), 7264857600L);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}