# Studio 18


1. Names: Aranna, Andy, Luke
2. 
3. We recognize that the createFile is a factory method and thus is declared in an interface but not defined by 
4. the base class and rather overridden by the derived classes. The advantage of a factory method would be that
5. each method defined in the derived classes can be tailored to meet each class's needs. Since tailoring to each needs
6. is the factory method's main advantage, it would be relatively easy to create a new file system implementation.
7. Modifying code for new concrete file types may affect the file system implementations.
8. We must modify the code for all the concrete file system implementation when new file types are created.

9. Abstract Factory Pattern allows for interchanging concrete classes without changing the client code but its
10. complexity to code and additional code required is the drawback. 
11. You want to create a new concrete file factory class when new file type is introduced but the previous
12. existing file types do not handle the new one.
13. What code must be modified if a new file type is introduced that should be created by existing factories?
14. Abstract factory interface and all the concrete factory classes that implement the interface.
15. Given two file system implementations that manage the same types of files, can the same factory be
16. used to create files for both?: Yes, because they manage the same type of files. 
17. Given two file system implementations that manage different types of files, 
18. can the same concrete factory implementation be used to create files for both?:
19. No, since they do not manage the same type of files.

20. Output:
X X
X
X X
X X X X X3
21. The output was the above. It successfully printed the expected output when given the read and write functions.

22.  At this point, does SimpleFileSystem depend on any concrete file types or does
     it depend on the AbstractFile interface only?
23. It depends on the AbstractFile interface only and would not depend on any concrete file type.
24. Its system file implementation doesn't have the reponsibility of creating files anymore.



