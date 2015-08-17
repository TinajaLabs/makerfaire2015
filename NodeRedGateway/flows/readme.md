## Tinaja Home Automation Flows

These are flows designed for Node-RED.  On the Node-RED Gateway device (Beaglebone Black running Debian Wheezy) we have installed these flows.  You can read about flows [here](http://nodered.org/docs/getting-started/second-flow.html "Node-RED Flows")


### Install a Node-RED Flow

To install theses flows you basically cut and paste the json formatted configurations in these files into the Node-RED Import dialog (Ctrl-I or via the dropdown menu).  It is suggested that you import each flow into a new Node-RED Tab.

* xbeesensors2graphite.json - this flow receives input on a tcp socket node and is configured to listen on port 2007.  The input is meant for the sensorgate2.py python script which collects data from xbee radio sensors and sends it to this TCP port.  The data out of sensorgate2.py is json formatted so the flow passes the data through a json to object converter.  From there it goes through a Node-RED function module that formats the data for whisper (an RRD data store) and sends it to carbon (a remote host TCP listener built into the Graphite charting application).

* XBee2X10.json - 
* capswitch2x10.json
* X102Mochad.json

