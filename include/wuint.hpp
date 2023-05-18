#ifndef WUINT_HPP
#define WUINT_HPP

#include <bitset>
#include <cassert>
#include <cctype>
#include <charconv>
#include <concepts>
#include <cstdint>
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

using std::abs;
using std::bitset;
using std::integral;
using std::isspace;
using std::string;
using std::uint32_t;
using std::unsigned_integral;

enum class radixformat { bin, dec };

template <uint32_t R> class wuint
{
private:
    uint32_t m_num;

public:
    static consteval size_t digits() noexcept {
        return (std::numeric_limits<uint32_t>::digits);
    }

    constexpr bitset<digits()> natural_binary() const noexcept {
        return bitset<digits()>{ m_num };
    }

    constexpr wuint() noexcept = default;

    constexpr wuint(const wuint&) noexcept = default;

    constexpr wuint(wuint&&) noexcept = default;

    constexpr bool is_0() const noexcept {
        return (m_num == 0ul);
    }

    constexpr bool is_not_0() const noexcept {
        return (m_num != 0ul);
    }

    constexpr bool is_1() const noexcept {
        return (m_num == 1ul);
    }

    constexpr bool is_not_1() const noexcept {
        return (m_num != 1ul);
    }

    constexpr bool is_max() const noexcept {
        return (m_num == R-1ul);
    }

    constexpr bool is_not_max() const noexcept {
        return (m_num != R-1ul);
    }

    template <integral Int_t>
    constexpr wuint(Int_t num) noexcept
        : m_num{ static_cast<uint32_t>(abs(static_cast<int64_t>(num))) }
    {}

    wuint& operator=(const wuint&) noexcept = default;

    wuint& operator=(wuint&&) noexcept = default;

    template <integral Int_t> const wuint& operator=(Int_t num) noexcept {
        m_num = static_cast<Int_t>(abs(num));
        return (*this);
    }

    template <integral Int_t>
    explicit operator Int_t() const noexcept {
        return (static_cast<Int_t>(m_num));
    }

    string to_string(radixformat rf = radixformat::dec) const noexcept {
        if(rf == radixformat::dec) {
            return ("dig#"+std::to_string(m_num)+"#R"+std::to_string(R));
        } else {
            return natural_binary().to_string();
        }
    }

    bool from_string(const string& source) noexcept {
        using std::isspace;
        using std::isdigit;
        // Constantes tipo string
        const string start_format = "dig#";
        const string end_format = "#R" + std::to_string(R);
        const string empty_str = "";
        // String recipiente del parse de source
        string source_cp{};

        /// PARA TRABAJAR CON SOURCE DE FORMA MAS RACIONAL
        /// CON SOURCE ENCONTRANDO LOS TOKEN Y SUS POSICIONES
        /// auto it{source_cp.cbegin()};
        /// const auto itend{source_cp.cend()};
        /// decltype(it) it_token_begin = nullptr;
        /// decltype(it) it_token_end = nullptr;
        /// TOKEN = STD::TUPLE<IT_BEGIN,IT_END,TOKEN_TYPE,TOKEN_VALUE>

        // Quitamos espacios en blanco
        // No es correcto. En "dig" no puede haber espacios en blanco,
        // en las dos cadenas numéricas tampoco.
        for(auto car : source) {
            if(!isspace(car)) {
                source_cp.push_back(car);
            }
        }
        // Vemos si comienza por dig#, y si es el caso, se quita
        const bool buen_comienzo = source_cp.starts_with(start_format);
        if(buen_comienzo) {
            source_cp.replace(0, 4, empty_str);
        } else {
/// Format error in the begining
#ifndef NDEBUG
            std::cerr << "Comienzo de formato erróneo." << std::endl;
#endif
            return false;
        }
        // Vemos si termina por #B numero R, y si es el caso, se quita
        const bool buen_final = source_cp.ends_with(end_format);
        if(buen_final) {
            const size_t pos = source_cp.find(end_format);
            const size_t fin = source_cp.size() - pos;
            source_cp.replace(pos, fin, empty_str);
        } else {
/// Format error in the end
#ifndef NDEBUG
            std::cerr << "Final de formato erróneo." << std::endl;
#endif
            return false;
        }
        // Vemos si la fuente parseada esta vacia: entonces es error
        if(source_cp.size() == 0) {
#ifndef NDEBUG
            std::cerr << "Sin digitos." << std::endl;
#endif
            return false;
        }
        // Solo debe quedar un numero entero positivo
        // Lo sacamos con std::from_chars
        uint32_t entero{};
        auto [ptr, ec] = std::from_chars(
                    source_cp.data(),
                    source_cp.data() + source_cp.size(),
                    entero
        );
        // Parseado erroneo
        if(ec != std::errc{}) {
#ifndef NDEBUG
            std::cerr << source_cp
                      << std::endl;
            std::cerr << "Entero con formato erróneo o demasiado grande."
                      << std::endl;
#endif
            return false;
        }
        // Todo ha ido bien
        else {
            m_num = entero;
            return true;
        }
    }

    consteval static uint32_t radix() noexcept { return R; }

    bool operator==(const wuint& otro) const noexcept {
        return (m_num == otro.m_num);
    }

    bool operator!=(const wuint& otro) const noexcept {
        return (m_num != otro.m_num);
    }

    bool operator<(const wuint& otro) const noexcept {
        return (m_num < otro.m_num);
    }

    bool operator<=(const wuint& otro) const noexcept {
        return (m_num <= otro.m_num);
    }

    bool operator>(const wuint& otro) const noexcept {
        return (m_num > otro.m_num);
    }

    bool operator>=(const wuint& otro) const noexcept {
        return (m_num >= otro.m_num);
    }

    const wuint& operator++() noexcept {
        ++m_num;
        return (*this);
    }

    const wuint& operator--() noexcept {
        --m_num;
        return (*this);
    }

    wuint operator++(int) noexcept {
        wuint ret{ *this };
        ++m_num;
        return ret;
    }

    wuint operator--(int) noexcept {
        wuint ret{ *this };
        --m_num;
        return ret;
    }

    const wuint& operator|=(const wuint& otro) noexcept {
        m_num |= otro.m_num;
        return (*this);
    }

    const wuint& operator&=(const wuint& otro) noexcept {
        m_num &= otro.m_num;
        return (*this);
    }

    const wuint& operator^=(const wuint& otro) noexcept {
        m_num ^= otro.m_num;
        return (*this);
    }

    wuint operator|(wuint otro) const noexcept {
        return wuint{ m_num | otro.m_num };
    }

    wuint operator&(wuint otro) const noexcept {
        return wuint{ m_num & otro.m_num };
    }

    wuint operator^(wuint otro) const noexcept {
        return wuint{ m_num ^ otro.m_num };
    }

    const wuint& operator>>=(size_t n) noexcept {
        m_num >>= n;
        return (*this);
    }

    const wuint& operator<<=(size_t n) noexcept {
        m_num <<= n;
        return (*this);
    }

    wuint operator>>(size_t n) const noexcept { return wuint{ m_num >> n }; }

    wuint operator<<(size_t n) const noexcept { return wuint{ m_num << n }; }

    const wuint& operator+=(const wuint& otro) noexcept {
        m_num += otro.m_num;
        return (*this);
    }

    const wuint& operator-=(const wuint& otro) noexcept {
        m_num -= otro.m_num;
        return (*this);
    }

    const wuint& operator*=(const wuint& otro) noexcept {
        m_num *= otro.m_num;
        return (*this);
    }

    const wuint& operator/=(const wuint& otro) noexcept {
        m_num /= otro.m_num;
        return (*this);
    }

    const wuint& operator%=(const wuint& otro) noexcept {
        m_num %= otro.m_num;
        return (*this);
    }

    wuint operator+(wuint otro) const noexcept {
        return wuint{ m_num + otro.m_num };
    }

    wuint operator-(wuint otro) const noexcept {
        return wuint{ m_num - otro.m_num };
    }

    wuint operator*(wuint otro) const noexcept {
        return wuint{ m_num * otro.m_num };
    }

    wuint operator/(wuint otro) const noexcept {
        return wuint{ m_num / otro.m_num };
    }

    wuint operator%(wuint otro) const noexcept {
        return wuint{ m_num % otro.m_num };
    }

    wuint operator+() const noexcept {
        return wuint{ m_num };
    }

    wuint operator~() const noexcept {
        auto ret{ ~natural_binary() };
        return wuint{ static_cast<uint32_t>(ret.to_ullong()) };
    }

    wuint operator-() const noexcept {
        auto ret{ ~natural_binary() };
        return wuint{ static_cast<uint32_t>(ret.to_ullong()) + 1 };
    }

    template <uint32_t K>
    friend std::ostream& operator<<(std::ostream& os, const wuint<K>& arg);

    template <uint32_t K>
    friend std::istream& operator>>(std::istream& os, wuint<K>& arg);
};

template <uint32_t K>
std::ostream& operator<<(std::ostream& os, const wuint<K>& arg) {
    os << "dig#" << arg.to_string() << "#R" << std::to_string(K);
    return os;
}

template <uint32_t K>
std::istream& operator>>(std::istream& is, wuint<K>& arg) {
    string entrada{};
    is >> entrada;
    arg.from_string(entrada);
    return is;
}

#endif // WUINT_HPP
