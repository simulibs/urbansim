function shapeClass = getShapeClass(vehID)
%getShapeClass
%   shapeClass = getShapeClass(VEHID) Returns the shape class of this 
%   vehicle.

%   Copyright 2015 Universidad Nacional de Colombia,
%   Politecnico Jaime Isaza Cadavid.
%   Authors: Andres Acosta, Jairo Espinosa, Jorge Espinosa.
%   $Id: getShapeClass.m 20 2015-03-02 16:52:32Z afacostag $

import traci.constants
shapeClass = traci.vehicle.getUniversal(constants.VAR_SHAPECLASS, vehID);