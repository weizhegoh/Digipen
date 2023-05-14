#include <cstdio>
#include <string>
#include <tuplet/tuple.hpp>

bool is_good(int a, int b, std::string c) {
    return a == 1 && b == 2 && c == "Hello, world!";
}

int main() {
    using namespace tuplet::literals;

    auto tup1 = tuplet::tuple {0, 0, std::string()};

    tuplet::tuple<int&, int&, std::string&> tup = tuplet::convert {tup1};

    tup1[0_tag] = 1;
    tup1[1_tag] = 2;
    tup1[2_tag] = "Hello, world!";

    return !is_good(get<0>(tup), get<1>(tup), get<2>(tup));
}
