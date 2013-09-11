import struct

def load_settings():
	print "Loading Settings"
	print "Please Enter the name of the setting you wish to load followed by its value"
	print "To Finish simply leave the key field blank"
	loadedDict={}
	while(True):
		inputKey=''
		inputValue=0
		inputKey=raw_input("Please enter the next key: ")
		if(inputKey==''):
			break
		inputValue=int(raw_input("Please enter its value: "))
		loadedDict[inputKey]=inputValue
	print loadedDict
	return loadedDict



def load_stream(dictList):
	output=''
	for line in dictList:
		output+=line+"\0"+struct.pack("H",dictList[line])
	return output

f=open("debug","w")

loadedDict=load_settings()
f.write(load_stream(loadedDict))
#f.close()
#exit()
