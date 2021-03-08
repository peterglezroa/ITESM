Protocols
===
### Rules
#### Message Encoding
> Encoding is the process of converting information into another acceptable form, for transmission. Decoding reverses this process in order to interpet the information

#### Message Formatting and Encapsulation
> When a message is sent from source to destination, it must use a specific format or structure. Message formats depend on the type of message and the cannel that is used to deliver the message.

#### Message size
> ... sentences are limited in size to what the receiving person can process at one time...  
The size restrictions of frame require the source host to break a long message into individual pieces that meet both the minimum and maximum size requirements.

#### Message timing
##### Access method
Determines when someone is able to send a message.
##### Flow control
Source and destination hosts use flow control methods to negotiate correct timing for successful communication.
##### Reponse timeout
Hosts on the network also have rules that specify how long to wait for responses and what action to take if a response timeout occurs.

### Protocols
#### Application Layer
##### HTTP
Application protocol that governs the way a web server and a web client interact.
* Defines the content and formatting of the requests and responses
* Relies on other protocols to govern how the messages are transported

##### BOOTP
Enables a diskless workstation to discover its own IP address.

##### DHCP
Dynamic Host Configuration Protocol, dynamically assings IP addresses to client stations at start-up

##### SMTP
Simple Mail Transfer Protocol, enables clients and servers to send emails.

##### POP
Post Office Protocol, enables clients to retrieve email from server.

##### IMAP
Internet Message Access Protocol, enables clients to access email stored on a mail server

##### FTP
File Transfer Protocol, sets the rules that enable a user on one host to access and transfer files to and from another host.

##### TFTP
Trivial File Transfer Protocol, simple connectionless file transfer protocol.

#### Transport layer
##### TCP
Transport protocol that manages the individual conversations.
* Responsible for controlling the size and rate at which messages are exchanged between the server and the client.

##### UDP
User Datagram Protocol, enables a process running on one host to send packets to a process running on another host.

#### Internet layer
##### IP
Responsible for taking the formatted segments from TCP, encapsulating them into packets, assigning them the appropriate addresses, and delivering them to the destination host.

##### NAT
Translates IP addresses from a private network into a globally unique public IP addresses

##### ICMP
Internet Control Message Protocol, provides feedback from a destination host to a source host about errors in packet delivery.

##### OSPF
Open Shortest Path First, link-state routing protocol.

##### Enhanced Interior Gateway Routing Protocol
Cisco proprietary routing protocol.

#### Network Access Layer
##### Ethernet
Is a network access protocol that describes two primary functions:
1. communication over a data link and the physical transmission of data
2. taking the packets from IP and formatting them to be transmitted over the media.

##### ARP
Address Resolution Protocol, provides dynamic address mapping between an IP address and a hardware address

##### PPP
Point-to-Point Protocol, provides a means of encapsulating packets for transmission over a serial link.

##### Interface Drivers
Provides instructions to a machine for the control of a specific interface on a network device.


### Protocol Suites and Industry Standards
![protocols][protocols]

Protocol suite is a set of protocols that work together to provide comprehensive network communication services.

[protocols]: ../img/protocols_protocols.png
