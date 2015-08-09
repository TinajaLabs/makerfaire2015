These are files that support the home automation setup we presented at the SF Bay Maker Faire 2015.

The folders contain the following:

* **Esp8266Arduino** - code that is loaded into a breadboarded esp8266-1 wifi module.  One acting as a switch sensor, one acting as a web service/actuator.
* **SensorPCB** - PCB design files, eagle cad, schematic, layout. Sensors hooked up to XBee radio
* **SensorGateway** (on a RaspBerry Pi) - Python script and supporting modules to integrate into Raspberry Pi.  Reads serial input from XBee coordination radio and sends out a TCP socket to Node-Red.
* **NodeRedGateway** (on a Beaglebone Black) - Files used to set up Node-Red as a communications hub for various signals running through the home automation system.
* **ChartingGateway** (on an Odroid C1) - Files supporting data charting with Graphite/Grafana


For more explanation of the setup see the blog post at: http://tinajalabs.com/