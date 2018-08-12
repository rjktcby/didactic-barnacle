#include "ParameterDefs.h"

#include <memory>
#include <array>
#include <string>
#include <iostream>

void ParameterDef::RegisterAllDefs()
{
    std::array<std::unique_ptr<ParameterDef>, 3> all_defs(
        {std::make_unique<IntParameterDef>(),
         std::make_unique<DoubleParameterDef>(),
         std::make_unique<StringParameterDef>()});

    StringParameterDef name_def;
    for (auto &def : all_defs)
    {
        std::string step_def = "^I set " + name_def.regexp + " to " + def->regexp + "$";
        std::cout << "Registering step definition: " << step_def << std::endl;
    }
}