#pragma once

#include <cmath>

#include "math/vector.hpp"
#include "math/matrix.hpp"

namespace mcore {

    // Convert degrees to radians
    template<typename T>
    T toRadians(T degrees)
    {
        return degrees * static_cast<T>(0.017453292519943295);  // pi/180
    }

    // Create a translation matrix
    template<typename T>
    void translate(Matrix4x4<T>& matrix, const Vector<T, 3>& translation)
    {
        matrix[12] += translation[0];
        matrix[13] += translation[1];
        matrix[14] += translation[2];
    }

    // Create a rotation matrix around the X axis
    template<typename T>
    void rotateX(Matrix4x4<T>& matrix, T angleDegrees)
    {
        T angleRadians = toRadians(angleDegrees);
        T cosTheta = std::cos(angleRadians);
        T sinTheta = std::sin(angleRadians);

        matrix = Matrix4x4<T>::identity();
        matrix[5] = cosTheta;
        matrix[6] = -sinTheta;
        matrix[9] = sinTheta;
        matrix[10] = cosTheta;
    }

    // Create a rotation matrix around the Y axis
    template<typename T>
    void rotateY(Matrix4x4<T>& matrix, T angleDegrees)
    {
        T angleRadians = toRadians(angleDegrees);
        T cosTheta = std::cos(angleRadians);
        T sinTheta = std::sin(angleRadians);

        matrix = Matrix4x4<T>::identity();
        matrix[0] = cosTheta;
        matrix[2] = sinTheta;
        matrix[8] = -sinTheta;
        matrix[10] = cosTheta;
    }

    // Create a rotation matrix around the Z axis
    template<typename T>
    void rotateZ(Matrix4x4<T>& matrix, T angleDegrees)
    {
        T angleRadians = toRadians(angleDegrees);
        T cosTheta = std::cos(angleRadians);
        T sinTheta = std::sin(angleRadians);

        matrix = Matrix4x4<T>::identity();
        matrix[0] = cosTheta;
        matrix[1] = -sinTheta;
        matrix[4] = sinTheta;
        matrix[5] = cosTheta;
    }

    // Create a scaling matrix
    template<typename T>
    void scale(Matrix4x4<T>& matrix, const Vector<T, 3>& scale)
    {
        matrix = Matrix4x4<T>::identity();
        matrix[0] = scale[0];
        matrix[5] = scale[1];
        matrix[10] = scale[2];
    }

    

}  // namespace mcore
