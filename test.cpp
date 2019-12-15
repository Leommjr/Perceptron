//
// Created by leommjr on 15/12/2019.
//
#include "Perceptron.h"
#include <iostream>
int main(int argc,char *argv[])
{
    Perceptron p = Perceptron(3, 0.2);
    vector<struct train> ts;
    struct train t = train();
    struct train t1 = train();
    struct train t2 = train();
    struct train t4 = train();
    struct train t5 = train();
    vector<int> t3;
    t3.push_back(1);
    t3.push_back(0);
    t3.push_back(1);
    t.labels.push_back(1);
    t.labels.push_back(1);
    t.labels.push_back(0);
    t.output = 1;
    t1.labels.push_back(0);
    t1.labels.push_back(1);
    t1.labels.push_back(0);
    t1.output = -1;
    t2.labels.push_back(0);
    t2.labels.push_back(0);
    t2.labels.push_back(1);
    t2.output = -1;
    t4.labels.push_back(1);
    t4.labels.push_back(1);
    t4.labels.push_back(0);
    t4.output = 1;
    t5.labels.push_back(1);
    t5.labels.push_back(1);
    t5.labels.push_back(1);
    t5.output = 1;
    ts.push_back(t);
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t4);
    ts.push_back(t5);
    p.fit(ts, 100);
    cout << p.test(t3) << endl;
    p.weights();
    return 0;
}
