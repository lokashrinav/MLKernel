#include <arm_neon.h>
#include <iostream>

void add_neon(float* a, float* b, float* result, size_t size) {
    for (size_t i = 0; i < size; i += 4) {
        float32x4_t va = vld1q_f32(&a[i]);   
        float32x4_t vb = vld1q_f32(&b[i]);  
        float32x4_t vr = vaddq_f32(va, vb);  
        vst1q_f32(&result[i], vr);           
    }
}

int main() {
    const size_t size = 8;
    float a[size] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    float b[size] = { 2, 3, 4, 5, 6, 7, 8, 9 };
    float result[size];

    add_neon(a, b, result, size);

    for (size_t i = 0; i < size; i++) {
        std::cout << result[i] << " ";  
    }
    std::cout << std::endl;

    return 0;
}
