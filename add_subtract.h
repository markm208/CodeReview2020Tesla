//
//  add_subtract.hpp
//  add_subtract
//
//  Created by Brad Dodds on 3/5/20.
//  Copyright © 2020 Brad Dodds. All rights reserved.
//

#ifndef add_subtract_h
#define add_subtract_h

#include <stdio.h>
#pragma once

int improperFractionNumerator (int c1, int n1, int d1);
int commonDenom (int d1, int d2);
int moveDecimal(long numerator, int digitsLeft, int commonDenom);
bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);

#endif /* add_subtract_hpp */