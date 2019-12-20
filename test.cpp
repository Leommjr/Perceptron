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
    vector<float> t3;
    t3.push_back(10.0);
    t3.push_back(5.0);
    t3.push_back(2.0);
    t.labels.push_back(7.0);
    t.labels.push_back(0.0);
    t.labels.push_back(10.0);
    t.output = 1;
    t1.labels.push_back(-5.0);
    t1.labels.push_back(4.0);
    t1.labels.push_back(2.5);
    t1.output = -1;
    t2.labels.push_back(1.0);
    t2.labels.push_back(3.5);
    t2.labels.push_back(1.0);
    t2.output = -1;
    t4.labels.push_back(6.6);
    t4.labels.push_back(-2.0);
    t4.labels.push_back(8.0);
    t4.output = 1;
    t5.labels.push_back(10.0);
    t5.labels.push_back(3.0);
    t5.labels.push_back(6.9);
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
