int main() - indica que la funci�n "main" debe regresar un entero, y no recibe par�metros. Antes de cerrar la funci�n tienes que poner un "return 0;", ojo, es 0 no (). 

int main (void) - Es lo mismo que la anterior, s�lo que con �sta, est�s indicando de manera expl�cita que no se reciben par�metros, pero su funcionameniento es exactamente igual que la anterior. 

void main() - Aqu� est�s indicando que "main" no regresa ning�n valor, o sea, antes de cerrarla no debes poner el "return 0;". Tambi�n indica que no tiene par�metros. 

main() - Esta manera ya no se usa, pero seg�n recuerdo, es igual que "void main()". 

Hay varias cosas que se tienen que tomar en cuenta, por ejemplo que el estandar de C/C++ dice que "main" debe regresar un entero, por lo que la correcta es "int main()". La palabra clave "void" tiene dos significados: 

- si est� delante del nombre de una funci�n (void main), indica que esa funci�n no regresa ning�n valor (o sea, no usa "return"). 

- si est� dentro de los par�ntesis de una funci�n (main (void)) indica que esa funci�n no admite par�metros. Esta manera de usar no tiene mucha utilidad, ya que main () y main (void) hacen exactamente lo mismo