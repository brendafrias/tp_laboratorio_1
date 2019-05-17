typedef struct
{
    int idSector;
    char descripcion[51];

}eSector;

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int idSector;
    int isEmpty;

}eEmployee;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void initEmployee(eEmployee[],int len);
int addEmployee(eEmployee list[], int len, char name[],char lastName[],float salary,int sector,int idMain);
int findEmployeeById(eEmployee[], int len,int id);
int removeEmployee(eEmployee[], int len, int id);
void sortEmployees(eEmployee[], int lenE, int order);
void printEmployees(eEmployee[], int lenE,eSector[],int lenS);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void modifyNameEmployee(eEmployee[],int len, int position);
void modifyLastNameEmployee(eEmployee[],int len, int position);
void modifySalaryEmployee(eEmployee[],int len, int position);
void modifySectorEmployee(eEmployee[],int lenE, int position,eSector[],int lenS);
int validateSector(eSector[],int len);
void printOneEmployee(eEmployee[],int lenE,eSector[],int lenS,int position);
int searchSectorDescription(eEmployee[],eSector[],int lenS,int position);
void toUpperFirstLetter(eEmployee[],int len,int position);
void hardcodeEmployeeList(eEmployee[],int len);
float salaryAverage(eEmployee[],int len);
float salaryTotal(eEmployee[],int len);
int salaryAverageOvercome(eEmployee[],int len);
int oneEmployee(eEmployee[],int len);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int addEmployeeMenu(eEmployee[],int lenE,eSector sectors[],int lenS,int idMain);
void removeEmployeeMenu(eEmployee[],int len);
void modifyEmployeeMenu(eEmployee[],int lenE,eSector[],int lenS);
void showEmployeesMenu(eEmployee[],int lenE,eEmployee[]);
int menuDeInformes ();
void mostrarMenu();
