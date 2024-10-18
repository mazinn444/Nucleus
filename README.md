<h1 align="center">Nucleus</h1>

<p align="center">
  <img src="https://img.shields.io/badge/C++-11-blue.svg" alt="C++ Version">
  <img src="https://img.shields.io/badge/Linux-compatible-green.svg" alt="Linux Compatible">
  <img src="https://img.shields.io/badge/Windows-compatible-green.svg" alt="Windows Compatible">
  <img src="https://img.shields.io/badge/Versão-1.0.0-blue.svg" alt="Versão">
  <img src="https://img.shields.io/badge/MIT-License-green.svg" alt="MIT License">
</p>

<p style="text-align: justify;">
  Nucleus é um avançado utilitário desenvolvido em C++ projetado para fornecer uma visão abrangente e detalhada do sistema operacional em execução. Com uma interface intuitiva e eficiente, o Nucleus oferece aos usuários uma análise completa dos componentes essenciais do sistema, incluindo informações sobre hardware e software, permitindo uma compreensão profunda da configuração e desempenho do computador.
</p>

## Funcionalidades

O programa coleta e exibe as seguintes informações:

- Sistema Operacional
  - Nome
  - Distribuição (***apenas para Linux***)
  - Versão do Kernel
  - Versão do SO
  - Arquitetura
  - Tempo de Atividade

- Memória
  - Memória Usada
  - Memória Livre
  - Memória Total

- CPU
  - Modelo
  - Número de Núcleos
  - Número de Threads

- GPU
  - Modelo
  - Memória

## Requisitos do Sistema

- Sistema Operacional: Windows ou Linux
- Compilador C++ com suporte a C++11 ou superior

## Como Usar

1. Clone o repositório:
   ```bash
   git clone https://github.com/mazinn444/Nucleus.git
   ```

2. Navegue até o diretório do projeto:
   ```bash
   cd nucleus
   ```

3. Compile o projeto:
   ```bash
   g++ -o nucleus main.cpp -std=c++11
   ```

4. Execute o programa:
   ```bash
   ./nucleus
   ```

# Observações

- O programa foi testado apenas no Linux.
- É totalmente permitido utilizar o código como base para um projeto pessoal.
- Pode republicar em outros locais sem necessidade de permissão e créditos.
