#include <vector>
#include <string>
#include "AbstractFile.h"

class TextFile : public AbstractFile {
public:
    TextFile(std::string);
    virtual std::string getName();
    virtual unsigned int getSize();
    virtual void read();
    virtual int write(std::vector<char>);
    virtual int append(std::vector<char>);
protected:
    std::vector<char> contents;
    std::string name;
private:

};