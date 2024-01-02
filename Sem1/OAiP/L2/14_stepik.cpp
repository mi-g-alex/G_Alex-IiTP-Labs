// OK 4.3.9
#include <iostream>

long double min_a(long double x1, long double x2) {
    return (x1 < x2 ? x1 : x2);
}

    int main() {

    long double x1, y1, x2, y2, W, H, tw, th, ans = UINT64_MAX, leftW, leftH;
    std::cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> tw >> th;

    if (x1 > x2) std::swap(x1, x2);
    if (y1 > y2) std::swap(y1, y2);

    leftH = H - y2 + y1;
    leftW = W - x2 + x1;

    if (tw > leftW && th > leftH) {
        std::cout << -1 << "\n";
        return 0;
    }

    if (th <= leftH) ans = min_a(th - y1, th - (H - y2));
    if (tw <= leftW) ans = min_a(min_a(tw - x1, tw - (W - x2)), ans);
    if (ans < 0) ans = 0;
    std::cout << ans << "\n";
    return 0;
}
