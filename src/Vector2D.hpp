#ifndef VECTOR_2D_HPP
#define VECTOR_2D_HPP

class Vector2D {
    public:
    int x = 0;
    int y = 0;
    void setPossition(int x, int y);
    bool isEqual(Vector2D vec);
};

#endif
