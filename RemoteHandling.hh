#ifndef RemoteHandling_hh
#define RemoteHandling_hh

//
// Make the following volumes invisible:
//  - anything in the top two levels of the volume heirarchy
//  - anything related to the building, shielding or the CRV
//  - Virtual detectors
//

class TGeoNode;
class TGeoVolume;

#include <iostream>
#include <string>
#include <vector>

class RemoteHandling{

public:

  RemoteHandling( TGeoNode *, int depth );

  // Accept compiler written d'tor, copy c'tor and assignment operator.

  std::string const& name() const { return _name; }

  static int maxDepth;

private:
  std::string _name;
  int         _depth;

};

#endif /* RemoteHandling_hh */
