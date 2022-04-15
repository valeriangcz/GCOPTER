#include<iostream>
#include<string>
#include<Eigen/Eigen>
#include<sensor_msgs/PointCloud2.h>
#include"gcopter/lbfgs.hpp"
#include"gcopter/sfc_gen.hpp"
using namespace std;
void eigen_map(){
    Eigen::VectorXd x(3+4);
    x<<1,2,3,4,5,6,7;
    std::cout<<"VectorXd x ="<<x.transpose()<<std::endl;
    Eigen::Map<Eigen::VectorXd> y(x.data(),3);
    y.resize(2);
    y[1] = 100;
    cout <<x.transpose()<<endl;
}

void eigne_normal(){
    Eigen::Matrix3d x;
    Eigen::MatrixXd y, z;
    x << 1,2,3,4,5,6,7,8,9;
    Eigen::VectorXd vec;
    vec.resize(4);
    vec<<1,2,3,4;
    cout << vec.head(0)<<endl;
    // cout << vec.head(4) <<endl;

}

void PointCloud2Msg_demo(){
    
}

class L_BFGS{
public:
    L_BFGS(int id):id(id){}
    lbfgs::lbfgs_parameter_t lbfgs_param;    
    int id;
    static inline double costFunctional(void *ptr, const Eigen::VectorXd &x, Eigen::VectorXd &g){
        double cost;
        double x1 = x[0], x2 = x[1];
        cost = x1*x1 + x2*x2 +x1*x2 +2;
        g[0] = 2*x1 + x2;
        g[1] = x1 + 2*x2;
        return cost;
    }

    static inline int progress(void * ptr, const Eigen::VectorXd &x,
                               const Eigen::VectorXd &g,
                               const double fx,
                               const double step,
                               const int k,
                               const int ls){
                                //    L_BFGS &l = *(L_BFGS*) ptr;
                                   
                                   return 0;
    }

    inline double optimize(){
        Eigen::VectorXd x(2);
        x << 1, -4;
        // Eigen::VectorXd g(2);
        lbfgs_param.mem_size = 6;
        lbfgs_param.past = 5;
        lbfgs_param.g_epsilon = 0;
        double minCostFunctional;

        lbfgs::lbfgs_optimize(x, minCostFunctional, &L_BFGS::costFunctional,nullptr,progress,this,lbfgs_param);
        cout << "optimal x=" <<x.transpose()<<endl;
        cout << "minCostFunctional="<<minCostFunctional<<endl;
        return minCostFunctional;

    }
};

int main(){
    // L_BFGS L_1(2);
    // L_1.optimize();

    // eigen_map();
    eigne_normal();
    // cout << "hello\n";
    // std::cout<<"for test\n";
    return 0;
}