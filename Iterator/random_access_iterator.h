#ifndef  __RANDOM_ACCESS_ITERATOR_H__
# define __RANDOM_ACCESS_ITERATOR_H__

# include "base_iterator_types.h"
# include "base_iterator_funcs.h"

namespace cp
{
	template <typename T>
		class random_access_iterator : public iterator<random_access_iterator_tag, T>
		{
			public:
				using iterator_type     = iterator<random_access_iterator_tag, T>;

				using pointer           = typename iterator_type::pointer;
				using reference         = typename iterator_type::reference;
				using value_type        = typename iterator_type::value_type;
				using difference_type   = typename iterator_type::difference_type;
				using iterator_category = typename iterator_type::iterator_category;

			public:
				constexpr          random_access_iterator() noexcept                                    : mptr(nullptr)    { }
				explicit constexpr random_access_iterator(pointer ptr) noexcept                         : mptr(ptr)        { }
				constexpr          random_access_iterator(const random_access_iterator& other) noexcept : mptr(other.mptr) { }

				virtual ~random_access_iterator() { }

				operator random_access_iterator<const T>() const
				{ return static_cast<random_access_iterator<const T>>(this->mptr); }

				constexpr random_access_iterator& operator=(const random_access_iterator& other) noexcept;

			public:
				constexpr pointer base() const noexcept { return this->mptr; }

			public:
				constexpr reference operator*()  const noexcept { return *mptr; }
				constexpr pointer   operator->() const noexcept { return mptr;  }

			public:
				constexpr random_access_iterator& operator++()    noexcept;
				constexpr random_access_iterator& operator--()    noexcept;
				constexpr random_access_iterator  operator++(int) noexcept;
				constexpr random_access_iterator  operator--(int) noexcept;

				constexpr random_access_iterator  operator+(difference_type diff)  const noexcept;
				constexpr random_access_iterator  operator-(difference_type diff)  const noexcept;
				constexpr random_access_iterator& operator+=(difference_type diff)       noexcept;
				constexpr random_access_iterator& operator-=(difference_type diff)       noexcept;

				constexpr difference_type operator-(const random_access_iterator& rhs) const noexcept
				{ return mptr - rhs.mptr; }

				constexpr const reference operator[](difference_type diff) const noexcept { return *(mptr + diff); }
				constexpr       reference operator[](difference_type diff)       noexcept;

			public:
				constexpr bool operator==(const random_access_iterator& rhs) const noexcept { return mptr == rhs.mptr; }
				constexpr bool operator!=(const random_access_iterator& rhs) const noexcept { return mptr != rhs.mptr; }

				constexpr bool operator>(const random_access_iterator& rhs)  const noexcept { return mptr > rhs.mptr; }
				constexpr bool operator<(const random_access_iterator& rhs)  const noexcept { return mptr < rhs.mptr; }

				constexpr bool operator>=(const random_access_iterator& rhs) const noexcept { return mptr >= rhs.mptr; }
				constexpr bool operator<=(const random_access_iterator& rhs) const noexcept { return mptr <= rhs.mptr; }

			private:
				pointer mptr;
		};

		template <typename T>
			constexpr random_access_iterator<T>&
			random_access_iterator<T>::operator=(const random_access_iterator<T>& other) noexcept
			{
				if (this == &other) {
					return *this;
				}

				this->mptr = other.mptr;
				return *this;
			}

		template <typename T>
			constexpr random_access_iterator<T>&
			random_access_iterator<T>::operator++() noexcept
			{
				++mptr;
				return *this;
			}

		template <typename T>
			constexpr random_access_iterator<T>&
			random_access_iterator<T>::operator--() noexcept
			{
				--mptr;
				return *this;
			}

		template <typename T>
			constexpr random_access_iterator<T>
			random_access_iterator<T>::operator++(int) noexcept
			{
				random_access_iterator<T> tmp(*this);
				++mptr;
				return tmp;
			}

		template <typename T>
			constexpr random_access_iterator<T>
			random_access_iterator<T>::operator--(int) noexcept
			{
				random_access_iterator<T> tmp(*this);
				--mptr;
				return tmp;
			}

			template <typename T>
				constexpr random_access_iterator<T>
				random_access_iterator<T>::operator+(difference_type diff) const noexcept
				{
					random_access_iterator<T> tmp(*this);
					tmp.mptr += diff;
					return tmp;
				}

			template <typename T>
				constexpr random_access_iterator<T>
				random_access_iterator<T>::operator-(difference_type diff) const noexcept
				{
					random_access_iterator<T> tmp(*this);
					tmp.mptr -= diff;
					return tmp;
				}

			template <typename T>
				constexpr random_access_iterator<T>&
				random_access_iterator<T>::operator+=(difference_type diff) noexcept
				{
					mptr += diff;
					return *this;
				}

			template <typename T>
				constexpr random_access_iterator<T>&
				random_access_iterator<T>::operator-=(difference_type diff) noexcept
				{
					mptr -= diff;
					return *this;
				}

			template <typename T>
				constexpr typename random_access_iterator<T>::reference
				random_access_iterator<T>::operator[](difference_type diff) noexcept
				{
					return const_cast<reference>(
						static_cast<const random_access_iterator<T>&>(*this)[diff]
					);
				}

// ----------------------------------------------------------------------------

			template <typename T>
				constexpr random_access_iterator<T>
				operator+(typename random_access_iterator<T>::difference_type diff,\
							const random_access_iterator<T>& rhs)
				{ return rhs + diff; }

			template <typename T_L, typename T_R>
				constexpr typename random_access_iterator<T_L>::difference_type
				operator-(const random_access_iterator<T_L>& lhs, const random_access_iterator<T_R>& rhs)
				{ return lhs.base() - rhs.base(); }

			template <typename T_L, typename T_R>
				constexpr bool
				operator==(const random_access_iterator<T_L>& lhs, const random_access_iterator<T_R>& rhs)
				{ return lhs.base() == rhs.base(); }

			template <typename T_L, typename T_R>
				constexpr bool
				operator!=(const random_access_iterator<T_L>& lhs, const random_access_iterator<T_R>& rhs)
				{ return lhs.base() != rhs.base(); }

			template <typename T_L, typename T_R>
				constexpr bool
				operator>(const random_access_iterator<T_L>& lhs, const random_access_iterator<T_R>& rhs)
				{ return lhs.base() > rhs.base(); }

			template <typename T_L, typename T_R>
				constexpr bool
				operator>=(const random_access_iterator<T_L>& lhs, const random_access_iterator<T_R>& rhs)
				{ return lhs.base() >= rhs.base(); }

			template <typename T_L, typename T_R>
				constexpr bool
				operator<(const random_access_iterator<T_L>& lhs, const random_access_iterator<T_R>& rhs)
				{ return lhs.base() < rhs.base(); }

			template <typename T_L, typename T_R>
				constexpr bool
				operator<=(const random_access_iterator<T_L>& lhs, const random_access_iterator<T_R>& rhs)
				{ return lhs.base() <= rhs.base(); }

} // namespace cp

#endif 