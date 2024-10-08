#include "q2.h"

std::map<std::string, std::map<std::string, int>> distance_init(){
    std::map<std::string, std::map<std::string, int>> distance;

    distance["SCE"]["PHL"] = 160;
    distance["SCE"]["ORD"] = 640;
    distance["SCE"]["EWR"] = 220;

    return distance;
}