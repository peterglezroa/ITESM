Ip Addressing
====
## Network and Host Portions
### IPv4 Address Structure
* The network potion is defined by the mask. The rest is the host portion

![ip address and mask][ipaddress]

#### Subnet Mask representation
![subnet mask][subnetmask]

## Types of IPv4 addresses
### Public and Private Addresses
#### Private Address
Private address blocks:

Block         | Starts at   | Finishes at
--------------|-------------|------------
10.0.0.0/8    |10.0.0.0     |10.255.255.255
172.16.0.0/12 |172.16.0.0   |172.31.255.255
192.168.0.0/16|192.168.0.0  |192.168.255.255

## IPv6
**0000**:0000:0000:0000:0000:0000:0000:0001

First hextet (Far left) | Type of IPv6 Address
------------------------|---------------------
0000 to 00FF            | Loopback address, any address, unspecified address, or IPv4-compatible
2000 to 3FFF            | Global unicast address ( a routable address in a range of addresses that is currently being handed out by the Internet Assigned Numbers Authority [IANA])
FE80 to FEBF            | Link-local (a unicast address which identifies the host computer on the local network)
FC00 to FCFF            | Unique-local (a unicast address which can be assigned to a host to identify it as being part of a specific subnet on the local network)
FF00 to FFFF            | Multicast address   


[ipaddress]: ../img/ipaddressing_ipAddress.png
[subnetmask]: ../img/ipaddressing_subnetRepresentation.png
