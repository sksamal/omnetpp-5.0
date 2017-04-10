// -*-c-*-
// $Id: packet.msg,v 1.3 2013/06/11 06:09:38 ahmet Exp $
// Ahmet Sekercioglu

enum PayloadTypes
{
    routing = 1; // we will use to mark routing packets
    data    = 2; // best-effort, bulk data
    video   = 3; 
    voip    = 4; 
}


//
// Represents a packet in the network.
//
packet Packet
{
    int srcAddr;
    int destAddr;
    int hopCount;
    int payloadType @enum(PayloadTypes);
    unsigned char data[1000];
}

