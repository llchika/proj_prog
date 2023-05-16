#include <CSVReader.h>

CSVReader::CSVReader(std::string filename, char delimiter) :
	m_filename(filename), m_delimiter(delimiter) {}

std::vector<std::vector<int>> CSVReader::getData() {
    std::ifstream file(m_filename);
    if (!file.is_open()) {
        std::cerr << "Could not open the file - '"
            << m_filename << "'" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::vector<std::vector<int> > dataList;
    std::vector<int> row;
    std::string line, word;

    // Iterate through each line and split the content using delimeter
    while (getline(file, line)) {
        row.clear();
        std::stringstream ss(line); 
        while (getline(ss, word, m_delimiter)) {
            row.push_back(std::stoi(word));
        }
        dataList.push_back(row);
    }
    // Close the File
    file.close();
    return dataList;
}
