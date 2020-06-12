#pragma once
#include <string>
#include <iostream>

using namespace std;
class cArticulo
{
protected:
	float Precio;
	string Descripcion;
	const int NroSerie;
	int Stock; // stock en la realidad.. es flotante

public:
	// Constructor con parametros por defecto
	cArticulo(int NroSeriee, string Descripcion, float Precio=0, int stock=0):NroSerie(NroSeriee)
	{
		this->Descripcion = Descripcion;
		this->Precio = Precio;
		this->Stock = stock;		
	}
	// Constructor por copia
	cArticulo(int NroSerie, const cArticulo& otro) :NroSerie(NroSerie)
	{
		Descripcion = otro.Descripcion;
		Precio = otro.Precio;
		Stock = otro.Stock;	
	}
	
	// GETERSSS DEBEN SER CONST!!!
	float getPrecio()const { return Precio; }
	string getDescripcion()const { return Descripcion; }
	int getNroSerie()const { return NroSerie; }
	int getStock()const { return Stock; }

	void setPrecio(float precio) {
		if (precio < 0)throw exception("Precio no puede ser negativo");
		this->Precio = precio;
	}
	void setDescripcion(string descripcion) {
		this->Descripcion = descripcion;
	}
	void ActualizarStock(int cant){ 
		Stock += cant;
		// se podria chequear stock negativo!
	}
	
	// para hacer la clase abstracta
	virtual void Imprimir()const = 0;
	
	// la llamada sera miarticulo+=4
	int operator+=(int cantidad) { // ven que es EXACTAMENTE LO MISMO.. solo cambia el nombre
		Stock += cantidad;
		return Stock;
	}
	const cArticulo& operator=(const cArticulo& der)
	{
		Descripcion = der.Descripcion;
		Stock = der.Stock;
		Precio = der.Precio;
		return der;
	}

	// SECCION FRIEND
	// recuerden.. es friend prototipo!
	friend ostream& operator<<(ostream& out, const cArticulo& art);
	friend istream& operator>>(istream& in, cArticulo& art);
	///sobrecargas logicas
	bool operator==(const cArticulo&otro)
	{
		if (NroSerie == otro.NroSerie &&
			Descripcion == otro.Descripcion &&
			Precio == otro.Precio)
			return true;
		return false;
	}

	bool operator==(string Descripcion)
	{
		return Descripcion == this->Descripcion;
	}

};
// la llamada sera miarticulo-=4
//int operator-=(cArticulo& art, int cantidad) { // ven que es EXACTAMENTE LO MISMO.. solo cambia el nombre
//	art.ActualizarStock(-cantidad);
//	return art.getStock();
//}

