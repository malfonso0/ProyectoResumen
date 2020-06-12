#pragma once
#include <string>
#include <iostream>
using namespace std;

class cArticulo; //FORWARD DECLARATION de la clase articulo
class cVenta;//mismo
class cArticuloVenta
{
	static int counter;
	const int id;
	cArticulo* articulo;
	cVenta* venta;// esta propiedad de NAVEGACION.. podria no estar
	int cantidad;

public:

	cArticuloVenta(cArticulo* art, cVenta* v, int cantidad = 1):id(counter++)
	{
		this->articulo = art;
		this->venta = v;
		this->cantidad = cantidad;
	}
	~cArticuloVenta()
	{
	//VACIO!.. NO debo eliminar el articulo.. 
	//porque hay mas ventas relacionadas al mismo

	// obviamente, no elimino venta.. porque es el PADRE
		articulo = NULL;
		venta = NULL;
	}
	friend cVenta;// solo para jugar con friend!
	int getID()const { return id; }
	// PRE INCREMENTO!
	cArticuloVenta& operator++()
	{
		cantidad++;
		return *this;	
	}
	// POST INCREMENTO
	cArticuloVenta operator++(int dummy)
	{
		cArticuloVenta otro(*this);
		cantidad++;
		return otro;
	}

	static int getLastID();
	float Total()const;
};

