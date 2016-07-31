#include <iostream>
#include <nlopt.hpp>

/* A simple example of the optimization.
 * fun: x1^2 + x2^2
 * constraint: x1^2 + x2^2 >= 30
 */

double minimizeFun(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data) {
  if (!grad.empty()) {
    grad[0] = -2*x[0];
    grad[1] = -2*x[1];
  }
  return (pow(x[0], 2) + pow(x[1], 2));
}

double constraintFun(const std::vector<double> &x, std::vector<double> &grad, void *data) {
  if (!grad.empty()) {
    grad[0] = -2*x[0];
    grad[1] = -2*x[1];
  }
  return (30 - (pow(x[0], 2) + pow(x[1], 2)));
}

int main(int argc, const char *argv[]) {
  nlopt::opt opt(nlopt::LD_CCSAQ, 2);

  opt.set_min_objective(minimizeFun, NULL);

  opt.add_inequality_constraint(constraintFun, NULL, 0);

  opt.set_xtol_rel(1e-10);

  std::vector<double> x(2);
  x[0] = 0.1; x[1] = -0.2;
  double minf;
  nlopt::result result = opt.optimize(x, minf);

  std::cout << "result: " << result << std::endl;
  std::cout << "x[0]: " << x[0] << std::endl;
  std::cout << "x[1]: " << x[1] << std::endl;
  std::cout << "pow(x[0], 2)+pow(x[1], 2): " << pow(x[0], 2)+pow(x[1], 2) << std::endl;

  return 0;
}
