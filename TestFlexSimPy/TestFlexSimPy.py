
print("Starting")
import FlexSimPy as fp
print("imported")
controller = fp.launch(checkLicense=False, showGUI=True)
print("launched")
controller.open('C:\\Anthony\\Documents\\Repositories\\Dev\\PostOfficeModel.fsm')
print("opened")
controller.reset();
print("reset")
controller.run();
