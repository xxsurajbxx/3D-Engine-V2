#include <iostream>#include <math.h>int main() {    const int FOV=120, numofTris=12, deg=1;    const double SCALING_FACTOR=tan(FOV*(M_PI/180));    double triangles[numofTris][3][3] = {        // SOUTH
		{{-0.5, -0.5, -0.5}, {-0.5, 0.5, -0.5}, {0.5, 0.5, -0.5}},
		{{-0.5, -0.5, -0.5}, {0.5, 0.5, -0.5}, {0.5, -0.5, -0.5}},

		// EAST
		{{0.5, -0.5, -0.5}, {0.5, 0.5, -0.5}, {0.5, 0.5, 0.5}},
		{{0.5, -0.5, -0.5}, {0.5, 0.5, 0.5}, {0.5, -0.5, 0.5}},

		// NORTH
		{{0.5, -0.5, 0.5}, {0.5, 0.5, 0.5}, {-0.5, 0.5, 0.5}},
		{{0.5, -0.5, 0.5}, {-0.5, 0.5, 0.5}, {-0.5, -0.5, 0.5}},

		// WEST
		{{-0.5, -0.5, 0.5}, {-0.5, 0.5, 0.5}, {-0.5, 0.5, -0.5}},
		{{-0.5, -0.5, 0.5}, {-0.5, 0.5, -0.5}, {-0.5, -0.5, -0.5}},

		// TOP
		{{-0.5, 0.5, -0.5}, {-0.5, 0.5, 0.5}, {0.5, 0.5, 0.5}},
		{{-0.5, 0.5, -0.5}, {0.5, 0.5, 0.5}, {0.5, 0.5, -0.5}},

		// BOTTOM
		{{0.5, -0.5, 0.5}, {-0.5, -0.5, 0.5}, {-0.5, -0.5, -0.5}},
		{{0.5, -0.5, 0.5}, {-0.5, -0.5, -0.5}, {0.5, -0.5, -0.5}}    };    std::cout << 360/deg << std::endl;    std::cout << numofTris << std::endl;    for(int i=0; i<360/deg; i++) {        for(int tri=0; tri<numofTris; tri++) {            for(int point=0; point<3; point++) {                double temporary = SCALING_FACTOR*(triangles[tri][point][2]+1.5);                std::cout << triangles[tri][point][0]/temporary << std::endl << -triangles[tri][point][1]/temporary << std::endl;            }        }        for(int a=0; a<numofTris; a++) {            double x, y, z;            for(int pt=0; pt<3; pt++) {                x = triangles[a][pt][0];                y = triangles[a][pt][1];                z = triangles[a][pt][2];                //rotation about x-axis                y = (y*cos((deg*M_PI)/180)) - (z*sin((deg*M_PI)/180));                z = (z*cos((deg*M_PI)/180)) + (y*sin((deg*M_PI)/180));                //rotation about y-axis                z = (z*cos((deg*M_PI)/180)) - (x*sin((deg*M_PI)/180));                x = (x*cos((deg*M_PI)/180)) + (z*sin((deg*M_PI)/180));                //rotation about z-axis                x = (x*cos((deg*M_PI)/180)) - (y*sin((deg*M_PI)/180));                y = (y*cos((deg*M_PI)/180)) + (x*sin((deg*M_PI)/180));                triangles[a][pt][0] = x;                triangles[a][pt][1] = y;                triangles[a][pt][2] = z;            }        }    }}