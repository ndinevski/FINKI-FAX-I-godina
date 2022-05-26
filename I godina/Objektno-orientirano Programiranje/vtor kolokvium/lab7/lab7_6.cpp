//https://i.imgur.com/inecuRO.png

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Task{
    protected:
        char ID[5];
    public:
        Task(char * ID=""){
            strcpy(this->ID, ID);
        }
        ~Task(){}
        char * getID(){
            return ID;
        }
        virtual int getOrder() = 0;
        virtual void print() = 0;
};

bool operator == (Task * t1, Task &t2){
    return (!strcmp(t1->getID(), t2.getID()) && t1->getOrder() == t2.getOrder());
}


class TimedTask : public Task{
    protected:
        int time;
    public:
        TimedTask(char * ID="", int time=0): Task(ID){
            this->time = time;
        }
        int getOrder(){
            return time;
        }
        void print(){
            cout<<"TT->"<<ID<<":"<<getOrder()<<endl;
        }

};

class PriorityTask : public Task{
    protected:
        int priority;
    public:
        PriorityTask(char * ID="", int priority=0): Task(ID){
            this->priority = priority;
        }
        int getOrder(){
            return priority;
        }
        void print(){
            cout<<"PT->"<<ID<<":"<<getOrder()<<endl;
        }
};
void BubbleSort(Task ** tasks, int n){
    Task * tmp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(tasks[j]->getOrder()>tasks[j+1]->getOrder()){
                tmp=tasks[j];
                tasks[j]=tasks[j+1];
                tasks[j+1]=tmp;
            }
        }
    }
}

void scheduleTimedTasks(Task ** tasks, int n , int t){
    BubbleSort(tasks,n);
    for(int i=0;i<n;i++){
        TimedTask * tt = dynamic_cast<TimedTask *>(tasks[i]);
        if(tt!=0){
            if(tasks[i]->getOrder() < t){
                tasks[i]->print();
            }
        }
    }
}


void schedulePriorityTasks(Task ** tasks, int n, int p){
    BubbleSort(tasks,n);
    for(int i=0;i<n;i++){
        PriorityTask * tt = dynamic_cast<PriorityTask *>(tasks[i]);
        if(tt!=0){
            if(tasks[i]->getOrder() < p){
                tasks[i]->print();
            }
        }
    }
}




int main () {
    int testCase;
    int n;
    cin>>testCase;
    
    if (testCase==0){
        cin>>n;
    	Task ** tasks;
        tasks = new Task * [n];
    	for (int i=0;i<n;i++){
        char id [5];
        int timeOrPriority;
        int type; //0 za timed, 1 za priority
        cin >> type >>id >> timeOrPriority;
        if (type==0)
        	tasks[i] = new TimedTask(id,timeOrPriority);
        else
            tasks[i] = new PriorityTask(id,timeOrPriority);
        //tasks[i]->print();
    	}
        
    	cout<<"SCHEDULING PRIORITY TASKS WITH PRIORITY DEGREE LESS THAN 10"<<endl;
    	schedulePriorityTasks(tasks,n,10);
        
    }
    else if (testCase==1) {
        cin>>n;
    	Task ** tasks;
        tasks = new Task * [n];
    	for (int i=0;i<n;i++){
        char id [5];
        int timeOrPriority;
        int type; //0 za timed, 1 za priority
        cin >> type >>id >> timeOrPriority;
        if (type==0)
        	tasks[i] = new TimedTask(id,timeOrPriority);
        else
            tasks[i] = new PriorityTask(id,timeOrPriority);
        //tasks[i]->print();
    	}
        
    	
        cout<<"SCHEDULING TIMED TASKS WITH EXECUTION TIME LESS THAN 50"<<endl;
        scheduleTimedTasks(tasks,n,50);
    }
    else {
        TimedTask * tt1 = new TimedTask("11",10);
        TimedTask * tt2 = new TimedTask("11",11);
        TimedTask * tt3 = new TimedTask("11",11);
        PriorityTask * pp1 = new PriorityTask("aa",10);
        PriorityTask * pp2 = new PriorityTask("11",10);
        
        cout << (tt1==(*tt2))<<endl;
        cout << (tt2==(*tt3))<<endl;
        cout << (pp1==(*pp2))<<endl;
        cout << (pp2==(*tt1))<<endl;
    }
    
	return 0;
}