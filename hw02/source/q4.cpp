#include <q4.h>

void create3DGraph(){
    // Generating meshgrid
    std::vector<double> x = matplot::iota(-10, 0.2, 10);
    std::vector<double> y = matplot::iota(-10, 0.2, 10);
    auto [X, Y] = matplot::meshgrid(x, y);

    // Computing z = sin(sqrt(x^2 + y^2))
    auto z = [](double x, double y){
        return std::sin(std::sqrt(x*x + y*y));
    };
    auto Z = matplot::transform(X, Y, z);

    // Plotting
    matplot::surf(X, Y, Z);
    matplot::zlim({-5, 5});
    matplot::save("results/graph_3D.jpg");
}

void csvPlot(){
    // Initializing vectors
    std::vector<double> X;
    std::vector<double> Y;

    // Open the file and skipping the headers
    std::ifstream file("butterfly_curve.csv");
    std::string line;
    std::getline(file, line);

    // Reading from the file
    while (std::getline(file, line)) {
        // Reading the entire line
        std::stringstream ss(line);

        // Reading each column
        std::string time_string, x_string, y_string;
        std::getline(ss, time_string, ',');
        std::getline(ss, x_string, ',');
        std::getline(ss, y_string, ',');

        // Converting string to double
        double x = std::stod(x_string);
        double y = std::stod(y_string);

        // Appending to X and Y vectors
        X.push_back(x);
        Y.push_back(y);
    }

    // Close file
    file.close();

    // Plot
    matplot::plot(X, Y);
    matplot::save("results/butterfly_curve.jpg");

}