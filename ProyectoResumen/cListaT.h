#pragma once
#include <exception>
#include <string>
#include <iostream>
using namespace std;
#define SIZE 100
template <class T, class U=string>
class cListaT
{
	T** vector;
	int CA, TAM;
	bool on_delete_erase;
	bool allow_duplicates;
public:
	cListaT(int TAM=SIZE, bool on_delete_erase=false	)
	{
		this->TAM = TAM;
		CA = 0;
		vector = new T * [TAM];
		for (int i = 0; i < TAM; i++)
		{
			vector[i] = nullptr;
		}
		this->on_delete_erase = on_delete_erase;
		allow_duplicates = false;
	}
	~cListaT() {	
		if (vector != nullptr)
		{
			if (on_delete_erase)
			{
				for (int i = 0; i < CA; i++)
				{
					if (vector[i] != nullptr)
						delete vector[i];
				}
			}
			delete[] vector;	
		}
		vector = nullptr;
	}

	void Agregar(T* objeto)
	{
	
		int pos = getPos(objeto);
		bool hay_lugar = CA < TAM;
		if (!hay_lugar)
			throw exception("No Hay Lugar");
		if(pos>=0 && !allow_duplicates)
			throw exception("ya esta en la lista");

		vector[CA++] = objeto;
	}

	T* Quitar(T* objeto)
	{
		int pos = getPos(objeto);
		if (pos < 0)
			return NULL;
		T* aux = vector[pos];
		for (int i = pos; i < CA - 1; i++)
		{
			vector[i] = vector[i + 1];
		}
		CA--;
		vector[CA] = NULL;
		return aux;
	}
	T* Quitar(U clave)
	{
		int pos = getPos(clave);
		if (pos < 0)
			return NULL;
		T* aux = vector[pos];
		for (int i = pos; i < CA - 1; i++)
		{
			vector[i] = vector[i + 1];
		}
		CA--;
		vector[CA] = NULL;
		return aux;
	
	}

	int getPos(T* objeto)
	{
		for (int i = 0; i < CA; i++)
		{
			// para esto.. necesito sobrecarga de ==
			if (*objeto == *(vector[i]))
				return i;
		}
		return -1;
	}
	
	int getPos(U clave)
	{
		for (int i = 0; i < CA; i++)
		{
			// para esto.. necesito sobrecarga de ==
			//con un string
			if ( (*vector[i])==clave)
				return i;
		}
		return -1;
	
	}


	void Listar()
	{
		for (int i = 0; i < CA; i++)
		{
			cout << *vector[i] << endl;
		}
	
	}

	T* operator[](unsigned int pos)
	{
		if (pos < CA)
			return vector[pos];
		else
			return NULL;
	
	}
};

