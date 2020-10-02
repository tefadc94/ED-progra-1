#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

#pragma region "Clase Nodo"
class nodo
{
  public:
  nodo(string v)
  {
    valor = v;
    siguiente = NULL;
  }
  nodo(string v, nodo * signodo)
  {
    valor = v;
    siguiente = signodo;
  }
  string GetValor();
  nodo* GetSiguiente();
  nodo* SetSiguiente(nodo* nodoSiguiente);

  private:
  string valor;
  nodo *siguiente;
  nodo *anterior;
  friend class lista;
  friend class listaC;
  friend class listaD;
  friend class listaDC;
};

typedef nodo *pnodo;

#pragma endregion

#pragma region "Clase Lista"
class lista
{
  public:
  lista()
    {
    primero=NULL;
    }
    ~lista();
    void InsertarInicio(string v);
    void InsertarFinal(string v);
    void InsertarPos (string v, int pos);
    bool ListaVacia() { return primero == NULL; }
    void Imprimir();
    void Mostrar();
    void Primero();
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    int largoLista();
    bool Buscar(string numero);
    pnodo GetPrimero();

  private:
  pnodo primero;

};

pnodo lista::GetPrimero()
{
  return primero;
}

string nodo::GetValor()
{
  return valor;
}

nodo* nodo::GetSiguiente()
{
  return siguiente;
}

nodo* nodo::SetSiguiente(nodo* nodoSiguiente)
{
  siguiente=nodoSiguiente;
  return siguiente;
}

bool lista::Buscar(string numero)
{
  bool resultado=false;
  pnodo apuntador=primero;
  if (apuntador!=NULL)
  {
    while(apuntador != NULL && numero!=apuntador->valor)
    {
      apuntador=apuntador->siguiente;
    }
    if (apuntador)
    {
      resultado=true;
    }
  }
  return resultado;
}

lista::~lista()
{
  pnodo aux;
  while(primero)
  {
  aux = primero;
  primero = primero->siguiente;
  delete aux;
  }
}

int lista::largoLista()
{
  int cont=0;
  pnodo aux;
  aux = primero;
  if(ListaVacia())
  {
      return cont;
  }
  else
  {
    while(aux!=NULL)
    {
    aux=aux->siguiente;
    cont++;
    }
  return cont;
  }
}

void lista::InsertarInicio(string v)
{
  if (ListaVacia())
    primero = new nodo(v);
  else
    primero=new nodo (v,primero);
}

void lista::InsertarFinal(string v)
{
  if (ListaVacia())
    primero = new nodo(v);
  else
  {
    pnodo aux = primero;
    while ( aux->siguiente != NULL)
      aux= aux->siguiente;
    aux->siguiente=new nodo(v);
  }
}

void lista::InsertarPos(string v, int pos)
{
  if (ListaVacia())
    primero = new nodo(v);
  else
  {
    if(pos <=1)
    {
      pnodo nuevo = new nodo(v);
      nuevo->siguiente= primero;
      primero= nuevo;
    }
    else
    {
      if (pos>=largoLista())
      InsertarFinal(v);
      else
      {
        pnodo aux= primero;
        int i =2;
        while((i != pos )&&(aux->siguiente!= NULL))
        {
          i++;
          aux=aux->siguiente;
        }
        pnodo nuevo= new nodo(v);
        nuevo->siguiente=aux->siguiente;
        aux->siguiente=nuevo;
      }
    }
  }
}

void lista::BorrarFinal()
{
  if (!ListaVacia())
  {
    if (primero->siguiente == NULL)
    {
      primero= NULL;
    }
    else
    {
      pnodo aux = primero;
      while (aux->siguiente->siguiente != NULL)
      {
        aux = aux->siguiente;
      }
      pnodo temp = aux->siguiente;
      aux->siguiente= NULL;
      delete temp;
    }
  }
}

void lista::BorrarInicio()
{
  if (!ListaVacia())
  {
    if (primero->siguiente == NULL)
    {
      pnodo temp=primero;
      primero= NULL;
      delete temp;
    }
    else
    {
      pnodo aux = primero;
      primero=primero->siguiente;
      delete aux;
    }
  }
}

