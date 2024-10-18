#ifndef CPU_HPP
#define CPU_HPP

#include <string>
#include <thread>
#ifdef __linux__
#include <fstream>
#elif _WIN32
#include <windows.h>
#include <intrin.h>
#endif

using namespace std;

string get_cpu_model() {
    #ifdef __linux__
        ifstream cpuinfo("/proc/cpuinfo");
        string line;
        while (getline(cpuinfo, line)) {
            if (line.find("model name") != string::npos) {
                return line.substr(line.find(":") + 2);
            }
        }
    #elif _WIN32
        char brand[0x40];
        unsigned int cpuInfo[4] = {0,0,0,0};
        __cpuid(cpuInfo, 0x80000002);
        memcpy(brand, cpuInfo, sizeof(cpuInfo));
        __cpuid(cpuInfo, 0x80000003);
        memcpy(brand + 16, cpuInfo, sizeof(cpuInfo));
        __cpuid(cpuInfo, 0x80000004);
        memcpy(brand + 32, cpuInfo, sizeof(cpuInfo));
        return brand;
    #endif
    return "Desconhecido";
}

int get_cpu_cores() {
    return thread::hardware_concurrency() / 2;
}

int get_cpu_threads() {
    return thread::hardware_concurrency();
}

#endif
