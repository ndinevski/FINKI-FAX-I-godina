#include<iostream>
#include <algorithm>
#include <cctype>
#include<cstring>
using namespace std;

class WrongLabelsFormatException{
public:
    WrongLabelsFormatException(){}
    void message(){
        cout<<"Labels must have the same length";
    }
};

class Evaluator{
protected:
    char vistinska[100];
    char predvidena[100];
public:
    Evaluator(const char * vistinska="", const char * predvidena=""){
        if(strlen(vistinska)!=strlen(predvidena)){
            throw WrongLabelsFormatException();
        }
        strcpy(this->vistinska, vistinska);
        strcpy(this->predvidena, predvidena);
    }
    virtual double evaluate () = 0;
    virtual void print() = 0;

};

class AccuracyEvaluator : public Evaluator{
public:
    AccuracyEvaluator(const char * vistinska="", const char * predvidena="") : Evaluator(vistinska, predvidena){}

    double evaluate(){
        int tocni=0;
        for(int i=0;i<strlen(vistinska);i++){
            if(vistinska[i]==predvidena[i]){
                tocni++;
            }
        }
        return (double)tocni/strlen(vistinska);
    }

    void print(){
        cout<<"Number of data points: "<<strlen(vistinska)<<" Prediction Accuracy: "<<evaluate()<<endl;
    }

};

class SensitivityEvaluator : public Evaluator{
public:
    SensitivityEvaluator(const char * vistinska="", const char * predvidena="") : Evaluator(vistinska, predvidena){}

    double evaluate(){
        int pluscounter=0, plusovi=0;
        for(int i=0;i<strlen(vistinska);i++){
            if(vistinska[i]=='+'){
                pluscounter++;
            }
            if(vistinska[i]=='+' && vistinska[i]==predvidena[i]){
                plusovi++;
            }
        }
        return (double)plusovi/pluscounter;
    }

    void print(){
        cout<<"Number of data points: "<<strlen(vistinska)<<" Prediction Sensitivity: "<<evaluate()<<endl;
    }
};

bool operator >= (Evaluator & a, Evaluator & b){
    if( a.evaluate() >= b.evaluate()){
        return true;
    }
    return false;
}

Evaluator * highestScore (Evaluator ** evaluators, int n){
    float maks=0;
    int indeks;
    for(int i=0;i<n;i++){
        if(evaluators[i]->evaluate()>= maks){
            maks = evaluators[i]->evaluate();
            indeks = i;
        }
    }
    Evaluator * tmp = evaluators[indeks];
    return tmp;
}

int main() {
    int testCase;
    char trueLabels[100];
    char predictedLabels[100];
    cin >> testCase;
    if (testCase == 1) {
        cout << "TESTING CREATION OF ACCURACY EVALUATOR. EXCEPTION CAN HAPPEN HERE!" << endl;
        cin >> trueLabels >> predictedLabels;
        try{
            Evaluator *evaluator = new AccuracyEvaluator(trueLabels, predictedLabels);
            cout << evaluator->evaluate() << endl;
            evaluator->print();
        }
        catch (WrongLabelsFormatException & e){
                e.message();
            }

    } else if (testCase == 2) {
        cout << "TESTING CREATION OF ACCURACY EVALUATOR. EXCEPTION CAN HAPPEN HERE!" << endl;
        cin >> trueLabels >> predictedLabels;
        try{
            Evaluator *evaluator = new SensitivityEvaluator(trueLabels, predictedLabels);
            cout << evaluator->evaluate() << endl;
            evaluator->print();
        }
        catch (WrongLabelsFormatException & e){
                e.message();
            }

    } else if (testCase == 3) {
        cout << "TESTING CREATION OF BOTH EVALUATORS. EXCEPTION CAN HAPPEN HERE!" << endl;
        cin >> trueLabels >> predictedLabels;
        try{
            Evaluator *accuracy = new AccuracyEvaluator(trueLabels, predictedLabels);
            Evaluator *sensitivity = new SensitivityEvaluator(trueLabels, predictedLabels);
            accuracy->print();
            sensitivity->print();
        }
        catch (WrongLabelsFormatException & e){
                e.message();
            }

    } else if (testCase == 4) {
        cout << "TESTING OPERATOR >=" << endl;
        cin >> trueLabels >> predictedLabels;
        Evaluator *accuracy = new AccuracyEvaluator(trueLabels, predictedLabels);
        Evaluator *sensitivity = new SensitivityEvaluator(trueLabels, predictedLabels);
        cin >> trueLabels >> predictedLabels;
        Evaluator *accuracy1 = new AccuracyEvaluator(trueLabels, predictedLabels);
        Evaluator *sensitivity1 = new SensitivityEvaluator(trueLabels, predictedLabels);

        accuracy->print();
        cout << (((*accuracy) >= (*sensitivity)) ? ">=" : "<") << endl;
        sensitivity->print();
        cout << endl;

        sensitivity->print();
       cout << (((*sensitivity) >= (*accuracy)) ? ">=" : "<") << endl;
        accuracy->print();
        cout << endl;

        accuracy->print();
        cout << (((*accuracy) >= (*accuracy1)) ? ">=" : "<") << endl;
        accuracy1->print();
        cout << endl;

        sensitivity->print();
        cout << (((*sensitivity) >= (*sensitivity1)) ? ">=" : "<") << endl;
        sensitivity1->print();
        cout << endl;
    } else {
        cout << "INTEGRATION TEST AND TESTING GLOBAL FUNCTION. EXCEPTION CAN HAPPEN HERE!" << endl;
        int n;
        cin >> n;
        Evaluator **evaluators = new Evaluator *[n];
        for (int i = 0; i < n; i++) {
            int type;
            cin >> type;
            cin >> trueLabels >> predictedLabels;
            if (type == 1) { //accuracy
                try{
                    evaluators[i] = new AccuracyEvaluator(trueLabels, predictedLabels);
                }catch (WrongLabelsFormatException & e){
                        e.message();
                        n--;
                        i--;
                }
            } else { //sensitivity
                try{
                evaluators[i] = new SensitivityEvaluator(trueLabels, predictedLabels);
                }catch (WrongLabelsFormatException & e){
                        e.message();
                        n--;
                        i--;
                }
            }

            }

        cout << "PRINT ALL EVALUATORS FIRST!" << endl;
        for (int i = 0; i < n; i++) {
            evaluators[i]->print();
        }

        cout << "RESULT FROM HIGHEST SCORE METHOD" << endl;
        highestScore(evaluators, n)->print();
    }

}