void lista:: BorrarPosicion(int pos)
{
  if(!ListaVacia())
  {
    if((pos>largoLista())||(pos<0))
    {
      cout << "Error en posicion" << endl;
    }
    else
    {
      if(pos==1)
      {
        primero=primero->siguiente;
      }
      else
      {
        int cont=2;
        pnodo aux=  primero;
        while(cont<pos)
        {
          aux=aux->siguiente;
          cont++;
        }
        aux->siguiente=aux->siguiente->siguiente;
      }
    }
  }
}

void lista::Mostrar()
{
  nodo *aux;
  if (primero== NULL)
      cout << "No hay elementos";
  else
  {
          aux = primero;
          while(aux)
          {
            cout << aux->valor << "-> ";
            aux = aux->siguiente;
          }
          cout << endl;
  }
}
#pragma endregion

#pragma region "Clase Lista Circular"
class listaC {
  public:
    listaC() { primero =  NULL; }
    ~listaC();
    
    void InsertarInicio(string v);
    void InsertarFinal(string v);
    void InsertarPos (string v, int pos);
    void EliminarInicio();
    void EliminarFinal();
    void EliminarPos(int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Imprimir();
    void Borrar(string v);
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    
  private:
    pnodo primero;
    
};

listaC::~listaC()
{
  pnodo aux;
  
  while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
  }
  
}

int listaC::largoLista(){
    int cont=0;

    pnodo aux= primero;
    if(ListaVacia())
        return cont;
    else
    {
      while(aux->siguiente!=primero)
      {
        cont++;        
      aux=aux->siguiente;
      }
      cont=cont+1;
      return cont;
    }
}

void listaC::InsertarInicio(string v)
{
  if (ListaVacia())
  {
    pnodo nuevo= new nodo(v);
    primero = nuevo;
    nuevo->siguiente=primero;
  }  
  else
  {
    pnodo nuevo= new nodo(v);
    pnodo aux=primero;
    while (aux->siguiente!=primero)
      aux= aux->siguiente;
    nuevo->siguiente=primero;   
    aux->siguiente=nuevo;
    primero=nuevo;   
  } 
}

void listaC::InsertarFinal(string v)
{
  if (ListaVacia())
  {
    pnodo nuevo= new nodo(v);
    primero = nuevo;
    nuevo->siguiente=primero;
  }  
  else
  { 
      pnodo nuevo=new nodo(v);
      pnodo aux = primero;
      while (aux->siguiente!=primero)  
        aux= aux->siguiente;
      nuevo->siguiente= primero;
      aux->siguiente= nuevo; 
      
  }    
}


void listaC::InsertarPos(string v,int pos)
{
  if (ListaVacia())
  {
    pnodo nuevo= new nodo(v);
    primero = nuevo;
    nuevo->siguiente=primero;
  } 
  else
  {
    if(pos <=1)
    {
      InsertarInicio(v);
    }      
    else
    {
      pnodo aux= primero;
      int i =2;
      while((i != pos )&&(aux->siguiente!= primero))
      {
          i++;
          aux=aux->siguiente;
      }
      pnodo nuevo= new nodo(v);
      nuevo->siguiente=aux->siguiente;
      aux->siguiente=nuevo;
      }
    }
}
      
void listaC::BorrarFinal()
{
    if (!ListaVacia())
    {
      if (primero->siguiente == primero)
      {
        pnodo temp= primero;
        primero= NULL;
        delete temp;
      }
      else 
      {
        pnodo aux = primero;
        while (aux->siguiente->siguiente != primero)
              aux = aux->siguiente;
        pnodo temp = aux->siguiente;
        aux->siguiente= primero;
        delete temp;
      }
    }
}

void listaC::BorrarInicio()
{
    if (!ListaVacia())
    {
    if (primero->siguiente == primero)
    {
        pnodo temp= primero;
        primero= NULL;
        delete temp;
    }
    else
    {
        pnodo aux = primero;
        pnodo temp= primero;
        while (aux->siguiente!=primero)
            aux= aux->siguiente;
        primero=primero->siguiente;                
        aux->siguiente=primero;
        delete temp;
      }
    }
}

