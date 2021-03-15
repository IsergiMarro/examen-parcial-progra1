#include <iostream>
#include <stdio.h>  
#include <string.h> 


using namespace std;
const char *nombe_archivo = "archivo.datos";

struct TRABAJADOR{
	int codigo;
	char nombre[50];
	char apellido[50];
	int telefono;
};
 void ingresar_trabajador();
void abrir_trabajador();
 void modificar_trabajador();
int main (){
	abrir_trabajador();
 ingresar_trabajador();
	modificar_trabajador();
	return 0;	
}
void buscar_codigo(){
	
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int indice=0,pos=0,cod=0;
	cout<<"BUSCAR CODIGO: ";
	cin>>cod;
	TRABAJADOR trabajador;
	
	fread ( &trabajador, sizeof(TRABAJADOR), 1, archivo );
		
		do{
			
			if (trabajador.codigo == cod){
			pos = indice;
			}
	
		fread ( &trabajador, sizeof(TRABAJADOR), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
		
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(TRABAJADOR), SEEK_SET );

    fread ( &trabajador, sizeof( TRABAJADOR ), 1, archivo );

    	cout << "Codigo: " << trabajador.codigo << endl;
        cout << "Nombre: " << trabajador.nombre << endl;
        cout << "Apellido: " << trabajador.apellido << endl;
        cout << "Telefono: " << trabajador.telefono << endl;
        cout << endl;
	
	fclose(archivo);
	system("PAUSE");
}


void buscar_indice(){
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int pos=0;
	cout<<"Que registro desea ver: ";
	cin>>pos;
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(TRABAJADOR), SEEK_SET );
	
	TRABAJADOR trabajador;
	
    fread ( &trabajador, sizeof( TRABAJADOR ), 1, archivo );

    	cout << "Codigo: " << trabajador.codigo << endl;
        cout << "Nombre: " << trabajador.nombre << endl;
        cout << "Apellido: " << trabajador.apellido << endl;
        cout << "Telefono: " << trabajador.telefono << endl;
        cout << endl;
	
	fclose(archivo);

	
}


void abrir_trabajador(){

	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	TRABAJADOR trabajador;
	int registro=0;
	fread ( &trabajador, sizeof(trabajador), 1, archivo );
	cout<<"____________________________________________________________________"<<endl;
	cout << "id" <<"|"<< "CODIGO" <<"|"<< "NOMBRE"<<" "<<"APELLIDO"<<" "<<"TELEFONO"<<" "<<endl;	
		do{
		cout<<"____________________________________________________________________"<<endl;
		cout << registro <<" |  "<< trabajador.codigo <<" | "<< trabajador.nombre<<" "<<trabajador.apellido<<" "<<trabajador.telefono<<endl;
        
        
		fread ( &trabajador, sizeof(trabajador), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
void ingresar_trabajador(){
	
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); // ab
	
	
		TRABAJADOR trabajador;
		 string nombre,apellido;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>trabajador.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(trabajador.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(trabajador.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>trabajador.telefono;
		cin.ignore();
		
		fwrite( &trabajador, sizeof(trabajador), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	abrir_trabajador();
	//buscar_indice();	
	buscar_codigo();
}
void modificar_trabajador(){
	
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int id;
		string nombre,apellido;	
    	TRABAJADOR trabajador;
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(trabajador), SEEK_SET );
	
		cout<<"Ingrese el Codigo:";
		cin>>trabajador.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(trabajador.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(trabajador.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>trabajador.telefono;
		cin.ignore();
		
		fwrite( &trabajador, sizeof(trabajador), 1, archivo );
		
	fclose(archivo);
	abrir_trabajador();
		system("PAUSE");
}

