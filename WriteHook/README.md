To hook the API function write() correctly, the hooklib.so must be loaded first. For this you should use the command:
export LD_PRELOAD=path_of_lib

then, you should execute the hook program with ./hook Testing 
