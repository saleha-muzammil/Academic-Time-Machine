/*
 * SPDX-License-Identifier: GPL-2.0-only
 */

#include "ns3/applications-module.h"
#include "ns3/core-module.h"
#include "ns3/internet-module.h"
#include "ns3/network-module.h"
#include "ns3/point-to-point-module.h"

// Default Network Topology
//
//       10.1.1.0
// n0 -------------- n1
//    point-to-point
//

using namespace ns3;

NS_LOG_COMPONENT_DEFINE("FirstScriptExample"); //used for logging the name

int main(int argc, char* argv[])
{
    CommandLine cmd(__FILE__);
    cmd.Parse(argc, argv);

    Time::SetResolution(Time::NS); //sets the resolution(smallest meaningful time unit) to 1 nanoseocnd

    //setting specific verbosity for the logging components
    LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO); 
    LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);

    //creates a node container topology helper with pointer to two nodes within it
    NodeContainer nodes;
    nodes.Create(2);

    PointToPointHelper pointToPoint;
    //sets the dataRate attrib of PointToPointHelperNetDevice to 5 Mbps
    pointToPoint.SetDeviceAttribute("DataRate", StringValue("10Mbps"));
    //sets the propagation delay attrib of PointToPointHelperChannel to 2 ms
    pointToPoint.SetChannelAttribute("Delay", StringValue("5ms"));
    
    //creates a container to configure each of the device(NIC) and the channel based on the attribs previously set in topology helper
    //After executing the pointToPoint.Install(nodes) call we will have two nodes, each with an installed point-to-point net device and a single point-to-point channel between them.
    NetDeviceContainer devices;
    devices = pointToPoint.Install(nodes);

    //install internet protocol stack(TCP/UDP, IP) on the nodes
    InternetStackHelper stack;
    stack.Install(nodes);

    //This allocates the IPs to the devices. first param = starting base IP, second = network mask to define the net and host IDs. Helper automatically assigns the addresses based on these starting from 10.1.1.1 and so on... 
    Ipv4AddressHelper address;
    address.SetBase("10.1.1.0", "255.255.255.0");

    //assigns the addresses and returns a list of IPv4 interface objects
    Ipv4InterfaceContainer interfaces = address.Assign(devices);

    //Using the second core abstraction onwards: Applications
    //this passes port num as param that the client must also know. Convention followed in ns3 that required params must be passed in the constructor that may be changed later using setters
    UdpEchoServerHelper echoServer(8080);

    //the following install methods installs the application in the server by getting it from the node container index 1. Note that install takes nodeCont as param that is implicitly converted
    //ret a list of applications installed
    ApplicationContainer serverApps = echoServer.Install(nodes.Get(1)); 
    //apps require time to start generating traffic and an optional time to stop
    //typecast to seconds to convert into ns3 Time object from double
    serverApps.Start(Seconds(1.0));
    serverApps.Stop(Seconds(10.0));

    //helper to install app on the client
    //need to set five attribs: IP of the servert taken from the container defined above, port ...
    UdpEchoClientHelper echoClient(interfaces.GetAddress(1), 8080);
    echoClient.SetAttribute("MaxPackets", UintegerValue(5)); //max packs allowed to send dur simul
    echoClient.SetAttribute("Interval", TimeValue(Seconds(0.5))); //wait b/w pkts
    echoClient.SetAttribute("PacketSize", UintegerValue(512)); //pkt size in bytes
    //this means that the client should send 1 pkt of size 1024 bytes

    //install app on client
    ApplicationContainer clientApps = echoClient.Install(nodes.Get(0));
    clientApps.Start(Seconds(2.0)); //start 1s after server
    clientApps.Stop(Seconds(10.0));

    //this will run the simulation. first event at 1s i.e. server starts and second at 2s i.e. client starts. Note that each event may trigger other events also. Run() completes once there are no more events to run i.e. in our case both server and client stops
    Simulator::Run();
    //clears the objects crreated
    Simulator::Destroy();
    return 0;
}
