#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include <chrono>
using namespace std::chrono;

#include<Eigen>

using namespace Eigen;
using Eigen::MatrixXd;
using Eigen::VectorXd;

using namespace std;
int main()
{
fstream time;
time.open("Eigen_time.txt", ios::out);

//Write a input matrix of elements of floating numbers in range [-1, 1] size 200*200
fstream file1;
file1.open("input_matrix1.txt", ios::out);

MatrixXd m1 = MatrixXd::Random(200,200);
m1 = (m1 + MatrixXd::Constant(200,200,1.2)) * 50;
file1 << std::endl << m1 << std::endl;
file1.close();

//Write a input vector of elements of floating numbers in range [-1, 1] size 200
fstream file2;
file2.open("input_vector1.txt", ios::out);
VectorXd v1 = VectorXd::Random(200);
v1 = (v1 + VectorXd::Constant(200, 1.2)) * 50;
file2 << std::endl << v1 << std::endl;
file2.close();



// Start timing
clock_t begin = clock();
for (int i = 0; i < 100; i++) {
    MatrixXd x = m1.fullPivLu().solve(v1);
}

// End timing
clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

time << elapsed_secs << " seconds" << endl;

return 0;
}