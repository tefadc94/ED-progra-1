#include "TipoTren.h"

TipoTren::TipoTren(int codigoTT, string nombreTT)
{
    codigo = codigoTT;
    nombre = nombreTT;
    listaTrenes = new ListaSimpleGenerica<Tren> ();
}

TipoTren::TipoTren()
{
    listaTrenes = new ListaSimpleGenerica<Tren> ();
}

TipoTren::~TipoTren()
{
}