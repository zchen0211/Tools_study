#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Eigen>
#include <unsupported/Eigen/CXX11/Tensor>

using namespace Eigen;
using Eigen::MatrixXd;

void test_matrix() {
  MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << m << std::endl;
}

int main() {
  test_matrix();

  Matrix4f A = Matrix4f::Random();
  Matrix4f B = Matrix4f::Random();
  Matrix4f C = Matrix4f::Random();
  std::cout << A << std::endl;

  /*float* raw_data = A.data();
  int stride = A.outerStride();
  for(int i=0; i< 16; i++)
    std::cout << raw_data[i] << " ";*/

  C = A + B + C;
  std::cout << C << std::endl;

  ::Eigen::Tensor<float, 3> t_3d(2, 3, 4);

  return 0;
}

