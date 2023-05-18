Este proyecto tiene como finalidad el aprendizaje sobre los elementos de la libre´ria estándard de C++ introducidos en el estándard del año 2017, concretamente, `std::variant` y la función `std::visit`. Utilizo un conjunto de tipos paramtrizados por un número entero sin signo, `template<std::uint32_t R> class wuint` que hace referencia a una simple clase `wrapper` para un `unsigned int`. Ésta tiene todos los elementos que encontraríamos para un tipo entero sin signo cualquiera. El archivo de cabeceras o declaraciones (que es el único sitio en que descansa esta plantilla de clase) es `wuint.hpp`.

Digamos que la clase importante es la estructura `wuint_variant` que deriva de `std::variant<false_type,true_type,wuint<2>,...,wuint<size_of_variant-1>` que llamo `wuint_variant_t`. El tipo objetivo es `struct wuint_variant : public wuint_variant_t`.

Un objetivo de esta clase/estructura es que no tenga datos miembro y que las funciones miembro de `template<std::uint32_t> wuint` sean utilizadas tal cual en los `std::visit`. Por ejemplo, tenemos dos opciones para una función original de `wuint` que recoje 2 objetos `wuint` inalterables con el mismo parámetro de plantilla (tienen el mismo tipo) y devuelve una copia de la operación binaria realizada por la clase `wuint`.

Código C++:

    wuint_variant operator+(wuint_variant otro) const { 
        return wuint_variant(std::visit(
            []<std::uint32_t K,std::uint32_t L>(
                        wuint<K> left , wuint<L> right
                ) {
                    if ((K == L)&&(K > 1)&&(K < 64))
                        return left+right;
                    else
                        return wuint<K>(0);
                },
                *this,
                otro
            )
        );
    }

Otra posibilidad es:

    wuint_variant operator+(wuint_variant otro) const { 
        return wuint_variant(std::visit(
            []<std::uint32_t K,std::uint32_t L>(
                        wuint<K> left , wuint<L> right
                ) {
                    if ((K == L)&&(K > 1)&&(K < 64))
                        return wuint_variant(left+right);
                    else
                        return wuint_variant(std::false_type{});
                },
                *this,
                otro
            )
        );
    }

La última es la única que me funciona:

    wuint_variant operator+(wuint_variant otro) const {
      wuint_variant result{*this};
      result += otro;
      return result;  
    }

Todo esto es lo que intento solucionar (es lo que me queda por hacer funcionar, los operadores binarios con argumetos ctes. y salida por copia).
