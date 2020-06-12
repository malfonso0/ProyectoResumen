#pragma once
#include"cCliente.h"
#include <string>
#include "cListaT.h"
using namespace std;
class cArticulo;
class cArticuloVenta;//
class cArticuloElectrico;
typedef enum
{
	PAGO_CONTADO,
	TARJETA_DEBITO,
	TARJETA_CREDITO,
	PAGA_DIOS
}eFormaPago;

#define MAX_SIZE 100
class cVenta
{ /// si quiesieramos.. tambien un id!
	cCliente* cliente;
	cArticuloVenta** articulos;
	int TAM, CA;
	string Fecha; //time.h.. o hacer la clase fecha.. posta!
	eFormaPago FormaDePago;

public:
	cVenta(cCliente* cliente, string Fecha, eFormaPago fpago, int TAM=MAX_SIZE)
	{

		this->cliente = cliente;
		this->Fecha = Fecha;
		this->FormaDePago = fpago;

		this->TAM = TAM;
		CA = 0;
		articulos = new cArticuloVenta * [TAM];
		for (int i = 0; i < TAM; i++)
		{
			articulos[i] = NULL;
		}
	}
	~cVenta()
	{
	// NO VOY A ELIMINAR LOS ARTICULOS INTERNOS!
		if(articulos!=NULL)
			for (int i = 0; i < CA; i++)
			{
				if (articulos[i] != NULL)
					delete articulos[i];
				articulos[i] = NULL;
			}
			delete[] articulos;
		articulos = NULL;
	}


	void AgregarArticulo(cArticulo*art, int cantidad);
	void QuitarArticulo(cArticulo* art, int cant = -1);//-1 TODO
	float Total()const;
	void Imprimir()const;

	void operator+(cArticulo* art);// agrega solo 1;

	cArticuloVenta* operator[](int pos);
	//podriamos agregarle.
	int getArticuloPos(cArticulo* art);
	int getArticuloPos(string Descripcion);
	int getArticuloPos(int NroSerie);

	cListaT<cArticuloElectrico>* Electricos();
	//float TotalElectricos();



};

