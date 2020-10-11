#include "Pais.h"
#include "Ciudad.h"
#include "Conexion.h"
#include "TipoTren.h"
#include "Tren.h"
#include "Ruta.h"
#include "Usuario.h"
#include "Administrador.h"
#include "ListaSimpleGenerica.h"
#include "ListaDobleGenerica.h"
#include "ListaCircularGenerica.h"
#include "ListaDobleCircularGenerica.h"
#include "Nodo.h"

ListaDobleCircularGenerica<Pais> *Estructura1 = new ListaDobleCircularGenerica<Pais> ();
ListaDobleGenerica<TipoTren> *Estructura2 = new ListaDobleGenerica<TipoTren> ();
ListaDobleCircularGenerica<Usuario> *Estructura3 = new ListaDobleCircularGenerica<Usuario> ();
ListaCircularGenerica<Administrador> *Estructura4 = new ListaCircularGenerica<Administrador> ();
ListaCircularGenerica<Ruta> *Estructura5 = new ListaCircularGenerica<Ruta> ();

//==================================================================================================================================================================================================================================
//==================================================================================================================================================================================================================================
//==================================================================================================================================================================================================================================
//==================================================================================================================================================================================================================================
//==================================================================================================================================================================================================================================

void CargarArchivoPaises(string nombreArchivo)
{
    FILE* parchivo;
    char linea[100];
    parchivo=fopen(nombreArchivo.c_str(),"r");
    while(true)
    {
        if (fgets(linea, 100, parchivo))
        {
            string arregloDescompuesto [2];
            char * temp;
            int cont=0;

            std::string s (linea);
            char valorEliminar='\n';
            s.erase(remove(s.begin(), s.end(), valorEliminar),s.end());
            std::string delimitador = ";";

            int pos = 0;
            std::string token;
            while ((pos = s.find(delimitador)) != std::string::npos)
            {
                token = s.substr(0, pos);
                arregloDescompuesto[cont]=token;
                s.erase(0, pos + delimitador.length());
                cont++;
            }
            arregloDescompuesto[cont]=s;
            Pais datosPais = {stoi(arregloDescompuesto[0]),arregloDescompuesto[1]};
            if (!(Estructura1->Contiene (datosPais)))
            {
                Estructura1->InsertarOrdenado(datosPais);
            }
        }
        if (feof(parchivo))
        {
            break;
        }
    }
}

void CargarArchivoCiudades(string nombreArchivo)
{
    FILE* parchivo;
    char linea[100];
    parchivo=fopen(nombreArchivo.c_str(),"r");
    while(true)
    {
        if (fgets(linea, 100, parchivo))
        {
            string arregloDescompuesto [3];
            char * temp;
            int cont=0;

            std::string s (linea);
            char valorEliminar='\n';
            s.erase(remove(s.begin(), s.end(), valorEliminar),s.end());
            std::string delimitador = ";";

            int pos = 0;
            std::string token;
            while ((pos = s.find(delimitador)) != std::string::npos)
            {
                token = s.substr(0, pos);
                arregloDescompuesto[cont]=token;
                s.erase(0, pos + delimitador.length());
                cont++;
            }
            arregloDescompuesto[cont]=s;
            Pais paisBuscar = {stoi(arregloDescompuesto[0]),""};
            Ciudad datosCiudad = {stoi(arregloDescompuesto[0]),stoi(arregloDescompuesto[1]),arregloDescompuesto[2]};
            if (Estructura1->Contiene (paisBuscar))
            {
                Pais paisEncontrado = Estructura1->Encontrado (paisBuscar);
                if (!(paisEncontrado.listaCiudades->Contiene (datosCiudad)))
                {
                    paisEncontrado.listaCiudades->InsertarOrdenado(datosCiudad);
                }
                }
        }
        if (feof(parchivo))
        {
            break;
        }
    }
}

