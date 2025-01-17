#pragma once
#ifndef CONSTEXPR_MATH_HPP
#define CONSTEXPR_MATH_HPP

#include <type_traits>

namespace constexpr_math {

template <typename T>
constexpr T min(const T &a, const T &b) {
    return a < b ? a : b;
}
template <typename iterable_t>
constexpr auto min(const iterable_t &iterable_obj) {
    static_assert(iterable_obj.size() > 0,
                  "Iterable object must have at least one element.");
    auto min_value = iterable_obj.front();
    for (auto &value : iterable_obj) {
        if (value < min_value) { min_value = value; }
    }
    return min_value;
}
template <typename iterator_t>
constexpr auto min(const iterator_t &begin, const iterator_t &end) {
    static_assert(end - begin > 0,
                  "Iterator range must have at least one element.");
    auto min_value = *begin;
    for (auto it = begin; it != end; ++it) {
        if (*it < min_value) { min_value = *it; }
    }
    return min_value;
}

template <typename T>
constexpr T max(const T &a, const T &b) {
    return a > b ? a : b;
}
template <typename iterable_t>
constexpr auto max(const iterable_t &iterable_obj) {
    static_assert(iterable_obj.size() > 0,
                  "Iterable object must have at least one element.");
    auto max_value = iterable_obj.front();
    for (auto &value : iterable_obj) {
        if (value > min_value) { max_value = value; }
    }
    return max_value;
}
template <typename iterator_t>
constexpr auto max(const iterator_t &begin, const iterator_t &end) {
    static_assert(end - begin > 0,
                  "Iterator range must have at least one element.");
    auto max_value = *begin;
    for (auto it = begin; it != end; ++it) {
        if (*it > max_value) { max_value = *it; }
    }
    return max_value;
}

template <typename number_t>
constexpr number_t abs(number_t x) {
    return x < 0 ? -x : x;
}

template <typename base_t, typename exponent_t>
constexpr base_t pow(base_t base, exponent_t exponent) {
    if constexpr (::std::is_integral<exponent_t>::value) {
        if constexpr (exponent > 0) {
            base_t result = 1;
            while (exponent != 0) {
                if (exponent % 2 == 1) { result *= base; }
                base *= base;
                exponent /= 2;
            }
            return result;
        } else if constexpr (exponent == 0) {
            return 1;
        }
    }
    // todo
}

} // namespace constexpr_math

#endif // CONSTEXPR_MATH_HPP