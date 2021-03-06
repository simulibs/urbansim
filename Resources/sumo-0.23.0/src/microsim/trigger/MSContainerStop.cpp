/****************************************************************************/
/// @file    MSContainerStop.cpp
/// @author  Daniel Krajzewicz
/// @author  Michael Behrisch
/// @date    Mon, 13.12.2005
/// @version $Id: MSContainerStop.cpp 18096 2015-03-17 09:50:59Z behrisch $
///
// A lane area vehicles can halt at
/****************************************************************************/
// SUMO, Simulation of Urban MObility; see http://sumo.dlr.de/
// Copyright (C) 2005-2015 DLR (http://www.dlr.de/) and contributors
/****************************************************************************/
//
//   This file is part of SUMO.
//   SUMO is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
/****************************************************************************/


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include <cassert>
//#include "MSTrigger.h"
#include "MSContainerStop.h"
#include <utils/vehicle/SUMOVehicle.h>
#include <microsim/MSVehicleType.h>

#ifdef CHECK_MEMORY_LEAKS
#include <foreign/nvwa/debug_new.h>
#endif // CHECK_MEMORY_LEAKS


// ===========================================================================
// method definitions
// ===========================================================================
MSContainerStop::MSContainerStop(const std::string& id,
                                 const std::vector<std::string>& lines,
                                 MSLane& lane,
                                 SUMOReal begPos, SUMOReal endPos)
    : Named(id), myLines(lines), myLane(lane),
      myBegPos(begPos), myEndPos(endPos), myLastFreePos(endPos) {
    computeLastFreePos();
}


MSContainerStop::~MSContainerStop() {}


const MSLane&
MSContainerStop::getLane() const {
    return myLane;
}


SUMOReal
MSContainerStop::getBeginLanePosition() const {
    return myBegPos;
}


SUMOReal
MSContainerStop::getEndLanePosition() const {
    return myEndPos;
}


void
MSContainerStop::enter(SUMOVehicle* what, SUMOReal beg, SUMOReal end) {
    myEndPositions[what] = std::pair<SUMOReal, SUMOReal>(beg, end);
    computeLastFreePos();
}


SUMOReal
MSContainerStop::getLastFreePos(const SUMOVehicle& forVehicle) const {
    if (myLastFreePos != myEndPos) {
        return myLastFreePos - forVehicle.getVehicleType().getMinGap();
    }
    return myLastFreePos;
}


void
MSContainerStop::leaveFrom(SUMOVehicle* what) {
    assert(myEndPositions.find(what) != myEndPositions.end());
    myEndPositions.erase(myEndPositions.find(what));
    computeLastFreePos();
}


void
MSContainerStop::computeLastFreePos() {
    myLastFreePos = myEndPos;
    std::map<SUMOVehicle*, std::pair<SUMOReal, SUMOReal> >::iterator i;
    for (i = myEndPositions.begin(); i != myEndPositions.end(); i++) {
        if (myLastFreePos > (*i).second.second) {
            myLastFreePos = (*i).second.second;
        }
    }
}



/****************************************************************************/

