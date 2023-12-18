#include "task.h"

using namespace task1;

void task1::print_matrix(vector<vector<double>> A) {

    cout << "-------------------------" << endl;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

void task1::print_vector(vector<double> A) {

    cout << "-------------------------" << endl;
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}


vector<double> task1::method_gaussa(vector<vector<double>> matrix_coef) {

    int n = matrix_coef.size();
    vector<double> x_answer;
    x_answer.resize(n);
    cout << "Исходная матрица " << endl;
    print_matrix(matrix_coef);

    for (int i = 0; i < n; i++) {
        double curr_max = matrix_coef[i][i];
        int index_max = i;
        for (int j = i; j < n; j++) {
            if (abs(matrix_coef[j][i]) > abs(curr_max)) {
                curr_max = matrix_coef[j][i];
                index_max = j;
            }
        }
        if (i != index_max) {
            for (int j = 0; j <= n; j++) {
                double new_temp = matrix_coef[i][j];
                matrix_coef[i][j] = matrix_coef[index_max][j];
                matrix_coef[index_max][j] = new_temp;
            }
        }
        for (int a = i + 1; a < n; a++) {
            double mu = matrix_coef[a][i] / matrix_coef[i][i];
            for (int b = i; b <= n; b++) {
                matrix_coef[a][b] -= (matrix_coef[i][b] * mu);
            }
        }
    }
    cout << "-------------------------" << endl;
    cout << "Матрица Гаусса" << endl;
    print_matrix(matrix_coef);
    x_answer[n - 1] = matrix_coef[n - 1][n] / matrix_coef[n - 1][n - 1];

    for (int i = n - 2; i >= 0; i--) {
        x_answer[i] = matrix_coef[i][n] / matrix_coef[i][i];
        int raz = abs(i - n + 1);
        for (int j = 1; j <= raz; j++) {
            x_answer[i] -= ((matrix_coef[i][i + j] * x_answer[i + j]) / matrix_coef[i][i]);
        }
    }
    return x_answer;
}

void task1::main_task1() {
    //point_1();
    point_2_3();
}

void task1::point_1() {
    vector<vector<double >> matrix_coef;
    matrix_coef = set_matrix(matrix_coef);
    vector<double> x_answer = method_gaussa(matrix_coef);
    cout << "-------------------------" << endl;
    cout << "Решение сиcтемы " << endl;
    print_vector(x_answer);
}

vector<vector<double>> &task1::set_matrix(vector<vector<double>> &matrix_coef) {
    int count;
    cout << "Введите количество уравнений в системе: " << endl;
    cin >> count;
    matrix_coef.resize(count);
    for (int i = 0; i < count; i++) {
        matrix_coef[i].resize(count);
    }
    for (int i = 0; i < count; i++) {
        cout << "Введите коэфиценты " << i + 1 << " уравнения " << endl;
        for (int j = 0; j < count; j++) {
            cin >> matrix_coef[i][j];
        }
    }
    cout << "Введите у_i: " << endl;
    double y_answer;
    for (int j = 0; j < count; j++) {
        cin >> y_answer;
        matrix_coef[j].push_back(y_answer);
    }
    cout << endl;
    return matrix_coef;
}

//vector<double> &initial_polynom(int n,) {
//
//}

double task1::rational_interpoletion(vector<double> &coef, double x) {
    return (coef[0] + x * coef[1]) /
           (1 + x * coef[2] + x * x * coef[3] + x * x * x * coef[4] + x * x * x * x * coef[5]);
}

vector<double> task1::get_coef() {
    vector<vector<double>> Matrix(6);
    for (int i = 0; i < x.size(); i++) {
        Matrix[i].push_back(1);// a0
        Matrix[i].push_back(x[i]);// a1 * x
        Matrix[i].push_back(-x[i] * y[i]); // -b1 * x * y
        Matrix[i].push_back(-x[i] * x[i] * y[i]);// -b2 * x (^2) * y
        Matrix[i].push_back(-x[i] * x[i] * x[i] * y[i]);// -b3 * x(^3) * y
        Matrix[i].push_back(-x[i] * x[i] * x[i] * x[i] * y[i]);// -b4 * x(^4) * y
        Matrix[i].push_back(y[i]); // = yi
    }
    vector<double> coef_inter = method_gaussa(Matrix);
    print_vector(coef_inter);
    return coef_inter;
}

void task1::write_node_file() {
    ofstream out_plot;
    out_plot.open("node_task1.txt");
    for (int i = 0; i < 6; i++) {
        out_plot << x[i] << " " << y[i] << endl;
    }
    out_plot.close();
}

void task1::point_2_3() {
    write_node_file();
    vector<double> coef = get_coef();
    ofstream outPlot;
    outPlot.open("interpolFoo_task1.txt");
    double x_cur = -3.5, h = 0.01;
    while (x_cur <= 3.5) {
        outPlot << x_cur << " " << rational_interpoletion(coef, x_cur) << endl;
        x_cur+=h;
    }
    outPlot.close();

    system("python D:\\5sem\\numerical\\Lab3\\src\\plot\\task1.py");
}