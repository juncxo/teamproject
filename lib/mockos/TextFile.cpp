#include <vector>
#include "mockos/TextFile.h"
#include <iostream>
using namespace std;


TextFile :: TextFile (string initializeName) {
    name = initializeName;
}

unsigned int TextFile::getSize () {
    return contents.size();
}

string TextFile::getName () {
    return name;
}

int TextFile::write(vector <char> vc) {
    contents = vc;
    /*if () {
        //failures
    }*/
    return 0;
}

int TextFile::append(vector <char> vc) {
    for (int i = 0; i < vc.size(); i++) {
        contents.push_back (vc[i]);
    }
    return 0;
}

vector<char> TextFile::read () {
    return contents;
}

void TextFile::accept(AbstractFileVisitor* afv){
    afv->visit_TextFile(this);
}




