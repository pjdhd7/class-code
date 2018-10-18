//Name: Peter Dolan   ID: 12410657
//Instructor: Morales    Section: A    Date: 04/25/2015
//File: llqueue.hpp     Desc: Class implementation of LLQueue

template <typename T>
const Ship& LLQueue<T>::front() const throw (Oops)
{
  Oops err("ERROR: empty list is empty!!!");
  if(m_next == NULL)
    throw err;
  return m_next -> m_next -> m_data;
}

template <typename T>
const Ship& LLQueue<T>::back() const throw (Oops)
{
  Oops err("ERROR: empty list is empty!!!");
  if(m_next == NULL)
    throw err;
  return m_next -> m_data;
}

template <typename T>
void LLQueue<T>::enqueue(const Ship& x)
{
  LLQueue<T>* tmp = new LLQueue<T>;
  if(m_next != NULL)
  {
    tmp -> m_next = m_next -> m_next;
	tmp->m_data.set_ship(x.getFuel(), x.getName(), x.getTime());
    m_next -> m_next = tmp;
    m_next = tmp;
  }
  else
  {
    tmp -> m_next = tmp;
    tmp -> m_data.set_ship(x.getFuel(), x.getName(), x.getTime());
    m_next = tmp;
  }
  return;
}

template <typename T>
void LLQueue<T>::enqueue(int fuel, string name, int time)
{
	LLQueue<T>* tmp = new LLQueue<T>;
	if (m_next != NULL)
	{
		tmp->m_next = m_next->m_next;
		tmp->m_data.set_ship(fuel, name, time);
		m_next->m_next = tmp;
		m_next = tmp;
	}
	else
	{
		tmp->m_next = tmp;
		tmp->m_data.set_ship(fuel, name, time);
		m_next = tmp;
	}
	return;
}

template <typename T>
void LLQueue<T>::dequeue()
{
  if(m_next != NULL)
  {
    LLQueue<T>* tmp = m_next -> m_next;
    m_next = m_next -> m_next -> m_next; 
    //makes the last element point to the hypothetical second element
    delete tmp;
  }
  return;
}

template <typename T>
int LLQueue<T>::count_ships() const
{
  int count = 0;
  LLQueue<T>* tmp = m_next;
  if(tmp != NULL)
  {
    tmp = m_next -> m_next;
    count++;
    while(tmp != m_next)
    {
      tmp = tmp -> m_next;
      count++;
    }
  }
  return count;
}

template <typename T>
void LLQueue<T>::waiting()
{
  if(m_next != NULL)
  {
    LLQueue<T>* tmp = m_next -> m_next;
    while(tmp != m_next)
    {
      tmp -> m_data.addWait();
      tmp = tmp -> m_next;
    }
  }
  return;
}