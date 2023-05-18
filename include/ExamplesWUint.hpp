#ifndef EXAMPLESWUINT_HPP
#define EXAMPLESWUINT_HPP

#include <wuint.hpp>

template <uint32_t R> void imprime_con_detalle_bitwise_OR(std::ostream& os, const wuint<R>& A, std::string A_name, const wuint<R>& B, std::string B_name)
{
    const wuint<R> arg_A{ A };
    const wuint<R> arg_B{ B };
    os << "Bitwise operator OR |. Se muestra "<< A_name <<"|" << B_name << " == ";
    os << (arg_A | arg_B) << std::endl;
    os << arg_A.to_string(radixformat::bin) << "\n";
    os << arg_B.to_string(radixformat::bin) << "\n";
    os << (arg_A | arg_B).to_string(radixformat::bin) << "\n\n";
}

template <uint32_t R> void imprime_con_detalle_bitwise_AND(std::ostream& os, const wuint<R>& A, std::string A_name, const wuint<R>& B, std::string B_name)
{
    const wuint<R> arg_A{ A };
    const wuint<R> arg_B{ B };
    os << "Bitwise operator AND &. Se muestra " << A_name << "&" << B_name << " == ";
    os << (arg_A & arg_B) << std::endl;
    os << arg_A.to_string(radixformat::bin) << "\n";
    os << arg_B.to_string(radixformat::bin) << "\n";
    os << (arg_A & arg_B).to_string(radixformat::bin) << "\n\n";
}

template <uint32_t R> void imprime_con_detalle_bitwise_EXOR(std::ostream& os, const wuint<R>& A, std::string A_name, const wuint<R>& B, std::string B_name)
{
    const wuint<R> arg_A{ A };
    const wuint<R> arg_B{ B };
    os << "Bitwise operator EXOR ^. Se muestra " << A_name << "^" << B_name << " == ";
    os << (arg_A ^ arg_B) << std::endl;
    os << arg_A.to_string(radixformat::bin) << "\n";
    os << arg_B.to_string(radixformat::bin) << "\n";
    os << (arg_A ^ arg_B).to_string(radixformat::bin) << "\n\n";
}

template <uint32_t R>
void imprime_con_detalle_bitwise_SHIFT_to_L(std::ostream& os, const wuint<R>& arg, std::string var_name, size_t n)
{
    const wuint<R> arg_{ arg };
    os << "Bitwise operator SHIFT_to_LEFT >>. Se muestra " << var_name << ">>" << n << " == ";
    os << arg_ << (arg_ >> n) << std::endl;
    os << (arg_ >> n).to_string(radixformat::bin) << "\n";
    os << arg_.to_string(radixformat::bin) << "\n\n";
}

template <uint32_t R>
void imprime_con_detalle_bitwise_SHIFT_to_R(std::ostream& os, const wuint<R>& arg, std::string var_name, size_t n)
{
    const wuint<R> arg_{ arg };
    os << "Bitwise operator SHIFT_to_RIGHT <<. Se muestra " << var_name << "<<" << n << " == ";
    os << arg_ << (arg_ << n) << std::endl;
    os << (arg_ << n).to_string(radixformat::bin) << "\n";
    os << arg_.to_string(radixformat::bin) << "\n\n";
}

template <uint32_t R>
void imprime_con_detalle_bitwise_SHIFT2L_n_ASSIGN(std::ostream& os, const wuint<R>& arg, std::string var_name, size_t n)
{
    wuint<R> arg_{ arg };
    os << "Bitwise operator SHIFT_to_LEFT and ASSIGN >>=. Se muestra " << var_name << ">>=" << n << " == ";
    os << arg << " -> " << (arg_ >>= n) << std::endl;
    os << arg_.to_string(radixformat::bin) << "\n";
    os << arg.to_string(radixformat::bin) << "\n\n";
}

template <uint32_t R>
void imprime_con_detalle_bitwise_SHIFT2R_n_ASSIGN(std::ostream& os, const wuint<R>& arg, std::string var_name, size_t n)
{
    wuint<R> arg_{ arg };
    os << "Bitwise operator SHIFT_to_RIGHT and ASSIGN <<=. Se muestra " << var_name << "<<=" << n << " == ";
    os << arg_ << " -> " << (arg_ <<= n) << std::endl;
    os << arg_.to_string(radixformat::bin) << "\n";
    os << arg.to_string(radixformat::bin) << "\n\n";
}

template <uint32_t R> void imprime_con_detalle_bitwise_ORnASSIGN(std::ostream& os, const wuint<R>& A, std::string A_name, const wuint<R>& B, std::string B_name)
{
    wuint<R> arg_A{ A };
    wuint<R> arg_B{ B };
    os << "Bitwise operator ORnASSIGN |=. Se muestra (" << A_name << "|=" << B_name << ") == ";
    os << (arg_A |= arg_B) << std::endl;
    os << arg_A.to_string(radixformat::bin) << "\n";
    os << arg_B.to_string(radixformat::bin) << "\n";
    arg_A = A;
    os << (arg_A |= arg_B).to_string(radixformat::bin) << "\n\n";
}

