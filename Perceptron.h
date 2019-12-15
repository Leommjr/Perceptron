//
// Created by leommjr on 07/12/2019.
//

#ifndef PERCEPTRON_PERCEPTRON_H
#define PERCEPTRON_PERCEPTRON_H
#include <vector>
using namespace std;

struct train{
    vector<int> labels;
    int output;
};
class Perceptron{
private:
    float rate{};
    vector<float> w;
public:
    Perceptron(int qtd, float rate);
    float getRate() const;
    void setRate(float rate);
    void fit(vector<struct train> train, int gens);
    int test(vector<int>labels);
    virtual ~Perceptron();
};


#endif //PERCEPTRON_PERCEPTRON_H
