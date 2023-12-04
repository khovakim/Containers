#ifndef  __VECTOR_H__
# define __VECTOR_H__

# include <iterator>
# include <vector>


# include "../Iterator/iterator.h"


namespace cp
{
	template <typename T>
	class vector
	{
		public:
			using value_type      = T;
			using pointer         = T*;
			using reference       = T&;

			using const_pointer   = const pointer;
			using const_reference = const reference;

			using size_type       = std::size_t;
			using difference_type = std::ptrdiff_t;

			using iterator        = cp::random_access_iterator<value_type>;
			using const_iterator  = cp::random_access_iterator<const value_type>;

		public:
			constexpr          vector() noexcept;
			explicit constexpr vector(size_type count);
			constexpr          vector(size_type count, const reference value);
			explicit           vector(size_type count, const reference value = T());
			constexpr          vector(const vector& other);
			constexpr          vector(vector&& other)                noexcept;
			constexpr          vector(std::initializer_list<T> init) noexcept;

			~vector();

			constexpr vector& operator=(const vector& other);
			constexpr vector& operator=(vector&& other) noexcept;
			constexpr vector& operator=(std::initializer_list<T> init);

		public:
			

		private:
			size_type msize;
			size_type mcapacity;
			pointer   marr;
	};
} // namespace cpp




#endif // __VECTOR_H__