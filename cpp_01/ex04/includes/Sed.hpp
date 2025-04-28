#ifndef __SED_HPP__
#define __SED_HPP__

#include <fstream>
#include <ios>
#include <iostream>

// replaceWords(std::string src, std::string *before, std::string *after);
// replaceWords(std::string src, std::string &before, std::string &after);
#define BUFFER_SIZE 42

class Sed
{
  private:
    std::string m_filename;
    std::string m_outFilename;
    std::string m_before;
    std::string m_after;
    std::fstream m_fileReader;
    std::fstream m_fileWriter;
    bool _openFile(std::fstream &file, std::string fileName, std::ios_base::openmode mode);
    std::string _createReplaceWords(const std::string &content, size_t readCount);

  public:
    Sed(std::string m_filename, std::string m_before, std::string m_after);
    ~Sed();
    void executeReplace();
};
#endif