#include "FakeApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
FakeApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

FakeApp::FakeApp(InputParameters parameters) : MooseApp(parameters)
{
  FakeApp::registerAll(_factory, _action_factory, _syntax);
}

FakeApp::~FakeApp() {}

void
FakeApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"FakeApp"});
  Registry::registerActionsTo(af, {"FakeApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
FakeApp::registerApps()
{
  registerApp(FakeApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
FakeApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  FakeApp::registerAll(f, af, s);
}
extern "C" void
FakeApp__registerApps()
{
  FakeApp::registerApps();
}
