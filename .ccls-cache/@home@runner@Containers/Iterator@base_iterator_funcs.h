#ifndef  __BASE_ITERATOR_FUNCS_H__
# define __BASE_ITERATOR_FUNCS_H__

# include "base_iterator_types.h"

namespace cp
{
	/**
	 *	@brief 	A generalization of pointer arithmetic.
	 *	@param 	first An input iterator.
	 *	@param 	last An input iterator.
	 *	@return	The distance between them.
	*/
	template <typename InputIterator>
		inline constexpr
		typename iterator_traits<InputIterator>::difference_type
		distance(InputIterator first, InputIterator last)
		{
			typename iterator_traits<InputIterator>::difference_type distance = 0;

			while (first != last) {
				++distance;
				++first;
			}

			return distance;
		}





} // namespace cp


#endif // __BASE_ITERATOR_FUNCS_H__
