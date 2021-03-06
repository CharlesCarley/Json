/*
-------------------------------------------------------------------------------
    Copyright (c) Charles Carley.

  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------------
*/
#ifndef _skJsonInteger_h_
#define _skJsonInteger_h_

#include "skJsonType.h"

/// \ingroup Json
class skJsonInteger final : public skJsonType
{
private:

    typedef union Integer
    {
        SKint16 i16[4];
        SKint32 i32[2];
        SKint64 i64;
        SKuint16 u16[4];
        SKuint32 u32[2];
        SKuint64 u64;
    } Integer;


    Integer m_integer;

    void notifyStringChanged() override
    {
        m_integer.i64 = m_value.toInt64();
    }

    void notifyValueChanged() override
    {
        skChar::toString(m_value, m_integer.i64);
    }

public:

    skJsonInteger() :
        skJsonType(Type::INTEGER),
        m_integer({})
    {
    }

    skJsonInteger(const SKint64& val) :
        skJsonType(Type::INTEGER),
        m_integer({})
    {
        m_integer.i64 = val;
        notifyValueChanged();
    }

    void toString(skStringBuilder& dest) override
    {
        dest.write(m_integer.i64);
    }
};

#endif  //_skJsonInteger_h_
