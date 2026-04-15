//
// Created by Lenovo on 14/04/2026.
//

#ifndef TAREA02_CORENUMERIC_H
#define TAREA02_CORENUMERIC_H

#include <concepts>
#include <iterator>
#include <type_traits>

namespace core_numeric {
    template <typename C>
    concept Iterable = requires (C c) {
        std::begin(c);
        std::end(c);
    };

    template <typename T>
    concept Addable = requires (T a, T b) {
        { a + b } -> std::same_as<T>;
    };

    template <typename T>
    concept Divisible = requires (T a, std::size_t n) {
        { a / n } -> std::same_as<T>;
    };

    // CONCEPT PROPIO
    template <typename T>
    concept Comparable = requires (T a, T b) {
        { a > b } -> std::convertible_to<bool>;
    };


    // Función base 'sum' (requerida por mean)
    template <Iterable C>
    requires Addable<typename C::value_type>
    auto sum(const C& container) {
        using T = typename C::value_type;
        T result{};

        // Uso obligatorio de if constexpr
        if constexpr (std::is_integral_v<T>) {
            // Comportamiento para enteros
            for (const auto& value : container) {
                result = result + value;
            }
        } else {
            // Comportamiento para float o clases
            for (const auto& value : container) {
                result = result + value;
            }
        }
        return result;
    }

    // Algoritmo mean
    template <Iterable C>
    requires Divisible<typename C::value_type> && Addable<typename C::value_type>
    auto mean(const C& container) {
        std::size_t count = std::distance(std::begin(container), std::end(container));
        return sum(container) / count;
    }

    // Algoritmo variance
    template <Iterable C>
    requires Iterable<C> && Addable<typename C::value_type> && Divisible<typename C::value_type>
    auto variance(const C& container) {
        auto m = mean(container);
        using T = typename C::value_type;
        T sum_sq{};
        std::size_t count = std::distance(std::begin(container), std::end(container));

        for (const auto& value : container) {
            auto diff = value - m;
            sum_sq = sum_sq + (diff * diff);
        }
        return sum_sq / count;
    }

    // Algoritmo max
    template <Iterable C>
    requires Comparable<typename C::value_type>
    auto max(const C& container) {
        auto it = std::begin(container);
        auto current_max = *it;
        for (; it != std::end(container); ++it) {
            if (*it > current_max) {
                current_max = *it;
            }
        }
        return current_max;
    }

    // Algoritmo transform_reduce
    template <Iterable C, typename F>
    auto transform_reduce(const C& container, F func) {
        using ReturnType = decltype(func(*std::begin(container)));
        ReturnType result{};
        for (const auto& value : container) {
            result = result + func(value);
        }
        return result;
    }


    template <typename... Args>
    auto sum_variadic(Args... args) {
        return (... + args);
    }

    template <typename... Args>
    auto mean_variadic(Args... args) {
        return sum_variadic(args...) / sizeof...(args);
    }

    template <typename... Args>
    auto variance_variadic(Args... args) {
        auto m = mean_variadic(args...);
        auto sum_sq = (((args - m) * (args - m)) + ...);
        return sum_sq / sizeof...(args);
    }

    template <typename T, typename... Args>
    auto max_variadic(T first, Args... args) {
        auto max_val = first;
        ((max_val = args > max_val ? args : max_val), ...);
        return max_val;
    }

}

#endif //TAREA02_CORENUMERIC_H
