#This program will create two nodes and pass traffice from one node to other node using TCP protocol

#Creating simulator object 
set ns [new Simulator]   

#Creating the nam file
set nf [open out.nam w]      
#It opens the file 'out.nam' for writing and gives it the file handle 'nf'. 
$ns namtrace-all $nf

# Open the trace file
#  set nf [open out.tr w]
#  $ns trace-all $nf

#    we are opening a newtrace file named as "out" and also telling that data must be stored in .tr [trace] format.
#   "nf" is the file handler that we are used here to handle the trace file.
#   "w" means write i.e the file out.tr is opened for writing.
#   "r" means reading 
#   The second line tells the simulator to trace each packet on every link in the topology and for that we give file handler nf for the simulator ns.



#Finish Procedure  (closes the trace file and starts nam)
proc finish {} {
        global ns nf
        $ns flush-trace
        close $nf
        exec nam out.nam &
        exit 0
        }
			
#The trace data is flushed into the file by using command $ns flush-trace and then file is closed.
        
#Creating Two nodes
set n0 [$ns node]
set n1 [$ns node]

#Creating a duplex link between two nodes (connect the nodes n0 and n1 with a duplex link with the bandwidth 1Megabit, a delay of 10ms and a SFQ queue)
$ns duplex-link $n0 $n1 1Mb 10ms SFQ     
$ns duplex-link-op $n0 $n1 orient right

#Creating a TCP agent and connecting it to n0 (Basically it defines source node of TCP)
set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0        

#Creating a Sink Agent and attaching it to n1
set sink0 [new Agent/TCPSink]
$ns attach-agent $n1 $sink0

#Connecting TCP agent with Sink agent
$ns connect $tcp0 $sink0

#Creating FTP agent for traffic and attching it to tcp0
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0

#Starting the FTP Traffic
$ns at 0.5 "$ftp0 start"
$ns at 4.5 "$ftp0 stop"

#Calling the finish procedure
$ns at 5.0 "finish"

#Run the simulation
$ns run
