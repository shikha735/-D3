#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Here, array index starts from 1.
int minTrials(int eggs, int floors){
    int T[eggs+1][floors+1];
    int c = 0;

    // for 1 egg and 0 floors we get 0 trials, m eggs and 1 floor we get 1 trial
    for(int i=1;i<=eggs;i++)
        T[i][0] = 0;
    // for 1 egg we have worst case as the number of floors itself
    // Initializing values for 1 egg
    for(int i=0;i<=floors;i++)
        T[1][i] = i;

    for(int e=2;e<=eggs;e++){
        for(int f=1;f<=floors;f++){
            T[e][f] = INT_MAX;
            for(int k=1;k<=floors;k++){
                c = 1 + max(T[e-1][k-1],T[e][f-k]);
                if(c < T[e][f])
                    T[e][f] = c;
            }
        }
    }
    return T[eggs][floors];
}

int recMinTrials(int eggs, int floors){
    if(eggs == 1)
        return floors;
    if(floors == 0 || floors == 1)
        return floors;
    int min = INT_MIN;
    for(int f=1;f<=floors;f++){
        int val = 1 + max(recMinTrials(eggs-1,f-1),recMinTrials(eggs,floors-f));
        if(val < min)
            min = val;
    }
    return min;
}

int main(){
    int eggs, floors;
    cout << "Enter number of eggs and floors: ";
    cin >> eggs >> floors;
    cout << recMinTrials(eggs, floors);
    return 0;
}
