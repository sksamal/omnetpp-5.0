//
//

package obsmodules.src.FSONode;

//
// Output interface for FSONode.
//
simple FSO_CoreOutput
{
    parameters:
        int numPorts; //Number of output fibers
        string lambdasPerPort; //Number of data channels for each fiber
        string lambdasEdge; // Number of channels from edge (note, control stuff comes on last lamba)
        string colours; // Colour of each data channel of each fiber. Should be a list of int numbers and vertical bars separated by spaces (each vertical bar separates a fiber). Use an empty string if you don't want to use colours. Example: "2 3 4 | 4 3 2 | 5 4 3" (3 fibers with 3 lambdas each one)
    gates:
        input in[];
        output out[];
}
