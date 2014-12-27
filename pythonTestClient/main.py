'''
    Created on Dec 27, 2014
    
    @author: alexey
    '''
import serial
from nexusMsg_pb2 import NexusMsg
from nexusMsg_pb2 import Twist
from nexusMsg_pb2 import Header

port =serial.Serial(
    "/dev/ttyUSB0",
    baudrate=115200,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    writeTimeout = 0,
    timeout = 10,
    rtscts=False,
    dsrdtr=False,
    xonxoff=False)



print(port.isOpen()) 
print("Port opened...") 

vel = Twist();
vel.velX = 10;
vel.velY = 20;
vel.rotZ = 5;

msg = NexusMsg();
#msg.header = Header();
msg.cmdVel.velX = 17;
msg.cmdVel.velY = 10;
msg.cmdVel.rotZ = 12;


print str(msg);
port.write(msg.SerializeToString()+'\n') 
print("Data sent")

#while True:
#    print("inside while")
#    response=port.read(8)
#    print(response)
#    print ("Data Received")
#    break