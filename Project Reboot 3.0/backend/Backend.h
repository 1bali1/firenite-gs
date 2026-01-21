#pragma once
#include <string>
using namespace std;

namespace Backend {
    const string apiUrl = "https://pyro.1bali1.hu/";
    void SendKill(string player, string killer);
}