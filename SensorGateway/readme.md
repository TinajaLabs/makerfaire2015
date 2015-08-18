## Sensorgate.py

On the SensorGateway device, this is the main application for retrieving sensor data from the XBee sensor boards and sends it to a TCP listener on a Node-RED server.  It also acts as a TCP socket listener and sends data back to the XBee devices.


The folders hold the following:

* /home/tinaja - files supporting the main application, sensorgate2.py.  Also includced are some libraries that must be installed as dependencies (e.g., XBEE.py, pyserial, simplejson).  See /home/tinaja/downloads/.
* /home/mochad* - applicattion files for running mochad, an X10 support library
* /etc/tinaja - the config file, tinaja.conf 
* /etc/init.d - the init file, tinaja_sensor

