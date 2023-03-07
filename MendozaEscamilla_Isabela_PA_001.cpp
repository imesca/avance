#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

struct usuarios {
    string nombrecom;
    string nombreus;
    string contrasena;
    string tipous;
    string sucursal;
    usuarios* sig;
};


usuarios* auxusuarios = nullptr;
usuarios* iniciousuarios = nullptr;


void altausuarios() {
    usuarios* nusuarios = new usuarios;

    cout << "ingrese el nombre completo del empleado" << endl;
    getline(cin, nusuarios->nombrecom);
    cout << "ingrese el nombre de usuario" << endl;
    getline(cin, nusuarios->nombreus);
    cout << "ingrese la contrasena" << endl;
    getline(cin, nusuarios->contrasena);
    cout << "ingrese el tipo de usuario" << endl;
    getline(cin, nusuarios->tipous);
    cout << "ingrese la sucursal" << endl;
    getline(cin, nusuarios->sucursal);

    if (iniciousuarios == nullptr) {
        iniciousuarios = nusuarios;
        iniciousuarios->sig = nullptr;
    }
    else {
        auxusuarios = iniciousuarios;
        while (auxusuarios->sig != nullptr) {
            auxusuarios = auxusuarios->sig;
        }
        auxusuarios->sig = nusuarios;
        auxusuarios = auxusuarios->sig;
        auxusuarios->sig = nullptr;
    }
    system("pause");
}

//void modificarusuarios

//void eliminarusuarios

void listausuarios() {
    auxusuarios = iniciousuarios;
    if (iniciousuarios != nullptr) {
        while (auxusuarios != nullptr) {
            cout << auxusuarios->nombrecom << endl;
            cout << auxusuarios->nombreus << endl;
            cout << auxusuarios->contrasena << endl;
            cout << auxusuarios->tipous << endl;
            cout << auxusuarios->sucursal << endl;
            auxusuarios = auxusuarios->sig;
        }
    }
    else {
        cout << "no ha ingresado ningun cliente" << endl;
    }
    system("pause");
}

void escribirusuarios() {
    ofstream archivousuarios;
    archivousuarios.open("archivousuarios.bin", ios::out | ios::trunc | ios::binary);
    if (archivousuarios.is_open()) {
        auxusuarios = iniciousuarios;
        while (iniciousuarios != nullptr && auxusuarios != nullptr) {
            archivousuarios.write((char*)auxusuarios, sizeof(usuarios));
            auxusuarios = auxusuarios->sig;
        }
        archivousuarios.close();
    }
    else {
        cout << "no se pudo abrir el archivo" << endl;
        system("pause");
    }
}

void leerusuarios() {
    ifstream archivousuarios;
    archivousuarios.open("archivvousuarios.bin", ios::in | ios::binary);
    if (archivousuarios.is_open()) {
        usuarios* usuarioleido = new usuarios;
        while (!archivousuarios.read((char*)usuarioleido, sizeof(usuarios)).eof()) {
            if (iniciousuarios == nullptr) {
                iniciousuarios = usuarioleido;
                iniciousuarios->sig = nullptr;
                auxusuarios = iniciousuarios;
            }
            else {
                auxusuarios->sig = usuarioleido;
                auxusuarios = auxusuarios->sig;
                auxusuarios->sig = nullptr;
            }
            usuarioleido = new usuarios;
        }
        archivousuarios.close();
        delete usuarioleido;
    }
    else {
        cout << "no se pudo abrir el archivo";
        system("pause");
    }
}

struct clientes {
    string nombre;
    string telefono;
    string correo;
    string sucursal;
    int puntos = 0;
    clientes* sig;
};

clientes* auxclientes = nullptr;
clientes* inicioclientes = nullptr;

