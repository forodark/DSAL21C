#include <iostream>
#include <cstddef>
#include <type_traits>

template <typename T>
struct GetOffsetHelper {
    template <typename U>
    static constexpr std::size_t getOffset(U* instance, decltype(&U::name) member) {
        return reinterpret_cast<std::size_t>(&instance->*member);
    }
};

#define GET_OFFSET(instance, member) \
    GetOffsetHelper<std::remove_reference_t<decltype(instance)>>::getOffset(&(instance[0]), &decltype(instance[0])::member)

struct Student {
    std::string name;
    int age;
};

int main() {
    Student test[] = {
        {"bob", 20},
        {"alice", 30}
    };

    std::size_t offset = GET_OFFSET(test, name);
    std::cout << "Offset of 'name': " << offset << std::endl;

    return 0;
}
