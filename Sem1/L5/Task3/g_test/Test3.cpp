#include "../../googletest/googlemock/include/gmock/gmock.h"

long long forTest(long long , long long , long long **);

TEST(Task3, Test1) {
    auto **a = new long long *[3];
    for (int i = 0; i < 3; i++) {
        a[i] = new long long[3];
        for (int j = 0; j < 3; j++) {
            a[i][j] = i * 3 + j + 1;
        }
    }
    EXPECT_EQ(forTest(3LL, 3LL, (long long **) a), 0L);
}

TEST(Task3, Test2) {
    auto **a = new long long *[3];
    for (int i = 0; i < 3; i++) {
        a[i] = new long long[4];
        for (int j = 0; j < 4; j++) {
            a[i][j] = (i + 1) * 2;
        }
    }


    EXPECT_EQ(forTest(4LL, 3LL, (long long **) a), 48L);
}

TEST(Task3, Test3) {
    auto **a = new long long *[3];
    for (int i = 0; i < 3; i++) {
        a[i] = new long long[4];
        for (int j = 0; j < 4; j++) {
            a[i][j] = (i + 1000 + j) * 2;
        }
    }


    EXPECT_EQ(forTest(4LL, 3LL, (long long **) a), 8048064000LL);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}