// ProyectoResumen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "cListaT.h"

#include "cCliente.h"

#include "cArticuloElectrico.h"
#include "cArticuloLimpieza.h"

#include "cVenta.h"


void TestListaConEnteros()
{
    cListaT<int, int> milista(10, true);

    try {
        milista.Agregar(new int(5));
        milista.Agregar(new int(50));
        milista.Agregar(new int(10));

        milista.Listar();
        int* aux = milista.Quitar(50);
        delete aux;
        cout << endl;
        milista.Listar();


    }
    catch (exception ex)
    {
        cout << ex.what() << endl;
    }

}
void TestClaseCliente()
{
    cCliente* cliente=new cCliente("123131", "PEPE");
    cout << cliente->getCuit() << endl;
    cout << cliente->getRazonSocial()<< endl;
    try
    {
        cliente->setRazonSocial("pared");
        cliente->setRazonSocial("pure");
    }
    catch (const std::exception&ex)
    {
        cout << ex.what() << endl;
    }


}
void TestArticulos()
{
    cListaT<cArticulo, string> milista(10, true);

    try {
        milista.Agregar(new cArticuloElectrico(1, "Afeitadora", 110));
        milista.Agregar(new cArticuloLimpieza(1, "Procenex", 10));
        milista.Agregar(new cArticuloElectrico(1, "Lavarropa", 220));

        milista.Listar();
        cArticulo* aux = milista.Quitar("Lavarropa");
        delete aux;
        cout << endl;
        milista.Listar();


    }
    catch (exception& ex)
    {
        cout << ex.what() << endl;
    }

    /// deberia COMPLETAR.. con los demas metodos hechos para las 3 clases
    //Art, ArtElec y ArtLimp
}
int main()
{
    cCliente* cliente = new cCliente("31289257", "Manuel");

    //*****************************
    //truquillo.. agregar esta lista.. como metodo ESTATICO de la clase articulo
    // agregar elementos al crear
    //remover elementos al eliminar

    cListaT<cArticulo> articulos(50, true);
    articulos.Agregar(new cArticuloElectrico(1, "Afeitadora", 110));
    articulos.Agregar(new cArticuloLimpieza(2, "Procenex", 10));
    articulos.Agregar(new cArticuloElectrico(3, "Lavarropa", 220));
    articulos.Agregar(new cArticuloLimpieza(4, "Detergente", 220));
    articulos.Agregar(new cArticuloElectrico(5, "Computadora", 220));
    articulos.Agregar(new cArticuloLimpieza(6, "Lavandina", 220));
    articulos.Agregar(new cArticuloElectrico(7, "Mouse", 220));
    articulos.Agregar(new cArticuloLimpieza(8, "Gato", 220));
    articulos.Agregar(new cArticuloElectrico(9, "Nebulizador", 220));
    articulos.Agregar(new cArticuloLimpieza(10, "Jabon", 10));

    //*****************************

    cVenta venta1(cliente, "12/06/2020", eFormaPago::PAGO_CONTADO);
    cVenta venta2(cliente, "10/06/2020", eFormaPago::PAGA_DIOS);


    venta1.AgregarArticulo(articulos[0], 1);
    venta1.AgregarArticulo(articulos[0], 2);//3
    venta1.AgregarArticulo(articulos[1], 3);
    venta1.AgregarArticulo(articulos[6], 4);
    venta1.AgregarArticulo(articulos[7], 2);
    venta1 + articulos[2];
    venta1.AgregarArticulo(articulos[5], 2);

    cout << "--------------VENTA 1 -----------------------" << endl;
    venta1.Imprimir();
    cout << venta1.Total() << endl;
    cListaT<cArticuloElectrico>* electricos = venta1.Electricos();
    delete electricos;

    venta2.AgregarArticulo(articulos[5], 3);
    venta2.AgregarArticulo(articulos[6], 4);
    venta2.AgregarArticulo(articulos[7], 2);
    venta2.AgregarArticulo(articulos[8], 1);
    venta2 +articulos[9];

    venta2.QuitarArticulo(articulos[8]);
    cout << "--------------VENTA 2 -----------------------" << endl;
    venta2.Imprimir();


    system("pause");
    return 0;
}