#include "../googletest/googlemock/include/gmock/gmock.h"

long long start(std::string x);

TEST(Task5, Test1) {
    ASSERT_EQ(start("100000000"), 10000000L);
}

TEST(Task5, Test2) {
    ASSERT_EQ(start("10000000"), 1000000L);
}

TEST(Task5, Test3) {
    ASSERT_EQ(start("9999"), 1000L);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}