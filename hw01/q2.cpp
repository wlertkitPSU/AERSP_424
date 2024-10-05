#include <iostream>
#include <string>
#include <map>

int main(){
    std::map<std::string, std::map<std::string, int>> distance;

    distance["SCE"]["PHL"] = 160;
    distance["SCE"]["ORD"] = 640;
    distance["SCE"]["EWR"] = 220;
}