template <uint32_t R>
void imprime_con_detalle_bitwise_ANDnASSIGN(std::ostream& os, const wuint<R>& A, std::string A_name, const wuint<R>& B, std::string B_name)
{
    wuint<R> arg_A{ A };
    wuint<R> arg_B{ B };
    os << "Bitwise operator ANDnASSIGN &=. Se muestra (" << A_name << "&=" << B_name << ") == ";
    os << (arg_A &= arg_B) << std::endl;
    os << arg_A.to_string(radixformat::bin) << "\n";
    os << arg_B.to_string(radixformat::bin) << "\n";
    arg_A = A;
    os << (arg_A &= arg_B).to_string(radixformat::bin) << "\n\n";
}

template <uint32_t R>
void imprime_con_detalle_bitwise_XORnASSIGN(std::ostream& os, const wuint<R>& A, std::string A_name, const wuint<R>& B, std::string B_name)
{
    wuint<R> arg_A{ A };
    wuint<R> arg_B{ B };
    os << "Bitwise operator XORnASSIGN ^=. Se muestra (" << A_name << "^=" << B_name << ") == ";
    os << (arg_A ^= arg_B) << std::endl;
    os << arg_A.to_string(radixformat::bin) << "\n";
    os << arg_B.to_string(radixformat::bin) << "\n";
    arg_A = A;
    os << (arg_A ^= arg_B).to_string(radixformat::bin) << "\n\n";
}

template <uint32_t R> void imprime_con_detalle(std::ostream& os, const wuint<R>& arg, std::string var_name)
{
    wuint<R> arg_{ arg };
    os << "El dígito base " << R << "      " << var_name << "  ==  ";
    os << arg_ << "  -> bin(R=2)  :\n";
    os << arg_.to_string(radixformat::bin);
    os << '\n';
    os << '\n';
}

template <uint32_t R> void imprime_con_detalle_unary_MINUS(std::ostream& os, const wuint<R>& arg, std::string var_name)
{
    wuint<R> arg_{ arg };
    os << "Flip every bit plus 1 >> -" << var_name << "   ==  ";
    os << (-arg_) << "  -> (2) \n";
    os << arg_.to_string(radixformat::bin) << std::endl;
    os << (-arg_).to_string(radixformat::bin) << std::endl;
    os << '\n';
    os << '\n';
}

template <uint32_t R> void imprime_con_detalle_unary_COMPL(std::ostream& os, const wuint<R>& arg, std::string var_name)
{
    wuint<R> arg_{ arg };
    os << "Flip every bit >> ~" << var_name << "   ==  ";
    os << (~arg_) << "  -> (2) \n";
    os << arg_.to_string(radixformat::bin) << std::endl;
    os << (~arg_).to_string(radixformat::bin) << std::endl;
    os << '\n';
    os << '\n';
}

template <uint32_t R> void imprime_con_detalle_unary_PLUS(std::ostream& os, const wuint<R>& arg, std::string var_name)
{
    wuint<R> arg_{ arg };
    os << "All remains the same >> +" << var_name << "   ==  ";
    os << (+arg_) << "  -> (2) \n";
    os << arg_.to_string(radixformat::bin) << std::endl;
    os << (+arg_).to_string(radixformat::bin) << std::endl;
    os << '\n';
    os << '\n';
}

template <uint32_t R> void muestra_preincr(std::ostream& os, const wuint<R>& var, std::string var_name)
{
    wuint<R> var_cp{ var };
    os << "  Muestra el PREINCREMENTO de " << var_name << " " << uint32_t(var) << " veces seguidas.\n";
    os << "  " << var_name << "   == " << var_cp << '\n';
    while(var_cp < var + wuint<R>(10)) {
        ++var_cp;
        os << "++" << var_name << "   == " << var_cp << '\n';
    }
    os << "\n\n";
}

template <uint32_t R> void muestra_predecr(std::ostream& os, const wuint<R>& var, std::string var_name)
{
    wuint<R> var_cp{ var + wuint<R>(10) };
    os << "  Muestra el PREDECREMENTO de " << var_name << "+10   " << uint32_t(var) + 10 << " veces seguidas.\n";
    os << "  " << var_name << "   == " << var_cp << '\n';
    while(var_cp > wuint<R>(0)) {
        --var_cp;
        os << "--" << var_name << "   == " << var_cp << '\n';
    }
    os << "\n\n";
}

template <uint32_t R> void muestra_postincr(std::ostream& os, const wuint<R>& var, std::string var_name)
{
    wuint<R> var_cp{ var };
    os << "  Muestra el POSTINCREMENTO de " << var_name << " " << uint32_t(var) << " veces seguidas.\n";
    os << "  " << var_name << "   == " << var_cp << '\n';
    while(var_cp < var + wuint<R>(10)) {
        os << var_name << "++  ==" << var_cp++ << " y ahora vale " << var_cp << '\n';
    }
}

template <uint32_t R> void muestra_postdecr(std::ostream& os, const wuint<R>& var, std::string var_name)
{
    wuint<R> var_cp{ var };
    os << "  Muestra el POSTDECREMENTO de " << var_name << "+10   " << uint32_t(var) + 10 << " veces seguidas.\n";
    os << "  " << var_name << "   == " << var_cp << '\n';
    while(var_cp > wuint<R>(0)) {
        os << var_name << "--  ==" << var_cp-- << " y ahora vale " << var_cp << '\n';
    }
}


#endif // EXAMPLESWUINT_HPP
