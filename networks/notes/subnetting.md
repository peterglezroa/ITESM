Subnetting Networks
====
## Network segmentation

### Broadcast Domains
Devices use broadcast to locate:
* Other devices - A device uses _Address Resolution Protocol (ARP)_ which sends Layer 2 broadcast to a known IPv4 address on the local network to discover the associated MAC address.
* Services - A host typically aquires its IPv4 address configuration using the _Dynamic Host Configuration Protocol (DHCP)_ which send broadcast on the local network to locate a DHCP server.

**Switches** propagate broadcasts out all interfaces except the interface on which it was received.

**Routers** do not propagate broadcasts. Each router interfaces connects a _broadcast domain_ and broadcasts are only propagated within specific broadcast domain.

### Problems with Large Broadcast Domains
> A large broadcast domain is a network that connects many hosts.

1. Slow network operations due to the significant amount of traffic it can cause.
2. Slow device operations because a device must accept and process each broadcast packet.

**Solution: Reduce the size of the network to create smaller broadcast domains in a process called _subnetting_. Smaller networks are called subnets.**

### Reasons for Subnetting
1. Reduces overall network traffic
2. Improves network performance
3. Enables an administrator to implement security policies such as which subnets are allowed or not allowed to communicate together.

![subnetting example][subnettingExample]

## Subnetting an IPv4
### Octet Boundaries
Every interface on a router is connected to a network. IPv4 subnets are created by using one or more of the hosts bits as network bits. This is done by extending the _subnet mask_ to borrow some of the bits from the _host_ portion of the address to create aditional network bits.

![ipv4 octet subnetting][octet]

* **Class C** /24 -> 255.255.255.0 -> 254 hosts
* **Class B** /16 -> 255.255.0.0 -> 65,534 hosts
* **Class A** /8 -> 255.0.0.0 -> 16,777,214

#### Example:
Consider an enterprise has chosen the private address **10.0.0.0/8** as its internal network address. The enterprise could further subnet the **10.0.0.0/8** address at the octet boundary of **/16**

![subnet example][subnetTableExample]

### Classless Subnetting
Borrows bits from any host bit position to create other masks.
![classless subnetting table][classlessSubnetting]

### Example
#### Find the subnet ip
IP            | Host Mask      | Host           | Subnet Mask         | Subnet
--------------|----------------|----------------|---------------------|-------
192.168.1.12  |255.255.255.0   |192.168.1.0   |255.255.255.128      |192.168.1.0 /25
192.168.1.138 |255.255.255.0   |192.168.1.0   |255.255.255.128      |192.168.1.128 /25

Type       | Fist Octet | Second Octet | Third Octet | Forth Octet
-----------|------------|--------------|-------------|------------
ip         |192         |168           |1            |12          
host mask  |255         |255           |255          |0           
subnet mask|255         |255           |255          |128         
ip         |11000000    |10101000      |00000001     |00001100    
host mask  |11111111    |11111111      |11111111     |00000000    
subnet mask|11111111    |11111111      |11111111     |**1**0000000    
host ip    |11000000    |10101000      |00000001     |00000000    
subnet ip  |11000000    |10101000      |00000001     |00000000    

### Subnetting Formulas
#### Subnet quantity
To calculate the number of subnets that can be created: 
$$2^n$$
, where _n_ is the bits borrowed.

#### Host quantity
To calculate the number of hosts that can be created in the subnet: 
$$2^n-2$$
, where _n_ is the number of bits remaining in the host field.

### Variable Length Subnet Masks (VLSM)
_VLSM_ allows a network space to be divided into unequal parts. With VLSM, the subnet mask will vary dependeing on how many bits have been borrowed for a particular _subnet_.

#### Basic VLSM
To create smaller subnets, one of the subnets will be divided into smallers subnets.

##### Example:
**Host: 192.168.1.0**

Subnet          | Available hosts
----------------|----------------
192.168.1.0/26  |64
192.168.1.64/26 |64
192.168.1.128/26|64
192.168.1.192/27|32
192.168.1.224/27|32

#### Setting Up a VLSM
![vlsmPractice]
![vlsmChart]

