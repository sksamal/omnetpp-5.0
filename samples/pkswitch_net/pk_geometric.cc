// Ahmet Sekercioglu 2006
// $Id: pk_geometric.cc,v 1.1 2006/10/08 11:19:01 ahmet Exp $
//
// For generating geometrically distributed packet sizes 
// with a given shift (minimum packet size).

#include <omnetpp.h>

double pk_geometric(double min_pk_size, double avg_pk_size)
{
  double p = 1.0/(avg_pk_size - min_pk_size);
  return (geometric(p) + min_pk_size);
}

Define_Function(pk_geometric, 2);
