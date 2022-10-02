//
// For viewing the remote handling room.
//   - Keep the remote handling room walls.
//   - Keep the cryostats to provide a reference.
//   - Keep some of the relevant pipes.
//   - Otherwise make everything invisible.

#include "RemoteHandling.hh"

#include "Rtypes.h"
#include "TGeoNode.h"
#include "TGeoVolume.h"
#include "TColor.h"

#include<map>
#include<string>
#include<vector>

using namespace std;

int RemoteHandling::maxDepth      = 0;

RemoteHandling::RemoteHandling( TGeoNode * node, int depth ):
  _name(node->GetVolume()->GetName()),
  _depth(depth){

  maxDepth = std::max( maxDepth, depth );

  // Volumes will be made invisible if their name contains one of these strings.
  static std::vector<string> substrings  { "CRS", "ExtShield", "Ceiling",
    "backfill", "dirt", "concrete", "VirtualDetector", "CRV", "CRS", "Lid",
    "pipe", "pBend", "TrenchCover", "RackBox", "ExtMon", "HVAC",
    "ProtonBeamDump", "NeutronCave", "PTM", "mstm", "EMFPlane",
    "stmMagnet", "collimatorSS", "FOV", "CableRun", "collimator1Channel",
    "collimator2Channel", "stmDet", "crvshield" };

  // Volumes with these material names will be made invisible.
  static std::vector<string> materials { "MBOverburden", "CONCRETE" };

  // After eliminating the above volumes, keep these volumes; substring comparison/
  static std::vector<string> keepers { "remoteHandlingInterior", "pipeType4",
    "pipeType3", "pipeType6" };

  // Color the parts of the remote handling room; exact name match.
  static std::map<string,int> colors{
     {"remoteHandlingInteriorBeam",  kRed },
    { "remoteHandlingInteriorWall1", kGreen },
    { "remoteHandlingInteriorWall2", kOrange },
    { "remoteHandlingInteriorWall3", kCyan },
    { "remoteHandlingInteriorWall4", kBlue },
    { "remoteHandlingInteriorWallNotch1", kYellow },
    { "remoteHandlingInteriorWallNotch2", kMagenta},
    { "pipeType4Pipe1Component1", kRed },
    { "pipeType6Pipe1Component1", kMagenta },
    { "pipeType3Pipe5Component1", kOrange },
    { "pipeType3PiperComponent1", kRed },
    { "pipeType3Pipe6Component1", kBlue }
  };

  if ( _depth < 2 ){
    node->SetVisibility(kFALSE);

  } else{
    bool vis = true;
    node->SetVisibility(kTRUE);
    for ( auto const& substring : substrings ){
      if ( _name.find(substring) != string::npos ){
	vis = false;
	node->SetVisibility(kFALSE);
	break;
      }
    }
    if ( vis ){
      string material(node->GetVolume()->GetMaterial()->GetName());
      for ( auto const& mat : materials ){
	if ( material.find(mat) != string::npos ){
	  vis = false;
	  node->SetVisibility(kFALSE);
	  break;
	}
      }
    }
    if ( ! vis ){
      for ( auto const& keep : keepers ){
        if ( _name.find(keep) != string::npos ){
          vis = true;
          node->SetVisibility(kTRUE);

          // Set the color of the parts of the remote handling room.
          for ( auto const& i : colors ){
            if ( _name == i.first ) {
              node->GetVolume()->SetLineColor(i.second);
            }
          }
          break;
        }

      } // end loop over keepers
    } // end if ( !vis
  } // end depth >= 2

  // Descend recursively into each daughter TGeoNode.
  int ndau = node->GetNdaughters();
  for ( int i=0; i<ndau; ++i ){
    TGeoNode * dau = node->GetDaughter(i);
    RemoteHandling( dau, depth+1);
  }

}
