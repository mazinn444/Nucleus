#ifndef VISUAL_HPP
#define VISUAL_HPP

#include <iostream>
#include <string>

using namespace std;

// Códigos de escape ANSI para cores
namespace Color {
    const string RED = "\033[0;31m";
    const string GREEN = "\033[0;32m";
    const string BLUE = "\033[0;34m";
    const string YELLOW = "\033[0;33m";
    const string RESET = "\033[0m";
}

// Função para imprimir texto colorido
void printColor(const string& text, const string& color) {
    cout << color << text << Color::RESET;
}

// Funções específicas para cada cor
void printRed(const string& text) {
    printColor(text, Color::RED);
}

void printGreen(const string& text) {
    printColor(text, Color::GREEN);
}

void printBlue(const string& text) {
    printColor(text, Color::BLUE);
}

void printYellow(const string& text) {
    printColor(text, Color::YELLOW);
}

#endif
