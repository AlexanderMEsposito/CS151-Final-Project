#pragma once

class Chunk
{

public:

    Chunk() {};
    Chunk(int u, int v);

    Chunk& initialize(int u, int v);

private:

    int u {0}, v {0};

    bool initialized {false};

    float corner_upper_left_x {0.0f};
    float corner_upper_left_y {0.0f};
    float corner_lower_right_x {0.0f};
    float corner_lower_right_y {0.0f};

};



