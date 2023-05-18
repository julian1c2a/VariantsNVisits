
#include <variant>
#include <bitset>
#include <limits>
#include <type_traits>
#include <concepts>
#include <string>
#include <wuint.hpp>
#include <wuint_variant.hpp>


//wuint_variant create_wuint(std::uint32_t,std::uint32_t) ;
wuint_variant make_wuint_variant(std::uint32_t Radix,std::uint32_t value) {
    if ((Radix < 2)||(Radix > 63)) {
        switch (Radix) {
            case   2 : return wuint_variant(wuint<  2>(value)); 
            case   3 : return wuint_variant(wuint<  3>(value)); 
            case   4 : return wuint_variant(wuint<  4>(value));
            case   5 : return wuint_variant(wuint<  5>(value)); 
            case   6 : return wuint_variant(wuint<  6>(value)); 
            case   7 : return wuint_variant(wuint<  7>(value)); 
            case   8 : return wuint_variant(wuint<  8>(value));
            case   9 : return wuint_variant(wuint<  9>(value)); 
            case 10 : return wuint_variant(wuint<10>(value)); 
            case 11 : return wuint_variant(wuint<11>(value)); 
            case 12 : return wuint_variant(wuint<12>(value));
            case 13 : return wuint_variant(wuint<13>(value)); 
            case 14 : return wuint_variant(wuint<14>(value)); 
            case 15 : return wuint_variant(wuint<15>(value)); 
            case 16 : return wuint_variant(wuint<16>(value));
            case 17 : return wuint_variant(wuint<17>(value)); 
            case 18 : return wuint_variant(wuint<18>(value)); 
            case 19 : return wuint_variant(wuint<19>(value));
            case 20 : return wuint_variant(wuint<20>(value)); 
            case 21 : return wuint_variant(wuint<21>(value)); 
            case 22 : return wuint_variant(wuint<22>(value));
            case 23 : return wuint_variant(wuint<23>(value)); 
            case 24 : return wuint_variant(wuint<24>(value)); 
            case 25 : return wuint_variant(wuint<25>(value)); 
            case 26 : return wuint_variant(wuint<26>(value));
            case 27 : return wuint_variant(wuint<27>(value)); 
            case 28 : return wuint_variant(wuint<28>(value)); 
            case 29 : return wuint_variant(wuint<29>(value)); 
            case 30 : return wuint_variant(wuint<30>(value)); 
            case 31 : return wuint_variant(wuint<31>(value)); 
            case 32 : return wuint_variant(wuint<32>(value));
            case 33 : return wuint_variant(wuint<33>(value)); 
            case 34 : return wuint_variant(wuint<34>(value)); 
            case 35 : return wuint_variant(wuint<35>(value)); 
            case 36 : return wuint_variant(wuint<36>(value));
            case 37 : return wuint_variant(wuint<37>(value)); 
            case 38 : return wuint_variant(wuint<38>(value)); 
            case 39 : return wuint_variant(wuint<39>(value)); 
            case 40 : return wuint_variant(wuint<40>(value)); 
            case 41 : return wuint_variant(wuint<41>(value)); 
            case 42 : return wuint_variant(wuint<42>(value));
            case 43 : return wuint_variant(wuint<43>(value)); 
            case 44 : return wuint_variant(wuint<44>(value)); 
            case 45 : return wuint_variant(wuint<45>(value)); 
            case 46 : return wuint_variant(wuint<46>(value));
            case 47 : return wuint_variant(wuint<47>(value)); 
            case 48 : return wuint_variant(wuint<48>(value)); 
            case 49 : return wuint_variant(wuint<49>(value));
            case 50 : return wuint_variant(wuint<50>(value)); 
            case 51 : return wuint_variant(wuint<51>(value)); 
            case 52 : return wuint_variant(wuint<52>(value));
            case 53 : return wuint_variant(wuint<53>(value)); 
            case 54 : return wuint_variant(wuint<54>(value)); 
            case 55 : return wuint_variant(wuint<55>(value)); 
            case 56 : return wuint_variant(wuint<56>(value));
            case 57 : return wuint_variant(wuint<57>(value)); 
            case 58 : return wuint_variant(wuint<58>(value)); 
            case 59 : return wuint_variant(wuint<59>(value));
            case 60 : return wuint_variant(wuint<60>(value)); 
            case 61 : return wuint_variant(wuint<61>(value)); 
            case 62 : return wuint_variant(wuint<62>(value));
            case 63 : return wuint_variant(wuint<63>(value));
            default : return wuint_variant(wuint<  2>(value)); 
        };
    }
    else {
        return wuint_variant(wuint<  2>(value)); 
    }
}