void CargarArchivoConexiones(string nombreArchivo)
{
    FILE* parchivo;
    char linea[100];
    parchivo=fopen(nombreArchivo.c_str(),"r");
    while(true)
    {
        if (fgets(linea, 100, parchivo))
        {
            string arregloDescompuesto [6];
            char * temp;
            int cont=0;

            std::string s (linea);
            char valorEliminar='\n';
            s.erase(remove(s.begin(), s.end(), valorEliminar),s.end());
            std::string delimitador = ";";

            int pos = 0;
            std::string token;
            while ((pos = s.find(delimitador)) != std::string::npos)
            {
                token = s.substr(0, pos);
                arregloDescompuesto[cont]=token;
                s.erase(0, pos + delimitador.length());
                cont++;
            }
            arregloDescompuesto[cont]=s;
            Pais paisBuscar = {stoi(arregloDescompuesto[0]),""};
            Pais paisBuscar2 = {stoi(arregloDescompuesto[3]),""};
            Ciudad ciudadBuscar = {stoi(arregloDescompuesto[0]),stoi(arregloDescompuesto[1]),""};
            Ciudad ciudadBuscar2 = {stoi(arregloDescompuesto[3]),stoi(arregloDescompuesto[4]),""};
            Conexion datosConexion = {stoi(arregloDescompuesto[0]),stoi(arregloDescompuesto[1]),stoi(arregloDescompuesto[2]),stoi(arregloDescompuesto[3]),stoi(arregloDescompuesto[4]),stoi(arregloDescompuesto[5])};
            if (Estructura1->Contiene (paisBuscar) && Estructura1->Contiene (paisBuscar2))
            {
                Pais paisEncontrado = Estructura1->Encontrado (paisBuscar);
                Pais paisEncontrado2 = Estructura1->Encontrado (paisBuscar2);
                if (paisEncontrado.listaCiudades->Contiene (ciudadBuscar) && paisEncontrado2.listaCiudades->Contiene (ciudadBuscar2))
                {
                    Ciudad ciudadEncontrada = paisEncontrado.listaCiudades->Encontrado (ciudadBuscar);
                    Ciudad ciudadEncontrada2 = paisEncontrado2.listaCiudades->Encontrado(ciudadBuscar2);
                    if (!(ciudadEncontrada.listaConexiones->Contiene (datosConexion)))
                    {
                        ciudadEncontrada.listaConexiones->InsertarOrdenado(datosConexion);
                    }
                }
            }
            if (feof(parchivo))
            {
                break;
            }
        }
    }
}

//==================================================================================================================================================================================================================================
//==================================================================================================================================================================================================================================
//==================================================================================================================================================================================================================================
//==================================================================================================================================================================================================================================
//==================================================================================================================================================================================================================================

void CargarArchivoTipoTren(string nombreArchivo)
{
    FILE* parchivo;
    char linea[100];
    parchivo=fopen(nombreArchivo.c_str(),"r");
    while(true)
    {
        if (fgets(linea, 100, parchivo))
        {
            string arregloDescompuesto [2];
            char * temp;
            int cont=0;

            std::string s (linea);
            char valorEliminar='\n';
            s.erase(remove(s.begin(), s.end(), valorEliminar),s.end());
            std::string delimitador = ";";

            int pos = 0;
            std::string token;
            while ((pos = s.find(delimitador)) != std::string::npos)
            {
                token = s.substr(0, pos);
                arregloDescompuesto[cont]=token;
                s.erase(0, pos + delimitador.length());
                cont++;
            }
            arregloDescompuesto[cont]=s;
            TipoTren datosTipoTren = {stoi(arregloDescompuesto[0]),arregloDescompuesto[1]};
            if (!(Estructura2->Contiene (datosTipoTren)))
            {
                Estructura2->InsertarOrdenado(datosTipoTren);
            }
        }
        if (feof(parchivo))
        {
            break;
        }
    }
}

