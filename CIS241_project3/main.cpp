#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "Enter the radius of the circle" << std::endl;
    float radius;
    std::cin >> radius;

    float area = 3.14159 * radius * radius;
    std::cout << std::endl;
    std::cout << "The area of this circle is: " << area << std::endl;
}
