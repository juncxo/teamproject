#include <vector>
#include <string>
#include "mockos/AbstractParsingStrategy.h"

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
    virtual std::vector <std::string> parse (std::string) override;
};