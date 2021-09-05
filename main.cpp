#include "ClusterAnalysis.h"

using namespace std;

int main() {
    ClusterAnalysis myClusterAnalysis;                        //聚类算法对象声明
    myClusterAnalysis.Init_xt("/home/cxy/CLionProjects/dbscan/point_data/1_cpp_res.npy", 1, 5);        //算法初始化操作，指定半径为15，领域内最小数据点个数为3，
    myClusterAnalysis.DoDBSCANRecursive();                    //执行聚类算法
    myClusterAnalysis.WriteToXtFile("/home/cxy/CLionProjects/dbscan/point_data/1_cpp_dbscan.npy");//写执行后的结果写入文件

    std::cout << "聚类成功！\n";
    return 0;            //返回
}