void altaclientes() {
    clientes* nclientes = new clientes;

    cout << "ingrese el nombre completo del cliente" << endl;
    getline(cin, nclientes->nombre);
    cout << "ingrese el telefono del cliente" << endl;
    getline(cin, nclientes->telefono);
    cout << "ingrese el correo del cliente" << endl;
    getline(cin, nclientes->correo);
    cout << "ingrese la sucursal" << endl;
    getline(cin, nclientes->sucursal);
    cout << "ingrese sus puntos iniciales" << endl;
    cin >> nclientes->puntos;

    if (inicioclientes == nullptr) {
        inicioclientes = nclientes;
        inicioclientes->sig = nullptr;
    }
    else {
        auxclientes = inicioclientes;
        while (auxclientes->sig != nullptr) {
            auxclientes = auxclientes->sig;
        }
        auxclientes->sig = nclientes;
        auxclientes = auxclientes->sig;
        auxclientes->sig = nullptr;
    }
    system("pause");
}

// void modificarclientes

//void eliminarclientes

void listaclientes() {
    auxclientes = inicioclientes;
    if (inicioclientes != nullptr) {
        while (auxclientes != nullptr) {
            cout << auxclientes->nombre << endl;
            cout << auxclientes->telefono << endl;
            cout << auxclientes->correo << endl;
            cout << auxclientes->sucursal << endl;
            cout << auxclientes->puntos << endl;
            auxclientes = auxclientes->sig;
        }
    }
    else {
        cout << "no ha ingresado ningun cliente" << endl;
    }
    system("pause");
}

void escribirclientes() {
    ofstream archivoclientes;
    archivoclientes.open("archivoclientes.bin", ios::out | ios::trunc | ios::binary);
    if (archivoclientes.is_open()) {
        auxclientes = inicioclientes;
        while (inicioclientes != nullptr && auxclientes != nullptr) {
            archivoclientes.write((char*)auxclientes, sizeof(clientes));
            auxclientes->sig;
        }
        archivoclientes.close();
    }
    else {
        cout << "no se pudo abrir el archivo" << endl;
        system("pause");
    }
}

void leerclientes() {
    ifstream archivoclientes;
    archivoclientes.open("archivoclientes.bin", ios::in | ios::binary);
    if (archivoclientes.is_open()) {
        clientes* clienteleido = new clientes;
        while (!archivoclientes.read((char*)clienteleido, sizeof(clientes)).eof()) {
            if (inicioclientes == nullptr) {
                inicioclientes = clienteleido;
                inicioclientes->sig = nullptr;
                auxclientes = inicioclientes;
            }
            else {
                auxclientes->sig = clienteleido;
                auxclientes = auxclientes->sig;
                auxclientes->sig = nullptr;
            }
            clienteleido = new clientes;
        }
        archivoclientes.close();
        delete clienteleido;
    }
    else {
        cout << "no se pudo abrir el archivo";
        system("pause");
    }
}

struct promociones {
    string nombrepromo;
    string puntosre;
    string porcentaje;
    string estatus;
    promociones* sig;
};

promociones* auxpromociones = nullptr;
promociones* iniciopromociones = nullptr;

void altapromociones() {
    promociones* npromociones = new promociones;

    cout << "ingrese el nombre de la promocion" << endl;
    getline(cin, npromociones->nombrepromo);
    cout << "ingrese los puntos requeridos" << endl;
    getline(cin, npromociones->puntosre);
    cout << "ingrese el porcentaje del descuento" << endl;
    getline(cin, npromociones->porcentaje);
    cout << "ingrese el estatus de la promocion" << endl;
    getline(cin, npromociones->estatus);

    if (iniciopromociones == nullptr) {
        iniciopromociones = npromociones;
        iniciopromociones->sig = nullptr;
    }
    else {
        auxpromociones = iniciopromociones;
        while (auxpromociones->sig != nullptr) {
            auxpromociones = auxpromociones->sig;
        }
        auxpromociones->sig = npromociones;
        auxpromociones = auxpromociones->sig;
        auxpromociones->sig = nullptr;
    }
    system("pause");
}

//void modificarpromociones

//void eliminarpromociones

void listapromociones() {
    auxpromociones = iniciopromociones;
    if (iniciopromociones != nullptr) {
        while (auxpromociones != nullptr) {
            cout << auxpromociones->nombrepromo << endl;
            cout << auxpromociones->puntosre << endl;
            cout << auxpromociones->porcentaje << endl;
            cout << auxpromociones->estatus << endl;
            auxpromociones = auxpromociones->sig;
        }
    }
    else {
        cout << "no ha ingresado ninguna promocion" << endl;
    }
    system("pause");
}

