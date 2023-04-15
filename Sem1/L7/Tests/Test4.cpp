#include "../googletest/googlemock/include/gmock/gmock.h"

std::string start(long long x);

TEST(Task4, Test1) {
    ASSERT_EQ(start(3999), "MMMCMXCIX");
}

TEST(Task4, Test2) {
    ASSERT_EQ(start(1), "I");
}

TEST(Task4, Test3) {
    ASSERT_EQ(start(2345), "MMCCCXLV");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}