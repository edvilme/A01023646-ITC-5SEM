#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <sstream>
#include <math.h>
using namespace std;

class Task {
    public:
        static bool areForwardCompatible(Task t1, Task t2){
            return t1.end <= t2.start;
        };
        static bool areBackwardCompatible(Task t1, Task t2){
            return t1.start >= t2.end;
        };
        int index, 
            start, 
            end, 
            weight;
        Task(){
            index = 0;
            start = 0;
            end = 0;
            weight = 0;
        }
        Task(int index, int start, int end, int weight){
            this->index = index;
            this->start = start;
            this->end = end;
            this->weight = weight;
        }
        friend ostream& operator<<(ostream& os, const Task& t){
            os << "[" << t.index << "]\t" << t.start << " -> " << t.end << "\tw: "<<t.weight;
            return os;
        }
};

vector<Task> findNextCompatibleTasks(Task t1, Task allTasks[], int N){
    vector<Task> tasks;
    tasks.push_back(t1);
    for(int i = t1.index + 1; i<N-1; i++){
        if( Task::areForwardCompatible(t1, allTasks[i]) ){
            tasks.push_back(allTasks[i]);
        }
    }
    return tasks;
}

int main(int argc, char** argv){
    int N = atoi(argv[1]);
    int startValues[N], endValues[N], weightValues[N];
    Task allTasks[N];
    for(int i = 0; i<N; i++){
        int start = atoi(argv[i+2]);
        int end = atoi(argv[i+2+N]);
        int weight = atoi(argv[i+2+N+N]);
        allTasks[i] = Task(i, start, end, weight);
        cout<<allTasks[i]<<endl<<"============================"<<endl;
    }
    cout<<endl<<endl;

    for(int i = 0; i<N; i++){
        cout<<"["<<i<<"]\t";
        vector<Task> compatibleTasks = findNextCompatibleTasks(allTasks[i], allTasks, N);
        for(int j = 0; j<compatibleTasks.size(); j++){
            cout<<compatibleTasks[j]<<", ";
        }
        cout<<endl;
    }

    return 0;
}