#include "Tren.h"

Tren::Tren(int codTT, int codigoT, string nombreT, int campos)
{
    refTipoTren=codTT;
    codigo=codigoT;
    nombre=nombreT;
    asientos=campos;
}

Tren::Tren()
{
}

Tren::~Tren()
{
}
void Conexion::Mostrar()
    {
        std::cout << "Codigo: " << codigo <<"Nombre: "<< nombre <<"Asientos: "<< asientos << "\n\n";
    }