void escribirpromociones() {
    ofstream archivopromociones;
    archivopromociones.open("archivopromociones.bin", ios::out | ios::trunc | ios::binary);
    if (archivopromociones.is_open()) {
        auxpromociones = iniciopromociones;
        while (iniciopromociones != nullptr && auxpromociones != nullptr) {
            archivopromociones.write((char*)auxpromociones, sizeof(promociones));
            auxpromociones = auxpromociones->sig;
        }
        archivopromociones.close();
    }
    else {
        cout << "no se pudo abrir el archivo" << endl;
        system("pause");
    }
}

void leerpromociones() {
    ifstream archivopromociones;
    archivopromociones.open("archivopromociones.bin", ios::in | ios::binary);
    if (archivopromociones.is_open()) {
        promociones* promoleida = new promociones;
        while (!archivopromociones.read((char*)promoleida, sizeof(promociones)).eof()) {
            if (iniciopromociones == nullptr) {
                iniciopromociones = promoleida;
                iniciopromociones->sig = nullptr;
                    auxpromociones=iniciopromociones;
            }
            else {
                auxpromociones->sig = promoleida;
                auxpromociones = auxpromociones->sig;
                auxpromociones->sig = nullptr;
            }
            promoleida = new promociones;
        }
        archivopromociones.close();
        delete promoleida;
    }
    else {
        cout << "no se pudo abrir el archivo";
        system("pause");
    }
}

struct sucursales {
    string nombresu;
    string direccion;
    sucursales* sig;
};

sucursales* auxsucursales = nullptr;
sucursales* iniciosucursales = nullptr;

void altasucursales() {
    sucursales* nsucursales = new sucursales;

    cout << "ingrese el nombre de la sucursal" << endl;
    getline(cin, nsucursales->nombresu);
    cout << "ingrese la direccion de la sucursal" << endl;
    getline(cin, nsucursales->direccion);

    if (iniciosucursales == nullptr) {
        iniciosucursales = nsucursales;
        iniciosucursales->sig = nullptr;
    }
    else {
        auxsucursales = iniciosucursales;
        while (auxsucursales->sig != nullptr) {
            auxsucursales = auxsucursales->sig;
        }
        auxsucursales->sig = nsucursales;
        auxsucursales = auxsucursales->sig;
        auxsucursales->sig = nullptr;
    }
    system("pause");
}

// void modificarsucursales

//void eliminarsucursales

void listasucursales() {
    auxsucursales = iniciosucursales;
    if (iniciosucursales != nullptr) {
        while (auxsucursales != nullptr) {
            
            cout << auxsucursales->nombresu << endl;
            cout << auxsucursales->direccion << endl;
            auxsucursales = auxsucursales->sig;
        }
    }
    else {
        cout << "no ha ingresado ninguna sucursal" << endl;
    }
    system("pause");
}

void escribirsucursales() {
    ofstream archivosucursales;
    archivosucursales.open("archivosucursales.bin", ios::out | ios::trunc | ios::binary);
    if (archivosucursales.is_open()) {
        auxsucursales = iniciosucursales;
        while (iniciosucursales != nullptr && auxsucursales != nullptr) {
            archivosucursales.write((char*)auxsucursales, sizeof(sucursales));
            auxsucursales = auxsucursales->sig;
        }
        archivosucursales.close();
    }
    else {
        cout << "no se pudo abrir el archivo" << endl;
        system("pause");
    }
}

void leersucursales() {
    ifstream archivosucursales;
    archivosucursales.open("archivosucursales.bin", ios::in | ios::binary);
    if (archivosucursales.is_open()) {
        sucursales* sucursalleido = new sucursales;
        while (!archivosucursales.read((char*)sucursalleido, sizeof(sucursales)).eof()) {
            if (iniciosucursales == nullptr) {
                iniciosucursales = sucursalleido;
                iniciosucursales->sig = nullptr;
                auxsucursales = iniciosucursales;
            }
            else {
                auxsucursales->sig = sucursalleido;
                auxsucursales = auxsucursales->sig;
                auxsucursales->sig = nullptr;
            }
            sucursalleido = new sucursales;
        }
        archivosucursales.close();
        delete sucursalleido;
    }
    else {
        cout << "no se pudo abrir el archivo";
        system("pause");
    }
}

