#include <iostream>
#include <array>

using namespace std;

// hard coded values
float plane_weight = 2050;
float plane_moment = 155400;
int front_num = 2;
float front_weight = 330;
float front_moment_arm = 85;
int rear_num = 2;
float rear_weight = 330;
float rear_moment_arm = 121;
float fuel = 44;
double current_fuel = fuel;
float fuel_weight_density = 6;
float fuel_moment_arm = 75;
float baggage_weight = 10;
float baggage_moment_arm = 140;
float fuel_weight = current_fuel * fuel_weight_density;

// limits
float max_weight = 2950;
float foward_cg = 82.1;
float backward_cg = 84.7;

// values that need to be found
double total_weight;
double total_moment;
double cg;
double delta_fuel;

int main(){
    total_weight = plane_weight + front_weight + rear_weight + baggage_weight + fuel_weight;
    total_moment = plane_moment + (front_weight * front_moment_arm) + (rear_weight * rear_moment_arm) + (baggage_weight + baggage_moment_arm) + (fuel_weight + fuel_moment_arm);
    cg = total_moment/total_weight;

    while (total_weight > max_weight){
        current_fuel -= 0.01;
        fuel_weight = current_fuel * fuel_weight_density; // update new fuel weight
        total_weight = plane_weight + front_weight + rear_weight + baggage_weight + fuel_weight;
        cout << current_fuel << endl;
    }
    
    cout << total_weight << endl;
    cout << total_moment << endl;
    cout << cg << endl;
    return 0;
}