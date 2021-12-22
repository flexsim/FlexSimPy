--PyConnector DLL Project--

The PyConnector project creates a dll that will bind dll-toggled nodes to python 
functions. 

The PyConnector specifically targets embedded python, but FlexSim has also been 
configured to bind to really any language, and this project can be seen as 
one example that implements such a language binding. The primary callbacks that 
need to be implemented on the DLL are:

extern "C" void * findProc(const char* moduleName, const char* procName)
	Takes a module name and a function name, and returns a void*, representing 
	some type of reference to a function

extern "C" CodeSDT* bindToNode(TreeNode* node, void* proc)
	Takes a TreeNode and a procedure pointer (the same as was returned from 
	findProc) and "binds" the procedure to the node. The
	way to do this is to define your own CodeSDT subclass that holds 
	the procedure pointer, and save an instance of that subclass on the 
	node's branch node.

The CodeSDT subclass you create will then have its evaluate() method called 
whenever the node's evaluate is called, so you would handle parameter translation, 
code forwarding, etc. through that method.