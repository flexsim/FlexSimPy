print("Starting")
import FlexSimPy as fp
import os
scriptPath = os.path.dirname(os.path.realpath(__file__))
pDir = scriptPath + "\\..\\..\\..\\program\\";
print("imported")
controller = fp.launch(evaluationLicense=True, showGUI=False, programDir=pDir)
print("launched")
controller.open(scriptPath + "\\PostOfficeModel.fsm")
print("opened")
controller.reset();
print("reset")
controller.run();
exit();

