#include "fromFile.h"
void fromFile(const string& path, char* res, size_t size) {
    ifstream file(path, ios::binary); // ��������� ���� � �������� ������ ��� ����������� ������ �������� ������
    if (file.is_open()) {
        file.seekg(0, ios::end); // ���������� ������ � ����� �����
        streamsize fileSize = file.tellg(); // �������� ������ �����
        if (fileSize > size) {
            throw runtime_error("Buffer is too small to hold file content");
        }
        file.seekg(0, ios::beg); // ���������� ������ � ������ �����
        file.read(res, fileSize); // ������ ���������� ����� � ������ res
        res[fileSize] = '\0'; // ��������� ����-���������� � ����� �������
        file.close();
    }
    else {
        throw runtime_error("Failed to open file");
    }
}