#ifndef __CIUDAD_H__
#define __CIUDAD_H__
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include "Conexion.h"
#include "ListaDobleGenerica.h"

using namespace std;

class Ciudad
{
private:
public:
    Ciudad();
    ~Ciudad();
    void Mostrar();
    Ciudad(int codPais, int codigoC, string nombreC);
    int refPais;
    int codigo;
    string nombre;
    ListaDobleGenerica <Conexion> *listaConexiones;

    bool operator < (const Ciudad& obj) {
        bool resultado;
        resultado = codigo < obj.codigo;
        return resultado;
    }

    bool operator > (const Ciudad& obj) {
        bool resultado;
        resultado = codigo > obj.codigo;
        return resultado;
    }

    bool operator == (const Ciudad& obj) {
        bool resultado;
        resultado = codigo == obj.codigo;
        return resultado;
    }
};

#endif