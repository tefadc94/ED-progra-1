#define __CONEXION_H__
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;


class Conexion
{
private:
public:
    Conexion();
    ~Conexion();
    void Mostrar();
    Conexion(int codPais, int codCiudad, int codigoCo, int codPais2, int codCiudad2, int horas);
    int refPais;
    int refCiudad;
    int codigo;
    int refPais2;
    int refCiudad2;
    int tiempo;

    bool ConexionCiudades()
    {
    }

    bool operator < (const Conexion& obj) {
        bool resultado;
        resultado = codigo < obj.codigo;
        return resultado;
    }

    bool operator > (const Conexion& obj) {
        bool resultado;
        resultado = codigo > obj.codigo;
        return resultado;
    }

    bool operator == (const Conexion& obj) {
        bool resultado;
        resultado = codigo == obj.codigo;
        return resultado;
    }
};

#endif