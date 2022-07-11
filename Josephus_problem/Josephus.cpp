#include <iostream>

//Funcion para encontrar la posible potencia mas grande
int bpp(int n){ //bpp - best posible power
  int position = 0;
  while(n != 0){
    position++;

    n = n >> 1; //Aqui se siguen cambiando los numeros a la derecha hasta que quedemos con 0.
  }
  return position;
}

//Funcion para dar a conocer que lugar Josephus se debe sentar para sobrevivir
int josephus(int n){

  int position = bpp(n); //Aqui se obtiene la mayor potencia posible.
  
  int i = 1 << (position - 1); //En i se almacena el número con el que se va a | or el número n.
  
  n = n ^ i; //En esta parte, se cambia la mayor potencia posible a la izquierda en este caso cambiando el 1 más a la izquierda a 0.

  n = n << 1; //Se mueve a la izquierada una vez, esto para añadir un 0 extra al extremo derecho del número binario.

  n = n | 1; //En este apartado se cambia el ultimo digito binario por 1.

  return n;
}

int main() {
  
  int n = 0;
  std::cout << "Enter the number of soldiers in the circle: "; //En este apartado se pide la entrada del número de soldados.
  std::cin >> n; 
  std::cout << "The person who survives is in the position: " << josephus(n); // Se imprime la posición del que sobrevive.

  return 0;
}

/*
El problema Josephus se trata de soldados que se colocan en un circulo. Cada persona mata a la persona que este 
enseguida en una dirección especifica. Si la persona mata a la persona que tiene a la derecha la dirreción se mantiene. 
La ultima persona viva es liberada, entonces el programa encontrara esa posición para que la persona quede viva.
*/
