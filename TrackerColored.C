//
// View inside the TrackerMother volume.
// Modify the colors of selected volumes.
//

{
  gEnv->SetValue("Viewer3D.DefaultDrawOption", "ogl");

  TGeoManager *geom = TGeoManager::Import("mu2e.gdml");
  TBrowser *b       =  new TBrowser();

  geom->GetVolume("TrackerEndRingUpstream")->SetLineColor(kRed);

  geom->GetVolume("ThinSupportRing_0")->SetLineColor(kRed);
  geom->GetVolume("ThinSupportRing_1")->SetLineColor(kRed);

  geom->GetVolume("TrackerSupportBeam_10")->SetLineColor(kGreen);
  geom->GetVolume("TrackerSupportBeam_11")->SetLineColor(kGreen);
  geom->GetVolume("TrackerSupportBeam_12")->SetLineColor(kGreen);
  geom->GetVolume("TrackerSupportBeam_20")->SetLineColor(kGreen);
  geom->GetVolume("TrackerSupportBeam_21")->SetLineColor(kGreen);
  geom->GetVolume("TrackerSupportBeam_22")->SetLineColor(kGreen);

  geom->GetVolume("VirtualDetector_TT_Mid")->SetLineColor(kBlue);

  geom->GetVolume("TrackerMother")->Draw();
}
