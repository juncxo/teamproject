#include <vector>
#include "mockos/TextFile.h"
#include <iostream>
using namespace std;

/*
 * Constructor for the TextFile
 */
TextFile :: TextFile (string initializeName) {
    name = initializeName;
}

/*
 * Gets the length of the content inside a text file
 */
unsigned int TextFile::getSize () {
    return contents.size();
}

/*
 * Gets the name of the text file
 */
string TextFile::getName () {
    return name;
}

/*
 * Writes the content passed in to the file
 */
int TextFile::write(vector <char> vc) {
    contents = vc;
    return textSucess;
}

/*
 * Adds content to the existing content in the file
 */
int TextFile::append(vector <char> vc) {
    for (int i = 0; i < vc.size(); i++) {
        contents.push_back (vc[i]);
    }
    return textSucess;
}

/*
 * Returns the content that's in the text file
 */
vector<char> TextFile::read () {
    return contents;
}


/*
 * Clones the file passed in the parameter, add the extension of the file, sets the file's content to match source file's
 */
AbstractFile* TextFile::clone (string fileName) {
    TextFile* newFile =  new TextFile(*this);
    newFile->name = fileName + ".txt";
    newFile->contents = contents;
    return newFile;
}

/*
 * Visits the displayvisitor function
 */
void TextFile::accept(AbstractFileVisitor* afv){
    afv->visit_TextFile(this);
}




