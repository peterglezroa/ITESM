Ethernet
===
* Most used LAN technology today.
* Operates in the data link layer and the physical layer.
* Supports from 10Mb/s to 100kMb/s(100Gb/s)
![ethernet][ethernet]

### Sublayers

#### LLC sublayer
* Handles the communication between the upper layers and the lower layers.
* Is implemented in software
* Independent of the hardaware.
* Can be considered the driver software for the NIC
> The NIC driver is a program that interacts directly with the hardware on the NIC to pass the data between the MAC sublayer and the physical media.

#### MAC layer
![MAC][MAC]
* The lower sublayer of the data link layer.
* Implemented by hardware
##### Data encapsulation
* Frame assembly before transmission and frame disassembly upon reception of a frame.
1. Frame delimiting: provides important delimiters that are used to identify a group of bits that make up a frame.
2. Addressing: contains the Layer 3 PDU and also provides for data link layer addressing.
3. Error detection: contains a trailer used to detect any errors in transmissions.
##### Ethernet frame structure

##### Media access control
* Responsible for the placement of frames on the media and the removal of frames from the media. 
* 48-bit **binary** expressed as 12 **hexadecimal** digits.
![MAC structure address][MACstruct]
* 2 rules:
  1. All MAC addresses assigned to a NIC or other Ethernet device muse use that vendor's assigned OUI as the first 3 bytes.
  2. All MAC addresses with the same OUI must be assigned a unique value in the last 3 bytes.
##### Unicast Mac address
  * unique address used when a frame is sent from a single transmitting device to a single destination device.
![unicast][unicast]

##### Broadcast MAC address
* Contains a destination IPv4 address that has all ones (1s) in the host portion. This means that all hosts on that local network will receive and process the packet.
* We use ARP protocol
![broadcast][broadcast]

##### Multicast MAC address
* Allow a source device to send a packet to a group of devices.
* Range of IPv4: 224.0.0.0 to 239.255.255.255
* Range of IPv6: begin with FF00::/8
* Used in gaming
![multicast ethernet][multicast]


### Switch fundamentals (incompleto)
* A layer 2 switch uses MAC addresses to make forwarding decisions.
#### Frame Forwarding Methods on Cisco Switches
##### Store-and-forward
* stores the data in buffers until the complete frame has been received.
* uses CRC (Cyclic Redudancy Check) to check for errors
  * CRC uses a mathematical formula, based on the number of bits in the frame, to determine whether the received frame has an error
* Used for quality of service
##### Cut-through
* forwards the frame before it is entirely received.
* as soon as the MAC address is read, the frame starts to be forwarded.
* the switch does not perform any error checking on the frame.
* **Fast-forward switching**:
  * Lowest level of latency.
  * immediately forwards a packet after reading the destination address.
* **Fragment-free switching**:
  * Stores the first 64 bytes of the frame before forwarding. Because the max amount of bytes in 100 meters is 64 bytes.
  * The most network errors and collisions occur during the first 64 bytes.

#### Port-based and shared memory buffering
##### Port-based memory
Frames are stored in queues that are linked to specific incoming and outgoing ports.
##### Shared memory
Deposits all frames into a common memory buffer, which all the ports on the switch share.

#### Duplex and Speed Settings
The duplex and bandwidth settings must match between the switch port and the connected devices.
##### Full-duplex
Both ends of the connection can send and receive simultaneously.
##### Half-duplex
Only one end of the connection can be send at a time.

##### Auto-MDIX (Automatic Medium Dependent Interface Connection)
In addition to having the currect duplex setting, it is also necessary to have the correct cable type defined for each port. Most switch devices now support the mdix auto interface configuration command in the CLI.

##### Destination on Same Network
* IP addresses are used to identify the address of the original source and final destination. Most use DNS (Domain Name System).
* Layer 2 addresses are used to deliver the data link frame with the encapsulated IP packer from one NIC to another NIC on the same network
![destination local][local]

##### Destination Remote Network
* The destination MAC address will be the address of the host's default gateway, the router's NIC.
![destination local][remote]


[ethernet]: ../img/ethernet_ethernet.png
[MAC]: ../img/ethernet_MAC.png
[MACstruct]: ../img/ethernet_MACstruct.png
[unicast]: ../img/ethernet_unicast.png
[broadcast]: ../img/ethernet_broadcast.png
[multicast]: ../img/ethernet_multicast.png
[local]: ../img/ethernet_local.png
[remote]: ../img/ethernet_remote.png
