#include "cArticulo.h"
#include "cArticuloLimpieza.h"
#include "cArticuloElectrico.h"
#include <iomanip>

// uso cout<<miarticulo
ostream& operator<<(ostream& out, const cArticulo& art)
{
	bool FRIEND = true; // SOLO PARA EL EJEMPLO!!

	if (!FRIEND)// Linea para cuando no es FRIEND
		out << setw(5) << art.getNroSerie() << "\t" << setw(45) << art.getDescripcion() << "\t" << setw(10) << art.getPrecio();
	else // Si fuera friend
		out << art.NroSerie << "\t" << art.Descripcion << "\t" << art.Precio;

	return out;
}

istream& operator>>(istream& in, cArticulo& art) {
	cout << "Ingrese Precio: ";
	bool FRIEND = true; // SOLO PARA EL EJEMPLO!!
	if (!FRIEND) { // Seccion SIN FRIEND
		float auxfloat;
		in >> auxfloat; //LEO HACIA EL AUXILIAR
		art.setPrecio(auxfloat); //luego utilizo el SETTER
	}
	else// seccion con FRIEND
		in >> art.Precio; //si es friend.. puedo leer hacia el atributo directamente
	return in;
}


ostream& operator<<(ostream& out, const cArticuloLimpieza& art)
{
	cArticulo& artt = (cArticulo&)art; // ME QUEDO CON LA PARTE
	out << artt << "\t" << setw(10) << art.getCloro();// PADRE.. y la imprimo!
	return out;
}

istream& operator>>(istream& in, cArticuloLimpieza& art) {
	cArticulo& artt = (cArticulo&)art; // ME QUEDO CON LA PARTE
	in >> artt;						// PADRE.. y la lleno!
	int aux;
	cout << "Cantidad de cloro: ";
	in >> aux;
	art.setCloro(aux);

	return in;
}

istream& operator>>(istream& in, cArticuloLimpieza* art) {
	cArticulo* artt = (cArticulo*)art; // ME QUEDO CON LA PARTE	PADRE.. y la lleno!
	in >> (*artt);// aca con puntero, porque en el padre solo implemente por alias!
	int aux;
	cout << "Cantidad de cloro: ";
	in >> aux;
	art->setCloro(aux);

	return in;
}



ostream& operator<<(ostream& out, const cArticuloElectrico& art)
{
	cArticulo& artt = (cArticulo&)art; // ME QUEDO CON LA PARTE
	out << artt << "\t" << setw(10) << art.getVoltaje();// PADRE.. y la imprimo!

	return out;
}

istream& operator>>(istream& in, cArticuloElectrico& art) {
	cArticulo& artt = (cArticulo&)art; // ME QUEDO CON LA PARTE
	in >> artt;						// PADRE.. y la lleno!
	int aux;
	cout << "Voltaje: ";
	in >> aux;
	art.setVoltaje(aux);

	return in;
}
