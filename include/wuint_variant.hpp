#ifndef WUINT_VARIANT_HPP
#define WUINT_VARIANT_HPP

#include <variant>
#include <bitset>
#include <limits>
#include <type_traits>
#include <concepts>
#include <string>
#include <array>
#include <wuint.hpp>

constexpr static std::size_t size_of_variant=64ull; 

class wuint_variant;
template <template <std::size_t I> class TC, class>
struct TC_variant;

template <template <std::size_t I> class TC, std::size_t... Is>
struct TC_variant<TC, std::index_sequence<Is...>> {
  using type = std::variant<TC<Is>...>;
};

template <template <std::size_t I> class TC, class TSeq>
using TC_variant_t = typename TC_variant<TC, TSeq>::type;

using wuint_variant_t = TC_variant_t<wuint , std::make_index_sequence<size_of_variant>>;

struct wuint_variant : public wuint_variant_t {
private:

//    std::array<wuint_variant,size_of_variant> m_dispatch_of_returns;
    
public :

   inline static constexpr size_t digits = std::numeric_limits<uint32_t>::digits;

   bool is_0() const;

   bool is_not_0() const;

   bool is_1() const;

   bool is_not_1() const;

   bool is_max() const;

   bool is_not_max() const;

   wuint_variant()  = default;

   wuint_variant(const wuint_variant&)  = default;

   wuint_variant(wuint_variant&&)  = default;

   wuint_variant(const wuint_variant_t& arg)  :
       wuint_variant_t(arg) {}
       
    wuint_variant(wuint_variant_t&& arg)  :
       wuint_variant_t(std::move(arg)) {}

   wuint_variant & operator=(const wuint_variant&)  = default;

   wuint_variant & operator=(wuint_variant &&)  = default;
   
   wuint_variant & operator=(const wuint_variant_t& arg) {
       (*this) = arg;
       return (*this);
   }

   wuint_variant & operator=(wuint_variant_t && arg) {
       (*this) = std::move(arg);
       return (*this);
   }

   template<std::uint32_t k>
   wuint_variant(wuint<k> elem)  : wuint_variant_t(elem) {}

   template<std::uint32_t k>
   constexpr const wuint_variant&operator=(wuint<k> elem)  {
        (*this)= elem;
        return (*this);
   }

   std::bitset<digits> natural_binary() const;

   template <std::integral Int_t>
   explicit operator Int_t() const  {
    return
      std::visit(
        []<std::uint32_t k>(wuint<k> arg)->Int_t {
          if constexpr (k > 1)
            return static_cast<Int_t>(arg);
          else
            return static_cast<Int_t>(0);
        },          // FIN DE LA DEFINICION DE LA FUNCION LAMBDA
        *this    // ARGUMENTO
      )             // FIN DE LA LLAMADA AL STD::VISIT
    ;               // FIN DEL RETURN STATEMENT
   }                // FIN DE LA FUNCION OPERATOR INT_T -> INT_T [CAST]

   std::string to_string(radixformat rf=radixformat::dec) const;

   std::string to_binary_string() const;

   bool from_string(const std::string& source);

   std::uint32_t radix() const;

   bool operator==(const wuint_variant& otro) const;

   bool operator!=(const wuint_variant& otro) const;

   bool operator<(const wuint_variant& otro) const;

   bool operator<=(const wuint_variant& otro) const;

   bool operator>(const wuint_variant& otro) const;

   bool operator>=(const wuint_variant& otro) const;

   const wuint_variant& operator++();

   const wuint_variant& operator--();

   wuint_variant operator++(int);

   wuint_variant operator--(int);

   const wuint_variant& operator|=(const wuint_variant& otro);

   const wuint_variant& operator&=(const wuint_variant& otro);

   const wuint_variant& operator^=(const wuint_variant& otro);

   wuint_variant operator|(const wuint_variant& otro) const;

   wuint_variant operator&(const wuint_variant& otro) const;

   wuint_variant operator^(const wuint_variant& otro) const;

   const wuint_variant& operator>>=(size_t n);

   const wuint_variant& operator<<=(size_t n);

   wuint_variant operator<<(size_t n) const;

   wuint_variant operator>>(size_t n) const;

   const wuint_variant& operator+=(const wuint_variant& otro);

   const wuint_variant& operator-=(const wuint_variant& otro);

   const wuint_variant& operator*=(const wuint_variant& otro);

   const wuint_variant& operator/=(const wuint_variant& otro);

   const wuint_variant& operator%=(const wuint_variant& otro);

   wuint_variant operator+(wuint_variant otro) const;

   wuint_variant operator-(wuint_variant otro) const ;

   wuint_variant operator*(wuint_variant otro) const;

   wuint_variant operator/(wuint_variant otro) const;

   wuint_variant operator%(wuint_variant otro) const;

   wuint_variant operator+() const;

   wuint_variant operator~() const;


   wuint_variant operator-() const;

   friend std::ostream& operator<<(std::ostream& os, const wuint_variant& arg);

   friend std::istream& operator>>(std::istream& is, wuint_variant& arg);

};

wuint_variant make_wuint_variant(std::uint32_t,std::uint32_t) ;

#endif // WUINT_VARIANT_HPP
