#pragma once
#include<string>

using namespace std;
class cCliente
{
	string RazonSocial;
	const string CUIT;
	bool validarcuit(string cuit) {
	// 12-12345678-1
	// 1234567890123
	//validar formato!
		return true;
	}

public:
										// al ser constante debe ir ACA!
	cCliente(string CUIT, string RazonSocial):CUIT(CUIT)
	{
		if (!validarcuit(CUIT))
			throw exception("CUIT INVALIDO");
		setRazonSocial(RazonSocial);
	}

	string getRazonSocial()const
	{
		return RazonSocial;
	}
	void setRazonSocial(string rs)
	{
		if (rs == "pure")
			throw exception("La razon social no puede ser pure!");
		RazonSocial = rs;	
	}

	string getCuit()const { return CUIT; }
	
	//lista de ventas!
};

