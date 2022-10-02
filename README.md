Examples of browsing the Mu2e GDML file using ROOT TGeometry.

This is an evolution of the Geometry Browsing tutorial from the June 2019 Collaboration Meeting:
https://mu2ewiki.fnal.gov/wiki/GeometryBrowserTutorial2019

To use this repo:

1. Setup a recent version of root; root v6_26_06 is known to work.
2. Find a mu2e gdml file and copy it to the local working area.  It must be named mu2e.gdml.  See below.
3. root -l file.C,  where file.C is any of the .C files shown here.
4. The videos reference in Exercises 1 and 2 on the 2019 page are still substantially correct.  The
   main differences are:
   - The level of detail of the Mu2e building and shielding within the hall has changed.  So the geometry
     file that you look at will be different in those details.
   - The .C files have been updated so that the Open GL viewer is selected automatically.  You no longer
     not to perform the step of opening the OGL viewer.
   - The .C files have been changed to use the modern root style of building the supporting .cc file;
     that is   ```gROOT->ProcessLine(".L file.cc+");``` has been changed to
     ```#include "file.cc+"```


