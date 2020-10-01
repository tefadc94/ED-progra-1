#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;
class nodo
{
  public:
  nodo(int v)
  {
    valor = v;
    siguiente = NULL;
  }
  nodo(int v, nodo * signodo)
  {
    valor = v;
    siguiente = signodo;
  }
  int GetValor();
  private:
  int valor;
  nodo *siguiente;
  friend class lista;
};
int nodo::GetValor()
{
  return valor;
}

typedef nodo *pnodo;