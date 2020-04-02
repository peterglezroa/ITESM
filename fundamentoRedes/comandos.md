Commands
=====
### Router
#### Change hostname
```cisco
router> enable
router# config terminal
router(config t)#hostname R1
R1(config t)# end
R1#
```

#### Show IP's
```cisco
router# show ip interface brief
```

#### Save actual configuration
```cisco
router# copy running-config startup-config
```

#### Configure IP on interface gigabit 0/0
```cisco
router# config t
router(config t)# interface g0/0
router(interface)# ip address 192.168.1.1 255.255.255.0
router(interface)# no shutdown
router(interface)# end
router#
```

#### Show routing table
```cisco
router# show rout brief
```

#### Set virtual terminals and passwords
```cisco
router# config terminal
router(config t)# line vty 0 5
router(config-line)# password pass
router(config-line)# login
router(config-line)# exit
router(config t)# enable secret secret_pass
```

### Switch
#### Configure IP
```cisco
S1# config terminal
S1(config terminal)# interface vlan 1
S1(config terminal)# ip address 192.168.1.2 255.255.255.0
S1(config terminal)# no shutdown
S1(config terminal)# end
S1#
```

#### Default gateway
```cisco
S1# config terminal
S1(config terminal)# ip default-gateway 192.168.1.1
```

#### Configure virtual terminals and passwords
```cisco
S1# config terminal
S1(config t)# line vty 0 15
S1(config-line)# password pass
S1(config-line)# login
S1(config-line)# exit
S1(config t)# enable secret secret_pass
```
