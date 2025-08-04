#include <iostream>
#include <cmath>
#include <string>

struct Vector2D {
    double x;
    double y;
};

Vector2D add(const Vector2D& v1, const Vector2D& v2) {
    return {v1.x + v2.x, v1.y + v2.y};
}

Vector2D subtract(const Vector2D& v1, const Vector2D& v2) {
    return {v1.x - v2.x, v1.y - v2.y};
}

Vector2D scale(const Vector2D& v, double scalar) {
    return {v.x * scalar, v.y * scalar};
}

double length(const Vector2D& v) {
    return std::sqrt(v.x * v.x + v.y * v.y);
}

Vector2D normalize(const Vector2D& v) {
    double len = length(v);
    return {v.x / len, v.y / len};
}

void printVector(const Vector2D& v) {
    std::cout << "(" << v.x << ", " << v.y << ")" << std::endl;
}

int main() {

    std::setlocale(LC_ALL, "Russian_Russia.1251");

    std::string operation;
    std::cout << "Enter the command (add, subtract, scale, length, normalize): ";
    std::cin >> operation;

    if (operation == "add" || operation == "subtract") {
        Vector2D v1, v2;
        std::cout << "Enter the coordinates of the first vector (x y): ";
        std::cin >> v1.x >> v1.y;
        std::cout << "Enter the coordinates of the second vector (x y): ";
        std::cin >> v2.x >> v2.y;

        Vector2D result;
        if (operation == "add") {
            result = add(v1, v2);
        } else {
            result = subtract(v1, v2);
        }
        printVector(result);

    } else if (operation == "scale") {
        Vector2D v;
        double scalar;
        std::cout << "Enter vector coordinates (x y): ";
        std::cin >> v.x >> v.y;
        std::cout << "Enter scalar: ";
        std::cin >> scalar;

        Vector2D result = scale(v, scalar);
        printVector(result);

    } else if (operation == "length") {
        Vector2D v;
        std::cout << "Enter vector coordinates (x y): ";
        std::cin >> v.x >> v.y;

        double result = length(v);
        std::cout << "Vector length: " << result << std::endl;

    } else if (operation == "normalize") {
        Vector2D v;
        std::cout << "Enter vector coordinates (x y): ";
        std::cin >> v.x >> v.y;

        Vector2D result = normalize(v);
        printVector(result);

    } else {
        std::cout << "Unknown command" << std::endl;
    }

    return 0;
}