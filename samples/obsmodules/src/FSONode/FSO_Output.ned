//
//
// Suraj: Obselete and not needed any more

package obsmodules.src.FSONode;

//
// Output interface for OBS_CoreNode.
//
simple FSO_Output
{
    parameters:
        int numoxcPorts; //Number of output fibers = n
        string lambdasPerPort; //Number of data channels for each fiber
        int numserverPorts; // Electrical ports = s (Servers in the top of rack)
        string colours; // Colour of each data channel of each fiber. Should be a list of int numbers and vertical bars separated by spaces (each vertical bar separates a fiber). Use an empty string if you don't want to use colours. Example: "2 3 4 | 4 3 2 | 5 4 3" (3 fibers with 3 lambdas each one)
    gates:
        input in[];
        output out[];
}
