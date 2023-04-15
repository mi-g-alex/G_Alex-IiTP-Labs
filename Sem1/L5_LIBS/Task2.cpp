#include <cmath>

extern "C" __declspec(dllexport) long double P(long double *a, long long l, long long r) {
    if(r - l > 1) return P(a, l, l + (r - l) / 3) * P(a, l + (r - l) / 3 + 1, r);
    return (sin(a[l - 1])-cos(a[l - 1]));

}