bool wuint_variant::is_0() const{
  return std::visit(
      []<std::uint32_t k>(const wuint<k>& arg)->bool {
          return (arg.is_0());
      } ,
      *this
  );
}

bool wuint_variant::is_not_0() const{
  return std::visit(
      []<std::uint32_t k>(const wuint<k>& arg)->bool {
          return (arg.is_not_0());
      } ,
      *this
  );
}

bool wuint_variant::is_1() const{
  return std::visit(
      []<std::uint32_t k>(const wuint<k>& arg)->bool {
          return (arg.is_1());
      } ,
      *this
  );
}

bool wuint_variant::is_not_1() const{
  return std::visit(
      []<std::uint32_t k>(const wuint<k>& arg)->bool {
          return (arg.is_not_1());
      } ,
      *this
  );
}

bool wuint_variant::is_max() const{
  return std::visit(
      []<std::uint32_t k>(const wuint<k>& arg)->bool {
          return (arg.is_max());
      } ,
      *this
  );
}

bool wuint_variant::is_not_max() const{
  return std::visit(
      []<std::uint32_t k>(const wuint<k>& arg)->bool {
          return (arg.is_not_max());
      } ,
      *this
  );
}

std::bitset<wuint_variant::digits> wuint_variant::natural_binary() const{
  return
    std::visit(
      []<std::uint32_t k>(wuint<k> arg)->std::bitset<digits>{
        if constexpr (k > 1) {
          return arg.natural_binary();
        } else {
          wuint<k> ret{};
          return ret.natural_binary();
        }
      }, // FIN DE LA DEFINICION DE LA FUNCION LAMBDA
      *this // ARGUMENTO
    ) // FIN DE LA LLAMADA AL STD::VISIT
  ; // FIN DEL RETURN STATEMENT
} // FIN DE LA FUNCION NATURAL_BINARY() -> STD::BITSET<DIGITS>

std::string wuint_variant::to_string(radixformat rf) const{
  return
    std::visit(
      [rf]<std::uint32_t k>(const wuint<k>& arg){
              if constexpr (k > 1)
                  return arg.to_string(rf);
              else
                  return std::string("");
      }
      ,
      *this
    );
}

std::string wuint_variant::to_binary_string() const{
  return this->to_string(radixformat::bin);
}

bool wuint_variant::from_string(const std::string& source)
{
  return
      std::visit(
          [source]<uint32_t k>(wuint<k>& arg){
              if constexpr (k > 1)
                  return arg.from_string(source);
              else
                  return false;
          } ,
          *this
      );
}

std::uint32_t wuint_variant::radix() const{
  return
    std::visit(
       []<std::uint32_t k>(const wuint<k>& arg) -> std::uint32_t {
           return std::decay_t<decltype(arg)>::radix();
       } ,*this
    );
}

bool wuint_variant::operator==(const wuint_variant& otro) const{
  return
    std::visit(
      []<std::uint32_t k,std::uint32_t l>(
        const wuint<k>& left,const wuint<l>& right
        ) -> bool {

        if constexpr ((k == l) &&(k > 1)){ // CASOS COMPARABLES
          return  (left == right);
        }
        else {// CASOS INCOMPARABLES
          return false;
        }

      },      // FIN DE DEFINICION DE LA FUNCION LAMBDA
      *this,  // ARGUMENTO 1
      otro    // ARGUMENTO 2
    ) // FIN DEL VISIT
  ;   // FIN DEL RETURN
}     // FIN DE LA FUNCION OPERATOR==() -> BOOL

bool wuint_variant::operator!=(const wuint_variant& otro) const{
  return
    std::visit(
      []<std::uint32_t k,std::uint32_t l>(
        const wuint<k>& left,const wuint<l>& right
      )->bool {

        if constexpr ((k == l) &&(k > 1)){ // CASOS COMPARABLES
          return  (left != right);
        }
        else { // CASOS INCOMPARABLES
          return false;
        }

      }, // FIN DE DEFINICION DE LA FUNCION LAMBDA
      *this, // ARGUMENTO 1
      otro   // ARGUMENTO 2
    ) // FIN DEL VISIT
  ; // FIN DEL RETURN
} // FIN DE LA FUNCION OPERATOR!= -> BOOL

bool wuint_variant::operator<(const wuint_variant& otro) const{
  return
    std::visit(
      []<std::uint32_t k,std::uint32_t l>(
        const wuint<k>& left,const wuint<l>& right
      )->bool{

        if constexpr ((k == l) &&(k > 1)){ // CASOS COMPARABLES
          return  (left < right);
        }
        else { // CASOS INCOMPARABLES
          return false;
        }

      }, // FIN DE DEFINICION DE LA FUNCION LAMBDA
      *this, // ARGUMENTO 1
      otro   // ARGUMENTO 2
    ) // FIN DEL VISIT
  ; // FIN DEL RETURN
} // FIN DE LA FUNCION OPERATOR== -> BOOL

