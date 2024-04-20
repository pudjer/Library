#include "fromFile.h"
void fromFile(const string& path, char* res, size_t size) {
    ifstream file(path, ios::binary); // Открываем файл в двоичном режиме для правильного чтения бинарных данных
    if (file.is_open()) {
        file.seekg(0, ios::end); // Перемещаем курсор в конец файла
        streamsize fileSize = file.tellg(); // Получаем размер файла
        if (fileSize > size) {
            throw runtime_error("Buffer is too small to hold file content");
        }
        file.seekg(0, ios::beg); // Возвращаем курсор в начало файла
        file.read(res, fileSize); // Читаем содержимое файла в массив res
        res[fileSize] = '\0'; // Добавляем нуль-терминатор в конец массива
        file.close();
    }
    else {
        throw runtime_error("Failed to open file");
    }
}