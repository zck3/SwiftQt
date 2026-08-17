/*=========================================================================
 * This file is part of SwiftQt.
 * (C) 2023 Zack T Smith.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * The author may be reached at 3 at zs3 dot me.
 *=======================================================================*/

#include <stdio.h>

#include "CShim.h"

SQPoint SQPoint_new (SQCoord x, SQCoord y)
{
	SQPoint point;
	point.x = x;
	point.y = y;
	return point;
}

SQPoint SQPoint_zero ()
{
	SQPoint point = {0, 0};
	return point;
}

void SQPoint_print(SQPoint point)
{
	printf ("%ldx%ld", point.x, point.y);
}

SQSize SQSize_new (SQCoord width, SQCoord height)
{
	SQSize size;
	size.width = width;
	size.height = height;
	return size;
}

SQSize SQSize_zero ()
{
	SQSize size = {0, 0};
	return size;
}

void SQSize_print(SQSize size)
{
	printf ("%ldx%ld", size.width, size.height);
}

bool SQSize_equals (SQSize first, SQSize second)
{
	return first.width == second.width && first.height == second.height;
}

void SQRect_print(SQRect rect)
{
	printf ("(%ld,%ld %ldx%ld)", rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
}

SQRect SQRect_zero ()
{
	SQRect rect = { {0, 0}, {0, 0} };
	return rect;
}

SQRect SQRect_new (SQCoord x, SQCoord y, SQCoord width, SQCoord height)
{
	SQRect rect;
	rect.origin.x = x;
	rect.origin.y = y;
	rect.size.width = width;
	rect.size.height = height;
	return rect;
}

bool SQRect_containsPoint (SQRect rect, SQCoord x, SQCoord y)
{
	SQCoord x0 = rect.origin.x;
	SQCoord y0 = rect.origin.y;
	if (x < x0 || y < y0) {
		return false;
	}
	SQCoord xlimit = x0 + rect.size.width;
	SQCoord ylimit = y0 + rect.size.height;
	if (x >= xlimit || y >= ylimit) {
		return false;
	}
	return true;
}

bool SQRect_equals (SQRect first, SQRect second)
{
	return first.size.width == second.size.width 
		&& first.size.height == second.size.height 
		&& first.origin.x == second.origin.x
		&& first.origin.y == second.origin.y;
}

//===========

const char *SQReleaseName(void) {
	return kKitName;
}

const char *SQReleaseString(void) {
	return kKitRelease;
}

long SQReleaseMajor() {
	return kKitReleaseMajor;
}

long SQReleaseMinor() {
	return kKitReleaseMinor;
}

