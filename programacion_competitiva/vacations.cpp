#include <bits/stdc++.h>
using namespace std;
using vint = vector<int>;

int countRestDays(vint days){
    int count = 0;
    vector<string> activities;
    bool wasGym = false;
    bool wasContest = false;
    for(int i = 0; i < days.size(); i++){
        bitset<2> todayConditions = days[i];
        bool isGym = todayConditions[0];
        bool isContest = todayConditions[1];
        cout<<"-"<<isGym<<isContest<<endl;
        // Rest if none
        if(!isGym && !isContest){
            // cout<<i+1<<" Rest"<<endl;
            count++;
            wasContest = false;
            wasGym = false;
            continue;
        }
        // If is gym and previusly wasnt
        if(isGym && !wasGym){
            // cout<<i+1<<" Gym"<<endl;
            wasGym = true;
            continue;
        }
        if(isContest && !wasContest){
            // cout<<i+1<<" Contest"<<endl;
            wasContest = true;
            continue;
        }
        wasContest = isContest;
        wasGym = isGym;

        count++;
    }
    return count;
}


int main(){
    int n;
    cin>>n;
    vint vacations(n);
    for(int &day : vacations) cin>>day;
    cout<<countRestDays(vacations)<<endl;
    return 0;
}