//Top down with Memoization Weighted Interval Scheduling

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <sstream>
#include <math.h>
using namespace std;

// Task Object
class Task{
    public:   
        int index; 
        int start; //starting time
        int end; //finish time
        int weight; //weight of task
        Task(){}
        Task(int index, int start, int end, int weight){
            this->index = index;
            this->start = start;
            this->end = end;
            this->weight = weight;
        }
        void print(){
            cout<<this->start<<"->"<<this->end<<endl;
        }   
        friend ostream& operator<<(ostream& os, const Task& selected){
            os << "(" << selected.index << ") " << selected.start<<"->"<<selected.end<<" w: "<<selected.weight;
            return os;
        }      
}; 

class TaskCombination{
    private:
        vector<Task> tasks;
    public: 
        int maxProfit; 
        vector<int> indexes; 

        TaskCombination(){
            maxProfit = 0;
        };
        void push_back_previous(Task t){
                maxProfit += t.weight;
                indexes.push_back(t.index);
                tasks.push_back(t);
        }
        friend ostream& operator<<(ostream& os, const TaskCombination& t){
            os << "Max Profit: " << t.maxProfit << "\t Indexes: ";
            for (int i = 0; i < t.indexes.size(); i++) os << t.tasks[i] << ", ";
            return os;
        }
};

bool areCompatible(Task t1, Task t2){
    // If they dont overlap
    return t2.start >= t1.end;
}

// Merge
void merge(Task tasks[], int const left, int const mid, int const right)
{
    auto const subArrayLeft = mid - left + 1;
    auto const subArrayRight = right - mid;
 
    auto *leftArray = new Task[subArrayLeft],
         *rightArray = new Task[subArrayRight];
 
    for (auto i = 0; i < subArrayLeft; i++)
        leftArray[i] = tasks[left + i];
    for (auto j = 0; j < subArrayRight; j++)
        rightArray[j] = tasks[mid + 1 + j];
 
    auto indexOfSubArrayLeft = 0, 
        indexOfSubArrayRight = 0;
    int indexOfMergedArray = left; 

    while (indexOfSubArrayLeft < subArrayLeft && indexOfSubArrayRight < subArrayRight) {
        if (leftArray[indexOfSubArrayLeft].end <= rightArray[indexOfSubArrayRight].end) {
            tasks[indexOfMergedArray] = leftArray[indexOfSubArrayLeft];
            indexOfSubArrayLeft++;
        }
        else {
            tasks[indexOfMergedArray] = rightArray[indexOfSubArrayRight];
            indexOfSubArrayRight++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayLeft < subArrayLeft) {
        tasks[indexOfMergedArray] = leftArray[indexOfSubArrayLeft];
        indexOfSubArrayLeft++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayRight < subArrayRight) {
        tasks[indexOfMergedArray] = rightArray[indexOfSubArrayRight];
        indexOfSubArrayRight++;
        indexOfMergedArray++;
    }
}

// Merge sort
void mergeSort(Task tasks[], int const low, int const high){
    if (low >= high)
        return; // Returns recursivly
 
    auto mid = low + (high - low) / 2;
    mergeSort(tasks, low, mid);
    mergeSort(tasks, mid + 1, high);
    merge(tasks, low, mid, high);
}

// Find task that is compatible
int binarySearch(Task tasks[], int currentIndex){
    int low = 0; 
    int high = currentIndex - 1;
  
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (tasks[mid].end <= tasks[currentIndex].start)
        {
            if (tasks[mid + 1].end <= tasks[currentIndex].start)
                low = mid + 1;
            else
                return mid;
        }
        else
            high = mid - 1;
    }
    return -1;
}

Task selectMaxWeight(Task t1, Task t2){
    if(t1.weight > t2.weight) return t1;
    return t2;
}

// Fin
vector<int> findCompatible(Task allTasks[], int N){
    // Indices will be stored here
    vector<int> result;
    //Sort by end time with mergeSort 
    mergeSort(allTasks, 0, N-1);
    // Hacer lista de taskcombinations
    vector<TaskCombination> allCombinations;
    for(int i = 0; i<N; i++) allCombinations.push_back(TaskCombination());
    // Iterar tareas
    for(int i = 0; i<N; i++){
        Task t = allTasks[i];
        allCombinations[i].push_back_previous(t);
        int previousCompatibleTaskIndex = binarySearch(allTasks, i);
        while(previousCompatibleTaskIndex != -1){
            allCombinations[i].push_back_previous(allTasks[previousCompatibleTaskIndex]);
            previousCompatibleTaskIndex = binarySearch(allTasks, previousCompatibleTaskIndex);
        }
        cout<<allCombinations[i]<<endl;
    }



    sort(result.begin(), result.end());
    return result;
}



/**
 *
 * @param argc Size of argv
 * @param argv N, N start values, N finish values. N weight values
 * @return Indexes of tasks in the max set of compatible tasks with max weight value
*/
int main(int argc, char** argv){ 

    //First argument is the amount of tasks
    int N = atoi(argv[1]);
    
    // 2 - N+2 Start values
    int startValues[N]; 
    for(int i = 0; i<N; i++){
        startValues[i] = atoi(argv[i+2]);   
    }
    // N - 2*N End values
    int endValues[N]; 
    for(int i = 0; i<N; i++){
        endValues[i] = atoi(argv[i+2+N]);
    }
    // Weights
    int weightValues[N]; 
    for(int i = 0; i<N; i++){
        weightValues[i] = atoi(argv[i+2+N+N]);
    }

    // Create tasks
    Task allTasks[N];
    for(int i = 0; i<N; i++){
        Task selected(i, startValues[i], endValues[i], weightValues[i]);
        allTasks[i] = selected;
        // Print tasks
        // TODO: remove
        cout<<selected<<endl<<"====================="<<endl;
    }



    // Resultados
    vector<int> resultados = findCompatible(allTasks, N);

    for(int i = 0; i < resultados.size(); i++){
        cout << resultados[i] << " ";  
    } 
    //imprimir result printArray(allTasks, N);
    return 0;
}