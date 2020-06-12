#include "cVenta.h"
#include "cArticuloVenta.h"
#include "cArticulo.h"
#include "cArticuloElectrico.h"


void cVenta::AgregarArticulo(cArticulo* art, int cantidad)
{
	// primero verifico si mi articulo esta
	// si ya esta.. sumo cantidad..

	int pos = getArticuloPos(art->getNroSerie());
	bool hay_lugar = CA < TAM;
	if (pos < 0 && !hay_lugar)// debo agregar y no hay lugar
		throw exception("No hay lugar!");
	if (pos < 0) {// no estaba en la lista.
		cArticuloVenta* aventa = new cArticuloVenta(art, this, cantidad);
		articulos[CA++] = aventa;
		return;
	}
	// Si llega aca.. pos>=0. solo debo actualizar
	articulos[pos]->cantidad += cantidad;
	


}
void cVenta::QuitarArticulo(cArticulo* art, int cant)//-1 TODO
{
	int pos = getArticuloPos(art);
	if (pos < 0)
		throw exception("No estaba en la lista");

	cArticuloVenta* articulov = articulos[pos];
	if (cant >= 0 && articulov->cantidad > cant){
		articulov->cantidad -= cant;
		return;
	}

	// tengo que quitar

	for (int i = pos; i < CA-1; i++)
	{
		articulos[i] = articulos[i + 1];
	}
	CA--;
	articulos[CA] = NULL;

	delete articulov;//en este caso.. el "QUITAR" tambien elimina.
	//recordemos que articuloventa solo tiene sentido, en la venta actual

}
float cVenta::Total()const
{
	float total = 0;

	for (int i = 0; i < CA; i++)
	{
		total += articulos[i]->Total();
	}
	return total;
}
void cVenta::Imprimir()const
{
	cArticuloVenta* aux = NULL;
	for (int i = 0; i < CA; i++)
	{
		aux = articulos[i];
		cout << aux->cantidad<<"\t";
		//aux->articulo->Imprimir();
		cout << *(aux->articulo) << endl;
		//cout << endl;
	}


}

void cVenta::operator+(cArticulo* art)// agrega solo 1;
{
	AgregarArticulo(art, 1);
}

cArticuloVenta* cVenta::operator[](int pos)
{
	if (pos > 0 && pos << CA)
		return articulos[pos];
	else
		return NULL;
}
//podriamos agregarle.



int cVenta::getArticuloPos(cArticulo* art)
{

	for (int i = 0; i < CA; i++)
	{
		if (*art == articulos[i]->articulo[0])
			return i;
	}
	return -1;

}
int cVenta::getArticuloPos(string Descripcion)
{
	for (int i = 0; i < CA; i++)
	{
		if (Descripcion == articulos[i]->articulo->getDescripcion())
			return i;
	}
	return -1;
}
int cVenta::getArticuloPos(int NroSerie)
{
	for (int i = 0; i < CA; i++)
	{
		if (NroSerie == articulos[i]->articulo->getNroSerie())
			return i;
	}
	return -1;
}



cListaT<cArticuloElectrico>* cVenta::Electricos()
{
	int cantidad = 0;

	for (int i = 0; i < CA; i++)
	{
		if (dynamic_cast<cArticuloElectrico*>(articulos[i]->articulo) != NULL)
			cantidad++;
	}

	cListaT<cArticuloElectrico>* lista = new cListaT<cArticuloElectrico>(cantidad);
	cArticuloElectrico* aux = NULL;
	for (int i = 0; i < CA; i++)
	{
		aux=dynamic_cast<cArticuloElectrico*>(articulos[i]->articulo);
		if ( aux!= NULL)
			lista->Agregar(aux);
	}
	return lista;
}
