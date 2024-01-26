#include "./stack.h"

template <typename T>
	cp::stack<T>::stack(const stack& other)
		: _top{nullptr}, _size{0}
	{
		this->copy(other);
	}

template <typename T>
	cp::stack<T>::stack(stack&& other) noexcept
		:_top{other._top}, _size{other._size}
	{
		other._top  = nullptr;
		other._size = 0;
	}

template <typename T>
	cp::stack<T>::~stack()
	{
		this->clear();
	}

template <typename T>
	cp::stack<T>& cp::stack<T>::operator=(const stack& other)
	{
		if (this == &other) {
			return *this;
		}

		this->clear();
		this->copy(other);
	}

template <typename T>
	cp::stack<T>& cp::stack<T>::operator=(stack&& other)
	{
		if (this == &other) {
			return *this;
		}

		this->clear();

		this->_top  = other._top;
		this->_size = other._size;

		other._top  = nullptr;
		other._size = 0;
	}

// ----------------------------------------------------------------------------

template <typename T>
	void cp::stack<T>::push(const value_type& val)
	{
		this->_top = new Node<T> (val, this->_top);
		++this->_size;
	}

template <typename T>
	void cp::stack<T>::push(value_type&& val)
	{
		this->_top = new Node<T> (std::move(val), this->_top);
		++this->_size;
	}

template <typename T>
	void cp::stack<T>::pop()
	{
		if (this->empty()) {
			throw std::out_of_range("stack is empty");
		}

		Node<T>* del = this->_top;

		this->_top = this->_top->_next;
		delete del;

		--this->_size;
	}


template <typename T>
	typename cp::stack<T>::const_reference cp::stack<T>::top() const
	{
		if (this->empty()) {
			throw std::out_of_range("stack is empty");
		}

		return this->_top->_val;
	}

template <typename T>
	typename cp::stack<T>::reference cp::stack<T>::top()
	{
		if (this->empty()) {
			throw std::out_of_range("stack is empty");
		}

		return this->_top->_val;
	}

template <typename T>
	void cp::stack<T>::swap(stack& other) noexcept
	{
		swap(_top, other._top);
		swap(_size, other._size);
	}

template <typename T>
	bool cp::stack<T>::operator==(const stack& other) const
	{
		if (this == &other) {
			return true;
		}

		if (this->size() != other.size()) {
			return false;
		}

		Node<T>* thisNode  = this->_top;
		Node<T>* otherNode = other._top;

		while (thisNode != nullptr) {
			if (thisNode->_val != otherNode->_val) {
				return false;
			}

			thisNode  = thisNode->_next;
			otherNode = otherNode->_next;
		}

		return true;
	}

template <typename T>
	bool cp::stack<T>::operator<(const stack& other) const
	{
		if (this == &other) {
			return false;
		}

		if (this->size() < other.size()) {
			return true;
		}

		Node<T>* thisNode  = this->_top;
		Node<T>* otherNode = other._top;

		while (thisNode != nullptr) {
			if (thisNode->_val >= otherNode->_val) {
				return false;
			}

			thisNode  = thisNode->_next;
			otherNode = otherNode->_next;
		}

		return true;
	}

// ----------------------------------------------------------------------------

template <typename T>
	void cp::stack<T>::clear()
	{
		while (!this->empty()) {
			this->pop();
		}
	}

template <typename T>
	void cp::stack<T>::copy(const stack& other)
	{
		Node<T>* tmp  = other._top;
		Node<T>* prev = nullptr;

		while (tmp != nullptr) {
			Node<T>* node = new Node<T>(tmp->_val);

			if (this->_top == nullptr) {
				this->_top = node;
			} else {
				prev->_next = node;
			}

			prev = node;
			tmp  = tmp->_next;
		}
	}

// ----------------------------------------------------------------------------

template <typename T>
	void swap(stack<T>& lhs, stack<T>& rhs) noexcept
	{
		lhs.swap(rhs);
	}

template <typename T>
	bool operator==(const stack<T>& lhs, const stack<T>& rhs)
	{
		return lhs == rhs;
	}

template <typename T>
	bool operator!=(const stack<T>& lhs, const stack<T>& rhs)
	{
		return !(lhs == rhs);
	}

template <typename T>
	bool operator<(const stack<T>& lhs, const stack<T>& rhs)
	{
		return lhs < rhs;
	}

template <typename T>
	bool operator>(const stack<T>& lhs, const stack<T>& rhs)
	{
		return rhs < lhs;
	}

template <typename T>
	bool operator<=(const stack<T>& lhs, const stack<T>& rhs)
	{
		return !(lhs > rhs);
	}

template <typename T>
	bool operator>=(const stack<T>& lhs, const stack<T>& rhs)
	{
		return !(lhs < rhs);
	}