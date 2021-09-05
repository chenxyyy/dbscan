//
// Created by cxy on 2021/9/6.
//

#ifndef DBSCAN_CLUSTERANALYSIS_H
#define DBSCAN_CLUSTERANALYSIS_H

#include <iostream>
#include <cmath>
#include "DataPoint.h"
#include <xtensor/xarray.hpp>
#include <xtensor/xnpy.hpp>
#include <xtensor/xview.hpp>
#include<ctime>

using namespace std;



//聚类分析类型
class ClusterAnalysis {
private:
    vector<DataPoint> dadaSets;        //数据集合
    unsigned int dimNum;            //维度
    double radius;                    //半径
    unsigned int dataNum;            //数据数量
    unsigned int minPTs;            //邻域最小数据个数

    double GetDistance(DataPoint &dp1, DataPoint &dp2);                    //距离函数
    void SetArrivalPoints(DataPoint &dp);                                //设置数据点的领域点列表
    void KeyPointCluster(unsigned long i, unsigned long clusterId);    //对数据点领域内的点执行聚类操作
public:

    ClusterAnalysis() {}                    //默认构造函数
    bool Init(char *fileName, double radius, int minPTs);    //初始化操作
    bool Init_xt(char *fileName, double radius, int minPTs);    //初始化操作
    bool DoDBSCANRecursive();            //DBSCAN递归算法
    bool WriteToFile(char *fileName);    //将聚类结果写入文件
    bool WriteToXtFile(char *fileName);
    void rand_color(int cls_num);
    vector<vector<float>> ColorToCluster;
};

#endif //DBSCAN_CLUSTERANALYSIS_H
