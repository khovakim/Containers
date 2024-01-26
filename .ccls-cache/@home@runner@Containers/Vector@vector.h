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
				using value_type             = T;

				using pointer                = T*;
				using reference              = T&;

				using const_pointer          = const pointer;
				using const_reference        = const reference;

				using size_type              = std::size_t;
				using difference_type        = std::ptrdiff_t;

				using iterator               = cp::random_access_iterator<value_type>;
				using const_iterator         = cp::random_access_iterator<const value_type>;

				using reverse_iterator       = cp::reverse_iterator<iterator>;
				using consr_reverse_iterator = cp::reverse_iterator<const_iterator>;
	
			public:
				constexpr          vector() noexcept;
  			explicit constexpr vector(size_type count);
				// constexpr          vector(size_type count, const T& value);
				explicit           vector(size_type count, const T& value = T());
				constexpr          vector(const vector& other);
				constexpr          vector(vector&& other)                noexcept;
				constexpr          vector(std::initializer_list<T> init) noexcept;

				~vector();

				constexpr vector& operator=(const vector& other);
				constexpr vector& operator=(vector&& other) noexcept;
				constexpr vector& operator=(std::initializer_list<T> init);

			public:
				constexpr iterator               begin()         noexcept;
				constexpr const_iterator         cbegin()  const noexcept;

				constexpr iterator               end()           noexcept;
				constexpr const_iterator         cend()    const noexcept;
	
				constexpr reverse_iterator       rbegin()        noexcept;
				constexpr consr_reverse_iterator crbegin() const noexcept;

				constexpr reverse_iterator       rend()          noexcept;
				constexpr consr_reverse_iterator crend()   const noexcept;

			private:
				size_type msize;
				size_type mcapacity;
				pointer   marr;
		};
} // namespace cp




#endif // __VECTOR_H__