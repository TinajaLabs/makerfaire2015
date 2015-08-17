## Tinaja Home Automation Flows

These are flows designed for Node-RED.  On the Node-RED Gateway device (Beaglebone Black running Debian Wheezy) we have installed these flows.  You can read about Node-RED flows [here](http://nodered.org/docs/getting-started/second-flow.html "Node-RED Flows").

### Install a Node-RED Flow

To install theses flows you basically cut and paste the json formatted configurations in these files into the Node-RED Import dialog (Ctrl-I or via the dropdown menu).  It is suggested that you import each flow into a new Node-RED Tab.


* **xbeesensors2graphite.json** - this flow receives input on a tcp socket node and is configured to listen on port 2007.  The input is meant for the sensorgate2.py python script which collects data from xbee radio sensors and sends it to this TCP port.  The data out of sensorgate2.py is json formatted so the flow passes the data through a json to object converter.  From there it goes through a Node-RED function module that formats the data for whisper (an RRD data store) and sends it to carbon (a remote host TCP listener built into the Graphite charting application).
* **nodered2sensorgate.json** - this flow sets up a number of injection nodes to stand in as switches; mainly for testing purposes.  This sends a specialized string back to the sensorgate2.py script which has a TCP socket listener and then it redirects the signal back to the XBee radios turnuing a digital pin high/low; which can turn and LED/relay on/off.
* **nodered2netcatx10.json** - this one, as above, has injection nodes to stand in as switches which trigger an execution module.  The execution module is just running a linux command like this: ```echo "pl c1 on"  | nc tinajagate3 1099```.  This command runs the mochad application which provides access to the X10 system.
* **capswitch2x10.json** - this is an early experiment with using the esp8266 wifi modules.  The esp-01 module has been set up as a web server which takes a url like this:
 * to set the GPIO01 pin high: http://192.168.84.153/gpio/1
 * to set the GPIO01 pin low : http://192.168.84.153/gpio/0
 * There are some injection nodes configured with these URLs so we can set up an LED/Relay to turn things on/off.

