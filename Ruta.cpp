#include "Ruta.h"

Ruta::Ruta(int codTT, int codT, int codigoR, int codPais, int codCiudad, int codPais2, int codCiudad2, int costo)
{
    refTipoTren=codTT;
    refTren=codT;
    codigo=codigoR;
    refPais=codPais;
    refCiudad=codCiudad;
    refPais2=codPais2;
    refCiudad2=codCiudad2;
    precio=costo;
}

Ruta::Ruta()
{
}

Ruta::~Ruta()
{
}
