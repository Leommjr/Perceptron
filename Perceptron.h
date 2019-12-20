//
// Created by leommjr on 07/12/2019.
//

#ifndef PERCEPTRON_PERCEPTRON_H
#define PERCEPTRON_PERCEPTRON_H
#include <vector>
using namespace std;

struct train{
    vector<float> labels;
    int output;
};
class Perceptron{
private:
    float rate;
    vector<float> w;
    float threshold;
    bool winnow; //flag que define se o algoritmo Winnow sera usado
public:
    explicit Perceptron(int qtd, float rate = 0.1, bool winnow = false);
    float getRate() const;
    void setRate(float rate);
    void fit(vector<struct train> train, int gens);
    int test(vector<float>labels);
    void weights();
    virtual ~Perceptron();
};


#endif //PERCEPTRON_PERCEPTRON_H
