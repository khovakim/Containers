#ifndef  __VECTOR_H__
# define __VECTOR_H__

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

		private:

	};
} // namespace cpp




#endif // __VECTOR_H__