#include <iostream>
using namespace std;

class nodoLD {
   public:
    nodoLD(int v)
    {
       valor = v;
       siguiente = NULL;
       anterior =NULL;
    }

nodoLD(int v, nodoLD * signodoLD)
    {
       valor = v;
       siguiente = signodoLD;
    }

   private:
    int valor;
    nodoLD *siguiente;
    nodoLD *anterior;
    
        
   friend class listaD;
};

typedef nodoLD *pnodoLD;

class listaD {
   public:
    listaD() { primero =  NULL; }
    ~listaD();
    
    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarPos (int v, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Borrar(int v);
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    int largoLista();
    
   private:
    pnodoLD primero;
  
};
listaD::~listaD()
{
   pnodoLD aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   
}

int listaD::largoLista(){
    int cont=0;

    pnodoLD aux;
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

void listaD::InsertarInicio(int v)
{
   if (ListaVacia())
   {
   
     primero = new nodoLD(v);
     primero->anterior=NULL;     
   }
   else
   {
     primero=new nodoLD (v,primero);
     primero->siguiente->anterior=primero;
   }
}
 
void listaD::InsertarFinal(int v)
{
   if (ListaVacia())
   {
   
     primero = new nodoLD(v);
     primero->anterior=NULL;     
   }
   else
     { pnodoLD aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodoLD(v);
        aux->siguiente->anterior=aux;       
      }    
}


void listaD::InsertarPos(int v,int pos)
{
   if (ListaVacia())
    {
   
     primero = new nodoLD(v);
     primero->anterior=NULL;     
   }
   else{
        if(pos <=1)
          InsertarInicio(v);    
        else
        {
             pnodoLD aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodoLD nuevo= new nodoLD(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             aux->siguiente->anterior=aux;
             nuevo->siguiente->anterior=nuevo;                           
        }
        }
}
      
void listaD::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL)
		 {
        	pnodoLD temp=primero;
            primero= NULL;
            delete temp;
            } 
			else 
			{

                pnodoLD aux = primero;
                while (aux->siguiente->siguiente != NULL) 
                {
                    aux = aux->siguiente;
                }
                
              pnodoLD temp = aux->siguiente;
              aux->siguiente= NULL;
                      
                delete temp;
            }
        }
}

void listaD::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
            pnodoLD temp=primero;
            primero= NULL;
            delete temp;
            } 
			else
			{

                pnodoLD aux = primero;
                primero=primero->siguiente;                
                delete aux;
            }
        }
}



void listaD:: BorrarPosicion(int pos)
{
     if(ListaVacia())
     {
              cout << "Lista vacia" <<endl;
     }
     else
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
            pnodoLD aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodoLD temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            aux->siguiente->anterior=aux;
            delete temp;
          }
        }//e
      }//
    }//
}
 

void listaD::Mostrar()
{
   nodoLD *aux;
   
   aux = primero;
   while(aux) {
      cout << aux->valor << "-> ";
      aux = aux->siguiente;
   }
   cout << endl;
}


int main()
{
   listaD Lista;
   
    
   
   Lista.InsertarInicio(20);
   Lista.InsertarInicio(2);
   Lista.InsertarFinal(10);
   Lista.InsertarFinal(11);
   Lista.InsertarPos(5, 3);
   Lista.InsertarPos(6, 4);
   Lista.InsertarInicio(30);
   Lista.InsertarInicio(1);   
   Lista.InsertarFinal(5);
   Lista.InsertarPos(1, 3);
   Lista.Mostrar();
   Lista.BorrarInicio();
   Lista.Mostrar();
   Lista.BorrarFinal();
   Lista.Mostrar();
   Lista.InsertarInicio(2);
   Lista.Mostrar();
   Lista.BorrarPosicion(10);
   Lista.Mostrar();

   cout << "Lista de elementos:" << endl;
  
  
   cin.get();
   return 0;
}
