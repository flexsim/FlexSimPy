print("Starting")
import FlexSimPy as fp
import os
scriptPath = os.path.dirname(os.path.realpath(__file__))
pDir = scriptPath + "\\..\\..\\..\\program\\";
print("imported")
controller = fp.launch(evaluationLicense=True, showGUI=False, programDir=pDir)
print("launched")
#controller.open(scriptPath + "\\PostOfficeModel.fsm")
#print("opened")
#controller.reset();
#print("reset")
#controller.runToTime(3600);
#print("time ", controller.time());
#print("PerformanceMeasure1", controller.getPerformanceMeasure("PerformanceMeasure1"));
#print("Press Enter to continue");
#input();

controller.open(scriptPath + "\\TestSendReceive.fsm");
controller.reset();
controller.run(10);

while controller.time() < 30:
    value = controller.receive();
    print ("Received ", value);
    print("time: ", controller.time())
    print(" sending ", value * 2);
    controller.send(value * 2);

controller.stop();
output = controller.getPerformanceMeasure("Output");
print("Output: ", output)



