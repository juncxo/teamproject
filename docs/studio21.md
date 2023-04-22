# Studio 21
1.2
2. We need to declare a virtual destructor in the base class because we want to make sure that class slicing doesn't 
occur and that destruction sytarts from the derived class and then goes up to the base class.
3. It supports loosing coupling, which helps lose dependencty on the file system, file factory, and command objects.
