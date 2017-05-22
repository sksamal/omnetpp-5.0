//
//
// Suraj: Obselete and not needed anymore

package obsmodules.src.FSONode;

//
// Input module for OBS_FSONode. Splits optical fibers in two parts: control channels connected to the Control Unit and data channels connected to the OXC.
//
simple FSO_Input
{
    parameters:
        int numoxcPorts; //Number of input fibers = n
        int numserverPorts; //Number of electrical ports = s (from servers in topof rack)
        string lambdasPerPort;  //Number of data channels for each fiber
        string colours; // Colour of each data channel of each fiber. Should be a list of int numbers and vertical bars separated by spaces (each vertical bar separates a fiber). Use an empty string if you don't want to use colours. Example: "2 3 4 | 4 3 2 | 5 4 3" (3 fibers with 3 lambdas each one)
    gates:
        input in[];
        output out[];
}
