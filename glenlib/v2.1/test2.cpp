#include <iostream>
#include <cstddef>

struct Student {
    std::string name;
    int age;
};

template <typename T, typename U>
std::size_t getOffset(const T& array, const U& member) {
    return reinterpret_cast<std::size_t>(&member) - reinterpret_cast<std::size_t>(&array);
}

int main() {
    Student test[] = {
        {"bob", 20},
        {"alice", 30}
    };

    std::size_t offset1 = getOffset(test, test[0].age);
    std::size_t offset2 = offsetof(Student, name);

    std::cout << "Offset of age for Bob: " << offset1 << std::endl;
    std::cout << "Offset of age for Alice: " << offset2 << std::endl;

    return 0;
}
