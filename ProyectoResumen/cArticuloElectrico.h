#pragma once
#include "cArticulo.h"
class cArticuloElectrico :
	public cArticulo
{
	int Voltaje;
public:
	// recuerden. que necesitamos llenar las cosas del padre tambien!

	cArticuloElectrico(int NroSerie, string Descripcion, int voltaje) :cArticulo(NroSerie, Descripcion)
	{
		this->Voltaje = voltaje;
	}

	// Implementamos funcion IMPRIMIR!.. sino esta clase seguiria siendo ABSTRACTA
	virtual void Imprimir()const
	{
		cout << "ARTICULO ELECTRICO!" << endl;
		cout << this->NroSerie << endl;
	}

	int getVoltaje()const { return Voltaje; }
	void setVoltaje(int v) { Voltaje = v; }
};
