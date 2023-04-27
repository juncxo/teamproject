# Studio 18


1. Names: Aranna, Andy, Luke

2. We recognize that the createFile is a factory method and thus is declared in an interface but not defined by 
the base class and rather overridden by the derived classes. The advantage of a factory method would be that
each method defined in the derived classes can be tailored to meet each class's needs. Since tailoring to each needs
is the factory method's main advantage, it would be relatively easy to create a new file system implementation.
Modifying code for new concrete file types may affect the file system implementations.
We must modify the code for all the concrete file system implementation when new file types are created.

3. Abstract Factory Pattern allows for interchanging concrete classes without changing the client code but its
complexity to code and additional code required is the drawback. 
You want to create a new concrete file factory class when new file type is introduced but the previous
existing file types do not handle the new one.
Q. What code must be modified if a new file type is introduced that should be created by existing factories?
Abstract factory interface and all the concrete factory classes that implement the interface.
Q. Given two file system implementations that manage the same types of files, can the same factory be
used to create files for both?: Yes, because they manage the same type of files. 
Given two file system implementations that manage different types of files, 
Q. Can the same concrete factory implementation be used to create files for both?:
No, since they do not manage the same type of files.

4. Our main test was creating an immgeFile of the same size that we used in the studio 17.
Output:
X X
 X
X X
X X X X X3
The output was the above. It successfully printed the expected output when given the read and write functions. 


5. At this point, does SimpleFileSystem depend on any concrete file types or does
     it depend on the AbstractFile interface only?
It depends on the AbstractFile interface only and would not depend on any concrete file type.
Its system file implementation doesn't have the reponsibility of creating files anymore.



