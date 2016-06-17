Description:
This is a simple implementation of fisheye graphic distortion algorithm.(Ref[1])
Different algorithms (exp: Ref[2]) has been considered but this one is the simplest yet
providing acceptable results.

This is far from being optimal as stretching artifact are seen especially
at the edges (cropping is necessary).

Area of improvement:
- Quality can be improved using a more advanced algorithm.
- GPU Acceleration can be used to have a better implementation Ref[3] & Ref[4]
- API can be more generic for reusability.
- Algorithm's interface can be decoupled from image file manipulation interface

dependencies:
cmake and OpenCV

build:

dependencies:
 cmake is used to provide multiplatform build system.
 OpenCV is used for image file display and manipulation

Linux:
mkdir build
cmake ../
make

Windows:
- cmake-gui to generate a solution for exmpl: visual studio
- openCV folder need to provided in cmake 
- openCV bin folder need to be added in system PATH

tests:
- This implementation has been tested on both Linux (ubuntu 16.04) and Windows 8.1
- Two jpeg images files are provided for test 
   -input.jpg (from the asssignemt document)
   -input2.jpg Ref[5]

input: 
  - input file path
  - Strength of the undistortion (4.1 provided acceptable results)

both source image and output image are displayed on different windows
and the output file is saved in the application current folder

references:
Ref [1]: http://www.tannerhelland.com/4743/simple-algorithm-correcting-lens-distortion/
Ref [2]: http://mipav.cit.nih.gov/pubwiki/index.php/Barrel_Distortion_Correction
Ref [3]: http://paulbourke.net/miscellaneous/lenscorrection/#opengl
Ref [4]: https://www.shadertoy.com/view/4s2GRR
Ref [5]: https://www2.informatik.hu-berlin.de/~ruess/isprs2012ruess/index.php
http://paulbourke.net/dome/fisheye/
http://photo.net/learn/fisheye/

