#include "q2.h"
#include <vector>
#include <algorithm>
using namespace std;

void robots (int id, mutex& ma, mutex& mb, mutex& m0){
        int TIME_GRABBING_TOOL = 100;
        lock_guard<mutex> gma(ma);
        lock_guard<mutex> gmb(mb);
        {
            lock_guard<mutex> gm0 (m0);
            cout<<id<< " " << "is reaching and grabbing the tools."<<endl;
        }
    this_thread::sleep_for(chrono::milliseconds(TIME_GRABBING_TOOL));
        int TIME_LANDING_TOOL = 100;
        {
            lock_guard<mutex> gm0 (m0);
            cout<<id<< " " <<"has acquired the tools."<<endl;
        }
    this_thread::sleep_for(chrono::milliseconds(TIME_LANDING_TOOL));
        int TIME_USING_TOOL = 500;
        {
            lock_guard<mutex> gm0 (m0);
            cout<<id<<" "<<"starts performing the task."<<endl;
            cout<<id<<" "<< "finished the task and returned the tools."<<endl;
        }
    this_thread::sleep_for(chrono::milliseconds(TIME_USING_TOOL));
}