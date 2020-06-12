#include "cArticuloVenta.h"
#include "cArticulo.h"

//#include "cVenta"

float cArticuloVenta::Total()const { return articulo->getPrecio() * cantidad; }
int cArticuloVenta::getLastID() { return counter; }

// INICIALIZO ATRIBUTO ESTATICO!
int cArticuloVenta::counter = 0;
