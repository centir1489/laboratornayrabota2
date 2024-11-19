#pragma once
#include"My_Include/General/Massiv.h"
#include<ostream>
#include<cstdint>

Massiv<Massiv<int16_t>> AllSubMass(Massiv<int16_t> mass);
Massiv<Massiv<int16_t>> CorrectSubMass(Massiv<int16_t> mass, int16_t purpose);
std::ostream& operator<<(std::ostream& os, Massiv<Massiv<int16_t>> Mass);