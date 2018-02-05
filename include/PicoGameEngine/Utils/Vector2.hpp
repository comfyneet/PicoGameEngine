#ifndef PGE_UTILS_VECTOR2_HPP
#define PGE_UTILS_VECTOR2_HPP

#include <cstdint>

namespace pge
{
    template <typename T>
    struct Vector2
    {
        Vector2() :
            x{},
            y{}
        {
        }

        Vector2(T x, T y) :
            x{x},
            y{y}
        {
        }

        Vector2(const Vector2& vector) :
            x{vector.x},
            y{vector.y}
        {
        }

        template <typename U>
        explicit Vector2(const Vector2<U>& vector) :
            x{static_cast<T>(vector.x)},
            y{static_cast<T>(vector.y)}
        {
        }

        Vector2(Vector2&&) = delete;

        Vector2& operator=(const Vector2&) = delete;

        Vector2& operator=(Vector2&&) = delete;

        virtual ~Vector2() = default;

        union
        {
            struct
            {
                T x;
                T y;
            };

            struct
            {
                T width;
                T height;
            };
        };
    };

    template <typename T>
    Vector2<T> operator +(const Vector2<T>& left, const Vector2<T>& right)
    {
        return Vector2<T>(left.x + right.x, left.y + right.y);
    }

    template <typename T>
    Vector2<T> operator -(const Vector2<T>& left, const Vector2<T>& right)
    {
        return Vector2<T>(left.x - right.x, left.y - right.y);
    }

    template <typename T>
    Vector2<T> operator *(const Vector2<T>& left, const Vector2<T>& right)
    {
        return Vector2<T>(left.x * right.x, left.y * right.y);
    }

    template <typename T>
    Vector2<T> operator /(const Vector2<T>& left, const Vector2<T>& right)
    {
        return Vector2<T>(left.x / right.x, left.y / right.y);
    }

    template <typename T>
    bool operator ==(const Vector2<T>& left, const Vector2<T>& right)
    {
        return left.x == right.x && left.y == right.y;
    }

    template <typename T>
    bool operator !=(const Vector2<T>& left, const Vector2<T>& right)
    {
        return !(operator ==(left, right));
    }

    typedef Vector2<int32_t> Vector2I;
    typedef Vector2<uint32_t> Vector2U;
}

#endif
