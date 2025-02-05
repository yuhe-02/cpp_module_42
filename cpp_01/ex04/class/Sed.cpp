#include "Sed.hpp"

Sed::Sed(std::string filename, std::string before, std::string after) :
	m_filename(filename),
	m_before(before),
	m_after(after)
{
	this->m_outFilename = m_filename + ".replace";
	if (this->m_before.length() <= 0) {
		throw std::runtime_error("Search string (m_before) is empty");
	}
    if (!this->_openFile(this->m_fileReader, this->m_filename, std::ios::in)) {
        throw std::runtime_error("Failed to open input file: " + m_filename);
    }
    if (!this->_openFile(this->m_fileWriter, this->m_outFilename, std::ios::out)) {
        throw std::runtime_error("Failed to open output file: " + m_outFilename);
    }
}

Sed::~Sed() {
	if (this->m_fileReader.is_open()) {
        this->m_fileReader.close();
    }
    if (this->m_fileWriter.is_open()) {
        this->m_fileWriter.close();
    }
}

// bool			Sed::_openFileRDONLY() {
// 	this->m_fileReader.open(this->m_filename.c_str(), std::ios::in);
// 	if (!this->m_fileReader) {
// 		return (false);
// 	}
// 	return (true);
// }

// bool			Sed::_openFileWRITE() {
// 	this->m_fileWriter.open(this->m_outFilename.c_str(), std::ios::out);
// 	if (!this->m_fileWriter) {
// 		return (false);
// 	}
// 	return (true);
// }

bool			Sed::_openFile(std::fstream &file, std::string fileName, std::ios_base::openmode mode) {
	file.open(fileName.c_str(), mode);
	return (file.is_open());
}

std::string		Sed::_createReplaceWords(const std::string &content, size_t readCount) {
	int     	pos;
	size_t		before_len = this->m_before.length();
    std::string res;

	for (int i = 0; i < (int)readCount; i++)
	{
		pos = content.find(this->m_before, i);
		if (pos != -1 && pos == i)
		{
            res += this->m_after;
			i += (int)before_len - 1;
		}
		else
            res += content[i];
	}
	return (res);
}

void			Sed::executeReplace() {
	std::string content;
    std::string after;
    char        c;

	while(!this->m_fileReader.eof() && this->m_fileReader >> std::noskipws >> c)
		content += c;
    after = this->_createReplaceWords(content, content.size());
    this->m_fileWriter.write(after.c_str(), after.size());
    if (this->m_fileReader.fail() && !this->m_fileReader.eof()) {
        throw std::runtime_error("Error reading input file: " + m_filename);
    }
}