void CargarArchivoRutas(string nombreArchivo)
{
    FILE* parchivo;
    char linea[100];
    parchivo=fopen(nombreArchivo.c_str(),"r");
    while(true)
    {
        if (fgets(linea, 100, parchivo))
        {
            string arregloDescompuesto [8];
            char * temp;
            int cont=0;

            std::string s (linea);
            char valorEliminar='\n';
            s.erase(remove(s.begin(), s.end(), valorEliminar),s.end());
            std::string delimitador = ";";

            int pos = 0;
            std::string token;
            while ((pos = s.find(delimitador)) != std::string::npos)
            {
                token = s.substr(0, pos);
                arregloDescompuesto[cont]=token;
                s.erase(0, pos + delimitador.length());
                cont++;
            }
            arregloDescompuesto[cont]=s;
            Pais paisBuscar = {stoi(arregloDescompuesto[3]),""};
            Pais paisBuscar2 = {stoi(arregloDescompuesto[5]),""};
            Ciudad ciudadBuscar = {stoi(arregloDescompuesto[3]),stoi(arregloDescompuesto[4]),""};
            Ciudad ciudadBuscar2 = {stoi(arregloDescompuesto[5]),stoi(arregloDescompuesto[6]),""};

            Ruta datosRuta = {stoi(arregloDescompuesto[0]),stoi(arregloDescompuesto[1]),
            stoi(arregloDescompuesto[2]),stoi(arregloDescompuesto[3]),
            stoi(arregloDescompuesto[4]),stoi(arregloDescompuesto[5]),
            stoi(arregloDescompuesto[6]),stoi(arregloDescompuesto[7])};

            if (Estructura1->Contiene (paisBuscar) && Estructura1->Contiene (paisBuscar2))
            {
                Pais paisEncontrado = Estructura1->Encontrado (paisBuscar);
                Pais paisEncontrado2 = Estructura1->Encontrado (paisBuscar2);
                if (paisEncontrado.listaCiudades->Contiene (ciudadBuscar) && paisEncontrado2.listaCiudades->Contiene (ciudadBuscar2))
                {
                    Ciudad ciudadEncontrada = paisEncontrado.listaCiudades->Encontrado (ciudadBuscar);
                    Ciudad ciudadEncontrada2 = paisEncontrado2.listaCiudades->Encontrado(ciudadBuscar2);
                    if (!(Estructura5->Contiene (datosRuta)))
                    {
                        Estructura5->InsertarOrdenado(datosRuta);
                    }
                }
            }
            if (feof(parchivo))
            {
                break;
            }
        }
    }
}

//==================================================================================================================================================================================================================================
//==================================================================================================================================================================================================================================
//==================================================================================================================================================================================================================================
//==================================================================================================================================================================================================================================
//==================================================================================================================================================================================================================================

void CargarArchivoUsuarios(string nombreArchivo)
{
    FILE* parchivo;
    char linea[100];
    parchivo=fopen(nombreArchivo.c_str(),"r");
    while(true)
    {
        if (fgets(linea, 100, parchivo))
        {
            string arregloDescompuesto [5];
            char * temp;
            int cont=0;

            std::string s (linea);
            char valorEliminar='\n';
            s.erase(remove(s.begin(), s.end(), valorEliminar),s.end());
            std::string delimitador = ";";

            int pos = 0;
            std::string token;
            while ((pos = s.find(delimitador)) != std::string::npos)
            {
                token = s.substr(0, pos);
                arregloDescompuesto[cont]=token;
                s.erase(0, pos + delimitador.length());
                cont++;
            }
            arregloDescompuesto[cont]=s;
            Pais paisBuscar = {stoi(arregloDescompuesto[0]),""};
            Ciudad ciudadBuscar = {stoi(arregloDescompuesto[0]),stoi(arregloDescompuesto[1]),""};
            Usuario datosUsuario = {stoi(arregloDescompuesto[0]),stoi(arregloDescompuesto[1]),(arregloDescompuesto[2]),arregloDescompuesto[3],stoi(arregloDescompuesto[4])};
            if (Estructura1->Contiene (paisBuscar))
            {
                Pais paisEncontrado = Estructura1->Encontrado (paisBuscar);
                if (paisEncontrado.listaCiudades->Contiene (ciudadBuscar))
                {
                    if (!(Estructura3->Contiene (datosUsuario)))
                    {
                        Estructura3->InsertarOrdenado(datosUsuario);
                    }
                }
            }
        }
        if (feof(parchivo))
        {
            break;
        }
    }
}

