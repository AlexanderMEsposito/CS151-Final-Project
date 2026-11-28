#pragma once

#include "objectData.h"
#include <string_view>

namespace ObjectTemplates
{

    constexpr ObjectData tree {
        {200.0f, 200.0f},
        "objects/tree.png",
        0
    };

    constexpr ObjectData landmine {
        {50.0f, 50.0f},
        "objects/landmine.png",
        1
    };

};

