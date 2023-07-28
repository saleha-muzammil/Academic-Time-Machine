#This program will create two nodes and send data via UDP from one node to another over a duplex-link

#Creating Simulator Object
set ns [new Simulator]

#creating Two color classes for ns object to distinguish the traffic coming from various sources
$ns color 0 blue
$ns color 1 red

#Creating nam file
set nf [open out.nam w]
$ns namtrace-all $nf

#Finish procedure to open file using nam to visulaize our network
proc finish {} {
        global ns nf
        $ns flush-trace
        close $nf
        exec nam out.nam &
        exit 0
}

#Defining Nodes
set n0 [$ns node]
set n1 [$ns node]

#Setting Parameters of Nodes
$n0 color red
$n0 shape hexagon

$n1 color blue
$n1 shape box

#Defining Duplex link between nodes having bandwidth of 1Mbps, delay of 10ms and Droptail Queue
$ns duplex-link $n0 $n1 1Mb 10ms DropTail

#Orienting the nodes for proper visulaization
#n1 will be on the right-up position w.r.t n0
$ns duplex-link-op $n0 $n1 orient right-up 


#Displaying the angle of queue between the nodes
#0.5 means 0.5*pi(90 Degrees) i.e., straight up
$ns duplex-link-op $n0 $n1 queuePos 0.5

#Limiting the queue to only 30 packets 
$ns queue-limit $n0 $n1 30

#Specifying the UDP agent
set udp0 [new Agent/UDP]

#Specifying udp traffic to have red color as defined in the second line of program
$udp0 set fid_ 1

#Attaching the UDP agent with n0
$ns attach-agent $n0 $udp0

#Specifying the Null agent
set null0 [new Agent/Null]

#Attaching the NULL agent with n1
$ns attach-agent $n1 $null0

#Connecting both udp0 and null0 agents for transferring data between n0 and n1
$ns connect $udp0 $null0
 
#Specifying the CBR agent to generate the traffic over udp0 agent
set cbr0 [new Application/Traffic/CBR]

#Each packet having 500 bytes
$cbr0 set packetSize_ 500

#EAch packet will be generated after 5ms i.e., 200 packets per second
$cbr0 set interval 0.005 

#Attaching cbr0 with udp0
$cbr0 attach-agent $udp0

#Starting the cbr0 at 0.5 simulaio time
$ns at 0.5 "$cbr0 start"

#Stoping the cbr0 at 4.5 simulation time
$ns at 4.5 "$cbr0 stop"

$ns at 5.0 "finish"

$ns run
