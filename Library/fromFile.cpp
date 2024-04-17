#include "fromFile.h"
void fromFile(const string& path, char* res) {

    ifstream file(path);
    if (file.is_open()) {
        streamsize size = file.tellg();
        file.seekg(0, ios::beg);
        file.read(res, size);
        res[size] = '\0';
        file.close();
    }
    else {
        char temp[1024];
        strcpy_s(temp, path.c_str());
        throw exception(temp);
    }
}