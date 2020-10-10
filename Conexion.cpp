#include "Conexion.h"

Conexion::Conexion(int codPais, int codCiudad, int codigoCo, int codPais2, int codCiudad2, int horas)
{
    refPais=codPais;
    refCiudad2=codCiudad2;
    codigo=codigoCo;
    tiempo=horas;
}
ffdbfg
Conexion::Conexion()
{
}

Conexion::~Conexion()
{
}
void Conexion::Mostrar()
    {
        std::cout << "Codigo: " << codigo <<"Tiempo: "<< tiempo << "\n\n" << "  De " << refCiudad << ", " << refPais << "a " << refCiudad2 << ", " << refPais2 << "\n\n";
    }