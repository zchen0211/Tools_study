#include <iostream>
#include <Eigen/Eigen>

using namespace Eigen;
using namespace std;

int main() {
  // Basic Matrix
  Matrix4f A = Matrix4f::Random(); // size set at compile time
  std::cout << A << std::endl;
  MatrixXd m = MatrixXd::Random(3,3);
  cout << "m =" << endl << m << endl;
  m = m + MatrixXd::Constant(3,3,1.2); // constant (3, 3) matrix, all filled with 1.2
  m = m * 50;
  cout << "m =" << endl << m << endl;
  VectorXd v(3);
  v << 1, 2, 3;
  cout << "m * v =" << endl << m * v << endl;
  // class Matrix<typename Scalar, int RowsAtCompileTime, int ColsAtCompileTime>
  // typedef Matrix<float, 4, 4> Matrix4f;
  // typedef Matrix<float, 3, 1> Vector3f;
  // typedef Matrix<int, 1, 2> RowVector2i;


  // Small objects

  // Large objects, Dynamic objects
  // typedef Matrix<double, Dynamic, Dynamic> MatrixXd;
  // typedef Matrix<int, Dynamic, 1> VectorXi;

  // Communication
  int mymatrix[4], mymatrix2[16];
  // Map<MatrixXf> M(mymatrix, 1, 4);
  // Map<MatrixXf> M2(mymatrix2+4, 1, 4);
  for (size_t i = 0; i < 4; ++i) mymatrix[i] = i;
  for (size_t i = 0; i < 16; ++i) mymatrix2[i] = 0;

  for (size_t i = 0; i < 16; ++i) cout << mymatrix2[i] << " ";
  //
  Eigen::Map<Eigen::Array<int, Eigen::Dynamic, 1> >(mymatrix2+4, 4) = 
        (Eigen::Map<const Eigen::Array<int, Eigen::Dynamic, 1> >(mymatrix, 4)) +
        (Eigen::Map<const Eigen::Array<int, Eigen::Dynamic, 1> >(mymatrix2+4, 4));

  //cout << "M: " << M << endl;
  //cout << "M2: " << M2 << endl;

  //M2 = M2 + M;
  //cout << M2 << endl;

  for (size_t i = 0; i < 16; ++i) cout << mymatrix2[i] << " ";

  // Together with BLAS

  // Expression Templates

  // Tensors

  return 0;
}
