#include<iostream>
#include<string>
#include<Eigen/Eigen>
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
    
    cout <<"x.cols()="<<x.cols()<<endl;
    cout <<"x.rows()="<<x.rows()<<endl;
    cout <<"x.col(0)="<<endl;
    cout <<x.col(0)<<endl;
    cout <<"x.row(0)="<<endl;
    cout <<x.row(0) <<endl;
}
int main(){
    // eigen_map();
    eigne_normal();
    // std::cout<<"for test\n";
    return 0;
}