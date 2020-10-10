#include "Usuario.h"

Usuario::Usuario(int codPais, int codCiudad, string numPasaporte, string nombreU, int estado)
{
    refPais=codPais;
    refCiudad=codCiudad;
    codigo=numPasaporte;
    nombre=nombreU;
    estadoMigratorio=estado;
}

Usuario::Usuario()
{
}

Usuario::~Usuario()
{
}
