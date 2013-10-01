#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <ros/package.h>



int  main(int argc,char* argv[])
{


	std::string path = ros::package::getPath("ros_examples_things");
	// path += "/common/files/stl/"; // Ejemplo de como concatenar path
	std::cout << "Path: \n" <<  path <<  std::endl;

	return 0;
}
