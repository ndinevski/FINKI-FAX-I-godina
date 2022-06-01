//https://i.imgur.com/L2YUGBI.png

#include<cstring>
#include<iostream>
#include <algorithm>
#include <cctype>
using namespace std;


class CovidVaccine{
protected:
    char firma[100];
    char * ime;
    float koef;
public:
    CovidVaccine(char * firma ="", char * ime="", float koef=0){
        strcpy(this->firma, firma);
        this->ime = new char[strlen(ime)+1];
        strcpy(this->ime, ime);
        this->koef = koef;
    }
    ~CovidVaccine(){
        delete [] ime;
    }
    virtual float calculateVaccineEfficiency() = 0;
};

class GeneticVaccine: public CovidVaccine{
protected:
    short gens;
public:
    GeneticVaccine(char * firma ="", char * ime="", float koef=0, short gens=0) : CovidVaccine(firma, ime, koef){
        this->gens=gens;
    }

    float calculateVaccineEfficiency(){
        if(gens==1){
            return koef*1.55;
        }
        return koef*1.35;
    }
    friend ostream & operator <<(ostream & o , GeneticVaccine & g){
        o<<"Vaccine info: "<<g.ime<<" - "<<g.firma<<" - "<<g.calculateVaccineEfficiency()<<endl;
        o<<"Mechanism for storing genetic information: ";
        if(g.gens==1){
            o<<"DNA"<<endl;
        }else{
            o<<"RNA"<<endl;
        }
        return o;
    }
};

class InactivatedVaccine: public CovidVaccine{
protected:
    short sostojki;
public:
    InactivatedVaccine(char * firma ="", char * ime="", float koef=0, short sostojki=0): CovidVaccine(firma,ime,koef){
        this->sostojki= sostojki;
    }
    float calculateVaccineEfficiency(){
        if(sostojki==0){
            return koef*0.9;
        }else if(sostojki==1){
            return koef*1.12;
        }else if(sostojki==2){
            return koef*0.85;
        }else{
            return koef*1.2;
        }
    }
    friend ostream & operator <<(ostream & o , InactivatedVaccine & g){
        o<<"Vaccine info: "<<g.ime<<" - "<<g.firma<<" - "<<g.calculateVaccineEfficiency()<<endl;
        o<<"The vaccine consists of the following ingredient: ";
        if(g.sostojki==0){
            o<<"DMG"<<endl;
        }else if(g.sostojki==1){
            o<<"PEG"<<endl;
        }else if(g.sostojki==2){
            o<<"SM_102"<<endl;
        }else{
            o<<"DPSC"<<endl;
        }
        return o;
    }

};

bool operator <= (GeneticVaccine & a, InactivatedVaccine & b){
    if(a.calculateVaccineEfficiency() <= b.calculateVaccineEfficiency()){
        return true;
    }
    return false;
}

bool operator <= (GeneticVaccine & a, GeneticVaccine & b){
    if(a.calculateVaccineEfficiency() <= b.calculateVaccineEfficiency()){
        return true;
    }
    return false;
}

InactivatedVaccine  & mostEffectiveInactivatedVaccine(CovidVaccine ** niza, int n){
    InactivatedVaccine * tmp=nullptr;
    for(int i=0;i<n;i++){
        InactivatedVaccine * casted = dynamic_cast<InactivatedVaccine *>(niza[i]);
        if(casted!=0){
            if(tmp==nullptr){
                tmp=casted;
            }else if(niza[i]->calculateVaccineEfficiency()>= tmp->calculateVaccineEfficiency()){
                tmp=casted;
            }
        }
    }

    return *tmp;

}

