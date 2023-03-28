
#pragma once
#include <vector>

class AbstractFile {
public:
    virtual void read();
    virtual int write(std::vector<char>);
    virtual int append(std::vector<char>);
    virtual unsigned int getSize();
    virtual std::string getName();
private:
};