#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <iostream>

using namespace std;

#ifdef _WIN32
    #include <windows.h>

    size_t get_total_memory() {
        MEMORYSTATUSEX memInfo;
        memInfo.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&memInfo);
        return static_cast<size_t>(memInfo.ullTotalPhys);
    }

    size_t get_free_memory() {
        MEMORYSTATUSEX memInfo;
        memInfo.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&memInfo);
        return static_cast<size_t>(memInfo.ullAvailPhys);
    }

    size_t get_used_memory() {
        return get_total_memory() - get_free_memory();
    }

    double to_gb(size_t bytes) {
        return bytes / (1024.0 * 1024.0 * 1024.0);
    }

    double to_mb(size_t bytes) {
        return bytes / (1024.0 * 1024.0);
    }

#else
    #include <sys/sysinfo.h>

    size_t get_total_memory() {
        struct sysinfo memInfo;
        sysinfo(&memInfo);
        return static_cast<size_t>(memInfo.totalram) * memInfo.mem_unit;
    }

    size_t get_free_memory() {
        struct sysinfo memInfo;
        sysinfo(&memInfo);
        return static_cast<size_t>(memInfo.freeram) * memInfo.mem_unit;
    }

    size_t get_used_memory() {
        return get_total_memory() - get_free_memory();
    }

    double to_gb(size_t bytes) {
        return bytes / (1024.0 * 1024.0 * 1024.0);
    }

    double to_mb(size_t bytes) {
        return bytes / (1024.0 * 1024.0);
    }
    
#endif

#endif