int main() {
    int opcion = 0;
    do {
        system("cls");
        cout << ":::MENU:::" << endl;
        cout << "1)usuarios" << endl;
        cout << "2)clientes" << endl;
        cout << "3)promociones" << endl;
        cout << "4)sucursales" << endl;
        cout << "5)salir" << endl;

        cin >> opcion;
        switch (opcion) {
        case 1: {
            int opcion1 = 0;
            do {
                system("cls");
                cout << ":::MENU:::" << endl;
                cout << "1)alta" << endl;
                cout << "2)modificar" << endl;
                cout << "3)eliminar" << endl;
                cout << "4)lista" << endl;
                cout << "5)salir" << endl;

                cin >> opcion1;
                cin.ignore();
                switch (opcion1) {
                    system("cls");
                case 1:
                    altausuarios();
                    escribirusuarios();
                    leerusuarios();
                    opcion = 0;
                    break;
                case 2:
                    // modificarusuarios
                    opcion = 0;
                    break;
                case 3:
                    //eliminarusuarios
                    opcion = 0;
                    break;
                case 4:
                    listausuarios();
                    opcion = 0;
                    break;
                default:
                    opcion = 0;
                    break;
                }
            } while (opcion1 < 1 || opcion1>5);
        }
            break;
        case 2: {
            int opcion2 = 0;
            do {
                system("cls");
                cout << ":::MENU:::" << endl;
                cout << "1)alta" << endl;
                cout << "2)modificar" << endl;
                cout << "3)eliminar" << endl;
                cout << "4)lista" << endl;
                cout << "5)salir" << endl;

                cin >> opcion2;
                cin.ignore();
                switch (opcion2) {
                    system("cls");
                case 1:
                    altaclientes();
                    escribirclientes();
                    leerclientes();
                    opcion = 0;
                    break;
                case 2:
                    //modificarclientes
                    opcion = 0;
                    break;
                case 3:
                    //eliminarclientes
                    opcion = 0;
                    break;
                case 4:
                    listaclientes();
                    opcion = 0;
                    break;
                default:
                    opcion = 0;
                    break;
                }
            } while (opcion2 < 1 || opcion2>5);
        }
              break;
        case 3: {
            int opcion3 = 0;
            do {
                system("cls");
                cout << ":::MENU:::" << endl;
                cout << "1)alta" << endl;
                cout << "2)modificar" << endl;
                cout << "3)eliminar" << endl;
                cout << "4)lista" << endl;
                cout << "5)salir" << endl;
                cin >> opcion3;
                cin.ignore();
                switch (opcion3) {
                    system("cls");
                case 1:
                    altapromociones();
                    escribirpromociones();
                    leerclientes();
                    opcion = 0;
                    break;
                case 2:
                    //modificarpromociones
                    opcion = 0;
                    break;
                case 3:
                    //eliminarpromociones
                    opcion = 0;
                    break;
                case 4:
                    listapromociones();
                    opcion = 0;
                    break;
                default:
                    opcion = 0;
                    break;
                }
            } while (opcion3 < 1 || opcion3>5);
        }
              break;
        case 4: {
            int opcion4 = 0;
            do {
                system("cls");
                cout << ":::MENU:::" << endl;
                cout << "1)alta" << endl;
                cout << "2)modificar" << endl;
                cout << "3)eliminar" << endl;
                cout << "4)lista" << endl;
                cout << "5)salir" << endl;

                cin >> opcion4;
                cin.ignore();
                switch (opcion4) {
                    system("cls");
                case 1:
                    altasucursales();
                    escribirsucursales();
                    leersucursales();
                    opcion = 0;
                    break;
                case 2:
                    //modificarsucursales
                    opcion = 0;
                    break;
                case 3:
                    //eliminarsucursales
                    opcion = 0;
                    break;
                case 4:
                    listasucursales();
                    opcion = 0;
                    break;
                default:
                    opcion = 0;
                    break;
                }
            } while (opcion4 < 1 || opcion4>5);
        }
              break;
        default:
            break;
        }  
    }while (opcion < 1 || opcion>5);

    
    
    

    system("pause");
    return 0;
}