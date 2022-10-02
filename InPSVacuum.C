//
// Expose the product target and proton absorber assemblies
// inside the PS Vacuum.
//
{

#include  "InPSVacuum.cc+"

  gEnv->SetValue("Viewer3D.DefaultDrawOption", "ogl");

  TGeoManager *geom = TGeoManager::Import("mu2e.gdml");
  TBrowser *b       =  new TBrowser();

  InPSVacuum d(geom->GetTopNode(),false);

  geom->GetVolume("PSVacuum")->Draw();
}

