#include "Ciudad.h"
#include <iostream>

Ciudad::Ciudad(int codPais, int codigoC, string nombreC)
{
    refPais=codPais;
    codigo=codigoC;
    nombre=nombreC;
    listaConexiones = new ListaDobleGenerica<Conexion> ();
}

Ciudad::Ciudad()
{
    listaConexiones = new ListaDobleGenerica<Conexion> ();
}

Ciudad::~Ciudad()
{
}
void Ciudad::Mostrar()
    {
        std::cout << "Codigo: " << codigo << "  Nombre: " << nombre << "\n\n";
    }