void CargarArchivoAdministradores(string nombreArchivo)
{
    FILE* parchivo;
    char linea[100];
    parchivo=fopen(nombreArchivo.c_str(),"r");
    while(true)
    {
        if (fgets(linea, 100, parchivo))
        {
            string arregloDescompuesto [2];
            char * temp;
            int cont=0;

            std::string s (linea);
            char valorEliminar='\n';
            s.erase(remove(s.begin(), s.end(), valorEliminar),s.end());
            std::string delimitador = ";";

            int pos = 0;
            std::string token;
            while ((pos = s.find(delimitador)) != std::string::npos)
            {
                token = s.substr(0, pos);
                arregloDescompuesto[cont]=token;
                s.erase(0, pos + delimitador.length());
                cont++;
            }
            arregloDescompuesto[cont]=s;
            Administrador datosAdministrador = {arregloDescompuesto[0],arregloDescompuesto[1]};
            if (!(Estructura4->Contiene (datosAdministrador)))
            {
                Estructura4->InsertarOrdenado(datosAdministrador);
            }
        }
        if (feof(parchivo))
        {
            break;
        }
    }
}

//==================================================================================================================================================================================================================================
//==================================================================================================================================================================================================================================
//==================================================================================================================================================================================================================================
//==================================================================================================================================================================================================================================
//==================================================================================================================================================================================================================================

void CargarArchivos ()
{
    CargarArchivoAdministradores("Administradores.txt");
    CargarArchivoPaises("Paises.txt");
    CargarArchivoCiudades("Ciudades.txt");
    CargarArchivoConexiones("Conexiones.txt");
    CargarArchivoTipoTren("TipoTren.txt");
    CargarArchivoUsuarios("Usuarios.txt");
    CargarArchivoRutas("Rutas.txt");

}

void Trabajar()
{
    CargarArchivos();
}

void ImprimirPaises (ListaDobleCircularGenerica<Pais> *listaPaises)
 {
     Nodo<Pais> *aux = listaPaises->getPrimero();
     if (!aux)
     {
        cout << "\nNo hay registro de paises en la base de datos.";
     }
     else
     {
        aux->valor.Mostrar();
        aux = listaPaises->getPrimero()->siguiente;
        while (aux != listaPaises->getPrimero())
        {
            aux->valor.Mostrar();
            aux = aux->siguiente;
        }
     }    
 }
 
void ImprimirConexiones (ListaDobleGenerica<Conexion> *listaConexiones)
 {
     Nodo<Conexion> *aux = listaConexiones->getPrimero();
     if (!aux)
     {
        cout << "\nLa ciudad introducida no tiene ciudades registradas.";
     } 
     else
     {
        aux->valor.Mostrar();
        aux = listaConexiones->getPrimero()->siguiente;

        while (aux != listaConexiones->getPrimero())
        {
            aux->valor.Mostrar();
            aux = aux->siguiente;
        }
     }
 }


void ImprimirCiudades (ListaDobleCircularGenerica<Ciudad> *listaCiudades)
 {
     Nodo<Ciudad> *aux = listaCiudades->getPrimero();
     if (!aux)
     {
        cout << "\nEl pais introducido no tiene ciudades registradas.";
     }
     else
     {
        aux->valor.Mostrar();
        aux = listaCiudades->getPrimero()->siguiente;

        while (aux != listaCiudades->getPrimero())
        {
            aux->valor.Mostrar();
            aux = aux->siguiente;
        }
     }
 }

