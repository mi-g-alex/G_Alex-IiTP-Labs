#include <iostream>
#include <cmath>
#include <string>
/// 1	    I
/// 5	    V
/// 10	    X
/// 50	    L
/// 100	    C
/// 500	    D
/// 1000	M

std::string start(long long x) {
    std::string ans;
    while(x) {
        switch ((int)std::floor(std::log10(x)) + 1) {
            case 4:
                if(x / 1000 == 3) {
                    ans += "MMM";
                }
                if(x / 1000 == 2) {
                    ans += "MM";
                }
                if(x / 1000 == 1) {
                    ans += "M";
                }
                x %= 1000;
                break;
            case 3:
                if(x / 100 == 9) {
                    ans += "CM";
                }
                else if(x / 100 <= 8 && x / 100 >= 5) {
                    ans += "D";
                    for(int i = 6; i <= x / 100; i++) ans += "C";
                } else if(x / 100 == 4){
                    ans += "CD";
                } else {
                    for(int i = 1; i <= x / 100; i++) {
                        ans += "C";
                    }
                }
                x %= 100;
                break;
            case 2:
                if(x / 10 == 9) {
                    ans += "XC";
                }
                else if(x / 10 <= 8 && x / 10 >= 5) {
                    ans += "L";
                    for(int i = 6; i <= x / 10; i++) ans += "X";
                } else if(x / 10 == 4){
                    ans += "XL";
                } else {
                    for(int i = 1; i <= x / 10; i++) {
                        ans += "X";
                    }
                }
                x %= 10;
                break;
            case 1:
                if(x == 9) {
                    ans += "IX";
                }
                else if(x <= 8 && x >= 5) {
                    ans += "V";
                    for(int i = 6; i <= x; i++) ans += "I";
                } else if(x == 4){
                    ans += "IV";
                } else {
                    for(int i = 1; i <= x; i++) {
                        ans += "I";
                    }
                }
                x = 0;
                break;
        }
    }
    return(ans);
}
