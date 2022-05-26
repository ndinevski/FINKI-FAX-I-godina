//https://i.imgur.com/qRI7DB2.png

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Employee{
    protected:
        char name[100];
        int age;
        int exp;
    public:
        Employee(char * name="", int age=0, int exp=0){
            strcpy(this->name, name);
            this->age=age;
            this->exp=exp;
        }
        virtual double plata() = 0;
        virtual double bonus() = 0;
        int getAge(){
            return age;
        }
        bool operator==(Employee & o){
            return o.age==this->age;
        }
};
// inline bool operator == (Employee& a, Employee& o) { 
//     return (a.getAge() == o.getAge()); 
// }
class SalaryEmployee : public Employee {
    protected:
        int base;
    public:
        SalaryEmployee(char * name="", int age=0, int exp=0, int base=0): Employee(name, age, exp){
            this->base=base;
        }
        double plata(){
            return base+bonus();
        }
        double bonus(){
            return exp/100.0*base;
        }
};

class HourlyEmployee : public Employee {
    protected:
        int hours;
        int salaryHour;
    public:
        HourlyEmployee(char * name="", int age=0, int exp=0, int hours=0,int salaryHour=0): Employee(name, age, exp){
            this->hours=hours;
            this->salaryHour=salaryHour;
        }
        double plata(){
            return hours*salaryHour + bonus();
        }
        double bonus(){
            if(hours>=320){
                return (hours-320)*0.5*salaryHour;
            }
            return 0;
        }
};

class Freelancer : public Employee {
    protected:
        int projects;
        double sums[100];
    public:
        Freelancer(char * name="", int age=0, int exp=0, int projects=0,double * sums=0): Employee(name, age, exp){
            this->projects=projects;
            for(int i=0;i<projects;i++){
                this->sums[i]=sums[i];
            }
        }
        double plata(){
            double suma=0;
            for(int i=0;i<projects;i++){
                suma+=sums[i];
            }
            return suma + bonus();
        }
        double bonus(){
            if(projects>=5){
                return (projects-5)*1000;
            }
            return 0;
        }
};


int brSalary(Employee **employees, int vraboteni){
    int counter=0;
    for(int i=0;i<vraboteni;i++){
        SalaryEmployee * casted = dynamic_cast<SalaryEmployee *>(employees[i]);
        if(casted!=0){
            counter++;
        }  
    }
    return counter;
}
int brHourly(Employee **employees, int vraboteni){
    int counter=0;
    for(int i=0;i<vraboteni;i++){
        HourlyEmployee * casted = dynamic_cast<HourlyEmployee *>(employees[i]);
        if(casted!=0){
            counter++;
        }  
    }
    return counter;
}
int brFree(Employee **employees, int vraboteni){
    int counter=0;
    for(int i=0;i<vraboteni;i++){
        Freelancer * casted = dynamic_cast<Freelancer *>(employees[i]);
        if(casted!=0){
            counter++;
        }  
    }
    return counter;
}

class Company{
    protected:
        char name[100];
        int vraboteni;
        Employee ** employees;
    public:
        Company(char * name=""){
            strcpy(this->name,name);
            this->vraboteni=0;
            employees = new Employee *[0];
        }
        Company & operator +=(Employee * employee){
            Employee ** tmp = new Employee * [vraboteni+1];
            copy(employees,employees+vraboteni,tmp);
            delete [] employees;
            tmp[vraboteni++] = employee;
            employees=tmp;
            return *this;
        }
        ~Company(){
            delete [] employees;
        }
        double VkupnaPlata(){
            double vk=0;
            for(int i=0;i<vraboteni;i++){
                vk+=employees[i]->plata();
            }
            return vk;
        }
        double filtriranaPlata(Employee * emp){
            double vk=0;
            for(int i=0;i<vraboteni;i++){
                if(emp->getAge()==employees[i]->getAge()){
                    vk+=employees[i]->plata();
                }
                // if(emp==employees[i]){
                //     vk+=employees[i]->plata();
                // }
            }
            return vk;
        }
        void pecatiRabotnici(){
            cout<<"Vo kompanijata "<<name<<" rabotat:"<<endl;
            cout<<"Salary employees: "<<brSalary(employees, vraboteni)<<endl;
            cout<<"Hourly employees: "<<brHourly(employees, vraboteni)<<endl;
            cout<<"Freelancers: "<<brFree(employees, vraboteni)<<endl;
        }

};

int main() {

char name[50];
cin >> name;
Company c(name);

int n;
cin >> n;

char employeeName[50];
int age;
int experience;
int type;

for (int i=0; i <n; ++i) {
  cin >> type;
  cin >> employeeName >> age >> experience;

  if (type == 1) {
    int basicSalary;
    cin >> basicSalary;
    c += new SalaryEmployee(employeeName, age, experience, basicSalary);
  }

  else if (type == 2) {
    int hoursWorked;
    int hourlyPay;
    cin >> hoursWorked >> hourlyPay;
    c += new HourlyEmployee(employeeName, age, experience, hoursWorked, hourlyPay);
  }

  else if(type == 3) {
    int numProjects;
    cin >> numProjects;
    double projects[10];
    for (int i=0; i < numProjects; ++i) {
      cin >> projects[i];
    }
    c += new Freelancer(employeeName, age, experience, numProjects, projects);
  }
}

c.pecatiRabotnici();
cout << "Vkupnata plata e: " << c.VkupnaPlata() << endl;
Employee * emp = new HourlyEmployee("Petre_Petrov",31,6,340,80);
cout << "Filtriranata plata e: " << c.filtriranaPlata(emp);

delete emp;
}