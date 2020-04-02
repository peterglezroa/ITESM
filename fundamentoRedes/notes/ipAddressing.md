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




[ipaddress]: ../img/ipaddressing_ipAddress.png
[subnetmask]: ../img/ipaddressing_subnetRepresentation.png
