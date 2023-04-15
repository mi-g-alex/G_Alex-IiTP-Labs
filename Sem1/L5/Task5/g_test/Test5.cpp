#include "../../googletest/googlemock/include/gmock/gmock.h"

long double forTest(long long , long long , long long **);

TEST(Task5, Test1) {
    auto **a = new long long *[3];
    for (int i = 0; i < 3; i++) {
        a[i] = new long long[3];
        for (int j = 0; j < 3; j++) {
            a[i][j] = i * 3 + j + 1;
        }
    }

    EXPECT_EQ(forTest(3LL, 3LL, (long long **) a), 5L);
}

TEST(Task5, Test2) {
    auto **a = new long long *[3];
    for (int i = 0; i < 3; i++) {
        a[i] = new long long[4];
        for (int j = 0; j < 4; j++) {
            a[i][j] = (i + 1) * 2;
        }
    }

    EXPECT_EQ(forTest(3LL, 4LL, (long long **) a), 0L);
}

TEST(Task5, Test3) {
    auto **a = new long long *[3];
    for (int i = 0; i < 3; i++) {
        a[i] = new long long[4];
        for (int j = 0; j < 4; j++) {
            a[i][j] = i + 100;
        }
    }

    EXPECT_EQ(forTest(3LL, 4LL, (long long **) a), (long double)50.5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}