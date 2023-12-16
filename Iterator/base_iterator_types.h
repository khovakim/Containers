#ifndef  __BASE_ITERATOR_TYPES_H__
# define __BASE_ITERATOR_TYPES_H__

namespace cp
{
	/*======================================================*/
	/*                     Category tag                     */
	/*======================================================*/

	//	Marking input iterators.
	struct input_iterator_tag {	};

	//	Marking output iterators.
	struct output_iterator_tag {	};

	//	Forward iterators support a superset of
	//	input iterator operations.
	struct forward_iterator_tag : public input_iterator_tag {	};

	//	Bidirectional iterators support a superset of
	//	forward iterator operations.
	struct bidirectional_iterator_tag : public forward_iterator_tag {	};

	//	Random-access iterators support a superset of
	//	bidirectional iterator operations.
	struct random_access_iterator_tag : public bidirectional_iterator_tag {	};

	/*======================================================*/
	/*                       Iterator                       */
	/*======================================================*/

	/**
	 *	@brief Common %iterator class.
	 *
	 *	This class does nothing but define nested typedefs.
	 *	%Iterator classes can inherit from this class to save some work.
	 *	The typedefs are then used in specializations overloading.
	 *
	 *	In particular, tere are no default implementations of requirements
	 *	such as, @c operator++ and the like.
	 *	(How could there be?)
	*/
	template <
		typename Category,
		typename T,
		typename Distance  = std::ptrdiff_t,
		typename Pointer   = T*,
		typename Reference = T&
		> struct iterator
		{
			typedef Category  iterator_category;
			typedef T         value_type;
			typedef Distance  difference_type;
			typedef Pointer   pointer;
			typedef Reference reference;
		};

	/*======================================================*/
	/*                    Iterator_traits                   */
	/*======================================================*/

	/**
	 *	@brief  Traits class for iterators.
	 *
	 *	This class does nothing but define nested typedefs.
	 *	The general version simply @a forwards the nested
	 *	typedefs from the Iterator argument.
	 *	Specialized versions for pointers and pointers-to-const
	 *	provide tighter, more correct semantics.
	*/
	template <typename Iterator>
		struct iterator_traits
		{
			typedef typename Iterator::iterator_category iterator_category;
			typedef typename Iterator::value_type        value_type;
			typedef typename Iterator::difference_type   difference_type;
			typedef typename Iterator::pointer           pointer;
			typedef typename Iterator::reference         reference;
		};

	template <typename T>
		struct iterator_traits<T*>
		{
			typedef random_access_iterator_tag iterator_category;
			typedef T                          value_type;
			typedef std::ptrdiff_t             difference_type;
			typedef T*                         pointer;
			typedef T&                         reference;
		};

	template <typename T>
		struct iterator_traits<const T*>
		{
			typedef random_access_iterator_tag iterator_category;
			typedef T                          value_type;
			typedef std::ptrdiff_t             difference_type;
			typedef const T*                   pointer;
			typedef const T&                   reference;
		};
} // namespace cp

#endif //__BASE_ITERATOR_TYPES_H__