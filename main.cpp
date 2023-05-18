
#include <wuint.hpp>
#include <ExamplesWUint.hpp>
#include <wuint_variant.hpp>
#include <iostream>
#include <limits>

int main(int argc, char** argv)
{
    wuint_variant var1{wuint<10>{100}};
    std::cout << var1.natural_binary() << std::endl;
    std::cout << static_cast<std::uint32_t>(var1) << std::endl;
    std::cout << var1.to_binary_string() << std::endl;
    std::cout << var1.to_string() << std::endl;
    std::cout << var1.radix() << std::endl;
    wuint_variant var2{wuint<10>{100}};
    wuint_variant var3{wuint<10>{6}};
    const bool v12{var1 == var2};
    std::cout << std::boolalpha << v12 << "  ¿==?  true\t\t"  << ((v12)?("OK!"):("Fail!")) << '\n';
    const bool v13{var1 == var3};
    std::cout << std::boolalpha << v13 << "  ¿==?  false\t\t"  << ((!v13)?("OK!"):("Fail!")) << '\n';
    const bool nv12{var1 != var2};
    std::cout << std::boolalpha << nv12 << "  ¿!=?  false\t\t"  << ((!nv12)?("OK!"):("Fail!")) << '\n';
    const bool nv13{var1 != var3};
    std::cout << std::boolalpha << nv13 << "  ¿!=?  true\t\t"  << ((nv13)?("OK!"):("Fail!")) << '\n';

    {
        wuint_variant var(wuint<63>{0});
        for(std::size_t i{0} ; i < 10 ; ++i) {
            std::cout << var.to_string() << " ; ";
            ++var;
        }
        std::cout << var.to_string() << "\n";
        std::cout << "FIN PREINCREMENTO\n\n";
        for(std::size_t i{0} ; i < 10 ; ++i) {
            std::cout << var.to_string() << " ; ";
            --var;
        }
        std::cout << var.to_string() << "\n";
        std::cout << "FIN PREDECREMENTO\n\n";
    }

    {
        wuint_variant var(wuint<63>{0});
        for(std::size_t i{0} ; i < 10 ; ++i) {
            std::cout << var++.to_string() << " --> ";
            std::cout << var.to_string() << " ; ";
        }
        std::cout << "\n";
        std::cout << "FIN POSTINCREMENTO\n\n";
        for(std::size_t i{0} ; i < 10 ; ++i) {
            std::cout << var--.to_string() << " --> ";
            std::cout << var.to_string() << " ; ";
        }
        std::cout << "\n";
        std::cout << "FIN POSTDECREMENTO\n\n";
    }

     {
        wuint_variant var(wuint<53>{3});
        std::cout << "var == " << var.to_string(radixformat::dec) << "\n";
        const std::string dig_str{"dig#27#R53"};
        const bool parse_bien{var.from_string(dig_str)};
        if (parse_bien) {
            std::cout << "var == " << var.to_string(radixformat::dec) << "\n";
        } else {
            std::cout << "Algo ha ido mal en el parseado.\n";
        }
        std::cout << "\n";
        std::cout << "FIN FROM_STRING\n\n";
    }

    {
        wuint_variant leftvar(wuint<53>{13});
        wuint_variant rightvar(wuint<53>{21});
        std::cout << "\n\n\n";
        std::cout << "\t-------BITWISE   ORnASSIGN-------" << std::endl;
        std::cout << "left    variable\t==\t(bin)" << leftvar.to_binary_string() << std::endl;
        std::cout << "right   variable\t==\t(bin)" << rightvar.to_binary_string() << std::endl;
        std::cout << "right  |=   left\t==\t(bin)" << (rightvar|=leftvar).to_binary_string() << std::endl;
        std::cout << "\n\n\n";
    }

     {
        wuint_variant leftvar(wuint<53>{13});
        wuint_variant rightvar(wuint<53>{21});
        std::cout << "\n\n\n";
        std::cout << "\t-------BITWISE ANDnASSIGN-------" << std::endl;
        std::cout << "left    variable\t==\t(bin)" << leftvar.to_binary_string() << std::endl;
        std::cout << "right   variable\t==\t(bin)" << rightvar.to_binary_string() << std::endl;
        std::cout << "right  &=   left\t==\t(bin)" << (rightvar&=leftvar).to_binary_string() << std::endl;
        std::cout << "\n\n\n";
    }

     {
        wuint_variant leftvar(wuint<53>{13});
        wuint_variant rightvar(wuint<53>{21});
        std::cout << "\n\n\n";
        std::cout << "\t-------BITWISE XORnASSIGN-------" << std::endl;
        std::cout << "left    variable\t==\t(bin)" << leftvar.to_binary_string() << std::endl;
        std::cout << "right   variable\t==\t(bin)" << rightvar.to_binary_string() << std::endl;
        std::cout << "right  ^=   left\t==\t(bin)" << (rightvar^=leftvar).to_binary_string() << std::endl;
        std::cout << "\n\n\n";
    }

    {
        wuint_variant leftvar(wuint<53>{13});
        wuint_variant rightvar(wuint<53>{21});
        std::cout << "\n\n\n";
        std::cout << "\t-------BITWISE_____________OR-------" << std::endl;
        std::cout << "left    variable\t==\t(bin)" << leftvar.to_binary_string() << std::endl;
        std::cout << "right   variable\t==\t(bin)" << rightvar.to_binary_string() << std::endl;
        std::cout << "right  |    left\t==\t(bin)" << (rightvar|leftvar).to_binary_string() << std::endl;
        std::cout << "\n\n\n";
    }

     {
        wuint_variant leftvar(wuint<53>{13});
        wuint_variant rightvar(wuint<53>{21});
        std::cout << "\n\n\n";
        std::cout << "\t-------BITWISE_____________AND-------" << std::endl;
        std::cout << "left    variable\t==\t(bin)" << leftvar.to_binary_string() << std::endl;
        std::cout << "right   variable\t==\t(bin)" << rightvar.to_binary_string() << std::endl;
        std::cout << "right  &    left\t==\t(bin)" << (rightvar&leftvar).to_binary_string() << std::endl;
        std::cout << "\n\n\n";
    }

     {
        wuint_variant leftvar(wuint<53>{13});
        wuint_variant rightvar(wuint<53>{21});
        std::cout << "\n\n\n";
        std::cout << "\t-------BITWISE_____________XOR-------" << std::endl;
        std::cout << "left    variable\t==\t(bin)" << leftvar.to_binary_string() << std::endl;
        std::cout << "right   variable\t==\t(bin)" << rightvar.to_binary_string() << std::endl;
        std::cout << "right  ^    left\t==\t(bin)" << (rightvar^leftvar).to_binary_string() << std::endl;
        std::cout << "\n\n\n";
    }

    {
        wuint_variant rightvar(wuint<53ul>{21ul});
        std::cout << "\n\n\n";
        std::cout << "\t----------------UNARY_PLUS----------------" << std::endl;
        std::cout << " right   variable\t==\t(bin)" << rightvar.to_binary_string() << std::endl;
        std::cout << "+right   variable\t==\t(bin)" << (+rightvar).to_binary_string() << std::endl;
        std::cout << "\n\n\n";
    }

    {
        wuint_variant rightvar(wuint<53ul>{21ul});
        std::cout << "\n\n\n";
        std::cout << "\t----------------UNARY_MINUS---------------" << std::endl;
        std::cout << " right   variable\t==\t(bin)" << rightvar.to_binary_string() << std::endl;
        std::cout << "-right   variable\t==\t(bin)" << (-rightvar).to_binary_string() << std::endl;
        std::cout << "\n\n\n";
    }

    {
        wuint_variant rightvar(wuint<53ul>{21ul});
        std::cout << "\n\n\n";
        std::cout << "\t----------------COMPLEMENT_OPERATOR---------------" << std::endl;
        std::cout << " right   variable\t==\t(bin)" << rightvar.to_binary_string() << std::endl;
        std::cout << "~right   variable\t==\t(bin)" << (~rightvar).to_binary_string() << std::endl;
        std::cout << "\n\n\n";
    }

    {
        wuint_variant leftvar(wuint<53ul>{32ul});
        wuint_variant rightvar(wuint<53ul>{21ul});
        std::cout << "\n\n\n";
        std::cout << "\t-------------ADDnASSIGN_OPERATOR---------------" << std::endl;
        std::cout << "  left   variable\t==\t" << leftvar.to_string() << std::endl;
        std::cout << "  right  variable\t==\t" << rightvar.to_string() << std::endl;
        std::cout << "  l+=r   variable\t==\t" << (leftvar+=rightvar).to_string() << std::endl;
        std::cout << "  left   variable\t==\t" << leftvar.to_string() << std::endl;
        std::cout << "\n\n\n";
    }


    {
        wuint_variant leftvar(wuint<53ul>{32ul});
        wuint_variant rightvar(wuint<53ul>{21ul});
        std::cout << "\n\n\n";
        std::cout << "\t-------MULTnASSIGN_OPERATOR-plus-OSTREAM-----------" << std::endl;
        std::cout << "  left   variable\t==\t" << leftvar << std::endl;
        std::cout << "  right  variable\t==\t" << rightvar << std::endl;
        std::cout << "  l*=r   variable\t==\t" << (leftvar*rightvar) << std::endl;
        std::cout << "  left   variable\t==\t" << leftvar << std::endl;
        std::cout << "\n\n\n";
    }
    
    {
        std::cout << "\n\n\n";
        std::cout << "\t-------CREATE_IN_RUNTIME-----------" << std::endl;
        std::cout << "  create variable of Radix=10 and Value= 7\t==\t" << make_wuint_variant(10,  7) << std::endl;
        std::cout << "  create variable of Radix=50 and Value=31\t==\t" << make_wuint_variant(50,31) << std::endl;
        std::cout << "  create variable of Radix=47 and Value=23\t==\t" << make_wuint_variant(47,23) << std::endl;
        std::cout << "  create variable of Radix= 2 and Value= 1\t==\t" << make_wuint_variant(  2,  1) << std::endl;
        std::cout << "\n\n\n";
    }
    
    { /// CRUZO LOS DEDOS
        wuint_variant leftvar(wuint<53ul>{32ul});
        wuint_variant rightvar(wuint<53ul>{21ul});
        std::cout << "\n\n\n";
        std::cout << "\t-------ADD_2_ARGUMENTS_AND_RETURN_A_VARIANT_OF_CRRECT_TYPE_AND_VALUE-----------" << std::endl;
        std::cout << "  left   variable\t==\t" << leftvar << std::endl;
        std::cout << "  right  variable\t==\t" << rightvar << std::endl;
        std::cout << "  l + r   variable\t==\t" << (leftvar+rightvar) << std::endl;
        std::cout << "  left   variable\t==\t" << leftvar << std::endl;
        std::cout << "\n\n\n";
    }

//    wuint<10> A{ 25 };
//    imprime_con_detalle(std::cout, A, "A");
//    wuint<10> B{};
//    std::cout << "Introduce un digito de base " << 10 << " con el formato apropiado: ";
//    std::cin >> B;
//    imprime_con_detalle(std::cout, B, "B");
//    imprime_con_detalle_unary_MINUS(std::cout, A, "A");
//    imprime_con_detalle_unary_COMPL(std::cout, A, "A");
//    imprime_con_detalle_unary_PLUS(std::cout, A, "A");
//    imprime_con_detalle_unary_MINUS(std::cout, B, "B");
//    imprime_con_detalle_unary_COMPL(std::cout, B, "B");
//    imprime_con_detalle_unary_PLUS(std::cout, B, "B");

//    imprime_con_detalle_bitwise_OR(std::cout, A, "A", B, "B");
//    imprime_con_detalle_bitwise_AND(std::cout, A, "A", B, "B");
//    imprime_con_detalle_bitwise_EXOR(std::cout, A, "A", B, "B");

//    imprime_con_detalle_bitwise_ORnASSIGN(std::cout, A, "A", B, "B");
//    imprime_con_detalle_bitwise_ANDnASSIGN(std::cout, A, "A", B, "B");
//    imprime_con_detalle_bitwise_XORnASSIGN(std::cout, A, "A", B, "B");

//    imprime_con_detalle_bitwise_SHIFT_to_L(std::cout, A, "A", 0u);
//    imprime_con_detalle_bitwise_SHIFT_to_L(std::cout, A, "A", 1u);
//    imprime_con_detalle_bitwise_SHIFT_to_L(std::cout, A, "A", 2u);
//    imprime_con_detalle_bitwise_SHIFT_to_L(std::cout, A, "A", 3u);
//    imprime_con_detalle_bitwise_SHIFT_to_L(std::cout, A, "A", 4u);
//    imprime_con_detalle_bitwise_SHIFT_to_L(std::cout, A, "A", 5u);

//    imprime_con_detalle_bitwise_SHIFT_to_R(std::cout, A, "A", 0u);
//    imprime_con_detalle_bitwise_SHIFT_to_R(std::cout, A, "A", 1u);
//    imprime_con_detalle_bitwise_SHIFT_to_R(std::cout, A, "A", 2u);
//    imprime_con_detalle_bitwise_SHIFT_to_R(std::cout, A, "A", 3u);
//    imprime_con_detalle_bitwise_SHIFT_to_R(std::cout, A, "A", 4u);
//    imprime_con_detalle_bitwise_SHIFT_to_R(std::cout, A, "A", 5u);

//    imprime_con_detalle_bitwise_SHIFT_to_L(std::cout, B, "B", 0u);
//    imprime_con_detalle_bitwise_SHIFT_to_L(std::cout, B, "B", 1u);
//    imprime_con_detalle_bitwise_SHIFT_to_L(std::cout, B, "B", 2u);
//    imprime_con_detalle_bitwise_SHIFT_to_L(std::cout, B, "B", 3u);
//    imprime_con_detalle_bitwise_SHIFT_to_L(std::cout, B, "B", 4u);
//    imprime_con_detalle_bitwise_SHIFT_to_L(std::cout, B, "B", 5u);

//    imprime_con_detalle_bitwise_SHIFT_to_R(std::cout, B, "B", 0u);
//    imprime_con_detalle_bitwise_SHIFT_to_R(std::cout, B, "B", 1u);
//    imprime_con_detalle_bitwise_SHIFT_to_R(std::cout, B, "B", 2u);
//    imprime_con_detalle_bitwise_SHIFT_to_R(std::cout, B, "B", 3u);
//    imprime_con_detalle_bitwise_SHIFT_to_R(std::cout, B, "B", 4u);
//    imprime_con_detalle_bitwise_SHIFT_to_R(std::cout, B, "B", 5u);

//    imprime_con_detalle_bitwise_SHIFT2L_n_ASSIGN(std::cout, B, "B", 3u);
//    imprime_con_detalle_bitwise_SHIFT2R_n_ASSIGN(std::cout, B, "B", 10u);

//    imprime_con_detalle_bitwise_SHIFT2L_n_ASSIGN(std::cout, A, "A", 3u);
//    imprime_con_detalle_bitwise_SHIFT2R_n_ASSIGN(std::cout, A, "A", 10u);

//    muestra_preincr(std::cout, A, "A");
//    muestra_preincr(std::cout, B, "B");
//    muestra_predecr(std::cout, A, "A");
//    muestra_predecr(std::cout, B, "B");

//    muestra_postincr(std::cout, A, "A");
//    muestra_postincr(std::cout, B, "B");
//    muestra_postdecr(std::cout, A, "A");
//    muestra_postdecr(std::cout, B, "B");

    /*  std::cout << (A+B) << std::endl;
      std::cout << (A-B) << std::endl;
      std::cout << (A*B) << std::endl;
      std::cout << (A/B) << std::endl;
      std::cout << (A%B) << std::endl;
      wuint<10> C{A};
      std::cout << (C+=B) << std::endl;
      C = A;
      std::cout << (C-=B) << std::endl;
      C = A;
      std::cout << (C*=B) << std::endl;
      C = A;
      std::cout << (C/=B) << std::endl;
      C = A;
      std::cout << (C%=B) << std::endl;
      C = A;
      std::cout << (C|=B) << std::endl;
      C=A;
      std::cout << (C&=B) << std::endl;
      C=A;
      std::cout << (C^=B) << std::endl;*/

//    char espera;
//    std::cin >> espera;

    return 0;
}
