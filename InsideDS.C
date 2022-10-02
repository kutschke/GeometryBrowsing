// Draw only the objects that are inside DS2vacuum
// or DS3Vacuum volumes.
//
// But do not draw any virtual detectors.
//
{

#include "InsideDS.cc+"

  gEnv->SetValue("Viewer3D.DefaultDrawOption", "ogl");

  TGeoManager *geom = TGeoManager::Import("mu2e.gdml");
  TBrowser *b       =  new TBrowser();

  // Traverse the geometry tree and set the visibility
  // of each volume.
  InsideDS d(geom->GetTopNode(),false);

  geom->GetTopVolume()->Draw();
}

