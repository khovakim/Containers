#ifndef  __REVERSE_ITERATOR_H__
# define __REVERSE_ITERATOR_H__

# include "base_iterator_types.h"

namespace cp
{
	template <typename Iter>
		class reverse_iterator
		{
			public:
				using iterator_type     = Iter;

				using pointer           = typename iterator_traits<Iter>::pointer;
				using reference         = typename iterator_traits<Iter>::reference;
				using value_type        = typename iterator_traits<Iter>::value_type;
				using difference_type   = typename iterator_traits<Iter>::difference_type;
				using iterator_category = typename iterator_traits<Iter>::iterator_category;

			public:
				constexpr          reverse_iterator()                   noexcept : miter{iterator_type()} { }
				constexpr explicit reverse_iterator(iterator_type iter) noexcept : miter{iter}            { }

				virtual   ~reverse_iterator() { }

				template <typename It>
					constexpr reverse_iterator(const reverse_iterator<It>& other) noexcept
						: miter{other.miter}
					{ }

				template <typename It>
					constexpr reverse_iterator& operator=(const reverse_iterator<It>& other) noexcept;
			public:
				constexpr iterator_type base() const noexcept { return miter; }

			public:
				constexpr reference operator*()  const noexcept;
				constexpr pointer   operator->() const noexcept;

			public:
				constexpr reverse_iterator& operator++()    noexcept;
				constexpr reverse_iterator  operator++(int) noexcept;

				constexpr reverse_iterator& operator--()    noexcept;
				constexpr reverse_iterator  operator--(int) noexcept;

			public:
				constexpr reverse_iterator operator+(difference_type diff) const noexcept
				{ return reverse_iterator(miter - diff); }

				constexpr reverse_iterator operator-(difference_type diff) const noexcept
				{ return reverse_iterator(miter + diff); }

			public:
				constexpr reverse_iterator& operator+=(difference_type diff) noexcept;
				constexpr reverse_iterator& operator-=(difference_type diff) noexcept;

			public:
				constexpr const reference operator[](difference_type diff) const noexcept
				{ return *(*this + diff); }

				constexpr       reference operator[](difference_type diff)       noexcept;
			private:
				iterator_type miter;
		};

		template <typename Iter>
		template <typename It>
			constexpr reverse_iterator<Iter>&
			reverse_iterator<Iter>::operator=(const reverse_iterator<It>& other) noexcept
			{
				if (&other == this) {
					return *this;
				}

				miter = other.miter;
				return *this;
			}

		template <typename Iter>
			constexpr typename reverse_iterator<Iter>::reference
			reverse_iterator<Iter>::operator*() const noexcept
			{
				iterator_type tmp = miter;

				return *(--tmp);
			}

		template <typename Iter>
			constexpr typename reverse_iterator<Iter>::pointer
			reverse_iterator<Iter>::operator->() const noexcept
			{
				iterator_type tmp = miter;

				return &(*(--tmp));
			}

		template <typename Iter>
			constexpr reverse_iterator<Iter>&
			reverse_iterator<Iter>::operator++() noexcept
			{
				--miter;
				return *this;
			}

		template <typename Iter>
			constexpr reverse_iterator<Iter>
			reverse_iterator<Iter>::operator++(int) noexcept
			{
				reverse_iterator<Iter> tmp(*this);
				--miter;
				return tmp;
			}

		template <typename Iter>
			constexpr reverse_iterator<Iter>&
			reverse_iterator<Iter>::operator--() noexcept
			{
				++miter;
				return *this;
			}

		template <typename Iter>
			constexpr reverse_iterator<Iter>
			reverse_iterator<Iter>::operator--(int) noexcept
			{
				reverse_iterator<Iter> tmp(*this);
				++miter;
				return tmp;
			}

		template <typename Iter>
			constexpr reverse_iterator<Iter>&
			reverse_iterator<Iter>::operator-=(difference_type diff) noexcept
			{
				miter += diff;
				return *this;
			}

		template <typename Iter>
			constexpr reverse_iterator<Iter>&
			reverse_iterator<Iter>::operator+=(difference_type diff) noexcept
			{
				miter -= diff;
				return *this;
			}

		template <typename Iter>
			constexpr typename reverse_iterator<Iter>::reference
			reverse_iterator<Iter>::operator[](difference_type diff) noexcept
			{
				return const_cast<reference>(
					static_cast<const reverse_iterator<Iter>&>(*this)[diff]
				);
			}

		// ------------------------------------------------------------------------

		template <typename Iter_L, typename Iter_R>
			inline constexpr bool
			operator==(const reverse_iterator<Iter_L>& lhs, const reverse_iterator<Iter_R>& rhs)
			{ return lhs.base() == rhs.base(); }

		template <typename Iter_L, typename Iter_R>
			inline constexpr bool
			operator!=(const reverse_iterator<Iter_L>& lhs, const reverse_iterator<Iter_R>& rhs)
			{ return !(lhs.base() == rhs.base()); }

		template <typename Iter_L, typename Iter_R>
			inline constexpr bool
			operator>(const reverse_iterator<Iter_L>& lhs, const reverse_iterator<Iter_R>& rhs)
			{ return lhs.base() > rhs.base(); }

		template <typename Iter_L, typename Iter_R>
			inline constexpr bool
			operator<(const reverse_iterator<Iter_L>& lhs, const reverse_iterator<Iter_R>& rhs)
			{ return rhs.base() > lhs.base(); }

		template <typename Iter_L, typename Iter_R>
			inline constexpr bool
			operator>=(const reverse_iterator<Iter_L>& lhs, const reverse_iterator<Iter_R>& rhs)
			{ return !(lhs.base() < rhs.base()); }

		template <typename Iter_L, typename Iter_R>
			inline constexpr bool
			operator<=(const reverse_iterator<Iter_L>& lhs, const reverse_iterator<Iter_R>& rhs)
			{ return !(lhs.base() > rhs.base()); }

		template <typename Iter>
			inline constexpr typename reverse_iterator<Iter>::difference_type
			operator+(typename reverse_iterator<Iter>::difference_type diff, const reverse_iterator<Iter>& rhs)
			{ return rhs + diff; }

		template <typename Iter_L, typename Iter_R>
			inline constexpr typename reverse_iterator<Iter_R>::difference_type
			operator-(const reverse_iterator<Iter_L> &lhs, const reverse_iterator<Iter_R> &rhs)
			{ return (rhs.base() - lhs.base()); }
} // namespace cp

#endif // __REVERsE_ITERATOR_H__