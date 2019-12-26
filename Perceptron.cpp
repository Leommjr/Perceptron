//
// Created by leommjr on 07/12/2019.
//

#include "Perceptron.h"
#include <iostream>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-comparison"
using namespace std;


template <class T> static inline bool positivo(T num) {
    return 0 < num;
}
Perceptron::Perceptron(int qtd, float rate, bool winnow) {
    /*
     * @param qtd Quantidade de features a serem atribuidos com pesos
     *
     * Inicializa o vetor de pesos com zeros e da um valor para a taxa de aprendizado (de 0 a 1, por padrao 0.1)
     */
    Perceptron::threshold = 0.0;
    Perceptron::winnow = winnow;
    int val = 0.0;
    if(winnow){
        val = 1.0;
        Perceptron::threshold = (float)qtd;
    }
    int i = 0;
    do{
        Perceptron::w.push_back(val);
        i++;
    }while(i<qtd);
    Perceptron::rate = rate;
}
Perceptron::~Perceptron()
{
    Perceptron::w.clear();
    Perceptron::w.shrink_to_fit();
}

float Perceptron::getRate() const
{
    return rate;
}

void Perceptron::setRate(float rate)
{
    Perceptron::rate = rate;
}
void Perceptron::fit(vector<struct train> train, int gens)
{
    /*
     * @param train vetor constituido por objetos de treino (x,y), onde x eh um vetor de caracteristicas e y o output
     * @param gens condicao de parada (geracoes)
     */
    int gen = 0;
    do {
        for (auto & it : train) {
            float yl = 0.0;
            auto y = it.output;
            for (int i = 0; i < it.labels.size(); i++) {
                yl += Perceptron::w[i] * it.labels[i];
            }
            if(Perceptron::winnow){
                if(yl <= Perceptron::threshold && y == 1){
                    for (int i = 0; i < it.labels.size(); i++){
                        if(it.labels[i] == 1)
                            Perceptron::w[i] = 2*Perceptron::w[i];
                    }
                }else if(yl >= Perceptron::threshold && y == -1){
                    for (int i = 0; i < it.labels.size(); i++){
                        if(it.labels[i] == 1)
                            Perceptron::w[i] = Perceptron::w[i]/2;
                    }
                }
            }
            else if(positivo(y) != positivo((int)yl) || (int)yl == 0) {
                    for (int i = 0; i < it.labels.size(); i++) {
                        Perceptron::w[i] = w[i] + (Perceptron::rate *(y - yl)* it.labels[i]);//delta rule

                    }
                }
        }
        gen++;
    }while(gen < gens);
}
int Perceptron::test(vector<float>labels)
{
    float y=0.0;
    for(int i = 0; i < labels.size(); i++){
        y += Perceptron::w[i]*labels[i];
    }
    return y > Perceptron::threshold ? 1 : -1;
}
void Perceptron::weights()
{
    int i = 1;
    for(auto & it : Perceptron::w)
    {
        cout << "w"<< i++ << ": " << it << endl;
    }
}
#pragma clang diagnostic pop