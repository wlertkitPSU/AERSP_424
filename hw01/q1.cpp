#include <iostream>
#include <array>

using namespace std;

/*
// hard coded values
float plane_weight = 2050;
float plane_moment = 155400;
int front_num = 2;
float front_weight[2] = {180,150};
float front_moment_arm = 85;
int rear_num = 2;
float rear_weight[2] = {160,170};
float rear_moment_arm = 121;
float fuel = 44;
double current_fuel = fuel;
float fuel_weight_density = 6;
float fuel_moment_arm = 75;
float baggage_weight = 10;
float baggage_moment_arm = 140;
*/

int main(){

    // User input values
    float plane_weight;
    float plane_moment;
    int front_num;
    float front_weight[10]; // Assuming 10 person limit for front
    float front_moment_arm;
    int rear_num;
    float rear_weight[10]; // Assuming 10 person limit for rear
    float rear_moment_arm;
    float fuel;
    float fuel_weight_density;
    float fuel_moment_arm;
    float baggage_weight;
    float baggage_moment_arm;

    
    // Getting user input 

    // Input plane weight
    cout << "Enter the airplane empty weight (pounds): ";
    cin >> plane_weight;

    // Input plane moment
    cout << "Enter the airplane empty moment (pounds-inches):";
    cin >> plane_moment;

    // Input the number of passengers in the front of the plane
    cout << "Enter the number of front seat occupants: ";
    cin >> front_num;

    // Input the weight of each front passenger
    for (int i = 0; i < front_num; ++i) {
        cout << "Enter weight of front seat occupant " << (i + 1) << " (pounds): ";
        cin >> front_weight[i];
    }

    // Input the front moment arm
    cout <<  "Enter the front moment arm of the plane (pounds-inches): ";
    cin >> front_moment_arm;

    // Input the number of passengers in the rear of the plane
    cout << "Enter the number of rear seat occupants: ";
    cin >> rear_num;

    // Input the weight of each rear passenger
    for (int i = 0; i < rear_num; ++i){
        cout << "Enter weight of rear seat occupant " << (i + 1) << " (pounds): ";
        cin >> rear_weight[i];
    }

    // Input the rear moment arm
    cout << "Enter the rear moment arm of the plane (pounds-inches): ";
    cin >> rear_moment_arm;

    // Input fuel weight
    cout << "The number of gallons of usable fuel (gallons): "; 
    cin >> fuel;

    // Input the fuel weight density
    cout << "Usable fuel weight per gallon (pounds): ";
    cin >> fuel_weight_density;

    // Input fuel moment arm
    cout << "Fuel tank moment arm (inches): ";
    cin >> fuel_moment_arm;

    // Input baggage weight
    cout << "Baggage weight (pounds): ";
    cin >> baggage_weight;

    // Input baggage moment arm
    cout << "Baggage moment arm (inches): ";
    cin >> baggage_moment_arm;

    // Limits
    float max_weight = 2950;
    float forward_cg = 82.1;
    float backward_cg = 84.7;

    // Defining current fuel and fuel weight
    double current_fuel = fuel;
    float fuel_weight = current_fuel * fuel_weight_density;

    // Values that need to be found
    double total_weight;
    double total_moment;
    double cg;


    // Calculating total front weight
    float total_front_weight = 0;
    for (int i = 0; i < front_num; ++i){
        total_front_weight += front_weight[i];
    }

    // Calculating total rear weight
    float total_rear_weight = 0;
    for (int i = 0; i < rear_num; ++i){
        total_rear_weight += rear_weight[i];
    }
    
    // Calculating total weight, total moment, and CG location
    total_weight = plane_weight + total_front_weight + total_rear_weight + baggage_weight + fuel_weight;
    total_moment = plane_moment + (total_front_weight * front_moment_arm) + (total_rear_weight * rear_moment_arm) + (baggage_weight * baggage_moment_arm) + (fuel_weight * fuel_moment_arm);
    cg = total_moment/total_weight;
    
    if (cg < forward_cg){
        while (total_weight > max_weight || cg < forward_cg){
            current_fuel -= 0.01;
            fuel_weight = current_fuel * fuel_weight_density; // update new fuel weight
            total_weight = plane_weight + total_front_weight + total_rear_weight + baggage_weight + fuel_weight;
            cout << total_weight << " " << "pounds" << endl;
            cout << cg << " " << "inches" << endl;

            // Recalculate total moment
            total_moment = plane_moment + (total_front_weight * front_moment_arm) + (total_rear_weight * rear_moment_arm) + (baggage_weight * baggage_moment_arm) + (fuel_weight * fuel_moment_arm);

            // Recalculate CG
            cg = total_moment/total_weight;
        }
    }
    
    else if (cg > backward_cg){

        while (total_weight > max_weight || cg < forward_cg){
            current_fuel += 0.01;
            fuel_weight = current_fuel * fuel_weight_density; // update new fuel weight
            total_weight = plane_weight + total_front_weight + total_rear_weight + baggage_weight + fuel_weight;
            cout << total_weight << " " << "pounds" << endl;
            cout << cg << " " << "inches" << endl;

            // Recalculate total moment
            total_moment = plane_moment + (total_front_weight * front_moment_arm) + (total_rear_weight * rear_moment_arm) + (baggage_weight * baggage_moment_arm) + (fuel_weight * fuel_moment_arm);

            // Recalculate CG
            cg = total_moment/total_weight;

        }
    }

    cout << "Final gross weight: " << total_weight << " " << "pounds" << endl;
    cout << "Final CG location: " << cg << " " << "inches" << endl;
    return 0;
}