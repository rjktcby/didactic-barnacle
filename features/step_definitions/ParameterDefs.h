#pragma once

#include <string>

struct ParameterDef
{
    std::string regexp;
    ParameterDef(const std::string &_regexp) : regexp(_regexp){};
    virtual ~ParameterDef(){};

    static void RegisterAllDefs();
};

struct IntParameterDef : public ParameterDef
{
    IntParameterDef() : ParameterDef("(\\d+)") {}
};

struct DoubleParameterDef : public ParameterDef
{
    DoubleParameterDef() : ParameterDef("(.*)") {}
};

struct StringParameterDef : public ParameterDef
{
    StringParameterDef() : ParameterDef("\"([^\"]*)\"") {}
};
