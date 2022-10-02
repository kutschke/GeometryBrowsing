Examples of browsing the Mu2e GDML file using ROOT TGeometry.

This is an evolution of the Geometry Browsing tutorial from the June 2019 Collaboration Meeting:
https://mu2ewiki.fnal.gov/wiki/GeometryBrowserTutorial2019

# To use this repo:

1. Start in a clean working directory.
2. git clone https://github.com/kutschke/GeometryBrowsing
3. Setup a recent version of root; root v6_26_06 is known to work.
4. Find a mu2e gdml file and copy it to the local working area.  It must be named mu2e.gdml.  See below.
5. root -l file.C,  where file.C is any of the .C files shown here.
6. The videos referenced in Exercises 1 and 2 on the 2019 page are still substantially correct.  The
   main differences are:
   - The level of detail of the Mu2e building and shielding within the hall has changed.  So the geometry
     file that you look at will be different in those details.
   - The .C files have been updated so that the Open GL viewer is selected automatically.  You no longer
     not to perform the step of opening the OGL viewer.
   - The .C files have been changed to use the modern root style of building the supporting .cc file;
     that is   ```gROOT->ProcessLine(".L file.cc+");``` has been changed to
     ```#include "file.cc+"```


# Where to find published mu2e.gdml files

Every published musing of Offline contains a mu2e.gdml file.  See, for example,
/cvmfs/mu2e.opensciencegrid.org/Musings/Offline/v10_18_00/build/sl7-prof-e20-p033/Offline/gen/gdml/mu2e.gdml

This gdml file corresonds to the geometry specified by "Offline/Mu2eG4/geom/geom_common.txt" in that release.

# To build your own mu2e.gdml file

1. Go to a Muse working area from which you can run Offline.
2. Create a fcl file that contains two lines; in the second line choose the geometry file that you wish to use.
```
#include "Offline/Mu2eG4/fcl/gdmldump.fcl"
services.GeometryService.inputFile : "Offline/Mu2eG4/geom/geom_common_current.txt"
```
3. Run the .fcl file to create a file named mu2e.gdml in the local working directory: ```mu2e -c file.fcl```