bool wuint_variant::operator<=(const wuint_variant& otro) const{
  return
    std::visit(
      []<std::uint32_t k,std::uint32_t l>(
        const wuint<k>& left,const wuint<l>& right
        )->bool{

        if constexpr ((k == l) &&(k > 1)){ // CASOS COMPARABLES
          return  (left <= right);
        }
        else { // CASOS INCOMPARABLES
          return false;
        }

      }, // FIN DE DEFINICION DE LA FUNCION LAMBDA
      *this, // ARGUMENTO 1
      otro   // ARGUMENTO 2
    ) // FIN DEL VISIT
  ; // FIN DEL RETURN
} // FIN DE LA FUNCION OPERATOR<= -> BOOL

bool wuint_variant::operator>(const wuint_variant& otro) const{
  return
    std::visit(
      []<std::uint32_t k,std::uint32_t l>(
        const wuint<k>& left,const wuint<l>& right
        )->bool{

        if constexpr ((k == l) &&(k > 1)){ // CASOS COMPARABLES
          return  (left > right);
        }
        else { // CASOS INCOMPARABLES
          return false;
        }

      }, // FIN DE DEFINICION DE LA FUNCION LAMBDA
      *this, // ARGUMENTO 1
      otro   // ARGUMENTO 2
    ) // FIN DEL VISIT
  ; // FIN DEL RETURN
} // FIN DE LA FUNCION OPERATOR> -> BOOL

bool wuint_variant::operator>=(const wuint_variant& otro) const{
  return
    std::visit(
      []<std::uint32_t k,std::uint32_t l>(
        const wuint<k>& left,const wuint<l>& right
        )->bool{

        if constexpr ((k == l) &&(k > 1)){ // CASOS COMPARABLES
          return  (left >= right);
        }
        else { // CASOS INCOMPARABLES
          return false;
        }

      }, // FIN DE DEFINICION DE LA FUNCION LAMBDA
      *this, // ARGUMENTO 1
      otro   // ARGUMENTO 2
    ) // FIN DEL VISIT
  ; // FIN DEL RETURN
} // FIN DE LA FUNCION OPERATOR>= -> BOOL

const wuint_variant& wuint_variant::operator++()
{
  std::visit(
    []<std::uint32_t k>(wuint<k>& arg) -> void {
        if constexpr (k > 1)
        ++arg;
    }  // FIN DE LA DEFINICION DE LA FUNCION LAMBDA
    ,
    *this // ARGUMENTO
  ); // FIN DE LA LLAMADA AL STD::VISIT
  return (*this);
} // FIN DE LA FUNCION OPERATOR++()

const wuint_variant& wuint_variant::operator--()
{
  std::visit(
    []<std::uint32_t k>(wuint<k>& arg) -> void {
        if constexpr (k > 1)
            --arg;
    }  // FIN DE LA DEFINICION DE LA FUNCION LAMBDA
    ,
    *this // ARGUMENTO
  ); // FIN DE LA LLAMADA AL STD::VISIT
  return (*this);
} // FIN DE LA FUNCION OPERATOR--()

wuint_variant wuint_variant::operator++(int)
{
  wuint_variant ret{ *this };
  ++(*this);
  return ret;
}

wuint_variant wuint_variant::operator--(int){
  wuint_variant ret{ *this };
  --(*this);
  return ret;
}

const wuint_variant& wuint_variant::operator|=(
      const wuint_variant& otro
    ){

  std::visit(
    []<std::uint32_t k, std::uint32_t l>(wuint<k>& left,const wuint<l>& right) {

      if constexpr ((k == l) && (k > 1)) {
        left |= right;
      }

    },
    *this,
    otro
  );
  return (*this);
}

const wuint_variant& wuint_variant::operator&=(
    const wuint_variant& otro
  ) {
  std::visit(
    []<std::uint32_t k, std::uint32_t l>(wuint<k>& left,const wuint<l>& right) {
      if constexpr ((k == l) && (k > 1)) {
        left &= right;
      }
    },
    *this,
    otro
  );
  return (*this);
}

const wuint_variant& wuint_variant::operator^=(
    const wuint_variant& otro
  ){
  std::visit(
    []<std::uint32_t k, std::uint32_t l>(wuint<k>& left,const wuint<l>& right) {
      if constexpr ((k == l) && (k > 1)) {
        left ^= right;
      }
    },
    *this,
    otro
  );
  return (*this);
}

