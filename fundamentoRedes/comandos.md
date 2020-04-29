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
router# show ip route brief
router# show ipv6 route brief
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

#### Show interface status
```cisco
R1# show ip interface g0/0
R2# show ipv6 interface g0/0
```

#### Configurar ipv6
```cisco
R2(config)# ipv6 unicast-routing
R2(config)# interface g0/0
R2(config-if)# ipv6 address fe80::1 link-local
R2(config-if)# ipv6 address 2001:DB8:ACAD:A::1/64
R2(config-if)# no shutdown
```

#### Passwords
```cisco
R1(config)# enable secret cisco
R1(config-line)# line vty 0 5
R1(config-line)# password class
R1(config-line)# login
R1(config-line)# exit
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
S1(config)# int vlan1
S1(config-if)# ip address 192.168.1.1 255.255.255.0
S1(config-if)# no shutdown
S1(config)# line vty 0 15
S1(config-line)# password pass
S1(config-line)# login
S1(config-line)# exit
S1(config)# enable secret secret_pass
```

#### Habilitar ipv6
```cisco
Switch(config)# sdm prefer dual-ipv4-and-ipv6 default
Switch(config)# exit
Switch# reload
```
