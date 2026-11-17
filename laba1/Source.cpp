#include <iostream>
#include <stdexcept>

struct Interval {
    int first = 0;
    int second = 1;

    void Init(int left, int right) {
        if (left >= right)
            throw std::invalid_argument("Expected left < right");
        first = left;
        second = right;
    }
    void Read() {
        int left, right;
        if (!(std::cin >> left >> right))
            throw std::invalid_argument("Expected two integers");
        Init(left, right);
    }
    void Display() const {
        std::cout << '[' << first << ", " << second << ')';
    }
    bool rangecheck(int value) const {
        return first <= value && value < second;
    }
};

int main() {
    try {
        Interval range;
        std::cout << "Enter left and right bounds: ";
        range.Read();
        int value;
        std::cout << "Enter an integer: ";
        if (!(std::cin >> value))
            throw std::invalid_argument("Expected an integer");
        std::cout << "Interval: "; range.Display();
        std::cout << "\nValue: " << value
            << "\nBelongs: " << std::boolalpha
            << range.rangecheck(value) << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
}