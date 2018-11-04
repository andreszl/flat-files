#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <ctime>

using namespace std;


struct _student {
    string name, age, cedula, carnet,
           nFinal, teacher, year_course,
           semester, asignature, code_aisgnature;
};

void create();
char dashboard();
void read();
void store();
int destroy();
float addQualifications(int num);
int validateAge(int age);






int main()
{
    char op;

    do{
        op = dashboard();
        switch(op){
            case '1':
                system("cls");
                create();
                break;

            case '2':
                system("cls");
                read();
                break;

            case '3':
                system("cls");
                destroy();
                break;

            case '4':
                exit(1);
                break;

            default :
                cout << "\nError...";
                system("cls");
                break;
        }
    }while(op!= 4);

    system("PAUSE");
	return 0;






}


char dashboard(){
    char op;
    system("cls");
    printf("\n(1)Registrar estudiante");
    printf("\n(2)Mostrar informe");
    printf("\n(3)Eliminar registros");
    printf("\n(4)Salir");
    printf("\n selecione una opcion : "); fflush(stdin);
    cin >> op;
    return op;
}


void read()
{

    ifstream data("users.txt");

    _student reg;

    int cont = 0;
    float total = 0;
    int approved = 0;
    int disapproved = 0;
    float maxQ = 0;
    float minQ = 200;
    while(
            getline(data, reg.name) &&
            getline(data, reg.age) &&
            getline(data, reg.cedula) &&
            getline(data, reg.carnet) &&
            getline(data, reg.nFinal) &&
            getline(data, reg.teacher) &&
            getline(data, reg.year_course) &&
            getline(data, reg.semester) &&
            getline(data, reg.asignature) &&
            getline(data, reg.code_aisgnature)
          ){
            cont++;
            string nFinal = reg.nFinal;
            float qualification = strtof(nFinal.c_str(),0);
            total+= strtof(nFinal.c_str(),0);

            if(qualification > maxQ){
                maxQ = qualification;
            }

            if(minQ > qualification){
                minQ = qualification;
            }


           cout << "\n_______________________________\n" << '\n'
                << "Nombre : " << reg.name << '\n'
                << "Edad :" << reg.age << '\n'
                << "Cedula : " << reg.cedula << '\n'
                << "Carnet : " << reg.carnet << '\n'
                << "Nota Final : " << reg.nFinal << '\n'
                << "Docente : " << reg.teacher << '\n'
                << "Año del curso : " << reg.year_course << '\n'
                << "Semestre : " << reg.semester << '\n'
                <<  "Asignatura : " << reg.asignature << '\n'
                << "Codigo de Asignatura : " << reg.code_aisgnature << '\n';

             if(qualification >= 3.5 ){
                approved++;
                cout  << "ESTUDIANTE APROBADO" << '\n';
              }else{
                  disapproved++;
                cout  << "ESTUDIANTE REPROBADO" << '\n';
              }
          cout  << "_______________________________" << '\n';
    }
    if( minQ != 200 ){
        cout << "\n\n***************** INFORME DEL GRUPO ******************* " << endl;
        cout << "\n\nNumero de estudiantes matriculados : " <<cont << endl;
        cout << "Aprobados : " << approved << " | Reprobados :" <<  disapproved <<endl;
        cout << "promedio del grupo : " << total/cont << endl;
        cout << "Nota minima del grupo : " << minQ << " | Nota maxima del grupo : " << maxQ << endl;
    }else{
        cout << "No hay alumnos registrados" << endl;
    }
    cout << "_______________________________\n\n";

    system("PAUSE");


}

void store(const _student &newReg)
{
    ofstream file;
    file.open("users.txt", ios_base::app);
	if (file.fail())
	{
        cout << "not foung file";
        exit(1);
	}

    file << newReg.name << '\n'
         << newReg.age << '\n'
         << newReg.cedula << '\n'
         << newReg.carnet << '\n'
         << newReg.nFinal << '\n'
         << newReg.teacher << '\n'
         << newReg.year_course << '\n'
         << newReg.semester << '\n'
         << newReg.asignature << '\n'
         << newReg.code_aisgnature << '\n';
}


void create(){

    struct _student user;

    std::string name, age, cedula, carnet,
           nFinal, teacher, year_course,
           semester, asignature, code_aisgnature;

    int num;

    float average;

    std::cout << "\n\nIngrese nombre de estudiante: ";
    cin >> name;
	user.name = name;

    cout << "\n\nIngrese edad del estudiante : ";
    cin >> age;

    int converted = atoi(age.c_str());
    validateAge(converted);

	user.age = age;

    cout << "\n\nIngrese cedula del estudiante : ";
    cin >> cedula;
	user.cedula = cedula;

    cout << "\n\nIngrese carnet del estudiante : ";
    cin >> carnet;
	user.carnet = carnet;

	cout << "\n\nIngrese cuantas notas quieres registrar : ";
	cin >> num;

    average =  addQualifications(num);
    stringstream ss;
    ss << average;
    nFinal = ss.str();

	user.nFinal = nFinal;

    cout << "\n\nIngrese nombre del docente : ";
	cin >> teacher;
	user.teacher = teacher;

    cout << "\n\nIngrese año del curso : ";
	cin >> year_course;
	user.year_course = year_course;

	cout << "\n\nIngrese semestre : ";
	cin >> semester;
	user.semester = semester;

	cout << "\n\nIngrese Asignatura :";
	cin >> asignature;
	user.asignature = asignature;

	cout << "\n\nIngrese codigo de la asignatura : ";
	cin >> code_aisgnature;
	user.code_aisgnature = code_aisgnature;


    store(user);
}

