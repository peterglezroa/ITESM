Physical Layer
====
### Network Interface Cards (NICs)
* Ethernet NICs are used for a wired connection.
* WLAN NIC's are used for wireless
  * All wireless devices must share access to the airwaves connecting to the wireless access point.

### The Physical Layer
* The process that data undergoes from a source node to a destination node is:
  1. The user data is segmented by the transport layer, placed into packets by the network layer, and further encapsulated into frames by the data link layer.
  2. The physical layer encodes the frames and creates the electrical, optical, or radio wave signals that represent the bits in each frame.
  3. These signals are then sent on the media, one at a time.
  4. The destination node physical layer retrieves these individual signals from the media, restores them to their bit representation, and passes the bits up to the data link layer as a complete frame.
![The physical layer][physicalLayer]

* The physical layer produces the representation and grouping of bits for each type of media as:
  * Copper cable (electrical pulses)
  * Fiber-optic cable: (patterns of light)
  * Wireless (microwave transmissions)

### Physical layer standards
* The protocols and operations of the upper OSI layers are performed in software designed by software engineers and computer scientists.
* The physical layer hardware, media, encoding and singaling standards are defined and governed by the:
  * ISO - International Organization for Standarization
  * TIA - Telecommunications Industry Association
  * ITU - International Telecommunication Union
  * ANSI - American National Standards Institute

### Functions
#### Physical Components
* The physical components are the electronic hardware devices, media, and other connectors that transmit and carry the signals to represent the bits
* Hardware components such as NIC's, interfaces and connectors, cable, materials, and cable designs are all specified in standards associated with the phyhsical layer.

#### Encoding
* Encoding is a method of converting a stream of data bits into a predefined "code".
* Codes are grouping of bits used to provide a predictable pattern that can be recognized by both the sender and the receiver.

#### Signaling
* The physical layer must generate the electrical, optical, or wireless signals that represent the "1" and "0" on the media.
* The method of representing the bits is called the signaling method.


### Bandwidth
* Bandwidth is the capacity of a medium to carry data.
* Digital bandwidth measures the amount of data that can flow from one place to another.
* Bandwidth is measured in kilobits per second (kb/s), megabits per second (Mb/s), or gigabits per second (Gb/s).
* A combination of factors determines the practical brandwidth of a network:
  * The properties of the physical media
  * The technologies chosen for signaling and detecting network signals 


### Throughput
* Throughput is the measure of the transfer of bits across the media over a given period of time.
* Many factors influence throughput, including:
  * The amount of traffic
  * The type of traffic
  * The latency created by the number of network devices encountered between soruce and destination.
* **Latency** refers to the amount of time, to include delays, for data to travel from one point to another.

### Types of Physical Media
* The physical layer produces the representation and groupings of bits as voltages, radio frequencies, or light pulses.
#### Copper Cabling
* Data is transmitted on copper cables as electrical pulses.
* The longer the signal travels, the more it deteriorates.
* The timing and voltage values of the electrical pulses also susceptible to interference from two sources:
  * Electromagnetic interference (EMI) or radio frequency interference (RFI)
    * They can distort and corrupt the data signals being by copper media.
  * Crosstalk
    * disturbance caused by the electric or magnetic fields of a signal on one wire to the signal in an adjacent wire.
![EMI RFI crosstalk][disturbance]

* There are 3 main types of copper media used in networking:
![Copper media][copper]
  * UTP
    * used for interconnecting network hosts with intermediate networking devices, such as switches and routers
    * uses RJ-45
    * 100 meters
  * STP
    * uses RJ-45
    * better noise protection than UTP but they are more expensive
    * 100 meters
  * Coaxial
    * used in wireless installations (antennas) and cable internet installations.
    * 500 meters
* All three types of copper media are susceptible to fire and electrical hazards. Thats why the proper cabling practices are:
  * Separation of data and electrical power cabling
  * Cables must be connected correctly
  * Installations must be inspected for damage
  * Equipment must be grounded correctly

[physicalLayer]: ../img/physicalLayer.png
[disturbance]: ../img/copperdisturbance.png
[copper]: ../img/coppermedia.png
