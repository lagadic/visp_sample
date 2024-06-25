/****************************************************************************
 *
 * ViSP, open source Visual Servoing Platform software.
 * Copyright (C) 2005 - 2019 by Inria. All rights reserved.
 *
 * This software is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * See the file LICENSE.txt at the root directory of this source
 * distribution for additional information about the GNU GPL.
 *
 * For using ViSP with software that can not be combined with the GNU
 * GPL, please contact Inria about acquiring a ViSP Professional
 * Edition License.
 *
 * See http://visp.inria.fr for more information.
 *
 * This software was developed at:
 * Inria Rennes - Bretagne Atlantique
 * Campus Universitaire de Beaulieu
 * 35042 Rennes Cedex
 * France
 *
 * If you have questions regarding the use of this file, please contact
 * Inria at visp@inria.fr
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Description:
 * Test force/torque IIT sensor.
 *
 * Authors:
 * Fabien Spindler
 *
 *****************************************************************************/

/*!
  \example testForceTorqueIitSensor.cpp
  This example shows how to retrieve data from an IIT F/T sensor connected to
  a computer by Ethernet.
*/

#include <iostream>

#include <visp3/sensor/vpForceTorqueIitSensor.h>
#include <visp3/core/vpTime.h>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
#ifdef VISP_HAVE_FT_IIT_SDK
  vpForceTorqueIitSensor iit_ft;

  if (!iit_ft.connected()) {
    std::cout << "Unable to connect to IIT force-torque sensor" << std::endl;
    return EXIT_SUCCESS;
  }

  iit_ft.bias();
  iit_ft.startStreaming();
  vpColVector ft;
  for (int i = 0; i < 10; i++) {
    ft = iit_ft.getForceTorque();
    std::cout << ft.t() << std::endl;
    vpTime::sleepMs(1000);
  }
  iit_ft.stopStreaming();
#else
  std::cout << "ViSP is not build with IIT force-torque SDK support" << std::endl;
#endif
  return EXIT_SUCCESS;
}
