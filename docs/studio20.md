# Studio 20
1. Aranna, Andy, Luke
2. It is necessary to delete the pointer to the actual file in the destructor 
so we can avoid a memory leak, since the protectedFile was allocated in the heap.

Note: run better test cases in main and test what we performeced and it's resutls
