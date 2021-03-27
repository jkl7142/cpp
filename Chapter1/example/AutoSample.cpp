#include <iostream>

int main(void) {
    int a = 10;
    int b(a);
    auto c(b);

    std::cout << a << " " << b << " " << c << std::endl;

    a = 20;

    std::cout << a << " " << b << " " << c << std::endl;

    b = 30;

    std::cout << a << " " << b << " " << c << std::endl;

    return 0;
}