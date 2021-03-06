//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "FakeTestApp.h"
#include "FakeApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
FakeTestApp::validParams()
{
  InputParameters params = FakeApp::validParams();
  return params;
}

FakeTestApp::FakeTestApp(InputParameters parameters) : MooseApp(parameters)
{
  FakeTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

FakeTestApp::~FakeTestApp() {}

void
FakeTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  FakeApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"FakeTestApp"});
    Registry::registerActionsTo(af, {"FakeTestApp"});
  }
}

void
FakeTestApp::registerApps()
{
  registerApp(FakeApp);
  registerApp(FakeTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
FakeTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  FakeTestApp::registerAll(f, af, s);
}
extern "C" void
FakeTestApp__registerApps()
{
  FakeTestApp::registerApps();
}
