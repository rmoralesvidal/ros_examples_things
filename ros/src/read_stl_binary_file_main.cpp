#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <ros/package.h>



// Según:
// https://code.ros.org/trac/ros-pkg/browser/pkg/trunk/visualization/ogre_tools/src/stl_to_mesh/stl_to_mesh.cpp?rev=11460

int  main(int argc,char* argv[])
{
	std::cout << "Probando la lectura del stl binarios" <<  std::endl;
	std::cout << "------------------------------------" <<  std::endl;

	std::string path = ros::package::getPath("ros_examples_things");
	path += "/common/files/stl/";
	std::cout << "Buscando en : \n" <<  path <<  std::endl;
	std::cout << "el fichero:"  <<  std::endl;




	return 0;
}





