#include "../../googletest/googlemock/include/gmock/gmock.h"

long long forTest(long long , long long , long double **);

TEST(Task4, Test1) {
    auto **a = new long double *[3];
    for (int i = 0; i < 3; i++) {
        a[i] = new long double[3];
        for (int j = 0; j < 3; j++) {
            a[i][j] = i * j;
        }
    }
    EXPECT_EQ(forTest(3LL, 3LL, (long double **) a), 5L);
}

TEST(Task4, Test2) {
    auto **a = new long double *[3];
    for (int i = 0; i < 3; i++) {
        a[i] = new long double[4];
        for (int j = 0; j < 4; j++) {
            a[i][j] = (i - j) * 2;
        }
    }


    EXPECT_EQ(forTest(3LL, 4LL, (long double **) a), 3L);
}

TEST(Task4, Test3) {
    auto **a = new long double *[3];
    for (int i = 0; i < 3; i++) {
        a[i] = new long double[4];
        for (int j = 0; j < 4; j++) {
            a[i][j] = 0;
        }
    }


    EXPECT_EQ(forTest(3LL, 4LL, (long double **) a), 12LL);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}