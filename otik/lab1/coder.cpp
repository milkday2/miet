#include <cstdint>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

void coder(std::string, uint16_t, uint16_t);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "command should include a file name argument\n";
    return 0;
  }
  std::string path(argv[1]);
  coder(path,0,0);
  return 0;
}

void coder(std::string path, uint16_t compression_method,
           uint16_t filtering_method) {
  std::ifstream fileIn(path, std::ios::in | std::ios::binary);
  if (!fileIn.good()) {
    std::cout << "File not found" << std::endl;
    return;
  }

  uint32_t filesize = 0;
  filesize = fileIn.tellg();
  fileIn.seekg(0, std::ios::end);
  filesize = (uint32_t)fileIn.tellg() - filesize;
  fileIn.seekg(0, std::ios::beg);

  char *buf = new char[filesize];
  fileIn.read(buf, filesize);
  fileIn.close();

  std::string base_filename = path.substr(path.find_last_of("/\\") + 1);
  std::string::size_type const p(base_filename.find_last_of('.'));
  std::string file_without_extension = base_filename.substr(0, p);
  if (p == 0)
    file_without_extension = base_filename;

  std::ofstream fileOut(file_without_extension + ".kamd",
                        std::ios::out | std::ios::binary);
  if (!fileOut.good()) {
    std::cout << "Error opening file" << std::endl;
    return;
  }
  const char* signature = "\x4B\x61\x4D\x64";
  const char* version = "\x01\x00";
  uint16_t compression_data_size = 0;
  uint16_t filtering_data_size = 0;
  uint16_t filename_size = base_filename.length();
  fileOut.write(signature, 4);
  fileOut.write(version, 2);
  fileOut.write(reinterpret_cast<const char *>(&compression_method), 2);
  fileOut.write(reinterpret_cast<const char *>(&filtering_method), 2);
  fileOut.write(reinterpret_cast<const char *>(&filesize), 4);
  fileOut.write(reinterpret_cast<const char *>(&filename_size), 2);
  fileOut.write(reinterpret_cast<const char *>(&compression_data_size), 2);
  fileOut.write(reinterpret_cast<const char *>(&filtering_data_size), 2);
  fileOut.write(base_filename.c_str(), filename_size);

  fileOut.write(buf, filesize);

  delete[] buf;

  fileOut.close();
}

