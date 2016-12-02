/*
 * translation.cpp
 *
 *  Created on: 27 nov. 2016
 *      Author: robert
 */
#include <iostream>
#include <eigen3/Eigen/Geometry>
#include <eigen3/Eigen/Dense>
#include <cmath>
using namespace std;

int main(){
	Eigen::Vector3d pO;
	Eigen::Vector3d mB;
	Eigen::Vector3d qS;
	Eigen::Vector3d qO;
	Eigen::Vector3d qB;
	double Omega_deg = 30;
	double Beta_deg = 25;
	double Omega_rad;
	double Beta_rad;
	pO << 50,25,1;
	mB << 1.5,0.75,1;
	qS << 12,5,1;
	Omega_rad = (M_PI/180)*Omega_deg;
	Beta_rad = (M_PI/180)*Beta_deg;

	Eigen::Matrix3d Tbs;
	Eigen::Matrix3d Tob;
	Eigen::Matrix3d Tos;

	Tbs(0,0)= cos(Beta_rad);
	Tbs(0,1)= -sin(Beta_rad);
	Tbs(0,2)=  mB[0];
	Tbs(1,0)= sin(Beta_rad);
	Tbs(1,1)= cos(Beta_rad);
	Tbs(1,2)= mB[1];
	Tbs(2,0)=0;
	Tbs(2,1)=0;
	Tbs(2,2)=1;

	Tob(0,0)= cos(Omega_rad);
	Tob(0,1)= -sin(Omega_rad);
	Tob(0,2)=  pO[0];
	Tob(1,0)= sin(Omega_rad);
	Tob(1,1)= cos(Omega_rad);
	Tob(1,2)= pO[1];
	Tob(2,0)=0;
	Tob(2,1)=0;
	Tob(2,2)=1;

	qB = Tbs*qS;
	qO = Tob*Tbs*qS;


	std::cout << "qB:\n" << qB << std::endl;
	std::cout << "qO:\n" << qO << std::endl;


	return 0;
}

