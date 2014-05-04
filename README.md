int main() - indica que la función "main" debe regresar un entero, y no recibe parámetros. Antes de cerrar la función tienes que poner un "return 0;", ojo, es 0 no (). 

int main (void) - Es lo mismo que la anterior, sólo que con ésta, estás indicando de manera explícita que no se reciben parámetros, pero su funcionameniento es exactamente igual que la anterior. 

void main() - Aquí estás indicando que "main" no regresa ningún valor, o sea, antes de cerrarla no debes poner el "return 0;". También indica que no tiene parámetros. 

main() - Esta manera ya no se usa, pero según recuerdo, es igual que "void main()". 

Hay varias cosas que se tienen que tomar en cuenta, por ejemplo que el estandar de C/C++ dice que "main" debe regresar un entero, por lo que la correcta es "int main()". La palabra clave "void" tiene dos significados: 

- si está delante del nombre de una función (void main), indica que esa función no regresa ningún valor (o sea, no usa "return"). 

- si está dentro de los paréntesis de una función (main (void)) indica que esa función no admite parámetros. Esta manera de usar no tiene mucha utilidad, ya que main () y main (void) hacen exactamente lo mismo