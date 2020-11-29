#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Let's get visualizin'\n";

    for (auto i = 0; i < argc; ++i) {
        std::cout << argv[i] << '\n';
    }
}