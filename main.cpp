// Least squares conformal mapping
//
// Author   : Mi, Liang
// Email    : icemiliang@gmail.com
// Date     : July 31st 2020
// License  : MIT

#include <cmath>
#include "Mesh.h"
#include "FormTrait.h"
#include "LSCM.h"
#include <iostream>
#include <chrono>


using namespace MeshLib;

int main(int argc, char * argv[]) {


    // 创建计时器
    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();



	std::cout << "--> Reading mesh..." << std::endl;
	Mesh mesh;
	mesh.read_obj(argv[1]);

	FormTrait traits(&mesh);

	std::cout << "--> Computing conformal map..." << std::endl;
	LSCM lscm(&mesh);
    lscm.project();

	std::cout << "--> Writing mesh..." << std::endl;
	mesh.write_obj(argv[2]);


    // 计算函数执行时间
    std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;
    std::cout << "Function execution time: " << duration.count() << " seconds" << std::endl;
	
	return 0;
}
