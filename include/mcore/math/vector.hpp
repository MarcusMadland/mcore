#pragma once

#include <array>

namespace mcore
{

template <typename T, uint32_t N>
class Vector
{
public:
    Vector()
    {
        mValues.fill(static_cast<T>(0)); 
    }

    Vector(std::initializer_list<T> values)
    {
        size_t index = 0;
        for (const auto& value : values)
        {
            mValues[index++] = value;
            if (index >= N)
                break;
        }
    }

    Vector(const float* values)
    {
        for (uint32_t i = 0; i < N; i++)
        {
            mValues[i] = values[i];
        }
    }

    Vector operator+(const Vector& other) const
    {
        Vector result;
        for (size_t i = 0; i < N; ++i)
        {
            result[i] = mValues[i] + other[i];
        }
        return result;
    }

    Vector operator-(const Vector& other) const
    {
        Vector result;
        for (size_t i = 0; i < N; ++i)
        {
            result[i] = mValues[i] - other[i];
        }
        return result;
    }

    Vector operator*(const T& scalar) const
    {
        Vector result;
        for (size_t i = 0; i < N; ++i)
        {
            result[i] = mValues[i] * scalar;
        }
        return result;
    }

    Vector operator/(const T& scalar) const
    {
        Vector result;
        for (size_t i = 0; i < N; ++i)
        {
            result[i] = mValues[i] / scalar;
        }
        return result;
    }

    Vector& operator=(const Vector& other)
    {
        if (this != &other)
        {
            mValues = other.mValues;
        }
        return *this;
    }

    Vector& operator+=(const Vector& other)
    {
        for (size_t i = 0; i < N; ++i)
        {
            mValues[i] += other[i];
        }
        return *this;
    }

    Vector& operator-=(const Vector& other)
    {
        for (size_t i = 0; i < N; ++i)
        {
            mValues[i] -= other[i];
        }
        return *this;
    }

    Vector operator-() const
    {
        std::array<T, N> result;
        for (size_t i = 0; i < N; ++i)
        {
            result[i] = -mValues[i];
        }
        return Vector(result);
    }

    bool operator==(const Vector& other) const
    {
        return mValues == other.mValues;
    }

    bool operator!=(const Vector& other) const
    {
        return !(*this == other);
    }

    T& operator[](size_t index)
    {
        return mValues[index];
    }

    const T& operator[](size_t index) const
    {
        return mValues[index];
    }

public:
	std::array<T, N> mValues;

public:
    struct ElementAccess
    {
        Vector<T, N>& vector;

        T& operator=(const T& value)
        {
            return vector[ElementAccess::index];
        }

        operator T& () const
        {
            return vector[ElementAccess::index];
        }

        static const size_t index = 0;
    };

    ElementAccess x = { *this };
    ElementAccess y = { *this };
    ElementAccess z = { *this };
    ElementAccess w = { *this };
};

}	// namespace core