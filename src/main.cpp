#include "../include/List.h"
#include "../include/Hash.h"
#include "../include/DB.h"
#include <iostream>
#include <filesystem>

using std::cout, std::cin, std::cerr, std::endl, std::string, std::getline, std::filesystem::exists, std::exception;

int main() {
   while (1) {
      string path = "";
      DB* baseDatos = new DB;
      while (!exists(path)) {
	 cout << "Ingrese dirección válida de archivo. Puede ser relativa o absoluta. Para salir, presione Ctrl-C." << endl;
	 getline(cin, path);
      }
      try {
	 baseDatos->Load(path);
      } catch (exception& exc) {
	 cout << "El archivo: " << path << " no existe." << endl;
	 cerr << exc.what() << endl;
	 std::exit(1);
      }
      string op;
      int opI;
      while (1) {
	 cout << "Ingrese número de opción." << endl;
	 cout << "0. Cargar más datos" << endl;
	 cout << "1. Buscar datos por llave" << endl;
	 cout << "2. Buscar datos por valor" << endl;
	 cout << "3. Salir" << endl;
	 std::getline(cin, op);
	 try {
	    opI = stoi(op);
	 } catch (...) {
	    opI = -1;
	 }
	 switch (opI) {
	    case 0: break;
	    case 1: {cout << "Ingrese llave." << endl;
	       string llave;
	       getline(cin, llave);
	       List<int>* indices = baseDatos->SearchK(llave);
	       if (indices->Count() == 0) {
		  cout << "No existen datos bajo esa llave." << endl;
	       } else {
		  for (int i = 0; i < indices->Count(); ++i) {
		     cout << indices->GetAt(i) << ".";
		     for (int j = 0; j < 5; ++j) {
			cout << " " << baseDatos->GetAt(indices->GetAt(i))[j];
		     }
		     cout << endl;
		  }
	       }
	       continue;
	    }
	    case 2: {cout << "Ingrese valor." << endl;
	       string valor;
	       getline(cin, valor);
	       List<int>* indices = baseDatos->SearchV(valor);
	       if (indices->Count() == 0) {
		  cout << "No existen tales valores." << endl;
	       } else {
		  for (int i = 0; i < indices->Count(); ++i) {
		     cout << indices->GetAt(i) << ".";
		     for (int j = 0; j < 5; ++j) {
			cout << " " << baseDatos->GetAt(indices->GetAt(i))[j];
		     }
		     cout << endl;
		  }
	       }
	       continue;
	    }
	    case 3: std::exit(0);
	    default: cout << "Opción inválida." << endl;
	       continue;
	 }
	 break;
      }
   }
}
