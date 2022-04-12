#include<iostream>
#include<string>
#include<Eigen/Eigen>
#include"gcopter/test_lbfgs.hpp"
#include"gcopter/lbfgs.hpp"
using namespace std;
void eigen_map(){
    Eigen::VectorXd x(3+4);
    x<<1,2,3,4,5,6,7;
    std::cout<<"VectorXd x ="<<x<<std::endl;
    Eigen::Map<Eigen::VectorXd> y(x.data(),3);
    std::cout<<y<<std::endl;
}

void eigne_normal(){
    Eigen::Matrix3Xd x;
    x.resize(3,6);
    cout <<lbfgs::LBFGSERR_INVALID_N<<endl;
    cout <<lbfgs::LBFGS_CANCELED<<endl;
    // cout <<"x.cols()="<<x.cols()<<endl;
    // cout <<"x.rows()="<<x.rows()<<endl;
    // cout <<"x.col(0)="<<endl;
    // cout <<x.col(0)<<endl;
    // cout <<"x.row(0)="<<endl;
    // cout <<x.row(0) <<endl;
}
class L_BFGS{
public:
    lbfgs::lbfgs_parameter_t lbfgs_param;    

    static inline double costFunctional(void *ptr, const Eigen::VectorXd &x, Eigen::VectorXd &g){
        double cost;
        //f(x) = -3*x*sin(0.75) + e^-2x
        cost = -3*x[0]*sin(0.75*x[0]) + exp(-2*x[0]);
        g[0] = -3*sin(0.75*x[0]) - 3*0.75*x[0]*cos(0.75*x[0]) - 2*exp(-2*x[0]);
        return cost;
    }

    inline double optimize(){
        Eigen::VectorXd x(1);
        Eigen::VectorXd g(1);
        lbfgs_param.mem_size = 256;
        lbfgs_param.past = 3;
        
        double minCostFunctional;

        int ret = lbfgs::lbfgs_optimize(x, minCostFunctional, &L_BFGS::costFunctional,nullptr,nullptr,this,lbfgs_param);


    }
};

int main(){
    cout << exp(0) <<endl;
    cout << exp(1) <<endl;

    // eigen_map();
    // eigne_normal();
    // std::cout<<"for test\n";
    return 0;
}