wuint_variant wuint_variant::operator|(
    const wuint_variant& otro
  ) const {
  auto result{*this};
  result += otro;
  return result;
}

wuint_variant wuint_variant::operator&(const wuint_variant& otro) const{
  wuint_variant ret{*this};
  ret &= otro;
  return ret;
}

wuint_variant wuint_variant::operator^(const wuint_variant& otro) const
{
  wuint_variant ret{*this};
  ret ^= otro;
  return ret;
}

const wuint_variant& wuint_variant::operator>>=(size_t n){
  std::visit(
    [n]<std::uint32_t k>(wuint<k>& arg) -> void {
        arg >>= n;
    },
    *this
  );
  return (*this);
}

const wuint_variant& wuint_variant::operator<<=(size_t n){
  std::visit(
    [n]<std::uint32_t k>(wuint<k>& arg) -> void {
        arg <<= n;
    },
    *this
  );
  return (*this);
}

wuint_variant wuint_variant::operator<<(size_t n) const {
  wuint_variant arg{*this};
  arg <<= n;
  return arg;
}

wuint_variant wuint_variant::operator>>(size_t n) const {
  wuint_variant arg{*this};
  arg >>= n;
  return arg;
}

const wuint_variant& wuint_variant::operator+=(const wuint_variant& otro){
  std::visit(
    []<uint32_t k,uint32_t l>(wuint<k>& left , const wuint<l>& right) {
        if constexpr ((k == l) && (k > 1)) {
            left += right;
        }
    },
    *this,
    otro
  );
  return (*this);
}

const wuint_variant& wuint_variant::operator-=(const wuint_variant& otro){
  std::visit(
    []<uint32_t k,uint32_t l>(wuint<k>& left , const wuint<l>& right) {
        if constexpr ((k == l) && (k > 1)) {
            left -= right;
        }
    },
    *this,
    otro
  );
  return (*this);
}

const wuint_variant& wuint_variant::operator*=(const wuint_variant& otro){
  std::visit(
    []<uint32_t k,uint32_t l>(wuint<k>& left , const wuint<l>& right) {
        if constexpr ((k == l) && (k > 1)) {
            left *= right;
        }
    },
    *this,
    otro
  );
  return (*this);
}

const wuint_variant& wuint_variant::operator/=(const wuint_variant& otro){
  std::visit(
    []<uint32_t k,uint32_t l>(wuint<k>& left , const wuint<l>& right) {
        if constexpr ((k == l) && (k > 1)) {
            if (right != wuint<l>(0ul)) {
                left /= right;
            }
        }
    },
    *this,
    otro
  );
  return (*this);
}

const wuint_variant& wuint_variant::operator%=(const wuint_variant& otro){
  std::visit(
    []<uint32_t k,uint32_t l>(wuint<k>& left , const wuint<l>& right) {
        if constexpr ((k == l) && (k > 1)) {
            if (right != wuint<l>(0ul)) {
                left %= right;
            }
        }
    },
    *this,
    otro
  );
  return (*this);
}

wuint_variant wuint_variant::operator+(wuint_variant otro) const {
    wuint_variant result{*this};
    result += otro;
    return result;
} 

wuint_variant wuint_variant::operator-(wuint_variant otro) const {
  wuint_variant result{*this};
  result -= otro;
  return (result);
}

wuint_variant wuint_variant::operator*(wuint_variant otro) const {
  wuint_variant result{*this};
  result *= otro;
  return (result);
}

wuint_variant wuint_variant::operator/(wuint_variant otro) const {
  wuint_variant result{*this};
  if (otro.is_not_0())
    result /= otro;
  return (result);
}

wuint_variant wuint_variant::operator%(wuint_variant otro) const {
  wuint_variant result{*this};
  if (otro.is_not_0())
    result %= otro;
  return (result);
}

wuint_variant wuint_variant::operator+() const{
  return wuint_variant{*this};
}

wuint_variant wuint_variant::operator~() const{
  wuint_variant result{*this};
  std::visit(
    []<std::uint32_t k>(wuint<k>& arg) -> void {
        arg = ~arg;
    },
    result
  );
  return result;
}


wuint_variant wuint_variant::operator-() const{
  wuint_variant result{*this};
  std::visit(
    []<std::uint32_t k>(wuint<k>& arg) -> void {
        arg = -arg;
    },
    result
  );
  return result;
}

std::ostream& operator<<(std::ostream& os, const wuint_variant& arg) {
  os << arg.to_string();
  return os;
}

std::istream& operator>>(std::istream& is, wuint_variant& arg) {
  std::string source{};
  is >> source;
  arg.from_string(source);
  return is;
}