void listaC:: borrarPosicion(int pos)
{
  if(!ListaVacia())
  {
  if((pos>largoLista())||(pos<0))
    cout << "Error en posicion" << endl;
  else
    {
      if(pos==1)
        BorrarInicio();
      else
      {
      int cont=2;
      pnodo aux=  primero;
      while(cont<pos)
      {
        aux=aux->siguiente;
        cont++;
      }
      pnodo temp = aux->siguiente;
      aux->siguiente=aux->siguiente->siguiente;
      delete temp;
    }
    }
  }
}

void listaC::Mostrar()
{
  pnodo aux=primero;
  while(aux->siguiente!=primero)
    {
                                
      cout << aux->valor << "-> ";
      aux = aux->siguiente;
    }
    cout<<aux->valor<<"->";
    cout<<endl;
}
#pragma endregion

#pragma region "Clase Lista Doble"
class listaD {
   public:
    listaD() { primero =  NULL; }
    ~listaD();
    
    void InsertarInicio(string v);
    void InsertarFinal(string v);
    void InsertarPos (string v, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Borrar(string v);
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    int largoLista();
    
   private:
    pnodo primero;
  
};
listaD::~listaD()
{
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   
}

int listaD::largoLista(){
    int cont=0;

    pnodo aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }
    
}

void listaD::InsertarInicio(string v)
{
   if (ListaVacia())
   {
   
     primero = new nodo(v);
     primero->anterior=NULL;     
   }
   else
   {
     primero=new nodo (v,primero);
     primero->siguiente->anterior=primero;
   }
}
 
void listaD::InsertarFinal(string v)
{
   if (ListaVacia())
   {
   
     primero = new nodo(v);
     primero->anterior=NULL;     
   }
   else
     { pnodo aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodo(v);
        aux->siguiente->anterior=aux;       
      }    
}


void listaD::InsertarPos(string v,int pos)
{
   if (ListaVacia())
    {
   
     primero = new nodo(v);
     primero->anterior=NULL;     
   }
   else{
        if(pos <=1)
          InsertarInicio(v);    
        else
        {
             pnodo aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodo nuevo= new nodo(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             aux->siguiente->anterior=aux;
             nuevo->siguiente->anterior=nuevo;                           
        }
        }
}
      
void listaD::BorrarFinal()
{
    if (!ListaVacia())
    {
        if (primero->siguiente == NULL)
		 {
        	pnodo temp=primero;
            primero= NULL;
            delete temp;
            } 
			else 
			{
                pnodo aux = primero;
                while (aux->siguiente->siguiente != NULL) 
                {
                    aux = aux->siguiente;
                }
                
              pnodo temp = aux->siguiente;
              aux->siguiente= NULL;
                      
                delete temp;
            }
        }
}

void listaD::BorrarInicio()
{
    if (!ListaVacia()){
        if (primero->siguiente == NULL) {
            pnodo temp=primero;
            primero= NULL;
            delete temp;
            } 
			else
			{

                pnodo aux = primero;
                primero=primero->siguiente;                
                delete aux;
            }
        }
}



void listaD:: BorrarPosicion(int pos)
{
     if(!ListaVacia())
     {
        if((pos>largoLista())||(pos<0))
        {
        cout << "Error en posicion" << endl;
        }
        else
        {
        if(pos==1)
           BorrarInicio();
        else
        {
          if (pos == largoLista())   
             BorrarFinal();
          else
          {   
            int cont=2;
            pnodo aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodo temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            aux->siguiente->anterior=aux;
            delete temp;
          }//else
        }//else
      }//else
    }//else
}

void listaD::Mostrar()
{
   nodo *aux;
   
   aux = primero;
   while(aux) {
      cout << aux->valor << "-> ";
      aux = aux->siguiente;
   }
   cout << endl;
}
#pragma endregion

#pragma region "Clase Lista Doble Circular"
class listaDC {
   public:
    listaDC() { primero = NULL; }
    ~listaDC();
    
    void InsertarInicio(string v);
    void InsertarFinal(string v);
    void InsertarPos (string v, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Imprimir();
    void Borrar(string v);
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    int largoLista();
    
   private:
    pnodo primero;
   
};

listaDC::~listaDC()
{
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      primero->anterior=aux->anterior;
      aux->anterior->siguiente=primero;
      delete aux;
   }
   
}

int listaDC::largoLista()
{
    int cont=0;

    pnodo aux = primero;
    if(ListaVacia())
    {
        return cont;
    }
    else
    {
        while(aux!=primero)
        {
          aux=aux->siguiente;
          cont++;
        }
    return cont;
    }
    
}

void listaDC::InsertarInicio(string v)
{
  
   if (ListaVacia())
   {
     primero = new nodo(v);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   {
     pnodo nuevo=new nodo (v);
     nuevo->siguiente=primero;
     nuevo->anterior= primero->anterior;
     primero->anterior->siguiente=nuevo;
     nuevo->siguiente->anterior=nuevo;
     primero= nuevo;
   }
}
 
void listaDC::InsertarFinal(string v)
{
   if (ListaVacia())
     {
     primero = new nodo(v);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   { 
     pnodo nuevo = new nodo(v);
     nuevo->anterior = primero->anterior;
     nuevo->siguiente=primero->anterior->siguiente;
     primero->anterior->siguiente=nuevo;
     primero->anterior=nuevo;
    }    
}


void listaDC::InsertarPos(string v,int pos)
{
   if (ListaVacia())
   {
     primero = new nodo(v);
     primero->anterior=primero;
     primero->siguiente=primero;
   } 
   else
   {
      if(pos <=1)
        InsertarInicio(v);    
       else
       {
        if (pos==largoLista())
          InsertarFinal(v);
        else
        {     
             pnodo aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= primero))
             {
                   i++;
                   aux=aux->siguiente;
             }
             pnodo nuevo= new nodo(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             aux->siguiente->anterior=aux;
             nuevo->siguiente->anterior=nuevo;                           
        }
       }
   }
}   

void listaDC::BorrarFinal()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
      if (primero->siguiente == primero)
      {
        pnodo temp= primero;
        primero= NULL;
        delete temp;
      }
      else 
      {
         pnodo aux = primero;
         while (aux->siguiente->siguiente != primero)
              aux = aux->siguiente;
         pnodo temp = aux->siguiente;
         aux->siguiente= primero;
         primero->anterior=aux;
         delete temp;
      }
    }
}

