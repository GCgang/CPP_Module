#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

Base *Generate(void);
void Identify(Base *p);
void IdentifyPointer(Base *p, const std::string& type);
void Identify(Base &p);
void IdentifyReference(Base &p, const std::string type);
#endif