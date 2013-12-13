#ifndef _LOOP_QUEUE_H_
#define _LOOP_QUEUE_H_
//线性存储 循环队列
//zhangpeng 2013-3-17
template <class T>
class LoopQueue
{
public:
    LoopQueue(int nMaxSize = 50)
        :nSize(nMaxSize + 1)//浪费一个位置
        ,nFront(0)
        ,nRear(0)
    {
        queue = new T[nSize];
    }
    ~LoopQueue(){delete[] queue;};
    bool empty(){return nFront == nRear;};
    bool full(){return (nRear + 1)%nSize == nFront;};
    int size(){return nRear >= nFront?nRear - nFront:nSize + nRear - nFront;};
    bool push_back(const T& x);
    bool pop_front(T& x);
    bool front(T& x);
private:
    T* queue;
    int nFront;
    int nRear;
    int nSize;
};

template <class T>
bool LoopQueue<T>::push_back(const T& x)
{
    if (full())
    {
        return false;
    }
    nRear = (nRear + 1)%nSize;
    queue[nRear] = x;
    return true;
}

template <class T>
bool LoopQueue<T>::pop_front(T& x)
{
    if (empty())
    {
        return false;
    }
    nFront = (nFront + 1)%nSize;
    x = queue[nFront];
    return true;
}

template <class T>
bool LoopQueue<T>::front(T& x)
{
    if (empty())
    {
        return false;
    }
    x = queue[(nFront + 1)%nSize];
    return true;
}

#endif
