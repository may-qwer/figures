#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2 {
    public:
        float x;
        float y;
    
        Vector2(float x, float y);
    
        Vector2(int val);
    
        float scalar_product_of_vectors_this_and_v2(Vector2 *v2);
    
        float len_of_vector2();
    
        void normalize();
    
        void sum(Vector2 *v2);
    
        void sum(float num);

        void prod(Vector2 *v2);

        void prod(float val);

        void divis(float val);

        void divis(int val);
    
    private:
    
    };


#endif