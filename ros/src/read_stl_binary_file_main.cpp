#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <ros/package.h>
#include <stdio.h>

#include <geometric_shapes/shapes.h>



// Según:
// https://code.ros.org/trac/ros-pkg/browser/pkg/trunk/visualization/ogre_tools/src/stl_to_mesh/stl_to_mesh.cpp?rev=11460

int  main(int argc,char* argv[])
{
	std::cout << "Probando la lectura del stl binarios" <<  std::endl;
	std::cout << "------------------------------------" <<  std::endl;

	std::string path = ros::package::getPath("ros_examples_things");
	std::string file_name = "big_table.stl";
	path += "/common/files/stl/";
	std::cout << "Buscando en : \n" <<  path <<  std::endl;
	std::cout << "el fichero: "  << file_name <<  std::endl;
	path += file_name;

	// Open de file
	FILE* input = fopen(path.c_str(), "r" );
	if ( !input )
	{
		std::cout << "Error no se puede abrir el puto fichero"  <<std::endl;
		return -1;
	}
	std::cout << "Fichero abierto"  <<std::endl;

	fseek( input, 0, SEEK_END );
	long long fileSize = ftell( input );
	fseek( input, 0, SEEK_SET );
	char* buffer = new char[ fileSize ];
	fread( buffer, fileSize, 1, input );
	fclose( input );


	char* pos = buffer;
	pos += 80;
	unsigned int numTriangles = *(unsigned int*)pos;
	pos += 4;
	printf( "%d triangles\n", numTriangles );




	unsigned int vertexCount = 0;
	for ( unsigned int currentTriangle = 0; currentTriangle < numTriangles; ++currentTriangle )
	{
		float nX = *(float*)pos;
		pos += 4;
		float nY = *(float*)pos;
		pos += 4;
		float nZ = *(float*)pos;
		pos += 4;

		float v1X = *(float*)pos;
		pos += 4;
		float v1Y = *(float*)pos;
		pos += 4;
		float v1Z = *(float*)pos;
		pos += 4;

		float v2X = *(float*)pos;
		pos += 4;
		float v2Y = *(float*)pos;
		pos += 4;
		float v2Z = *(float*)pos;
		pos += 4;

		float v3X = *(float*)pos;
		pos += 4;
		float v3Y = *(float*)pos;
		pos += 4;
		float v3Z = *(float*)pos;
		pos += 4;

		pos += 2;


		// Hasta aquí a leido un triangulo (Normal y las 3 coordenadas de los tres vertices)
		// El siguiente paso es construir el mesh para ROS

		// Buscar moveit_msgs::AttachedCollisionObject


	}

	return 0;
}





