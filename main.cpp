#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double fatorial(int n) {
    double resultado = 1.0;

    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }

    return resultado;
}

double combinacao(int n, int x) {
    return fatorial(n) / (fatorial(x) * fatorial(n - x)); // calcula C(n, x)
}

// Probabilidade Binomial Individual: P(x) = C(n,x) * p^x * q^(n-x)
double probabilidadeBinomialIndividual(int n, int x, double p) {
    double q = 1.0 - p;
    double probabilidade = (combinacao(n, x) * pow(p, x) * pow(q, n - x)) * 100.0; // Convertendo para porcentagem
    return probabilidade;
}

int validaInput(int n, int x, double p) {
    if (n < 0) {
        cout << "Erro: n deve ser um numero inteiro não negativo." << endl;
        return 0;
    }
    if (x < 0) {
        cout << "Erro: x deve ser um numero inteiro não negativo." << endl;
        return 0;
    }
    if (p < 0.0 || p > 1.0) {
        cout << "Erro: p deve estar entre 0 e 1." << endl;
        return 0;
    }
    return 1; // Input válido
}

// g++ -o main main.cpp
int main() {
    int n, x;
    double p;

    cout << "*********************************************" << endl;
    cout << "*********** Distribuicao Binomial ***********" << endl;

    cout << "\nDigite n (numero total de experimentos): ";
    cin >> n;
    cout << "Digite x (numero de sucessos): ";
    cin >> x;
    cout << "Digite p (probabilidade de sucesso, entre 0 e 1): ";
    cin >> p;

    if (!validaInput(n, x, p)) {
        return 1; // Saída com erro
    }

    double prob = probabilidadeBinomialIndividual(n, x, p);
    cout << fixed << setprecision(4);

    cout << "\nProbabilidade Binomial Individual:" << endl;
    cout << "P (" << x << "): " << prob << " % \n" << endl;

    cout << "*********************************************" << endl;

    return 0;
}
