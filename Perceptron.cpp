//
// Created by leommjr on 07/12/2019.
//

#include "Perceptron.h"
#include <iostream>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-comparison"
using namespace std;

/* Era usada para comparar o sinal
 * bool positivo(int num) {
    return 0 < num;
}*/
Perceptron::Perceptron(int qtd, float rate) {
    /*
     * @param qtd Quantidade de features a serem atribuidos com pesos
     *
     * Inicializa o vetor de pesos com zeros e da um valor para a taxa de aprendizado (de 0 a 1, por padrao 0.1)
     */
    int i = 0;
    do{
        Perceptron::w.push_back(0.0);
        i++;
    }while(i<qtd);
    Perceptron::rate = rate;
    Perceptron::threshold = 0.0;
}
Perceptron::~Perceptron()
= default;

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
                if(y != yl) {
                    for (int i = 0; i < it.labels.size(); i++) {
                        Perceptron::w[i] = w[i] + (Perceptron::rate *(y - yl)* it.labels[i]);//delta rule

                    }
                }
        }
        gen++;
    }while(gen < gens);
}
int Perceptron::test(vector<int>labels)
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