int main()
{
    Trabajar();
    int opcion;
    int opcionu;
    int opcionpais;
    int opcionciudad;
    string ID;
    do
    {
        system("cls");

        cout << "Menu de Opciones" << endl;
        cout << "1. Menu Usuarios" << endl;
        cout << "2. Menu Administradores" << endl;
        cout << "0. SALIR" << endl;
        
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        
        while (opcion)
        {
            if(opcion==1)
            {
                cout << "\nInserte su identificacion:";
                cin >> ID;
                Usuario usuarioBuscar = {0,0,ID,"",0};
                if (Estructura3->Contiene (usuarioBuscar))
                {
                    
                    cout << "\n\nMenu de Usuario" << endl;
                    cout << "1. Consultar paises" << endl;
                    cout << "2. Consultar ciudades" << endl;
                    cout << "3. Consultar conexiones" << endl;
                    cout << "4. Consultar trenes" << endl;
                    cout << "5. Consultar precios" << endl;
                    cout << "6. Consultar asientos disponibles de un tren" << endl;
                    cout << "7. Consultar rutas" << endl;
                    cout << "0. SALIR" << endl;
                    
                    cout << "\nIngrese una opcion: ";
                    cin >> opcionu;
                    while (opcionu)
                    {
                        if(opcionu==1)
                        {
                            ImprimirPaises (Estructura1);
                            cout << "\nOprima 0 para salir: ";
                            cin >> opcion;
                            break;
                        
                        }
                        else if(opcionu==2)
                        {

                            ImprimirPaises (Estructura1);
                            cout << "\nIngrese el codigo de pais: ";
                            cin >> opcionpais;
                            Pais paisBuscar = {opcionpais,""};
                            if (Estructura1->Contiene (paisBuscar))
                            {
                                Pais paisEncontrado = Estructura1->Encontrado (paisBuscar);
                                ImprimirCiudades(paisEncontrado.listaCiudades);
                                
                            }
                            else
                            {
                                cout << "\nEl pais introducido no existe\n";
                            }
                            
                            break;
                        }
                        else if(opcionu==3)//consultar conexinoes
                        {

                            ImprimirPaises (Estructura1);
                            cout << "\nIngrese el codigo de pais: ";
                            cin >> opcionpais;
                            Pais paisBuscar = {opcionpais,""};
                            if (Estructura1->Contiene (paisBuscar))
                            {
                                Pais paisEncontrado = Estructura1->Encontrado (paisBuscar);
                                ImprimirCiudades(paisEncontrado.listaCiudades);
                                cout << "\nIngrese el codigo de ciudad: ";
                                cin >> opcionciudad;
                                Ciudad ciudadBuscar = {0,opcionciudad,""};
                                if (Estructura1->Contiene (ciudadBuscar))
                                {
                                    Ciudad ciudadEncontrado = Estructura1->Encontrado (ciudadBuscar);
                                    ImprimirConexiones(ciudadEncontrado.listaConexiones); 
                                }
                                else
                                {
                                    cout << "\nLa ciudad introducida no existe\n";
                                    
                                }
                            else
                            {
                                cout << "\nEl pais introducido no existe\n";
                            }
                            
                            break;
                        }
                        else if(opcionu==4)//Consultar trenes
                        {
                            cout << "\nLa identificacion introducida no existe\n";
                        }
                        else if(opcionu==5)//Consultar precios
                        {
                            cout << "\nLa identificacion introducida no existe\n";
                        }
                        else if(opcionu==6)//Consultar asientos disponibles de un tren
                        {
                            cout << "\nLa identificacion introducida no existe\n";
                        }
                         else if(opcionu==7)//Consultar asientos disponibles de un tren
                        {
                            cout << "\nLa identificacion introducida no existe\n";
                        }
                         else 
                         {
                            cout << "\nDebe seleccionar una opcion\n";
                        }
                    }
                }
                else
                {
                    cout << "\nLa identificacion introducida no existe\n";
                }
            }
            else if(opcion==2)
            {
                cout << "\n\nInserte su identificacion:" << endl;
                cin >> ID;
                break;
            }
                /*cout << "\n\nInserte una opcion valida." << endl;
                _sleep(5000);
                break;*/
        }
    }
    while (opcion != 0);
    return 0;
}