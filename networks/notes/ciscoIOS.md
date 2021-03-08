Cisco IOS
===
### Operating systems
* PC OS allows users to interact with computers
* CISCO IOS allows users to interact with Cisco devices.

#### Access methods
* Console
* Auxiliar
* Virtual terminal
  * Telnet
    * Not secure because it doesnt encrypt.
  * SSH
    * Require active networking services on the device including an active interface configured with an address.
  * Console
    * For new equipment that does not have telnet or ssh access enable by default.

### Primary Command Modes
To move from any sub-configuration mode to one step before:
<pre><code>Switch# exit</code></pre>
To move from any sub-configuration mode to the EXEC mode: (or Ctrl+Z)
<pre><code>Switch(configure)# end</code></pre>

#### User Exec Mode
* Allows access to only a limited number of basic monitoring commands.
* View-only like mode
* Recognition by the tag symbol '>' in the Prompt
#### Privileged EXEC Mode
* Recoginition by the tag symbol '#' in the Prompt
 * To access:
<pre><code>Switch> enable
Switch#</code></pre>

#### Configuration Command Modes
* Used to config a device
* To access:
<pre><code>Switch# config terminal 
Switch(config)#</code></pre>
* Line configuration mode
  * Used to config console, SSH, telnet, or AUX access.
<pre><code>Switch(config)# line console 0
Switch(config-line)#</code></pre>
* Interface Configuration Mode
  * Used to config a switch port or router network interface.
<pre><code>Switch(config)# interface FastEthernet 0/1
Switch(config-if)#</code></pre>

### Basic IOS Command Structure (2.1.4.1)
![command structure][structure]

### Basic Device Configuration

#### Limit acces to device configurations
* Secure device access
  * To set password to EXEC access
  <pre><code>enable secret &lt;password&gt;</code></pre>
* Virtual Terminal (VTY) line enables remote access to the device.
  * To secure VTY lines:
<pre><code>S1(config) # line con 0 // it can be from 0 to 15
S1(config-line) # password cisco
S1(config-line) # login
S1(config-line) # exit
S1(config) #</code></pre>
* Encrypt Passwords
<pre><code>S1(config) # service password-encryption</code></pre>

* Prevent unwanted DNS lookups.
<pre><code>S1(config) # no ip domain-lookup</code></pre>
 
#### Save configurations



[structure]: ./img/ioscommandstructure.png
