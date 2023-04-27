# Studio 16

2a)
Make all functions of the base classes virtual so that it can be overridden by future derived classes and declare the
constructors.

3a) Interface inheritance because we are only inheriting the declaration and not implementing the classes in any way.


3b) The member variables will be protected because further derived classes may utilize the variables.


4) To test if TextFile behaves as expected, we created TextFile pointer and a vector. Then we called each of the functions 
we wrote to see if the outputs are as expected. It successfully behaved as expected.


5) To test this, we did the following code:
   vector <char> vc = {'a', 'b', 'c', 'd', 'e'};
   vector<char> ap = {'f'};
   AbstractFile* af = new TextFile("testing");
   af->write(ap);
   af->read();    //prints f
   cout << af->getName()<<endl;   //prints "testing"
   cout << af->getSize()<<endl;   //prints 1
   af->append(vc);    
   af->read();    //prints "fabcde"
The functions behaves as expected.