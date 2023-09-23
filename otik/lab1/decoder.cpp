#include <cstdint>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

int decoder(std::string);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "command should include a file name argument\n";
        return 0;
    }
    std::string path(argv[1]);
    decoder(path);
    return 0;
}

int decoder(std::string path) {
    std::ifstream fileIn(path, std::ios::in | std::ios::binary);
    if (!fileIn.good()) {
        std::cout << "File not found" << std::endl;
        return 0;
    }

    char sig[4];
    fileIn.read(sig, 4);
    if (sig[0] != 0x4b || sig[1] != 0x61 || sig[2] != 0x4D || sig[3] != 0x64) {
        std::cout << "signature mismatch!\n";
        return 0;
    }

    char* headervars = new char[24];
    fileIn.seekg(0, std::ios::beg);
    fileIn.read(headervars, 24);
    uint32_t compression_method = headervars[6] | (headervars[7] << 8) | (headervars[8] << 16) | (headervars[9] << 24);
    uint32_t filtering_method = headervars[10] | (headervars[11] << 8) | (headervars[12] << 16) | (headervars[13] << 24);
    uint32_t filesize = headervars[17] | (headervars[16] << 8) | (headervars[15] << 16) | (headervars[14] << 24);

    uint16_t filenamesize = headervars[18] | (headervars[19] << 8);
    uint16_t compression_data_size = headervars[20] | (headervars[21] << 8);
    uint16_t filtering_data_size = headervars[22] | (headervars[23] << 8);

    char* filename = new char[filenamesize];
    fileIn.seekg(24,std::ios::beg);
    fileIn.read(filename, filenamesize);



   
    std::ofstream fileOut(filename, std::ios::out | std::ios::binary);
    if (!fileOut.good()) {
        std::cout << "Error opening file" << std::endl;
        return 0;
    }


    if (compression_method == 0 && filtering_method == 0) {


        char b[1024];
        for (int i = 0; i < filesize/1024 + 1; i++) {
            fileIn.read(b, 1024);
            fileOut.write(b, 1024);
        }
     
    }

    delete[] headervars;
    delete[] filename;

    fileIn.close();
    fileOut.close();
    return 1;
}
