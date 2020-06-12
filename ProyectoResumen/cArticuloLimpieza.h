#pragma once
#include "cArticulo.h"
class cArticuloLimpieza :
    public cArticulo
{
    int cantidadCloro;
public:
	// recuerden. que necesitamos llenar las cosas del padre tambien!
	cArticuloLimpieza(int NroSerie, string Descripcion,int cloro):cArticulo(NroSerie, Descripcion)
	{
		this->cantidadCloro = cloro;
	}

	// Implementamos funcion IMPRIMIR!.. sino esta clase seguiria siendo ABSTRACTA
	virtual void Imprimir()const
	{
		cout << "ARTICULO LIMPIEZA!" << endl;
		cout << this->NroSerie << endl;	
	}

	int getCloro()const { return cantidadCloro; }
	void setCloro(int cl) { cantidadCloro = cl; }
};