1. For Bulding A:
```cisco
R1(config)# interface gigabitethernet 0/0
R1(config-if)# ip address 192.168.20.1 255.255.255.224
R1(config-if)# exit
R1(config)# interface serial 0/0/0
R1(config-if)# ip address 192.168.20.225 255.255.255.252
R1(config-if)# end
R1#
```

2. For Bulding B:
```cisco
R2(config)# interface gigabitethernet 0/0
R2(config-if)# ip address 192.168.20.33 255.255.255.224
R2(config-if)# exit
R2(config)# interface serial 0/0/0
R2(config-if)# ip address 192.168.20.226 255.255.255.252
R2(config-if)# exit
R2(config)# interface serial 0/0/1
R2(config)# ip address 192.168.20.229 255.255.255.252
R2(config-if)# end
R2#
```

3. For Bulding C:
```cisco
R3(config)# interface gigabitethernet 0/0
R3(config-if)# ip address 192.168.20.65 255.255.255.224
R3(config-if)# exit
R3(config)# interface serial 0/0/0
R3(config-if)# ip address 192.168.20.226 255.255.255.252
R3(config-if)# exit
R3(config)# interface serial 0/0/1
R3(config)# ip address 192.168.20.233 255.255.255.252
R3(config-if)# end
R3#
```

4. For Bulding D:
```cisco
R4(config)# interface gigabitethernet 0/0
R4(config-if)# ip address 192.168.20.65 255.255.255.224
R4(config-if)# exit
R4(config)# interface serial 0/0/0
R4(config-if)# ip address 192.168.20.226 255.255.255.252
R4(config-if)# end
R4#
```



## Subnetting an IPv6 Network
### The IPv6 Global Unicast Address
Global Routing Prefix (48bits) | Subnet ID (16bits) | Interface ID (64bits)
-------------------------------|--------------------|----------------------
This is the network portion of the address that is assigned by the provides | Used by an organization to identify subnets within its site | This is the equivalent to the host portion of an IPv4 address. Th term interface ID is used because a single host may have multiple interfaces, each having one or more IPv6 addresses.

### Subnetting Using the Subnet ID
The subnet ID provides more than enough subnets and host support than will ever be needed in one subnet. The 16 bit section can:
1. Create 65,536 /64 subnets
2. Support up to 18 quintillion host IPv6 addresses per subnet

### Example

![subnet allocation ipv6][subnetAllocationExample]

##### Configure R1
```cisco
R1(config)# interface gigabitethernet 0/0
R1(config-if)# ipv6 address 2001:db8:acad:1::1/64
R1(config-if)# exit
R1(config)# interface gigabitethernet 0/1
R1(config-if)# ipv6 address 2001:db8:acad:2::1/64
R1(config-if)# exit
R1(config)# interface gigabitethernet 0/3
R1(config-if)# ipv6 address 2001:db8:acad:3::1/64
R1(config-if)# end
R1#
```

## Structured Design
### Planning to Address The Network
Three primary considerations for planning address allocation:
1. Prevent Duplication of Addresses
2. Monitor Security and Performance
3. Provide and Control Access

### Assigning Addresses to Devices
There are different types of devices that require addresses:

#### End user clients
Most networks allocate addresses using _Dynamic Host Configuration Protocol (DHCP)_. 

#### Servers and peripherals
These should have a predictable static IP address

#### Servers that are accessible from the Internet
These servers are assigned private addresses internally, and the router or firewall at the perimeter of the network must be configured to translate the internal address into a public address.

#### Intermediary devices
These devices are assigned addresses for network management, monitoring, and security.

#### Gateway
Routers and firewall devices have an IP address assigned to each interface which serves as the gateway for the hosts in that network

#### Example
![Address ranges IPv4][addressRangesExample]


[subnettingExample]: ./img/subnetting_subnettingExample.png
[octet]: ./img/subnetting_octet.png
[subnetTableExample]: ./img/subnetting_subTableExample.png
[classlessSubnetting]: ./img/subnetting_classlessSubnetting.png
[vlsmPractice]: ./img/subnetting_vlsmPractice.png
[vlsmChart]: ./img/subnetting_vlsmChart.png
[addressRangesExample]: ./img/subnetting_addressRangesExample.png
[subnetAllocationExample]: ./img/subnetting_subnetAllocationExample.png
