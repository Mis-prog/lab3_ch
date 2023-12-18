#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>
#include <fstream>

using namespace std;

namespace task1 {
    void print_matrix(vector<vector<double>> A);

    void print_vector(vector<double> A);

    vector<double> method_gaussa(vector<vector<double>> matrix_coef);

    void main_task1();

    vector<vector<double>> &set_matrix(vector<vector<double>> &matrix_coef);

    vector<double> get_coef();

    void point_1();

    double rational_interpoletion(vector<double> &coef, double x);

    const vector<double> x = {-3.5, -2.1, -0.7, 0.7, 2.1, 3.5};
    const vector<double> y = {-2.0709, -0.73400, -0.60998, 0.34831, 0.28276, 0.16644};

    void write_node_file();

    void point_2_3();
}

namespace task2 {

}