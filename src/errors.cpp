/****************************************************************************
**
** This file is part of the Ponder library, formerly CAMP.
**
** The MIT License (MIT)
**
** Copyright (C) 2009-2014 TEGESO/TEGESOFT and/or its subsidiary(-ies) and mother company.
** Copyright (C) 2015-2016 Billy Quith.
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
** 
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
** 
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
** THE SOFTWARE.
**
****************************************************************************/


#include <ponder/errors.hpp>
#include <ponder/class.hpp>
#include <ponder/detail/util.hpp>


namespace ponder
{
    
BadType::BadType(ValueType provided, ValueType expected)
    : Error("value of type " + typeName(provided) + 
            " couldn't be converted to type " + typeName(expected))
{
}

BadType::BadType(IdRef message)
    : Error(message)
{
}

ponder::String BadType::typeName(ValueType type)
{
    return detail::typeAsString(type);
}

BadArgument::BadArgument(ValueType provided,
                         ValueType expected,
                         std::size_t index,
                         IdRef functionName)
    : BadType("the argument #" + str(index) + " of function " + functionName +
              " couldn't be converted from type " + typeName(provided) + " to type "
              + typeName(expected))
{
}

ClassAlreadyCreated::ClassAlreadyCreated(IdRef type)
    : Error("class named " + type + " already exists")
{
}

ClassNotFound::ClassNotFound(IdRef name)
    : Error("the metaclass " + name + " couldn't be found")
{
}

ClassUnrelated::ClassUnrelated(IdRef sourceClass, IdRef requestedClass)
    : Error("failed to convert from " + sourceClass + " to " + requestedClass + 
            ": it is not a base nor a derived")
{
}

EnumAlreadyCreated::EnumAlreadyCreated(IdRef typeId)
    : Error("enum named " + typeId + " already exists")
{
}

EnumNameNotFound::EnumNameNotFound(IdRef name, IdRef enumName)
    : Error("the value " + name + " couldn't be found in metaenum " + enumName)
{
}

EnumNotFound::EnumNotFound(IdRef name)
    : Error("the metaenum " + name + " couldn't be found")
{
}

EnumValueNotFound::EnumValueNotFound(long value, IdRef enumName)
    : Error("the value " + str(value) + " couldn't be found in metaenum " + enumName)
{
}

ForbiddenCall::ForbiddenCall(IdRef functionName)
    : Error("the function " + functionName + " is not callable")
{
}

ForbiddenRead::ForbiddenRead(IdRef propertyName)
    : Error("the property " + propertyName + " is not readable")
{
}

ForbiddenWrite::ForbiddenWrite(IdRef propertyName)
    : Error("the property " + propertyName + " is not writable")
{
}

FunctionNotFound::FunctionNotFound(IdRef name, IdRef className)
    : Error("the function " + name + " couldn't be found in metaclass " + className)
{
}

NotEnoughArguments::NotEnoughArguments(IdRef functionName,
                                       std::size_t provided,
                                       std::size_t expected)
    : Error("not enough arguments for calling " + functionName + " - provided " + 
            str(provided) + ", expected " + str(expected))
{
}

NullObject::NullObject(const Class* objectClass)
    : Error("trying to use a null metaobject of class " + 
            (objectClass ? objectClass->name() : "unknown"))
{
}

OutOfRange::OutOfRange(std::size_t index, std::size_t size)
    : Error("the index (" + str(index) + ") is out of the allowed range [0, "
            + str(size - 1) + "]")
{
}

PropertyNotFound::PropertyNotFound(IdRef name, IdRef className)
    : Error("the property " + name + " couldn't be found in metaclass " + className)
{
}

} // namespace ponder
