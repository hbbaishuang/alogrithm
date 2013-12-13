#ifndef smartptr_h__
#define smartptr_h__
//简单的智能指针
//20131212
class CRefObjcet
{
	CRefObjcet():m_nRef(0)
	{

	}
	~CRefObjcet()
	{

	}

	void AddRef()
	{
		++m_nRef;
	}

	void DelRef()
	{
		if (--m_nRef == 0)
		{
			delete this;
		}
	}


private:
	int m_nRef;
};

template<class T>
class CSmartPtr
{
	CSmartPtr(T* p):m_pt(p)
	{
		if (m_pt)
		{
			m_pt->AddRef();
		}
		
	}
	~CSmartPtr()
	{
		if (m_pt)
		{
			m_pt->DelRef();
		}
	}

	CRefObjcet& operator=(T* p)
	{
		if (m_pt)
		{
			m_pt->DelRef();
		}
		m_pt = p;
		if (m_pt)
		{
			m_pt->AddRef();
		}
	}

	CRefObjcet& operator=(CRefObjcet& p)
	{
		if (m_pt)
		{
			m_pt->DelRef();
		}
		m_pt = p.m_pt;
		if (m_pt)
		{
			m_pt->AddRef();
		}
	}

private:
	T* m_pt;
};
#endif // smartptr_h__

