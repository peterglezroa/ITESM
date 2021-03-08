Ip Addressing
====
## IPv4
### Network and Host Portions
* The network potion is defined by the mask. The rest is the host portion.

![ip address and mask][ipaddress]
The example above is how you determine the host portion of an ipv4 address.

#### Subnet Mask representation
![subnet mask][subnetmask]

### IPv4 Unicast, Broadcast and Multicast
The largest population of hosts includes PCs, tablets, smartphones, and IP phones. It is also often the case that the user population and their devices change frequently. It would be impractical to statically assign IPv4 addresses for each device. Therefore, these devices are assigned IPv4 addresses dynamically using the **_Dynamic Host Configuration Protocol (DHCP)_**.
#### Unicast
The process of sending a _packet_ from one host to an **individual host**.  
* Host addresses in range of **0.0.0.0** to **223.255.255.255**

#### Broadcast
The process of sending a _packet_ from one host to **all hosts** in the network.
* All hosts on that local network will receive and look at the packet.
* Routers do not forward broadcasts.
* All host portion must be 1's.

#### Multicast
The process of sending a _packet_ from one host to a **selected group of hosts**.
* Reserved in the range of **224.0.0.0** to **239.255.255.255** addresses.

### Types of IPv4 addresses
#### Public and Private Addresses
##### Private Address
Private address blocks:

Block         | Starts at   | Finishes at
--------------|-------------|------------
10.0.0.0/8    |10.0.0.0     |10.255.255.255
172.16.0.0/12 |172.16.0.0   |172.31.255.255
192.168.0.0/16|192.168.0.0  |192.168.255.255

#### Special User
##### Loopback addresses
More commonly identified as only 127.0.0.1. Hosts use it to **direct traffic to itself**.
* Range from **127.0.0.1** to **127.255.255.254** (127.0.0.0/8)

##### Link-Local addresses
More commonly known as **Automatic Private IP Addressing (APIPA)** addresses. Used by a Windows _DHCP_ client to self-configure in the event that there are no _DHCP_ servers available.
* Useful in peer-to-peer connection
* Range from **169.254.0.1** to **169.254.255.254** (169.254.0.0/16)

##### TEST-NET addresses
Addresses set for **teaching** and **learning**.
* Range from **192.0.2.1** to **192.0.2.0** (192.0.2.255)

#### Legacy Classful Adressing
##### Class A
Designed to support **extremely large networks** with more than 16 million host addresses.
* **Most significant bit** must be a cero
* Range from **0.0.0.0/8** to **127.0.0.0/8**

##### Class B
Designed to support the needs of **moderate to large size networks** with up to 65,000 host addresses.
* **The most significant two bits** must be 10
* Range from **128.0.0.0/16** to **191.255.0.0/16**

##### Class C
Designed to support **small networks** with a maximum of 254 hosts.
* **The most significant two bits** must be 10
* Range from **192.0.0.0/24** to **223.255.255.0/24**

## IPv6
**0000**:0000:0000:0000:0000:0000:0000:0001

First hextet (Far left) | Type of IPv6 Address
------------------------|---------------------
0000 to 00FF            | Loopback address, any address, unspecified address, or IPv4-compatible
2000 to 3FFF            | Global unicast address ( a routable address in a range of addresses that is currently being handed out by the Internet Assigned Numbers Authority [IANA])
FE80 to FEBF            | Link-local (a unicast address which identifies the host computer on the local network)
FC00 to FCFF            | Unique-local (a unicast address which can be assigned to a host to identify it as being part of a specific subnet on the local network)
FF00 to FFFF            | Multicast address   

### Rules
#### Rule 1 - Omit Leading 0s
The first rule to help reduce the notation of IPv6 addresses is to omit any leading 0's in any 16-bit section or hextet. For example:
* **01AB** can be represented as **1AB**
* **09F0** can be represented as **9F0**

#### Rule 2- Omit all 0 Segments
A double colon ( **::** ) can replace any single, contiguous string of one or more 16-bit segments consisting of all 0's. Example:

Preferred -> 2001:0DB8:0000:1111:0000:0000:0000:0200  
No 0's -> 2001:DB8:0:1111:0:0:0:200   
Compressed -> 2001:DB8:0:1111::200

### IPv6 Addess Types
#### Unicast
A source IPv6 address must be a unicast address. The destination IPv6 address can be either a unicast or a multicast address.

##### Global unicast
A global unicast address is similar to a public IPv4 address.

##### Link-Local
Are used to **communicate with other devices on the same local link/subnet**.
* Not routable beyond the link.
* Range **FE80::/10**

##### Unique local
Are used for local **addressing within a site or between a limited number of sites**.
* Should not be routable in the global IPv6
* Should not be translated to a global IPv6 addresses
* Range from **FC00::/7** to **FDFF::/7**


[ipaddress]: ./img/ipaddressing_ipAddress.png
[subnetmask]: ./img/ipaddressing_subnetRepresentation.png
