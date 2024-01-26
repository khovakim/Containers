#ifndef  __STACK_H__
# define __STACK_H__

# include <algorithm>
# include <stdexcept>
# include <bits/c++config.h>

using std::swap;

namespace cp
{
	template <typename T>
		struct Node
		{
			public:
				Node(T val)             : _val{val}, _next{nullptr} {	}
				Node(T val, Node* next) : _val{val}, _next{next}    {	}
			public:
				T     _val;
				Node* _next;
		};

  template <typename T>
		class stack
		{
			public:
				using value_type      = T;
				using size_type       = std::size_t;

				using pointer         = T*;
				using reference       = T&;

				using const_pointer   = const T*;
				using const_reference = const T&;

			public:
				stack() : _top{nullptr}, _size{0} {	}
				stack(const stack& other);
				stack(stack&& other) noexcept;
				~stack();

				stack& operator=(const stack& other);
				stack& operator=(stack&& other);

			public:
				void push(const value_type& val);
				void push(value_type&& val);

				void pop();

				const_reference top() const;
				reference       top();

				bool      empty() const { return _top == nullptr; }
				size_type size()  const { return _size; }

				void swap(stack& other) noexcept;

				bool operator<(const stack& other) const;
				bool operator==(const stack& other) const;

			private:
				void copy(const stack& other);
				void clear();

			private:
				Node<value_type>*  _top;
				size_type          _size;
		};

	template <typename T>
		void swap(stack<T>& lhs, stack<T>& rhs) noexcept;

	template <typename T>
		bool operator==(const stack<T>& lhs, const stack<T>& rhs);

	template <typename T>
		bool operator!=(const stack<T>& lhs, const stack<T>& rhs);

	template <typename T>
		bool operator>=(const stack<T>& lhs, const stack<T>& rhs);

	template <typename T>
		bool operator<=(const stack<T>& lhs, const stack<T>& rhs);

	template <typename T>
		bool operator<(const stack<T>& lhs, const stack<T>& rhs);

	template <typename T>
		bool operator>(const stack<T>& lhs, const stack<T>& rhs);
	#include "stack.tpp"

} // namespace cp

#endif  // __STACK_H__