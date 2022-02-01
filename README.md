# FlexSimPy

The FlexSimPy repository includes two primary visual studio projects:
  1. The PyConnector project implements the ability to bind the evaluation
    of nodes in FlexSim's tree to the evaluation of python functions. The 
    project is implemented to work with python versions 3.7, 3.8, 3.9 and 3.10. 
    The output DLLs from this project are included in the installed version 
    of FlexSim.
    
  2. The FlexSimPy project implements a mechanism for controlling the 
    FlexSim application from python. It compiles to a valid python 
    module called 'FlexSimPy', meaning that, if you have properly 
    installed/placed the FlexSimPy .pyd dll, you can use the python command 
    'import FlexSimPy' and then use the resulting module to launch 
    and control FlexSim.
    
## Build Instructions

FlexSimPy is implemented similar to how a standard FlexSim module is set up 
using the [module SDK](https://docs.flexsim.com/en/22.0/Reference/DeveloperAdvancedUser/ModuleSDK/KeyConcepts/):

  1. Set up a FlexSim development environment as 
    [described in the module SDK documentation](https://docs.flexsim.com/en/22.0/Reference/DeveloperAdvancedUser/ModuleSDK/QuickStart/#preparing).
  2. Clone this repository to live in the 'FlexSim\modules\' directory.
  3. Open the FlexSimPy.sln solution in visual studio.
  4. Choose the configuration that corresponds to the python version you 
    will be using (Deb_3_10 is a debug configuration built against python 3.10, 
    Rel_3_9 is release build against python 3.9, etc.).
  5. Build the solution.

- If you are building it to create your own customized PyConnector, then the target dll 
  will automatically be copied to FlexSim\program\python\PyConnector<version>.dll. When 
  you subsequently open your model that connects to python, it should load your 
  custom-built dll.

- If you are building it to create a customized FlexSimPy python module, then you 
  can right-click on the python project TestFlexSimPy, and start the debugger. This 
  will run the TestFlexSimPy.py python script, which launches FlexSim and runs a test 'post office' 
  model.

Note: While FlexSimPy is built using the same process you would use to 
build a FlexSim 
module, it in itself is not technically a FlexSim module. It does not create a module 
dll that is automatically loaded into FlexSim when FlexSim starts up, nor 
does it have a .t tree file that is automatically loaded into FlexSim's tree. 
The PyConnector dlls are special dlls that are placed at FlexSim\program\python, 
and are loaded dynamically depending on the version of python you want FlexSim 
to connect to, when the evaluation of a node in your model requires python to 
be loaded. We place it in the modules directory merely to make the building 
process (updating of headers, etc.) similar to building modules, making the 
build process easier on our side.
