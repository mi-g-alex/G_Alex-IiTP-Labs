#include "../googletest/googlemock/include/gmock/gmock.h"

std::string start(long long x);

TEST(Task5, Test1) {
    ASSERT_EQ(start(7), "21");
}

TEST(Task5, Test2) {
    ASSERT_EQ(start(28), "231");
}

TEST(Task5, Test3) {
    ASSERT_EQ(start(2000000000), "11233323323111312232");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}