#ifndef OS_HPP
#define OS_HPP

#include <string>
#include <fstream>
#include <sstream>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

string get_os_name() {
    #ifdef _WIN32
        return "Windows";
    #elif __linux__
        return "Linux";
    #elif __APPLE__
        return "macOS";
    #else
        return "Unknown";
    #endif
}

string get_distro_name() {
    #ifdef __linux__
        ifstream os_release("/etc/os-release");
        string line;
        while (getline(os_release, line)) {
            if (line.find("ID=") == 0) {
                return line.substr(line.find("=") + 1);
            }
        }
        os_release.close();
    #elif _WIN32
        return "Windows";
    #endif
    return "Unknown";
}

string get_kernel_version() {
    #ifdef __linux__
        ifstream kernel_version("/proc/version");
        string line;
        getline(kernel_version, line);
        kernel_version.close();
        return line.substr(line.find(" ") + 1);
    #elif _WIN32
        OSVERSIONINFOEX osvi;
        ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
        osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
        GetVersionEx((OSVERSIONINFO*)&osvi);
        return to_string(osvi.dwMajorVersion) + "." + to_string(osvi.dwMinorVersion) + "." + to_string(osvi.dwBuildNumber);
    #endif
    return "Unknown";
}

string get_os_version() {
    #ifdef __linux__
        ifstream os_version("/etc/os-release");
        string line;
        while (getline(os_version, line)) {
            if (line.find("VERSION_ID=") == 0) {
                return line.substr(line.find("=") + 1);
            }
        }
        os_version.close();
    #elif _WIN32
        OSVERSIONINFOEX osvi;
        ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
        osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
        GetVersionEx((OSVERSIONINFO*)&osvi);
        return to_string(osvi.dwMajorVersion) + "." + to_string(osvi.dwMinorVersion);
    #endif
    return "Unknown";
}

string get_architecture() {
    #ifdef _WIN32
        SYSTEM_INFO sysInfo;
        GetNativeSystemInfo(&sysInfo);
        return sysInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64 ? "x64" : "x86";
    #elif __linux__
        return "x64";
    #endif
    return "Unknown";
}

string format_uptime(double uptime_seconds) {
    int days = uptime_seconds / (60 * 60 * 24);
    int hours = (int(uptime_seconds) / 3600) % 24;
    int minutes = (int(uptime_seconds) / 60) % 60;
    int seconds = int(uptime_seconds) % 60;

    stringstream ss;
    if (days > 0) ss << days << "d ";
    if (hours > 0) ss << hours << "h ";
    if (minutes > 0) ss << minutes << "m ";
    ss << seconds << "s";

    return ss.str();
}

double get_uptime() {
    #ifdef _WIN32
        return GetTickCount64() / 1000.0;
    #elif __linux__
        ifstream uptime_file("/proc/uptime");
        string line;
        getline(uptime_file, line);
        uptime_file.close();
        return stod(line.substr(0, line.find(" ")));
    #endif
    return 0;
}

#endif
