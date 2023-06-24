#pragma once

namespace mcore {

    template<typename T>
    class Matrix4x4
    {
    public:
        Matrix4x4()
        {
            for (size_t i = 0; i < 16; ++i)
            {
                mValues[i] = static_cast<T>(0);
            }
        }

        static Matrix4x4 identity()
        {
            Matrix4x4 result;
            for (size_t i = 0; i < 16; ++i)
            {
                if (i % 5 == 0)
                    result.mValues[i] = static_cast<T>(1);
                else
                    result.mValues[i] = static_cast<T>(0);
            }
            return result;
        }

        Matrix4x4 operator+(const Matrix4x4& other) const
        {
            Matrix4x4 result;
            for (size_t i = 0; i < 16; ++i)
            {
                result.mValues[i] = mValues[i] + other.mValues[i];
            }
            return result;
        }

        Matrix4x4 operator-(const Matrix4x4& other) const
        {
            Matrix4x4 result;
            for (size_t i = 0; i < 16; ++i)
            {
                result.mValues[i] = mValues[i] - other.mValues[i];
            }
            return result;
        }

        Matrix4x4 operator*(const Matrix4x4& other) const
        {
            Matrix4x4 result;
            for (size_t row = 0; row < 4; ++row)
            {
                for (size_t col = 0; col < 4; ++col)
                {
                    T sum = static_cast<T>(0);
                    for (size_t i = 0; i < 4; ++i)
                    {
                        sum += mValues[row * 4 + i] * other.mValues[i * 4 + col];
                    }
                    result.mValues[row * 4 + col] = sum;
                }
            }
            return result;
        }

        Matrix4x4 operator/(const Matrix4x4& other) const
        {
            Matrix4x4 result;
            for (size_t i = 0; i < 16; ++i)
            {
                if (other.mValues[i] != static_cast<T>(0))
                {
                    result.mValues[i] = mValues[i] / other.mValues[i];
                }
                else
                {
                    result.mValues[i] = static_cast<T>(0);
                }
            }
            return result;
        }

        Matrix4x4& operator=(const Matrix4x4& other)
        {
            if (this != &other)
            {
                for (size_t i = 0; i < 16; ++i)
                {
                    mValues[i] = other.mValues[i];
                }
            }
            return *this;
        }

        bool operator==(const Matrix4x4& other) const
        {
            for (size_t i = 0; i < 16; ++i)
            {
                if (mValues[i] != other.mValues[i])
                    return false;
            }
            return true;
        }

        bool operator!=(const Matrix4x4& other) const
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

    private:
        T mValues[16];
    };

}   // namespace mcore
