template <typename T>
bool LLStack<T>::isEmpty() const
{
	if (m_next == NULL)
		return true;
	return false;
}

template <typename T>
const T& LLStack<T>::top() const throw(Oops)
{
  	Oops err("ERROR: empty list is empty!!!");
	if (m_next == NULL)
	  throw err;
	return m_data;
}

template <typename T>
void LLStack<T>::push(const T& x)
{
	LLStack<T>* tmp = new LLStack<T>;
	tmp->m_data = m_data;
	tmp->m_next = m_next;
	m_data = x;
	m_next = tmp;
	return;
}

template <typename T>
void LLStack<T>::pop()
{
	if (m_next != NULL)
	{
		LLStack<T>* tmp = m_next;
		m_data = tmp->m_data;
		m_next = tmp->m_next;
		delete tmp;
	}
	return;
}

template <typename T>
void LLStack<T>::clear()
{
	while (m_next != NULL)
	{
		LLStack<T>* temp = m_next;
		m_data = temp->m_data;
		m_next = temp->m_next;
		delete temp;
	}
  return;
}

template <typename T>
void LLStack<T>::add2()
{
  if(~(isEmpty()) && m_next -> m_next != NULL)
  {
    int value = m_data + (m_next -> m_data);
    pop();
    m_data = value;
  }
  return;
}

template <typename T>
void LLStack<T>::minus()
{
  if(~(isEmpty()) && m_next -> m_next != NULL)
  {
    int value = (m_next -> m_data) - m_data;
    pop();
    m_data = value;
  }
  return;
}

template <typename T>
void LLStack<T>::times()
{
  if(~(isEmpty()) && m_next -> m_next != NULL)
  {
    int value = m_data * (m_next -> m_data);
    pop();
    m_data = value;
  }
  return;
}

template <typename T>
void LLStack<T>::divide()
{
  if(~(isEmpty()) && m_next -> m_next != NULL)
  {
	  int value = (m_next->m_data) / m_data;
    pop();
    m_data = value;
  }
  return;
}

template <typename T>
void LLStack<T>::mod()
{
  if(~(isEmpty()) && m_next -> m_next != NULL)
  {
    int value = (m_next -> m_data) % m_data;
    pop();
    m_data = value;
  }
  return;
}

template <typename T>
void LLStack<T>::negate()
{
  if(~(isEmpty()))
  {
    m_data = m_data * -1;
  }
  return;
}

template <typename T>
void LLStack<T>::sum()
{
  if(~(isEmpty()))
  {
	  int the_sum = 0;
	  while (m_next != NULL)
	  {
		  the_sum = the_sum + top();
		  pop();
	  }
	  push(the_sum);
  }
  return;
}

template <typename T>
void LLStack<T>::reverse()
{
  if(~(isEmpty()))
  {
    LLStack<T>* temp1= this;
    LLStack<T>* temp2=new LLStack<T>;
	while (temp1->m_next != NULL)
	{
		temp2->push(temp1->top());
		temp1->pop();
	}
	temp1->m_data = temp2->m_data;
	temp1->m_next = temp2->m_next;
	delete temp2;
  }
  return;
}