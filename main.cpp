#include <iostream>
#include <vector>
#include <iomanip>

#include "func/memory.hpp"
#include "func/os.hpp"
#include "func/cpu.hpp"
#include "func/gpu.hpp"
#include "design/visual.hpp"

using namespace std;

void printSystemInfo() {
    cout << "================================\n";
    printBlue("      Informações do Sistema\n");
    cout << "================================\n\n";
    
    printColor("Sistema Operacional\n", Color::GREEN);
    printColor("  Nome: " + get_os_name() + "\n", Color::YELLOW);
    #ifdef __linux__
        printColor("  Distribuição: " + get_distro_name() + "\n", Color::YELLOW);
    #endif
    printColor("  Versão do Kernel: " + get_kernel_version() + "\n", Color::YELLOW);
    printColor("  Versão do SO: " + get_os_version() + "\n", Color::YELLOW);
    printColor("  Arquitetura: " + get_architecture() + "\n", Color::YELLOW);
    printColor("  Tempo de Atividade: " + format_uptime(get_uptime()) + "\n\n", Color::YELLOW);

    printColor("Memória\n", Color::GREEN);
    printColor("  Usada: " + to_string(to_gb(get_used_memory())) + " GB\n", Color::YELLOW);
    printColor("  Livre: " + to_string(to_gb(get_free_memory())) + " GB\n", Color::YELLOW);
    printColor("  Total: " + to_string(to_gb(get_total_memory())) + " GB\n\n", Color::YELLOW);

    printColor("CPU\n", Color::GREEN);
    printColor("  Modelo: " + get_cpu_model() + "\n", Color::YELLOW);
    printColor("  Núcleos: " + to_string(get_cpu_cores()) + "\n", Color::YELLOW);
    printColor("  Threads: " + to_string(get_cpu_threads()) + "\n\n", Color::YELLOW);

    printColor("GPU\n", Color::GREEN);
    printColor("  Modelo: " + get_gpu_model() + "\n", Color::YELLOW);
    printColor("  Memória: " + to_string(get_gpu_memory()) + " GB\n", Color::YELLOW);
}

int main(int argc, char *argv[]) {
    try {
        printSystemInfo();
    } catch (const exception& e) {
        printRed("Erro ao obter informações do sistema: " + string(e.what()) + "\n");
        return 1;
    }
    return 0;
}
