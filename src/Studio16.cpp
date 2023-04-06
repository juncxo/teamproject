#include <vector>
#include <string>
#include "mockos/TextFile.h"
#include <iostream>

using namespace std;

int main (int argc, char * argv[]) {
    TextFile tf(" ");
    vector <char> vc = {'a', 'b', 'c', 'd', 'e'};
    tf.write(vc);
    tf.read();

}