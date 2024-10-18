#ifndef GPU_HPP
#define GPU_HPP

#include <string>
#ifdef __linux__
#include <fstream>
#include <sstream>
#elif _WIN32
#include <windows.h>
#include <dxgi.h>
#pragma comment(lib, "dxgi.lib")
#endif

using namespace std;

string get_gpu_model() {
    #ifdef __linux__
        ifstream gpuinfo("/sys/class/graphics/fb0/name");
        string model;
        getline(gpuinfo, model);
        return model;
    #elif _WIN32
        IDXGIFactory* pFactory;
        IDXGIAdapter* pAdapter;
        vector <IDXGIAdapter*> vAdapters;
        DXGI_ADAPTER_DESC adapterDesc;

        CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&pFactory);

        for (UINT i = 0; pFactory->EnumAdapters(i, &pAdapter) != DXGI_ERROR_NOT_FOUND; ++i) {
            vAdapters.push_back(pAdapter);
        }

        if (vAdapters.empty()) {
            return "Desconhecido";
        }

        pAdapter = vAdapters[0];
        pAdapter->GetDesc(&adapterDesc);

        wstring ws(adapterDesc.Description);
        string model(ws.begin(), ws.end());

        pFactory->Release();
        pAdapter->Release();

        return model;
    #endif
    return "Desconhecido";
}

int get_gpu_memory() {
    #ifdef __linux__
        ifstream meminfo("/sys/class/graphics/fb0/vram_size");
        int memory;
        meminfo >> memory;
        return memory / (1024 * 1024); // Converter para GB
    #elif _WIN32
        IDXGIFactory* pFactory;
        IDXGIAdapter* pAdapter;
        vector <IDXGIAdapter*> vAdapters;
        DXGI_ADAPTER_DESC adapterDesc;

        CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&pFactory);

        for (UINT i = 0; pFactory->EnumAdapters(i, &pAdapter) != DXGI_ERROR_NOT_FOUND; ++i) {
            vAdapters.push_back(pAdapter);
        }

        if (vAdapters.empty()) {
            return 0;
        }

        pAdapter = vAdapters[0];
        pAdapter->GetDesc(&adapterDesc);

        pFactory->Release();
        pAdapter->Release();

        return static_cast<int>(adapterDesc.DedicatedVideoMemory / (1024 * 1024 * 1024)); // Converter para GB
    #endif
    return 0;
}

#endif
