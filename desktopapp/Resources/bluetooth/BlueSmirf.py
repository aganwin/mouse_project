import bluetooth
import sys
bd_addr = "7C:61:93:D1:BE:4C" #Bluetooth Module address

port = 1
sock=bluetooth.BluetoothSocket( bluetooth.RFCOMM )
sock.connect((bd_addr, port))
print 'Connected'

while( 1 ):
	input = raw_input('>')
	if input == "exit":
		break
	if input == "R":
		sock.send("R")
	
	if (sock.send(input) == 0):
		print "Disconnected, please rerun the code."
		break
	print "Sent: ", input
	