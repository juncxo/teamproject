#include <vector>
#include <string>

class RenameParsingStrategy {
public:
    virtual std::vector <std::string> parse (std::string) = 0;
};