int main() {
    int test_case;

    cin >> test_case;

    //For CovidVaccine
    char manufacturer[100];
    char vaccineName[100];
    float basicEfficiencyCoefficient;

    //For GeneticVaccine
    unsigned short geneticMechanism; // 0 -> RNA, 1 -> DNA

    //For InactivatedVaccine
    unsigned short constituentIngredient; //0 -> DMG, 1 -> PEG, 2 -> SM_102, 3 -> DPSC


    if (test_case == 1) {
        // Test Case GeneticVaccine - Constructor, operator <<, calculateVaccineEfficiency
        cout << "Testing class GeneticVaccine, operator<< and calculateVaccineEfficiency" << endl;
        cin.get();
        cin.getline(manufacturer, 100);
        cin.getline(vaccineName, 100);
        cin >> basicEfficiencyCoefficient;
        cin >> geneticMechanism;

        GeneticVaccine gv(manufacturer, vaccineName, basicEfficiencyCoefficient, geneticMechanism);

        cout << gv;
    } else if (test_case == 2) {
        // Test Case InactivatedVaccine - Constructor, operator <<, calculateVaccineEfficiency
        cout << "Testing class InactivatedVaccine, operator<< and calculateVaccineEfficiency" << endl;
        cin.get();
        cin.getline(manufacturer, 100);
        cin.getline(vaccineName, 100);
        cin >> basicEfficiencyCoefficient;
        cin >> constituentIngredient;

        InactivatedVaccine iv(manufacturer, vaccineName, basicEfficiencyCoefficient, constituentIngredient);

        cout << iv;
    } else if (test_case == 3) {
        cout << "Testing operator <=" << endl;

        cin.get();
        cin.getline(manufacturer, 100);
        cin.getline(vaccineName, 100);
        cin >> basicEfficiencyCoefficient;
        cin >> geneticMechanism;

        GeneticVaccine gv(manufacturer, vaccineName, basicEfficiencyCoefficient, geneticMechanism);

        cin.get();
        cin.getline(manufacturer, 100);
        cin.getline(vaccineName, 100);
        cin >> basicEfficiencyCoefficient;
        cin >> constituentIngredient;

        InactivatedVaccine iv(manufacturer, vaccineName, basicEfficiencyCoefficient, constituentIngredient);

        if (gv <= iv) {
            cout << iv;
        } else {
            cout << gv;
        }
    } else if (test_case == 4) {
        cout << "Testing operator <=" << endl;

        cin.get();
        cin.getline(manufacturer, 100);
        cin.getline(vaccineName, 100);
        cin >> basicEfficiencyCoefficient;
        cin >> geneticMechanism;

        GeneticVaccine gv1(manufacturer, vaccineName, basicEfficiencyCoefficient, geneticMechanism);

        cin.get();
        cin.getline(manufacturer, 100);
        cin.getline(vaccineName, 100);
        cin >> basicEfficiencyCoefficient;
        cin >> geneticMechanism;

        GeneticVaccine gv2(manufacturer, vaccineName, basicEfficiencyCoefficient, geneticMechanism);

        if (gv1 <= gv2) {
            cout << gv2;
        } else {
            cout << gv1;
        }
    } else if (test_case == 5) {
        cout << "Testing function: mostEffectiveInactivatedVaccine " << endl;

        //1 - GeneticVaccine
        //2 - InactivatedVaccine
        short vaccineType;

        int number_of_vaccines;
        CovidVaccine **vaccine_array;

        cin >> number_of_vaccines;

        vaccine_array = new CovidVaccine *[number_of_vaccines];

        for (int i = 0; i < number_of_vaccines; ++i) {
            cin >> vaccineType;

            cin.get();
            cin.getline(manufacturer, 100);
            cin.getline(vaccineName, 100);
            cin >> basicEfficiencyCoefficient;

            switch (vaccineType) {
                case 1:
                    cin >> geneticMechanism;
                    vaccine_array[i] = new GeneticVaccine(manufacturer, vaccineName, basicEfficiencyCoefficient,
                                                          geneticMechanism);
                    break;
                case 2:
                    cin >> constituentIngredient;
                    vaccine_array[i] = new InactivatedVaccine(manufacturer, vaccineName, basicEfficiencyCoefficient,
                                                              constituentIngredient);
                    break;
            }

        }

        cout<<mostEffectiveInactivatedVaccine(vaccine_array, number_of_vaccines);
        delete[] vaccine_array;
    }

    return 0;
}
