#include <iostream>
#include <vector>
#include <ranges>
#include <concepts>
#include <numeric>

template <std::ranges::input_range Range, typename Condition>
auto sum_selected(const Range& data, Condition cond) {
    using ValueType = std::ranges::range_value_t<Range>;
    ValueType total{};
    for (auto&& item : data) {
        if (cond(item)) {
            total += item;
        }
    }
    return total;
}

int main() {
    std::vector<int> numbers {1,2,3,4,5,6,7,8,9,10};

    auto evens_cubed = numbers
        | std::views::filter([](int n) { return n % 2 == 0; })
        | std::views::transform([](int n) { return n * n * n; });

    std::cout << "even^3: ";
    for (auto val : evens_cubed) {
        std::cout << val << ' ';
    }
    std::cout << "\n";

    auto total_sum = sum_selected(numbers, [](int n) { return n > 4; });
    std::cout << "sum(n>4): " << total_sum << "\n";

    return 0;
}