void listaDC::BorrarInicio()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
     if (primero->siguiente == primero)
     {
        pnodo temp= primero;
        primero= NULL;
        delete temp;
     }
     else
     {
        pnodo aux = primero->anterior;
        pnodo temp= primero;
        aux->siguiente=primero->siguiente;
        primero=primero->siguiente; 
        primero->anterior=aux;
        delete temp;
      }
    }
}

void listaDC:: BorrarPosicion(int pos)
{
    
  if(ListaVacia())
    cout << "Lista vacia" <<endl;
  else
  {
   if((pos>largoLista())||(pos<0))
        cout << "Error en posicion" << endl;
   else
   {
      if(pos==1)
        BorrarInicio();
      else
      {
       int cont=2;
       pnodo aux=  primero;
       while(cont<pos)
       {
         aux=aux->siguiente;
         cont++;
       }
       pnodo temp = aux->siguiente;
       aux->siguiente=aux->siguiente->siguiente;
       delete temp;
     }
    }
  }
}

void listaDC::Mostrar()
{
   pnodo aux=primero;
   while(aux->siguiente!=primero)
     {
                                
      cout << aux->valor << "-> ";
      aux = aux->siguiente;
     }
     cout<<aux->valor<<"->";
     cout<<endl;
}
#pragma endregion

void leerLineasArchivo(pnodo x[5],int i,string nombreArchivo)
{
  FILE* parchivo;
  char linea[100];
  parchivo=fopen(nombreArchivo.c_str(),"r");
  while(true)
  {
    if (fgets(linea, 100, parchivo) != NULL)
    {
      if (strlen(linea)>1)
      {
        linea[strlen(linea) - 1] = '\0';
      }
    }

    if (feof(parchivo))
    {
      break;
    }
  }
}

void cargarArchivos()
{
  string y[5];
  y[0]="Arch1.txt";
  y[1]="Arch2.txt";
  y[2]="Arch3.txt";
  y[3]="Arch4.txt";
  y[4]="Arch5.txt";

  for (int i = 0; i < 5; i++)
  {
    //leerLineasArchivo();
  }
}

void Trabajar()
{
  cargarArchivos();
  string a;
  cin>> a;
}

int main()
{
  Trabajar();
  return 0;
}