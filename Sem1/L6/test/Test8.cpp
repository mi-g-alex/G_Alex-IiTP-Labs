#include "../googletest/googlemock/include/gmock/gmock.h"

std::string toDoTask8(std::string&, std::string&);

TEST(Task8, Test1) {
    std::string s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab\n";
    std::string s2 = "aba";
    std::string s3 = "YES";
    ASSERT_EQ(toDoTask8(s1, s2), s3);
}

TEST(Task8, Test2) {
    std::string s1 = "abaa";
    std::string s2 = "baaabab";
    std::string s3 = "NO";
    ASSERT_EQ(toDoTask8(s1, s2), s3);
}

TEST(Task8, Test3) {
    std::string s1 = "a";
    std::string s2 = "aa";
    std::string s3 = "NO";
    ASSERT_EQ(toDoTask8(s1, s2), s3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}