#pragma once
#ifndef CONSTEXPR_MATH_HPP
#define CONSTEXPR_MATH_HPP

#include <type_traits>

namespace constexpr_math {

inline namespace constant {

// π = circumference/diameter
template <typename number_t>
constexpr number_t pi = number_t(
    3.14159265358979323846264338327950288419716939937510582097494459230781640628620899L);
// τ = 2π
template <typename number_t>
constexpr number_t tau = number_t(
    6.28318530717958647692528676655900576839433879875021164194988918461563281257241799L);
// π⁻¹ = 1/π
template <typename number_t>
constexpr number_t inv_p = number_t(
    0.318309886183790671537767526745028724068919291480912897495334688117470859573164L);
// π⁻² = 1/√π
template <typename number_t>
constexpr number_t inv_sqrtpi = number_t(
    0.564189583547756286948079451560772585844050629329000826876428277587516887844419L);

// e = base of natural logarithm
template <typename number_t>
constexpr number_t e = number_t(
    2.71828182845904523536028747135266249775724709369995957496696762772407663035354759L);
// log₂e
template <typename number_t>
constexpr number_t log2e = number_t(
    1.442695040888963407359924681001892137426645954152985934135449406931219160354371L);
// log₁₀e
template <typename number_t>
constexpr number_t log10e = number_t(
    0.434294481903251827651128918916605082294397005803666566114453655241094391594651L);
// ln2
template <typename number_t>
constexpr number_t ln2 = number_t(
    0.693147180559945309417232121458176568075500134360255254120680009493393621969694L);
// ln10
template <typename number_t>
constexpr number_t ln10 = number_t(
    2.302585092994045684017991454684364207601101488628772976033327900967572609677352L);

// √2
template <typename number_t>
constexpr number_t sqrt2 = number_t(
    1.41421356237309504880168872420969807856967187537694807317667973799073247846210704L);
// √3
template <typename number_t>
constexpr number_t sqrt3 = number_t(
    1.73205080756887729352744634150587236694280525381038062805580697945193301690880037L);
// 3⁻² = 1/√3
template <typename number_t>
constexpr number_t inv_sqrt3 = number_t(
    0.577350269189625764509148780501957455647601751270126876018602326483977672437250L);

// γ = Euler's constant
template <typename number_t>
constexpr number_t egamma = number_t(
    0.57721566490153286060651209008240243104215933593992359880576723488486772677766467L);

// φ = golden ratio = (1 + √5)/2
template <typename number_t>
constexpr number_t phi = number_t(
    1.61803398874989484820458683436563811772030917980576286213544862270526046281890245L);

} // namespace constant

inline namespace function {

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

} // namespace function

} // namespace constexpr_math

#endif // CONSTEXPR_MATH_HPP