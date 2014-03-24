#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <fstream>
#include <string>

#include <sstream>

class FileReader {
 public:
  FileReader(const char* filename);
  FileReader(const std::string& filename);

  bool nextLine();

  int getFieldAsInt(const int n);
  float getFieldAsFloat(const int n);
  double getFieldAsDouble(const int n);
  std::string getFieldAsString(const int n);

  template <typename ReadOutType>
  ReadOutType getField(const int n);

  bool inputFailed() const;
  bool isValid() const;

 private:
  void skip_fields(std::istringstream& ist, const int n);
  std::ifstream file;
  std::string line;
  bool failed;
};

template <typename ReadOutType>
ReadOutType FileReader::getField(const int n)
{
  failed = false;
  std::istringstream ist(line);
  this->skip_fields(ist, n-1);
  ReadOutType rval;
  ist >> rval;
  if (ist.fail()) {
    failed = true;
    return ReadOutType();
  }
  else
    return rval;
}


#endif
