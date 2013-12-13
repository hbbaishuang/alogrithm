/**
* @file priority_queue.h
*/

#ifndef _PQUEUE_H_
#define _PQUEUE_H_

#include<vector>
using std::vector;
/**
* Implements the max priority queue ADT.
*
* The implementation is up to you, but you must complete all the given
*  public functions. You will need to add some member variables and private
*  helper functions.
*/
template <class T>
class PriorityQueue
{
public:
	/**
	* Constructor: creates an empty priority queue.
	*/
	PriorityQueue();
	//PriorityQueue(const vector<T> &items);
	/**
	* Inserts the given value into the queue.
	*
	* @param value The value to be inserted.
	*/
	void insert(const T & value);

	/**
	* Removes the highest value (and its associated data) from the
	*  queue.
	*
	* @return A copy of the removed (maximum) element
	*/
	T pop();

	/**
	* Returns the highest value from the queue. Does NOT remove it.
	*
	* @return A copy of the maximum element
	*/
	const T & top() const;

	/**
	* Determines if the queue is empty. Should be O(1).
	*
	* @return A boolean value indicating whether the queue is
	*  empty.
	*/
	bool isEmpty() const;

private:

	int m_nCurrentSize;

	std::vector<T> m_vtArray;

	int findHole(int min,int max,const T &value);

};

template <class T>
PriorityQueue<T>::PriorityQueue():m_vtArray(0),m_nCurrentSize(0)
{	
}

template <class T>
void PriorityQueue<T>::insert(const T & value)
{
	if(m_vtArray.size() == 0)
	{
		m_vtArray.push_back(value);
		++m_nCurrentSize;
		return;
	}
	if(m_nCurrentSize == m_vtArray.size())
	{
		m_vtArray.resize(m_nCurrentSize * 2);
	}

	//上面已经保证可以存下了，不会越界。

	//如果要放到最前面
	if(m_vtArray[0] >= value)
	{
		for(int i = m_vtArray.size() - 1; i > 0; i--)
		{
			m_vtArray[i] = m_vtArray[i-1];
		}
		m_vtArray[0] = value;
		m_nCurrentSize++;
		return;
	}
	//如果要放在最后面
	if(m_vtArray[m_nCurrentSize - 1] <= value)
	{
		m_vtArray[m_nCurrentSize++] = value;
		return;
	}

	int hole = findHole(0, m_nCurrentSize, value);
	for(int i = m_nCurrentSize; i > hole; i--)
	{
		m_vtArray[i] = m_vtArray[i-1];
	}

	m_vtArray[hole]=value;
	m_nCurrentSize++;

}

template <class T>
int PriorityQueue<T>::findHole(int min,int max,const T &value)
{
	//你的查找有问题。只要你自己实现查找就可以了
	while (m_vtArray[min] < value && min <= max)
	{
		min++;
	}
	return min;
}

template <class T>
T PriorityQueue<T>::pop()
{
	//如果越界是用户的问题
	T retval = m_vtArray[m_nCurrentSize - 1];
	m_vtArray.pop_back();
	m_nCurrentSize--;
	return retval;
}

template <class T>
const T & PriorityQueue<T>::top() const
{
	return m_vtArray[m_nCurrentSize-1];

}

template <class T>
bool PriorityQueue<T>::isEmpty() const
{
	return m_nCurrentSize == 0;
}

#endif