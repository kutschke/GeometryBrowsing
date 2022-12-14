// Draw only the virtual detectors
// (Actually all volumes whose name starts with "Virtual")
//
{
#include "VDs.cc+"

  gEnv->SetValue("Viewer3D.DefaultDrawOption", "ogl");

  TGeoManager *geom = TGeoManager::Import("mu2e.gdml");
  TBrowser *b       =  new TBrowser();

  TGeoNode *top = geom->GetTopNode();

  // Traverse the geometry tree; make all virtual
  // detectors visible and all others invisible.
  SelectVirtualDetectors d(top,0);

  geom->GetTopVolume()->Draw();
}

