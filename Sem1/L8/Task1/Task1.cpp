#include <string>

void start();

struct Data {
    long long numberOfWorkshop;
    char nameOfProduct[1000];
    long long numberOfProduct;
    long double weightOfOneProduct;
    long double weightOfAllProducts;
    bool statusIsCreated;
};

Data *a;

int main() {
    start();
}